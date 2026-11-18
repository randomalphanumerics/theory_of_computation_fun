/*  A small finite state machine
 *  Would like to make this more generic: implementing a configurable state machine 
 *  Here, we consider input as stdin and output as stdout. 
 *  Reading each one by one, we shift through the states to get an output
 */


#include <stdio.h> 

/* Current state machine is designed to detect two 1s in a row, and reject all other states
 *
 *
 *
 */ 



enum state {
    ONE, TWO, THREE
};

int main() {
    enum state curr_state = ONE; //starts at one
    int scanned_num;           //TODO: restrict to boolean (if possible)
    while (1) {
        switch (curr_state) {
        case ONE:
            printf("Enter 0 or 1: "); 
            scanf("%d", &scanned_num); 
            if(scanned_num == 0) {curr_state = ONE;}
            else if(scanned_num == 1) {curr_state = TWO;}
            else {printf("Please return a valid value\n");}
            break;

        case TWO:
            printf("Enter 0 or 1: "); 
            scanf("%d", &scanned_num); 
            if(scanned_num == 0) {curr_state = ONE;}
            else if(scanned_num == 1) {curr_state = THREE;}
            else {printf("Please return a valid value\n");}
            break;

        case THREE: 
            printf("Two ones detected.\n");
            return 0;  
        }
    } 

}
