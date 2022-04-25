#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


struct Voter {
  char username[50];
  char password[50];
};

struct Pair {
    int is_exits;
    int index;
};

struct Issue {
    char name[100];
    char is_done[10];
    char votes[10][10];
};


// *LEVEL 1*

// 1-) inputing username and password, then returning either 1 or 0


struct Pair login (struct Voter voter_array[], int array_size_of_voter_array){

    // asking username and checking is that username exists
    // asking password and checking is that password belongs to correct username
    // if everything matching return Pair which can stores both value 1 or 0 and index of user
    
    struct Pair pair;
    struct Voter user;
    int i = 0;
    printf("%s \n", "PLEASE, TYPE YOUR USERNAME :  ");
    scanf("%s", user.username);

    if (!strcmp(user.username, voter_array[i].username)) {
        //admin user
        printf("%s \n", "YOU WANT TO LOGIN AS AN ADMIN ");
        printf("%s \n", "PLEASE, TYPE YOUR PASSWORD :  ");
        scanf("%s", user.password);
        if (!strcmp(user.password, voter_array[i].password)) {
            //admin password correct
            pair.is_exits = 1;
            pair.index = i;
            printf("%s \n", "ADMIN IS HERE ");
            return pair;
        }
    }
    

    i++;
    for (; i < array_size_of_voter_array; i++) {

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

int ask_vote (struct Issue issue_array[], int issue_index, int user_index) {
    
    // first check is user voted already, if voted return 0. You can do this by looking vote and if it is "-" this means it is not voted yet. 
    if (strcmp(issue_array[issue_index].votes[user_index], "-")) {
        //user already voted
        printf("%s \n\n", "YOU ARE ALREADY VOTED");
        return 0;
    }

    if (strcmp(issue_array[issue_index].is_done, "no")){
        printf("%s \n\n", "THIS ISSUE IS ALREADY DONE");
        return 0;
    }

    // asking "yes" or "no" and add that answer to correct votes index
    printf("%s \n", "PLEASE VOTE, 'yes' or 'no'  :");
    char vote[10];
    scanf("%s", vote);

    // strcpy(voter_array[1].vote, "yes");   ->  example code
    if (!strcmp(vote, "yes") || !strcmp(vote, "no")){
        strcpy(issue_array[issue_index].votes[user_index], vote);
        printf("%s \n\n", "YOUR ANSWER IS TAKEN");
        //end of ask_vote function
        return 1;
    }
    printf("%s \n\n", "INVALID ANSWER");
    return 0;
}

// 3-) checking whether majority voted "yes" or "no" then returning true of false

int  checking_majority (struct Issue issue_array[], int issue_index, int array_size_of_issue_array, int array_size_of_voter_array) {
    // check the votes, and if there is majority return 1, if there no majority return 0
    int i;
    int yes = 0;
    int no = 0;
    int abstain = 0;

    for (i = 0; i < array_size_of_voter_array; i++){
        if(!strcmp(issue_array[issue_index].votes[i], "yes")){
            yes++;
        }
        if(!strcmp(issue_array[issue_index].votes[i], "no")){
            no++;
        }
        if(!strcmp(issue_array[issue_index].votes[i], "abstain")){
            abstain++;
        }
    } 

    if(yes > (array_size_of_voter_array - abstain)/2 || no > (array_size_of_voter_array - abstain)/2){ // after level1 we should find the size of array not just 4
        strcpy(issue_array[issue_index].is_done, "yes");
        printf("%s %d \n\n", "THERE IS MAJORITY IN THE ISSUE: ", issue_index);
        printf("yes vote: %d \nno vote : %d \n", yes, no);
        return 1;
    } 

    //there is no mojority
    return 0;
}

// LEVEL 2

// 3-) updating level 1.1, adding abstain format


// 4-) changing user password 

void changing_password (struct Voter voter_array[], int index) {
    // kadijasss

    printf("%s \n", "TYPE YOUR NEW PASSWORD");  
    scanf("%s",voter_array[index].password); 
    printf("%s \n", "YOUR PASSWORD CHANGED");
}


// 5-) changing votes

void changing_vote (struct Issue issue_array[], int issue_index, int index) {
    //eray

    printf("%s \n", "TYPE YOUR NEW VOTE");  
    scanf("%s", issue_array[issue_index].votes[index]); 
    printf("%s \n", "YOUR VOTE CHANGED");
}

// 6-) writing and reading data to file 

void writing_data (struct Voter voter_array[], struct Issue issue_array[], int array_size_of_voter_array, int array_size_of_issue_array) {
    //dilara and mehmet
    FILE *f;
    f = fopen("ex.txt", "w");

    if (f == NULL){
        printf("%s\n", "file do not exists");
    }

    //fprintf(f, "%s  ", "username");
    for (int i = 0; i < array_size_of_voter_array; i++) {
        fprintf(f, "%s  ", voter_array[i].username);
    }

    fprintf(f, "\n", "" );

    //fprintf(f, "%s  ", "password");
    for (int i = 0; i < array_size_of_voter_array; i++) {
        fprintf(f, "%s  ", voter_array[i].password);
    }

    fprintf(f, "\n", "" );

    //writing issue votes
    for (int i = 0; i < array_size_of_issue_array; i++) {

        for (int j = 0; j < array_size_of_voter_array ; j++) {
            fprintf(f, "%s  ", issue_array[i].votes[j]);
        }
        fprintf(f, "\n", "" );
        
    }

    fclose(f);
}

// reading from file
void reading_data (struct Voter voter_array[], int array_size_of_voter_array, struct Issue issue_array[], int array_size_of_issue_array) {
    char buf[100];

    FILE *r;
    r = fopen("ex.txt", "r");
    

    for (int i = 0; i < array_size_of_voter_array; i++){
        fscanf(r, "%s ", voter_array[i].username);
    }

    for (int i = 0; i < array_size_of_voter_array; i++){
        fscanf(r, "%s ", voter_array[i].password);
    }

    for (int i = 0; i < array_size_of_issue_array; i++) {

        for (int j = 0; j < array_size_of_voter_array ; j++) {
            fscanf(r, "%s  ", issue_array[i].votes[j]);
        }   
    }
}

void adding_new_user (struct Voter voter_array[], int array_size_of_voter_array) {

    struct Voter user_temp;

    printf("%s \n", "PLEASE, TYPE NEW USER'S USERNAME:  ");
    scanf("%s", user_temp.username);

    printf("%s \n", "PLEASE, TYPE NEW USER'S PASSWORD:  ");
    scanf("%s", user_temp.password);

    voter_array[array_size_of_voter_array] = user_temp;
    printf("%s \n", "ADDING USER IS COMPLETED");
}

void printing_multiple_issues (struct Issue issue_array[], int array_size_of_issue_array) {

    int i;
    printf("\n %s \n", "PLEASE, SELECT AN ISSUE :  ");
    for (i = 0; i < array_size_of_issue_array; i++) {
        printf(" %d - %s \n", i, issue_array[i].name );
    }
}

void adding_new_issue(struct Issue issue_array[], int array_size_of_issue_array) {

    struct Issue temp;

    printf("%s \n", "PLEASE, TYPE YOUR NEW ISSUE:  ");
    
    //not using scanf because scanf cannot take strings with spaces. for example: "new issue" this sting only shown as "new"
    fgets(temp.name, 100, stdin);

    strcpy(temp.is_done, "no");


    for(int i = 0; i < 10; i++ ){
        
        strcpy(temp.votes[i], "-");
    }

    issue_array[array_size_of_issue_array] = temp;
}

// calculating the undone issues
int size_of_done_issues (struct Issue issue_array[], int array_size_of_issue_array) {

    int i;
    int count = 0;
    for (i = 0; i < array_size_of_issue_array; i++){
        if (!strcmp(issue_array[i].is_done, "no")) {
            count++;
        }
    }
    return count;
}


int main(void){

    int cont; // continou or break
    int majority_val; // stores checking_mojority return
    int is_voted; // stores ask_vote return
    int b;        // used in finding the array size of issue array
    int e;        // used in finding the array size of voter array
    int undone_issue;  // stores size_of_done_issue function return.  used the store undone issues
    struct Pair pair;    // used store login return

    struct Voter admin = {"admin", "123"};
    struct Voter user1 = {"user1", "password1"};
    struct Voter user2 = {"user2", "password2"};
    struct Voter user3 = {"user3", "password3"};
    struct Voter user4 = {"user4", "password4"}; 
    struct Voter voter_array[10] = {admin, user1, user2, user3, user4};

    //  multiple issue part
    struct Issue issue1 = {"do you want to die?", "no", {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}}; 
    struct Issue issue2 = {"do you want to go to library?", "no", {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-"}};
    struct Issue issue_array[10] = {issue1, issue2};
    
    // finding the size of the issue array
    int array_size_of_issue_array = sizeof(issue_array)/sizeof(issue_array[0]);
    int count2 = 0;
    for(int b = 0; b < array_size_of_issue_array; b++){
        if (strcmp(issue_array[b].name, "")){
            count2++;
        }
    }
    array_size_of_issue_array = count2;
    
    //finding the size of  voter_array
    int array_size_of_voter_array = sizeof(voter_array)/sizeof(voter_array[0]);// finding how many user in voter_array
    int count = 0;
    for(int e = 0; e < array_size_of_voter_array; e++){
        if (strcmp(voter_array[e].username, "")){
            count++;
        }
    }
    array_size_of_voter_array = count;

    reading_data (voter_array, array_size_of_voter_array, issue_array, array_size_of_issue_array);

    writing_data(voter_array, issue_array, array_size_of_voter_array, array_size_of_issue_array);
    

    // main loop
    undone_issue = size_of_done_issues (issue_array, array_size_of_issue_array);

    while (undone_issue > 0) {
        printf("%s \n\n", "*WELLCOME*");

        //asking username and password to login
        pair = login(voter_array, array_size_of_voter_array);
        if (pair.is_exits == 0){
            //login is not correct, go to next user
            continue;
        }


        while(1) {
            
            printf("\n");
            if (pair.index == 0){
                //just for admin user
                printf("%s \n", "IF YOU WANT TO ADD NEW USER TYPE 99");
            }
            printf("%s \n", "IF YOU WANT TO VOTE PRESS 1 ");
            printf("%s \n", "IF YOU WANT TO LOGOUT PRESS 2");   
            printf("%s \n", "IF YOU WANT TO CHANGE YOUR PASSWORD PRESS 3");
            printf("%s \n", "IF YOU WANT TO CHANGE YOUR VOTE PRESS 4"); 
            printf("%s \n", "IF YOU WANT TO ADD NEW ISSUE PRESS 5");

            //*right now if user type char insted of intiger, program crashes*

            scanf("%d", &cont);

            // doing the next 4 line of code because of very complicated things and problems. if you ask me i can say to you
            int v;
                    do{
                        v = getchar();
                    }while(v != EOF && v != '\n');

            switch (cont){
                
                case 1:
                    printing_multiple_issues (issue_array, array_size_of_issue_array);
                    int issue_index;
                    scanf("%d", &issue_index);
                    // asking the users vote
                    is_voted = ask_vote(issue_array, issue_index, pair.index);
                    if (!is_voted) {
                        // user already voted, pass this user 
                        continue;
                    }
                    writing_data(voter_array, issue_array, array_size_of_voter_array, array_size_of_issue_array);

                    //checking majority
                    majority_val = checking_majority(issue_array, issue_index, array_size_of_issue_array, array_size_of_voter_array);
                    undone_issue = size_of_done_issues (issue_array, array_size_of_issue_array);
                    if (majority_val){
                        //there is majotiry exit
                        break;
                    }
                    continue;              
                
                case 2:
                    // user wants to leave
                    printf("%s \n", " USER SIGN OUT");
                    break;
                
                case 3:
                    changing_password(voter_array, pair.index);
                    writing_data(voter_array, issue_array, array_size_of_voter_array, array_size_of_issue_array);
                    continue;
                    //reading_data (voter_array, array_size_of_voter_array);
                
                case 4:
                    printing_multiple_issues (issue_array, array_size_of_issue_array);
                    scanf("%d", &issue_index);
                    changing_vote(issue_array, issue_index, pair.index);
                    writing_data(voter_array, issue_array, array_size_of_voter_array, array_size_of_issue_array);

                    //checking majority
                    majority_val = checking_majority(issue_array, issue_index, array_size_of_issue_array, array_size_of_voter_array);
                    undone_issue = size_of_done_issues (issue_array, array_size_of_issue_array);
                    if (majority_val){
                        //there is majotiry exit
                        break;
                    }
                    continue;
                
                case 5:
                    adding_new_issue(issue_array, array_size_of_issue_array);
                    array_size_of_issue_array++;
                    writing_data(voter_array, issue_array, array_size_of_voter_array, array_size_of_issue_array);
                    continue;
                
                case 99:
                    adding_new_user(voter_array, array_size_of_voter_array);
                    array_size_of_voter_array++;
                    writing_data(voter_array, issue_array, array_size_of_voter_array, array_size_of_issue_array);
                    continue;
            }
            break;
        }
    }

    printf("%s \n\n", "PROGRAM IS ENDED!!");
    remove("ex.txt");      
}