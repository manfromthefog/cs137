#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Person {
    int id;
    int speed;
    struct Person* next;
} Person;

// Returns a person with an ID and a specific speed
Person updatePerson(int id, int speed){
    Person p;
    p.id = id;
    p.speed = speed;
    p.next = NULL;

    return p;
}

// Adds a person to the end of the linked list of persons
// and makes the linked list circular (end points to start)
void addPerson(Person** start, Person* new) {
    // base case
    if (*start == NULL) {
        (*start) = new;
        new->next = new;
        return;
    }
    
    Person *cur = *start;
    while (cur->next != (*start))
        cur = cur->next;
    cur->next = new;
    new->next = (*start);
}

// Removes a person from the linked list of persons
// Does not free the pointer to the removed person
void removePerson(Person** start_ptr, Person* target, int id) {
    Person *curnode = target->next;

    // Loop to find prev and node to remove
    while (curnode->id != id) {
        target = curnode;
        curnode = curnode->next;
    }

    // check if the removed node is the current list head
    if (*start_ptr == curnode) {
        // the new head is the node after the removed one
        *start_ptr = curnode->next;
    }
    
    // Unlink the node
    target->next = curnode->next;
}

// Plays a game of duck duck goose, printing results for each round
// Winner of each round is determined by speed
// Returns the final winner
Person* play(Person* start) {
    Person *tag = start; // tagger
    Person *curp = start->next; // current person
    bool overthrown = true;

    while (true) {
        // first thing is to remove the tagger from the list
        if (overthrown) removePerson(&curp, tag, tag->id);
        Person *player = curp;

        for (int i=0;i<tag->id;i++) {
            printf("%d duck %d\n", tag->id, player->id);
            player=player->next;
        }
        printf("%d goose! %d\n", tag->id, player->id);

        // every game has a win condition
        // this time, it's if there is one person left in the circle
        if (curp->next == curp) {
            Person *win;
            if (tag->speed > curp->speed) {
                printf("winner! %d\n", tag->id);
                free(curp);
                win = tag;
            } else {
                printf("winner! %d\n", curp->id);
                free(tag);
                win = curp;
            }
            return win;
        }

        // compare their speeds
        if (tag->speed > player->speed) {
            // chaser won
            removePerson(&curp, player, player->id);
            free(player);
            overthrown = false;
        } else {
            // chaser lost
            Person *lostchaser = tag; // lostchaser = tag -> [...]
            tag = player; // tag -> [winner]
            curp = tag; // curp -> [winner] (to be moved forward)
            free(lostchaser); // the old address of the chaser is freed
            overthrown = true;
        }
    }
}


// Do Not Change
/*
int main() {
    int p, s;

    // List of people
    Person* lop = NULL;

    // Read in participants
    while (scanf("%d %d", &p, &s) == 2) {
        Person* np = (Person*)malloc(sizeof(Person));
        *np = updatePerson(p, s);
        addPerson(&lop, np);
    }

    Person* winner = play(lop);
    free(winner);
}
*/
