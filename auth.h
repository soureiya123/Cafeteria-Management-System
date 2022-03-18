#include <string.h>
#include <conio.h>

#ifndef auth
int login();
char getPassword();

int login(){
    FILE *file;
    char username[25];  //assuming user names wont be two long
    // char password[25]; //same assumption
    file = fopen("login.txt","w");

    if (file == NULL){
        printf("There was an error opeining file");
    }

    printf("Enter your username: ");
    scanf("%s",username);
    printf("Enter your password: ");
    getPassword();
    printf("\n\n");
    printf("you entered");
    
}

char getPassword(){
    char password[25];
    int index = 0;
    do {
        password[index] = getch();
        if(password[index] != '\r'){
            printf("*");
        }
        index++;
    }while(password[index-1] != '\r');
    printf("%s",password);
}

#define auth
#endif