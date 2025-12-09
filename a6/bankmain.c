#include "bank.h"
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

Bank* CreateBank(double money, double maxLoan, double loanInterest, double transferFeeRate) {
    // Allocate bank
    Bank *bank = malloc(sizeof(Bank));
    assert(bank);
    // No accounts yet
    bank->accounts = NULL;
    bank->nAcc = 0;
    // Assign inputs
    bank->money = money;
    bank->maxLoan = maxLoan;
    bank->loanInterest = loanInterest;
    bank->transferFeeRate = transferFeeRate;

    return bank;
}

Account* OpenAccount(Bank *bank) {
    Account *new_account = malloc(sizeof(Account));
    
    // Increase number of users
    bank->nAcc += 1;

    // Set the new number to the account ID
    new_account->id = bank->nAcc;

    // Reallocate accounts array and add new user
    bank->accounts = realloc(bank->accounts, sizeof(Account) * bank->nAcc);
    bank->accounts[bank->nAcc - 1] = new_account;

    // bank balance of zero and no loan numbers
    new_account->active = true;
    new_account->loan.active = false;
    new_account->loan.amount = 0.0;
    new_account->loan.interest = 1.0;

    // balance of zero and point at the bank
    new_account->balance = 0.0;
    new_account->bank = bank;

    return new_account;
}

void Deposit(double amount, Account *account) {
    if (account->active) {
        account->balance += amount;
    }
}

bool Withdraw(double amount, Account *account) {
    if (account->active) {
        if (account->balance >= amount) {
            account->balance -= amount;
            return true;
        }
    }
    return false;
}

bool TakeLoan(double amount, Account *account) {
    if (account->active && !account->loan.active) {
        if (amount <= account->bank->maxLoan) {
            // Increase balance by loan amount
            account->balance += amount;

            // Deduct this amount from the bank's money pool
            account->bank->money -= amount;

            // Set the loan struct so it can later be repaid
            account->loan.active = true;
            account->loan.amount = amount;
            account->loan.interest = account->bank->loanInterest;
            return true;
        }
    }
    return false;
}

bool PayLoan(Account *account) {
    // check if the account is active and has a loan
    if (account->active && account->loan.active) {
        // calculate the amount to be paid
        double deficit = account->loan.amount * account->loan.interest;
        if (account->balance > deficit) {
            // if it can be paid, pay it!
            account->balance -= deficit;
            account->bank->money += deficit;
            return true;
        }
    }
    return false;
}

bool Transfer(double amount, Account *sender, Account *receiver) {
    // if either of the senders are inactive return false
    if (!sender->active && !receiver->active) return false;
    double fee = 0;
    if (sender->bank != receiver->bank) {
        // set a transfer fee iff the banks are different
        fee = sender->bank->transferFeeRate * amount;
    }
    // the sender pays the transfer fee to their bank
    sender->bank->money += fee;

    // Transfer the money
    sender->balance -= amount + fee;
    receiver->balance += amount;

    return true;
}

bool CollectLoanPayments(Bank *bank) {
    // if a single instance is false, the return is false
    int all_paid = true;
    for (int i = 0; i < bank->nAcc; i++) {
        if (!PayLoan(bank->accounts[i])) {
            all_paid = false;
        }
    }
    return all_paid;
}

bool CloseAccount(Account *account) {
    // if the account is already inactive then it's closed
    if (!account->active) return true;

    // most importantly deactivate the account
    // set balance to zero
    account->active = false;
    account->balance = 0;

    // if we can't pay the loan bank then no closing
    if (!PayLoan(account)) return false;
    
    return true;
}

Bank* ForceDestroyBank(Bank *bank) {
    // Check if bank exists
    if (!bank)
        return NULL;
    // Just free the memory
    for (int i = 0; i < bank->nAcc; i++) {
                  free(bank->accounts[i]);
    }
    free(bank->accounts);
        
    free(bank);
    bank = NULL;
    return NULL;
}

void ShowAccount(Account *account) {
    printf("Account #%d:\n", account->id);
    if (account->active) {
        printf("Balance: %.3f\n", account->balance);
        if (account->loan.active) {
            printf("Loaned %.3f with interest %f\n",
                account->loan.amount, account->loan.interest);
        }
    } else {
        printf("Inactive account\n");
    }
}

void ShowBank(Bank *bank) {
    printf("BANK:\n");
    printf("Total money in bank: %.3f\n", bank->money);
    printf("Maximum loan offered: %.3f\n", bank->maxLoan);
    printf("Interest for loans: %f\n", bank->loanInterest);
    printf("Fee for a money transfer: %f\n", bank->transferFeeRate);
    //printf("----------------\n");
    for (int i = 0; i < bank->nAcc; i++) {
        ShowAccount(bank->accounts[i]);
        printf("----------------\n");
    }
}

int main(void) {
    printf("creating b0\n");
    Bank *b0 = CreateBank(1000, 100, 1.0001, 0.0001);
    assert(b0);
    printf("creating b1\n");
    Bank *b1 = CreateBank(2000, 300, 1.0001, 0.0001);
    assert(b1);
    printf("adding a0 to b0\n");
    Account *a0 = OpenAccount(b0);
    assert(a0);
    printf("adding a1 to b1\n");
    Account *a1 = OpenAccount(b1);
    assert(a1);
    printf("adding a2 to b1\n");
    Account *a2 = OpenAccount(b1);
    assert(a2);
    printf("deposit 200 in a0\n");
    Deposit(200, a0);
    ShowAccount(a0);
    printf("loan 100 for a0\n");
    TakeLoan(100, a0);
    ShowAccount(a0);
    printf("deposit 500 in a1\n");
    Deposit(500, a1);
    ShowAccount(a1);
    printf("deposit 400 in a2\n");
    Deposit(400, a2);
    ShowAccount(a2);
    
    // Deposit
    printf("deposit 300 in a0\n");
    Deposit(300, a0);
    printf("deposit 300 in a1\n");
    Deposit(300, a1);
    printf("deposit 100 in a2\n");
    Deposit(100, a2);

    ShowBank(b0);
    printf("*********\n");
    ShowBank(b1);
    // Withdraw
    printf("withdraw 200 from a0\n");
    Withdraw(200, a0);
    
    ShowBank(b0);
    printf("*********\n");
    ShowBank(b1);
    // Take Loan
    printf("100 loan to a0\n");
    TakeLoan(100, a0);

    // Transfer
    printf("100 transfer from a1 to a0\n");
    Transfer(100, a1, a0);  // No fee same bank
    printf("50 transfer from a1 to a2\n");
    Transfer(50, a1, a2);   // Fee applied - different banks

    ShowBank(b0);
    printf("*********\n");
    ShowBank(b1);
    // Pay Loan
    printf("collect loan payment b0\n");
    CollectLoanPayments(b0);

    ShowBank(b0);
    printf("*********\n");
    ShowBank(b1);

    Withdraw(5000, a1);
    ShowAccount(a1);
    printf("close a1\n");

    CloseAccount(a1);
    ShowBank(b0);
    printf("*********\n");
    ShowBank(b1);
    printf("the end\n");
    
    // Force Destroy 
    ForceDestroyBank(b0);
    ForceDestroyBank(b1);
    return 0;
}

