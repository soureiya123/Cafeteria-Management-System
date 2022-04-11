#include <string.h>
#include <conio.h>
#include <windows.h>

#ifndef auth
struct User login();
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
    int role;
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

struct User login(){
   printf("Enter your ID: ");
    scanf("%s",studentnId);
    printf("Enter your password: ");
    scanf("%s",studentPass);
    FILE *fp=fopen(" Students.data","r");
    while(fread(&student,sizeof(struct User),1,fp)){
            if(strcmp(student.id,studentnId) == 0){
                if(strcmp(student.password,studentPass) == 0){
                        return student;
                        break;
                }else{

                    printf("Invalid password \n");
                    Beep(800,300);
                }
            }
    }
    struct User invalid_user;
    invalid_user.role = 0;
    return invalid_user;
}

int signup(){
    struct User *userptr = malloc(sizeof *userptr);
    int user_role = 1;
    printf("Enter your id: ");
    scanf("%s",userptr->id);
    printf("Enter your course: ");
    scanf("%s",userptr->course);
    printf("Enter your password: ");
    scanf("%s",userptr->password);
    printf("Confirm your password: ");
    scanf("%s",finalPasswd);
    if (strcmp(userptr->password,finalPasswd) == 0)
    {
        printf("your password matched \n");
        printf("Select your role \n");
        printf("1 \t Student \n");
        printf("2 \t Admin \n");
        printf("Your selection: ");
        scanf("%d",&user_role);
        if(user_role == 2){
            userptr->role = 2;
        }else{
            userptr->role = 1;
        }
        fp=fopen("Students.data","a+");
        fwrite(userptr,sizeof(struct User),1,fp);

        if(fwrite!=0){
            if(userptr->role == 2){
                printf("Admin registration successfull");
            }else{  
                printf("Student registration successfull");
            }
        }
        else{
            printf(" Sorry, something went wrong");
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