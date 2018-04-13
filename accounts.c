#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "accounts.h"


void account_run()
{
    char password1[16],user_name1[50];

    int found=0,close=0,create_choice=0,logch,correct=0;
    FILE *user_name_read=fopen("user_name_data.txt","r");

    do{

    printf("Enter your choice 1.login 2.sign up 3.forgot password");
    scanf("%d",&logch);

    if(logch==2)
    {
        FILE *user_name_write=fopen("user_name_data.txt","a");
            printf("Please enter your new user name");
            scanf("%s",user_name1);
            printf("Please enter your new password");
            scanf("%s",password1);
            fprintf(user_name_write,"%s %s\n",user_name1,password1);
            printf("Written successfully");
            fclose(user_name_write);
    }


    printf("Please enter your username");
    scanf("%s",user_name1);

        fseek(user_name_read,0,SEEK_END);
        int len=(int)ftell(user_name_read);

        if(len<=0)
	{printf("File Empty");}else{
	    rewind(user_name_read);
    while(fscanf(user_name_read,"%s %s\n",obj_a.user_name,obj_a.password))
    {
        printf("%s",obj_a.user_name);
    if(!strcmp(user_name1,obj_a.user_name))
        {
            printf("username found");
            found=1;
            break;
        }
    if(feof(user_name_read))
	{
	break;
	}

    }

    if(!found)
    {
        printf("Username not found.Do you want to create a new account?1.create 2.retry");
        scanf("%d",&create_choice);
        if(create_choice==1)
        {
            FILE *user_name_write=fopen("user_name_data.txt","a");
            printf("Please enter your new user name");
            scanf("%s",user_name1);
            printf("Please enter your new password");
            scanf("%s",password1);
            fprintf(user_name_write,"%s %s\n",user_name1,password1);
        }
    }
    if(found)
    {
        while(1){
        printf("Please Enter your password");
        scanf("%s",password1);

        if(!strcmp(obj_a.password,password1))
        {
            strcpy(authorised_un,obj_a.user_name);
            printf("Welcome to your account.We missed you.....");
            correct=1;
        break;
        }
        else{printf("Sorry wrong password");}


        }
        if(correct)
        {
            break;
        }
    }

	}

    }while(close!=1);
    fclose(user_name_read);
}
