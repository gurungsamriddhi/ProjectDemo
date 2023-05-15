#include <stdio.h>   // standard input output header file
#include <conio.h>   // to use function such as getch and clrscr
#include <string.h>  // to use string function such as strcmp , strcpy, etc ..
#include <unistd.h>  // to use sleep function
#include <windows.h> // to make placement function
// completing within two days
// start coding from may 15.
#define MAX_USERS 50 // max user of our program will be 50.
typedef struct Info
{
    char name[30];
    char password[30];
} Information;

// declaring functions
void authentication_page();
void login();
void sign_up();
void exit_program();
void display_message();
void placementxy(int x, int y); // this function might get replaced later
int x, y;
FILE *ptr;

int main(int argc, char const *argv[])
{
    authentication_page();

    return 0;
}
void placementxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void authentication_page()
{
    system("cls");
    int choose_option;
    printf("Typing Speed Tracker\n");
    printf("1.\tLogin\n");
    printf("2.\tSignUp\n");
    printf("3.\tExit\n");
    printf("Choose Option");
    scanf("%d", &choose_option);
    switch (choose_option)
    {
    case 1:

        login();
        // printf("login page ");
        break;
    case 2:
        sign_up();
        // printf("signup page");
        break;
    case 3:
        exit_program();
        // printf("exit");

        break;
    default:
        printf("wrong input");
        getch();
       system("cls");
authentication_page();
        break;
    }
}
void sign_up()
{
    system("cls");
    Information i;
    ptr = fopen("authentication.txt", "ab"); // opening file in binary mode
    printf("SignUp\n");
    printf("Name :");
    scanf(" %[^\n]", i.name);
    fflush(stdin);
    printf("Password :");
    scanf(" %[^\n]", i.password);
    if (ptr == NULL)
    {
        printf("Unable to open file ");
    }
    else
    {
        fwrite(&i, sizeof(Information), 1, ptr); // writing into file in binary mode
        printf("\n Signed Up Sucessfully !!");
        getch();
        fclose(ptr);
    }
    authentication_page();
}

void login()
{
    system("cls");

    // Open the authentication file in binary read mode
    ptr = fopen("authentication.txt", "rb");

    Information i;
    char enter_name[30];
    char enter_pass[30];

    printf("Login\n");
    printf("Name: ");
    scanf(" %[^\n]", enter_name);
    fflush(stdin);
    printf("Password: ");
    scanf(" %[^\n]", enter_pass);

    // Read each struct from the file and compare the entered name and password
    while (fread(&i, sizeof(Information), 1, ptr))
    {
        // Check if the entered name and password match with the current struct
        if (strcmp(enter_name, i.name) == 0 && strcmp(enter_pass, i.password) == 0)
        {
            printf("Login Successful!\n");
            fclose(ptr); // Close the file
            return;      // Exit the function
        }
    }

    // If no match is found, print login failure message
    printf("Login Failed!\n");
    fclose(ptr); // Close the file
}
void exit_program()
{
    exit(1); // exit the program //
}
void display_message()
{
    printf("You entered Wrong Password for many times !! \n You might not have Signed Up your account Try signning up \n Press any key__ ");
    getch();
    authentication_page();
}
