#include <stdio.h>
#include <stdbool.h>
#include <string.h>


struct Voter {
  char username[50];
  char password[50];
  char vote[50];
};

struct Pair {
    int is_exits;
    int index;
};



// *LEVEL 1*

// 1-) inputing username and password, then returning either 1 or 0

struct Pair login (struct Voter voter_array[]){

    // asking username and checking is that username exists

    // asking password and checking is that password belongs to correct username

    // if everything matching return Pair which can stores both value 1 or 0 and index of user

}


// 2-) asking user vote

int ask_vote (struct Voter voter_array[]) {

    // first check is user voted already, if voted return 0

    // asking "yes" or "no" and add that answer to correct votes index

    // strcpy(voter_array[1].vote, "yes");   ->  example code

}


// 3-) checking whether majority voted "yes" or "no" then returning true of false

int  checking_majority (struct Voter voter_array[]) {

    // check the votes, and if there is majority return 1, if there no majority return 0

}


int main(void){

    
    int cont; // continou or break
    int login_val; // stores login return
    int login_index; // index of users
    int majority_val; // stores checking_mojority return
    int is_voted; // stores ask_vote return

    struct Voter user1 = {"user1", "password1", "-"};
    struct Voter user2 = {"user2", "password2", "-"};
    struct Voter user3 = {"user3", "password3", "-"};
    struct Voter user4 = {"user4", "password4", "-"}; 

    struct Voter voter_array[] = {user1, user2, user3, user4};

    struct Pair p; 
    // main loop

    while (true) {

        printf("%s \n\n", "PROGRAM STARTED");

        

        //asking username and password to login
        p = login(voter_array);
        if (is_exits == 0){
            //login is not correct
        }


        printf("%s \n", "IF YOU WANT TO VOTE ANYTHING ");
        printf("%s \n", "IF YOU WANT TO LEAVE PRESS 2");    
        
        scanf("%d", cont);
        switch (cont){
            
            case 2:
                // user wants to leave
                printf("%s \n", " PROGRAM END");
                return 0;
        }
        

        // asking the users vote
        ask_voted = ask_vote(voter_array);
        


        //checking majority
        majority_val = checking_majority(voter_array);
        if (majority_val == 1){
            //there is majotiry exit
        }

    }
         
}
