#include <stdio.h>
#include <stdlib.h>

//define includes
#include "auth.h"

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
            login();
            break;
    }
}