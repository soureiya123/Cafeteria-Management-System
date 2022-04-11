#include <stdio.h>
#include <stdlib.h>

//define includes
#include "auth.h"

//home menu prints
void homemenu(){
    int selection;
    printf("\n \n --------------------WELCOME-------------------------- \n \n");
    printf("Select a day from below \n");
    printf("1 \t Monday \n");
    printf("2 \t Tuesday \n");
    printf("3 \t Wednesday \n");
    printf("4 \t Thursday \n");
    printf("5 \t Friday \n");
    printf("6 \t Saturday \n");
    printf("7 \t Sunday \n");

    printf("Enter selected day: ");
    scanf("%d",&selection);

    switch (selection)
    {
        case 1:
            printf("you have selected monday");
            break;
        case 2:
            printf("you have selected Tuesday");
            break;
        case 3:
            printf("you have selected Wednesday");
            break;
        case 4:
            printf("you have selected Thursday");
            break;
        case 5:
            printf("you have selected Friday");
            break;
        case 6:
            printf("you have selected Saturday");
            break;
        case 7:
            printf("you have selected Sunday");
            break;
        default:
            printf("Invalid day selected");
            break;
        }

}

void login_user(){
    int loginr = 0;
    loginr = login();
    if(loginr == 1){
        homemenu();
    }else if(loginr == 2){
        printf("Admin interface \n");
    }else{
        login_user();
    }
}

int login();

int main(){
    int choice;

    printf("1:sign up\n");
    printf("2 login\n");
    printf("3:Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    fgetc(stdin);

    switch(choice){
        case 1:
            signup();
            break;
        case 2:
            login_user();
            break;
        default:
            printf("Exiting ........");
            return 1;
    }
}