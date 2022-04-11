#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//define includes
#include "auth.h"
struct User user;

struct meal {
    char day[16];
    char student_id[50];
    char food[100];
};

char meals_array[4][40] = {
    "Fry fish, Rice",
    "Beef, Rice",
    "Fish, Sweet, Rice",
    "Beaf Sweet, Rice"
};

char days[7][16] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};

void homemenu();

//save the meal to a file
int save_meal_to_file(char day[16], char food[100]){
    FILE *file;
    file = fopen("Meals.data","a+");
    struct meal selected_meal;
    strcpy(selected_meal.day,day);
    strcpy(selected_meal.food,food);
    strcpy(selected_meal.student_id,user.id);
    fwrite(&selected_meal,sizeof(struct meal),1,file);

    if(fwrite != 0){
        fclose(file);
        return 1;
    }else {
        fclose(file);
        return 2;
    }
}

//register meal
int register_meal(char day[16]){
    int selected_day;
    int file_operation;

    printf("\n\n----------------- %s's menu-----------------------\n\n",day);
    for(int i = 0; i<4; i++){
        printf("%d \t %s \n", i+1, meals_array + i);
    }

    printf("Please enter your choice: ");
    scanf("%d", &selected_day);

    switch (selected_day)
    {
    case 1:
        file_operation = save_meal_to_file(day,meals_array[0]);
        if(file_operation == 1){
            printf("Thanks, your choice \"%s\" has been registered \n", meals_array[0]);
        }else{
            printf("Error writng to file \n");
        }
        break;
    case 2:
        file_operation = save_meal_to_file(day,meals_array[1]);
        if(file_operation == 1){
            printf("Thanks, your choice \"%s\" has been registered \n", meals_array[1]);
        }else{
            printf("Error writng to file \n");
        }
        break;
    case 3:
        file_operation = save_meal_to_file(day,meals_array[2]);
        if(file_operation == 1){
            printf("Thanks, your choice \"%s\" has been registered \n", meals_array[2]);
        }else{
            printf("Error writng to file \n");
        }
        break;
    case 4:
        file_operation = save_meal_to_file(day,meals_array[3]);
        if(file_operation == 1){
            printf("Thanks, your choice \"%s\" has been registered \n", meals_array[3]);
        }else{
            printf("Error writng to file \n");
        }
        break;
    default:
        printf("\nInvalid meal selected \n");
        homemenu();
        break;
    }
}

//student home menu
void homemenu(){
    int selection;
    printf("\n \n --------------------WELCOME %s-------------------------- \n \n",user.id);
    
    for (int i = 0; i<7; i++){
        printf("%d \t %s \n", i+1, days + i);
    }

    printf("Enter selected day: ");
    scanf("%d",&selection);

    switch (selection)
    {
        case 1:
            register_meal(days[0]);
            break;
        case 2:
            register_meal(days[1]);
            break;
        case 3:
            register_meal(days[2]);
            break;
        case 4:
            register_meal(days[3]);
            break;
        case 5:
            register_meal(days[4]);
            break;
        case 6:
            register_meal(days[5]);
            break;
        case 7:
            register_meal(days[6]);
            break;
        default:
            printf("\nInvalid day selected \n");
            homemenu();
            break;
        }

}

//admin functionality
void adminhome(){
    int selection;

    char buffer[32];
    struct tm *ts;
    size_t last;
    time_t timestamp = time(NULL);

    ts = localtime(&timestamp);
    last = strftime(buffer,32, "%A", ts);


    printf("\n \n --------------------WELCOME %s-------------------------- \n \n",user.id);
    printf("Pleas select an option \n");
    printf("1 \t See the submited choices \n");
    printf("2 \t Exit \n");
    printf("Selectin: ");

    scanf("%d",&selection);

    if(selection == 1){
        FILE *fp;
        fp = fopen("Meals.data","r");
        struct meal meals;
        
        printf("\nDisplaying recorded meals for %s \n",buffer);
        printf("\nStudent ID \t Meal \t \n");
        while(fread(&meals, sizeof(struct meal), 1, fp)){
            if(strcmp(meals.day,buffer) == 0){
                printf("%s \t %s \t", meals.student_id, meals.food);
            }
        }
        fclose(fp);
    }else {
        printf("Exiting ....");
    }
}

void login_user(){
    user = login();
    if(user.role == 1){
        homemenu();
    }else if(user.role == 2){
        adminhome();
    }else{
        printf("Invalid user ID or password \n");
        login_user();
    }
}



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