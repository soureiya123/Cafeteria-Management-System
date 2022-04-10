#include <string.h>
#include <conio.h>
#include <windows.h>

#ifndef auth
int login();
int signup();
void takePassword();
void takeInput();

#define ENTER 13
#define TAB 9
#define BKSPC 8

struct User{

        char id[50];
        char course[50];
        char password[50];
        char role[50];
    };

    struct User user;

int choice;
char finalPasswd[50];
FILE *fp;
char studentnId[50];
char studentPass[50];
struct User student;


void takePassword(char passd[50]) {

         int i;
         char ch;

while(1){


        ch=getch();

        if(ch==ENTER || ch==TAB){
                passd[i]='\0';
                break;

    }else if (ch==BKSPC){
        if(i>0){
        i--;
        printf("\b \b");
        }else{
            passd[i++]=ch;
            printf("+ \b");
            }
     }

}
}

void takInput(char input[50]){
    fgets(input,50,stdin);//fgets stands for file get string. It is included in the C standard library header file stdio
    input[strlen(input)-1]=0;
}

int login(){
   printf("Enter your ID: ");
    scanf("%s",studentnId);
    printf("Enter your password: ");
    scanf("%s",studentPass);
    FILE *fp=fopen(" Students.data","r");
    while(fread(&student,sizeof(struct User),1,fp)){
            if(!strcmp(student.id,studentnId)){
                if(!strcmp(student.password,studentPass)){
                        printf("welcome \n");
                        return 1;
                        break;
                }else{

                    printf("Invalid password \n");
                    Beep(800,300);
                }
            }
    }
    return 0;
}

int signup(){
    struct User *userptr = malloc(sizeof *userptr);
    printf("Enter your id: ");
    scanf("%s",userptr->id);
    printf("Enter your course: ");
    scanf("%s",userptr->course);
    printf("Enter your password: ");
    scanf("%s",userptr->password);
    printf("Confirm your password: ");
    scanf("%s",finalPasswd);
    if (!strcmp(userptr->password,finalPasswd))
    {
        printf("your password matched");
        fp=fopen(" Students.data","a+");
        fwrite(userptr,sizeof(struct User),1,fp);

        if(fwrite!=0){
            printf(" Students registration is succed");
        }
        else{
            printf(" Sorry,so,ething went wrong");
        }
        fclose(fp);
    }
    else{
        printf("your passxord does not matched. Please try again\n");
        Beep(750,300);
        signup();
    }
}

#define auth
#endif