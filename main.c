#include <stdio.h>
#include <stdlib.h>

//define includes
#include "auth.h"

//home menu prints
void homemenu(){
    printf("Select from the menu below what you will want to do /n\n You can always press 0 to exit \n\n");
    printf("1: View todays menu \n");
    printf("2: New choice \n");
}

int login();

int main(){
    int choice;

    printf("1:sign up\n");
    printf("2 login\n");
    printf("3:Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    fgetc(stdin);

    switch(choice){
        case 1:
            signup();
            break;
        case 2:
            if(login()){
                int selected;
                while(scanf("%d",&selected) != 0){
                    homemenu();
                }
            }
            break;
    }
}