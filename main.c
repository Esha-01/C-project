#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void gotoxy(int, int);
void menu();
void addTeacher();
void addStudent();
void view();
void search();
void modify();
void deleterec();
void viewTeacher();

struct student
{
    char name[20];
    char mobile[10];
    int rollno;
    char course[20];
    char branch[20];
    int marks;
    double cgpa;
    double percentage;
};

struct teacher
{
    char name[20];
    char mobile[10];
    int teacherID;
    char subjectName[20];
    int subjectID;
};

int main()
{
    gotoxy(15, 8);
    printf("<--:Student Record Management System:-->");
    gotoxy(19, 15);
    printf("Press any key to continue.");
    getch();
    menu();
    return 0;
}

// Create the menu of the program
void menu()
{
    int choice;
    system("cls");
    gotoxy(10, 3);
    printf("<--:MENU:-->");
    gotoxy(10, 5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10, 7);
    printf("1 : Admin Settings");
    gotoxy(10, 8);
    printf("2 : Teacher");
    gotoxy(10, 9);
    printf("3 : Student");
    // gotoxy(10, 10);
    // printf("4 : Modify Record.");
    // gotoxy(10, 11);
    // printf("5 : Delete.");
    gotoxy(10, 10);
    printf("4 : Exit.");
    gotoxy(10, 15);
    printf("Enter your choice.");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\n\nSub Menu:\n1. Add teacher\n2. View Teacher\n\nEnter option: ");
        int subopt;
        scanf("%d", &subopt);
        switch (subopt)
        {
        case 1:
            addTeacher();
            break;
        case 2:
            //addStudent();
            viewTeacher();
            break;
        default:
            printf("\n\nInvalid choice");
            break;
        }
        break;
    case 3:
        printf("\n\nSub Menu:\n1. View Result \n2. Search\n\nEnter option: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            view();
            break;
        case 2:
            search();
        default:
            gotoxy(10, 17);
            printf("Invalid Choice.");
        }
        break;
    case 4:
        exit(1);
        break;
    default:
        printf("\n\nInvalid choice");
        break;
    }
}

void view()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,5);
    printf("S.No   Name of Student       Mobile No   Roll No  Course      Branch");
    gotoxy(10,6);
    printf("--------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,j);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxy(10,j);
        printf("%-7d%-22s%-12s%-9d%-12s%-12s",i,std.name,std.mobile,std.rollno,std.course,std.branch);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct student std;
    char stname[20];
    system("cls");
    gotoxy(10,3);
    printf("<--:SEARCH RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of student : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname,std.name) == 0  ){
            gotoxy(10,8);
            printf("Name : %s",std.name);
            gotoxy(10,9);
            printf("Mobile Number : %s",std.mobile);
            gotoxy(10,10);
            printf("Roll No : %d",std.rollno);
            gotoxy(10,11);
            printf("Course : %s",std.course);
            gotoxy(10,12);
            printf("Branch : %s",std.branch);
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}


void addTeacher()
{
    FILE *fp;
    struct teacher tcd;
    char another = 'y';
    system("cls");

    fp = fopen("teach.txt", "ab+");
    if (fp == NULL)
    {
        gotoxy(10, 5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while (another == 'y')
    {
        gotoxy(10, 3);
        printf("<--:ADD RECORD:-->");
        gotoxy(10, 5);
        printf("Enter details of teacher.");
        gotoxy(10, 7);
        printf("Enter Teacher Name : ");
        //        gets(std.name);///???
        gets(tcd.name);
        gotoxy(10, 8);
        printf("Enter Mobile Number : ");
        gets(tcd.mobile);
        gotoxy(10, 9);
        printf("Enter Teacher ID : ");
        scanf("%d", &tcd.teacherID);
        fflush(stdin);
        gotoxy(10, 10);
        printf("Enter subject Name of the teacher : ");
        //        gets(std.course);///???
        gets(tcd.subjectName);
        gotoxy(10, 11);
        printf("Enter Subject ID of the teacher : ");
        scanf("%d", &tcd.subjectID);
        //        gotoxy(10,12);
        //        printf("Enter Father's Name : ");
        //        gets(std.fathername);
        fwrite(&tcd, sizeof(tcd), 1, fp);
        gotoxy(10, 15);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        //        another = getch();///???
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10, 18);
    printf("Press any key to continue.");
    getch();
    menu();
}

void addStudent()
{
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD RECORD:-->");
        gotoxy(10,5);
        printf("Enter details of student.");
        gotoxy(10,7);
        printf("Enter Name : ");
//        gets(std.name);///???
        gets(std.name);
        gotoxy(10,8);
        printf("Enter Mobile Number : ");
        gets(std.mobile);
        gotoxy(10,9);
        printf("Enter Roll No : ");
        scanf("%d",&std.rollno);
        fflush(stdin);
        gotoxy(10,10);
        printf("Enter Course : ");
//        gets(std.course);///???
        gets(std.course);
        gotoxy(10,11);
        printf("Enter Branch : ");
        gets(std.branch);
//        gotoxy(10,12);
//        printf("Enter Father's Name : ");
//        gets(std.fathername);
        fwrite(&std,sizeof(std),1,fp);
        gotoxy(10,15);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
//        another = getch();///???
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}

void viewTeacher(){
     FILE *fp;
    int i=1,j;
    struct teacher tcd;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,5);
    printf("S.No   Name of Teacher   Mobile No   TeacherID   SubjectName     SubjectID");
    gotoxy(10,6);
    printf("--------------------------------------------------------------------");
    fp = fopen("teach.txt","rb+");
    if(fp == NULL){
        gotoxy(10,j);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&tcd,sizeof(tcd),1,fp) == 1){
        gotoxy(10,j);
        printf("%-7d%-22s%-12s%-9d%-12s%-12s",i,tcd.name,tcd.mobile,tcd.teacherID,tcd.subjectName,tcd.subjectID);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}

// Function to hold the cursor in the screen coordinate x and y
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}