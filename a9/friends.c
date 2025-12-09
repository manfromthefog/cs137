#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct Friend Friend;

// Linked List to represent connected friends
typedef struct IdLinked {
    Friend *this;
    struct IdLinked *next;
} IdLinked; 

// Friends
typedef struct Friend {
    int id;
    IdLinked *n;  
} Friend;

/**
 * createFriend(id)
 * Creates a friend with an ID and an uninitialized list of connections
 * 
 * requires: the passed ID is unique
 */
Friend* createFriend(int id) {
    Friend *created_friend = malloc(sizeof(Friend));

    created_friend->id = id;
    created_friend->n = NULL;

    return created_friend;
}

/**
 * connectFriends(f1, f2)
 * Connects two friends, if not mutually connected already.
 */
void connectFriends(Friend *f1, Friend *f2) {
    // check f1's connected friends
    IdLinked *f1_friends = f1->n;
    bool f1_conn_f2 = false;
    while (f1_friends) {
        // we found f2 in f1's connections
        if (f1_friends->this->id == f2->id) {
            f1_conn_f2 = true;
        }
        f1_friends = f1_friends->next;
    }
    
    // check f2's connected friends
    IdLinked *f2_friends = f2->n;
    bool f2_conn_f1 = false;
    while (f2_friends) {
        // we found f2 in f1's connections
        if (f2_friends->this->id == f1->id) {
            f2_conn_f1 = true;
        }
        f2_friends = f2_friends->next;
    }

    if (f1_conn_f2 && f2_conn_f1)
        return;
    else {
        if (!f2_conn_f1) {
            // add to the front of f2 LL
            IdLinked *link = malloc(sizeof(IdLinked));
            link->this = f1;
            link->next = f2->n;
            f2->n = link;
        }
        if (!f1_conn_f2) {
            // do it again for the front of f1 LL
            IdLinked *link = malloc(sizeof(IdLinked));
            link->this = f2;
            link->next = f1->n;
            f1->n = link;
        }
        
    }
}

/*** BFS HELPER FUNCTIONS ***/

// a linked list to document nodes already visited
typedef struct Visited {
    int val;
    struct Visited *next;
} Visited;

// a linked list to store friends in the order they are connected
typedef struct QueueNode {
    Friend *this;
    struct QueueNode *next;
} QueueNode;

// First in, first out queue principle

// Appends a friend to the front of the Queue, updating head and tail as well
void enter_queue(QueueNode **head, QueueNode **tail, Friend *f) {
    QueueNode *new_friend = malloc(sizeof(QueueNode));
    new_friend->this = f;
    new_friend->next = NULL;
    if (*tail) 
        (*tail)->next = new_friend;
    else
        *head = new_friend;
    *tail = new_friend;
}

// Removes the last friend from QueueNode and returns the friend.
Friend *leave_queue(QueueNode **head, QueueNode **tail) {
    // remove the last element in the queue
    QueueNode *curnode = *head;
    Friend *removed = curnode->this;
    *head = (*head)->next;
    // if nothing remains, nullify the tail as well
    if (!(*head)) (*tail) = NULL;
    free(curnode);

    return removed;
}

/**
 * isVisited(person, visitedlist)
 * Determines if a person is in the visited list.
 */
bool isVisited(Friend *person, Visited *visitedlist) {
    // a very important function in bfs
    // ID is a unique identifier
    while (visitedlist) {
        if (visitedlist->val == person->id)
            return true;
        visitedlist = visitedlist->next;
    }
    // add the person to our linked list
    
    return false;
}

// Add a friend's ID to the visited persons linked list
// does not check for pre-existing IDs
void addVisited(Friend *person, Visited **visitedhead) {
    Visited *newperson = malloc(sizeof(Visited));
    newperson->val = person->id;
    // newperson -> [...] <- visitedhead
    newperson->next = *visitedhead;
    // visitedhead -> newperson -> [...]
    (*visitedhead) = newperson;
}

