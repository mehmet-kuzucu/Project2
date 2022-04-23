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
    
    struct Pair pair;;
    struct Voter user;
    printf("%s \n", "PLEASE, TYPE YOUR USERNAME :  ");
    scanf("%s", user.username);

    int i;
    
    for (i = 0; i < 4; i++) {

        if (!strcmp(user.username, voter_array[i].username) ) {
            //username exits
            printf("%s \n", "USERNAME IS CORRECT!!  ");
            printf("%s \n", "PLEASE, TYPE YOUR PASSWORD :  ");
            scanf("%s", user.password);

            if (!strcmp(user.password, voter_array[i].password)) {
                //password correct
                printf("%s \n", "PASSWORD IS CORRECT!!  ");
                pair.is_exits = 1;
                pair.index = i;
                return pair;
            }
                //password is not exits but user name does.
                pair.is_exits = 0;
                pair.index = 0;
                printf("%s \n", "PASSWORD IS NOT MATCHING WITH USERNAME!! ");
                return pair;

        }
        } 
            //username is not exits
            pair.is_exits = 0;
            pair.index = 0;
            printf("%s \n", "USERNAME DOES NOT EXITS ");
            return pair;
            
            
    

}


// 2-) asking user vote

int ask_vote (struct Voter voter_array[], int user_index) {
    

    // first check is user voted already, if voted return 0. You can do this by looking vote and if it is "-" this means it is not voted yet. 
    if (strcmp(voter_array[user_index].vote, "-")) {
        //user already voted
        printf("%s \n\n", "YOU ARE ALREADY VOTED");
        return 0;
    }

    // asking "yes" or "no" and add that answer to correct votes index
    printf("%s \n", "PLEASE VOTE, 'yes' or 'no'  :");
    char vote[10];
    scanf("%s", vote);


    // strcpy(voter_array[1].vote, "yes");   ->  example code
    if (!strcmp(vote, "yes") || !strcmp(vote, "no")){
        strcpy(voter_array[user_index].vote, vote);
        //end of function
        return 1;
    }
    printf("%s \n\n", "INVALID ANSWER");
    return 0;

    

}


// 3-) checking whether majority voted "yes" or "no" then returning true of false

int  checking_majority (struct Voter voter_array[]) {
    // check the votes, and if there is majority return 1, if there no majority return 0
    int i;
    int yes = 0;
    int no = 0;
    
    for (i = 0; i < 4; i++){
        if(!strcmp(voter_array[i].vote, "yes")){
            yes++;
        }
        if(!strcmp(voter_array[i].vote, "no")){
            no++;
        }
        if(yes > 4/2 || no > 4/2){ // after level1 we should find the size of array not just 4
            printf("%s \n\n", "THERE IS MAJORITY");
            return 1;
        } 
    }
    
    //there is no mojority
    return 0;
}


// LEVEL 2

// 3-) updating level 1.1, adding abstain format


// 4-) changing user password // kadija

void changing_password (struct Voter voter_arry[]) {
  
  
}
   

// 5-) changing votes

void changing_vote (struct Voter voter_array[]) {
    //eray
    
}


// 6-) writing data to file 

void writing_data () {
    //dilara and mehmet

  
}






int main(void){

    
    int cont; // continou or break
    int majority_val; // stores checking_mojority return
    int is_voted; // stores ask_vote return

    struct Voter user1 = {"user1", "password1", "-"};
    struct Voter user2 = {"user2", "password2", "-"};
    struct Voter user3 = {"user3", "password3", "-"};
    struct Voter user4 = {"user4", "password4", "-"}; 

    struct Voter voter_array[] = {user1, user2, user3, user4};



    struct Pair pair; 
    

    // main loop
    int i = 0;

    while (i < 4) { //we should use array size not 4 but it is enough for level1
        
        printf("%s \n\n", "*PROGRAM STARTED*");
        printf("%s \n\n", "*WELLCOME*");

        

        //asking username and password to login
        pair = login(voter_array);
        if (pair.is_exits == 0){
            //login is not correct, go to next user
            continue;
        }

        printf("%s \n", "IF YOU WANT TO VOTE PRESS ANYTHING ");
        printf("%s \n", "IF YOU WANT TO LEAVE PRESS 2");    
        
        //*right now if user type char insted of intiger, program crashes*

        scanf("%d", &cont);
        switch (cont){
            
            case 2:
                // user wants to leave
                printf("%s \n", " USER SIGN OUT");
                continue;
        }
            

        // asking the users vote
        is_voted = ask_vote(voter_array, pair.index);
        if (!is_voted) {
            // user already voted, pass this user 
            continue;
        }
        i++;// for while loop


        //checking majority
        majority_val = checking_majority(voter_array);
        if (majority_val){
            //there is majotiry exit
            break;
        }

    }

    printf("%s \n\n", "PROGRAM WORKS!!");      
}
