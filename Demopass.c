// making a authentication login system
//Demo of suthentication system
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>
#include<windows.h>
void signup();
void login();
void main_menu(int choose_option);
int main()
{
  int choose_option;
  main_menu(choose_option); 
   return 0; 
} 
void main_menu(int choose_option){
printf("\n\t\t\t\t\t************Demo Password Authentication Login System************\t\t\t\n");
     printf("\t\t\t\t______________________________________________________________________________\t\n");
     printf("\n\t\t\t\t\t1.\tLogin\n\n");
     printf("\n\t\t\t\t\t2.\tSign Up\n\n");
     printf("\n\t\t\t\t\t3.\tExit\n\n");
     printf("\t\t\t\t\tEnter 1/2/3 for Following Operation : ");
     scanf("%d",& choose_option);        
     switch (choose_option)
     {
     case 1:
       system("cls");
       login();
        sleep(2);
        system("cls");
		main_menu(choose_option);
      system("cls");   
        break;
        case 2:
          system("cls");    
        signup();
        sleep(2);
        system("cls");
		main_menu(choose_option);  
        system("cls");
        break;
        case 3: 
          system("cls");      
        exit(0);
        break;     
     default:
         printf("\n\t\t\t\t\tInvalid Input !!!");
         getch();
           system("cls");
         
         main_menu(choose_option);
         
        break;
     }	
}
void signup(){

      FILE *fptr;
      char enter_email[30];
      char enter_password[30]; // variable to store password entered by user
printf("\n\t\t\t\t\t**************Sign Up Your Account**************\t\t\t\n");
  printf("\t\t\t\t______________________________________________________________________________\t\n");
    printf("\n\t\t\t\t\tEnter your name:");
      scanf(" %[^\n]",enter_email);
      printf("\n\t\t\t\t\tEnter your password:");
      scanf(" %[^\n]",enter_password);
      fptr=fopen("p_save.txt","w");
      if (fptr==NULL)
      {
        printf("Error while saving password");
      }
      else
      {
         fprintf(fptr,"%s\n%s",enter_email,enter_password);
               printf("\n\n\t\t\t\tSigned Up Sucessfully !!\n");
                fclose(fptr);
      }  
}
void login(){
    
    FILE *ptr;
   char check_email[30];
   char check_password[30];
   char email_check[30];
   char pass_check[30];
  
    printf("\n\t\t\t\t\t************** Login Your Information**************\t\t\t\n");
      printf("\t\t\t\t______________________________________________________________________________\t\n");
    printf("\n\t\t\t\t\tEnter Your name : ");
    scanf(" %[^\n]",check_email);
    printf("\n");
    printf("\t\t\t\t\tEnter Your password : ");
    scanf(" %[^\n]",check_password);
    ptr=fopen("p_save.txt","r");
    fscanf(ptr," %[^\n] %[^\n]",email_check,pass_check);
    // printf("%s",email_check);
    // printf("%s",pass_check); // checking only
    int compare_a=strcmp(check_email,email_check);
    int compare_b=strcmp(check_password,pass_check);
    if (compare_a==0 && compare_b==0)
    {
        printf("\n\n\t\t\t\tLogin Sucessfully !!!");
    }
    else
    {

          
          printf("\n\n\t\t\t\tNo account  has been signed Up you must sign up  !!");
           printf("\n\n\t\t\t\tpress any key to continue ....  !!");
           getch();               
        fclose(ptr);
        
    } 
     
}