/*
bool freeQueue(QueueNode *head) {}
*/

// freeVisited() frees the linked list of Visited friend's IDs
void freeVisited(Visited *head) {
    Visited *curnode = head;
    while (curnode) {
        head = curnode->next;
        free(curnode);
        curnode = head;
    }
}

/**
 * isConnected(f1, f2)
 * Determines if a series of continuous connections can be found
 * between f1 and f2 using BFS.
 */
bool isConnected(Friend *f1, Friend *f2) {
    bool found = false;

    // queue = {start}
    QueueNode *head = NULL, *tail = NULL;
    enter_queue(&head, &tail, f1);
    
    // mark start visited
    Visited *checked = NULL;
    addVisited(f1, &checked);
    //printf("Where?\n");
    while (head) {
        // look through each friend of current
        Friend *cur = leave_queue(&head, &tail);
        IdLinked *friends = cur->n;
        // for each friend in current
        for (;friends;friends = friends->next) {
            // found him?
            if (friends->this->id == f2->id && found == false) found = true;
            if (!isVisited(friends->this, checked)) {
                // mark as visited and append to queue
                addVisited(friends->this, &checked);
                enter_queue(&head, &tail, friends->this);
            }
        }
    }
    // free the Visited
    // queue should be freed as each friend leaves the queue
    freeVisited(checked);
    return found;
}

// Removes a friend. Frees their list of connections and removes themselves
// from all instances in other people's list of connections
void destroyFriend(Friend* f) {
    // we need to free everyone whose friend list includes friend
    // and the friend list of friend
    IdLinked *conn_list = f->n;
    while (conn_list) {
        // purge friend from this connected friend's list of friends
        IdLinked *curr = conn_list->this->n;
        IdLinked *prev = NULL;

        while (curr) {
            // found him
            if (curr->this == f) {
                bool freed = false;
                if (prev == NULL) {
                    conn_list->this->n = curr->next;
                    free(curr);
                    freed = true;
                }
                else {
                    // prev.next = curr.next
                    IdLinked *oldfriend = curr;
                    curr = curr->next;
                    prev->next = curr;
                    free(oldfriend);
                    freed = true;
                }
                if (freed) break;
            }
            prev = curr;
            curr = curr->next;
            
        }
        // we now free this friend from the friend's list
        IdLinked *next_friend = conn_list->next;
        
        // the current friend will be removed
        free(conn_list);
        conn_list = next_friend;
    }
    // lastly we free the friend
    free(f);
}

/*
int main() {
    Friend* f1 = createFriend(1);
    Friend* f2 = createFriend(2);
    Friend* f3 = createFriend(3);
    Friend* f4 = createFriend(4);

    connectFriends(f1, f2);
    assert(isConnected(f1, f2));
    assert(!isConnected(f1, f3));
    
    connectFriends(f2, f3);
    assert(isConnected(f1, f3));
    assert(isConnected(f2, f3));
    assert(isConnected(f3, f1));
    assert(!isConnected(f3, f4));

    connectFriends(f4, f3);
    assert(isConnected(f4, f1));

    connectFriends(f1, f4);
    assert(isConnected(f2, f3));
    assert(isConnected(f1, f3));

    connectFriends(f1,f3);

    Friend* f5 = createFriend(5);
    Friend* f6 = createFriend(6);
    assert(!isConnected(f5, f6));
    assert(!isConnected(f1, f5));

    connectFriends(f5, f6);
    connectFriends(f1, f5);
    assert(isConnected(f1, f5));
    assert(isConnected(f1, f6));
    assert(isConnected(f2, f6));
    
    destroyFriend(f2);
    destroyFriend(f4);
    assert(isConnected(f1, f3));
    destroyFriend(f1);
    assert(!isConnected(f3, f5));
    assert(isConnected(f5, f6));
    destroyFriend(f5);
    assert(!isConnected(f3, f6));
    destroyFriend(f3);
    destroyFriend(f6);

    printf("Done\n");
    return 0;
}
*/
