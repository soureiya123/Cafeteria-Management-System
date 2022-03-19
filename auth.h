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

struct user{

        char id[50];
        char course[50];
        char password[50];
        char role[50]
    } user;

int choice;
int finalPasswd;
FILE *fp;
char studentnId[50];
char studentPass[50];
struct user student;


void takPassword(char passd[50]) {

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
    fgets(input,50,stdin);//fgets stands for file get string. It is included in the C standard library header file stdio
    input[strlen(input)-1]=0;
}

int login(){
   printf("Enter your ID");
    takInput(studentnId);
    printf("Enter your password");
    takInput(studentPass);
    fp=fopen(" Students.data","r");
    while(fread(&student,sizeof(struct user),1,fp)){
            if(!strcmp(student.id,studentnId)){
                if(!strcmp(student.password,studentPass)){

                        printf("welcome");
                }else{

                    printf("Invalid password");
                    Beep(800,300);
                }
            }
    }
}

int signup(){
    printf("Enter your id: \t");
    takInput(user.id);
    printf("Enter your course: \t");
    takInput(user.course);
    printf("Enter your password: \t");
    takPassword(user.password);
    printf("Confirm your password: \t");
    takPassword(finalPasswd);
    printf("Enter your password: \t");
    scanf("%c",&finalPasswd);
    if (!strcmp(user.password,finalPasswd))
    {
        printf("your password matched");
        fp=fopen(" Students.data","a+");
        fwrite(&user,sizeof(struct user),1,fp);

        if(fwrite!=0)
            printf(" Students registration is succed");
        else
        printf(" Sorry,so,ething went wrong");
    }
    else{


        printf("your passxord does not matched");
        Beep(750,300);

    }
}

#define auth
#endif