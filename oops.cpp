#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include "driver.h"
#include "driver.cpp"

using namespace std;
/*
class student
{
  protected:
      char name[20];
      int usn=0;
  public:
      void getdetail(void)
      {
    cout<<"\n\nEnter name :- ";
    cin>>name;
    cout<<"\nEnter usn    :- ";
    cin>>usn;
      }
      void dispdetail(void)
      {
    cout<<"\n\nNAME      :- "<<name;
    cout<<"\nUSN         :- "<<usn;
      }
};

class account : virtual public student
{
  protected:
       float cgpa=0;
  public:
       void getcgpa(void)
       {
     cout<<"\nEnter CGPA :- ";
     cin>>cgpa;
       }
       void discgpa(void)
       {
      cout<<"\nCGPA      :- "<<cgpa;
       }
};

class admin : virtual public student
{
  protected:
       int semester=0;
  public:
       void getexpr(void)
       {
      cout<<"\nEnter Semester :- ";
      cin>>semester;
       }
       void dispexpr(void)
       {
      cout<<"\nSEMESTER :- "<<semester;
       }
};

class office : public account, public admin
{
    public:
    void create(void)
    {
       cout<<"\n\n=====GETDATA IN=====\n";
       getdetail();
       getcgpa();
       getexpr();
    }

    void display(void)
    {
    if(usn==0||semester==0||name=='\0')
    {
    cout<<"Please enter details of the student"<<endl;
    }
    else
    {
      cout<<"\n\n=====DISPLAY DETAILS=====\n";
      dispdetail();
      discgpa();
      dispexpr();
    }
    }

    void update(void)
    {
      cout<<"\n\n=====UPDATE DETAILS=====\n";
      cout<<"\nChoose detail you want to update\n";
      cout<<"1)  NAME\n";
      cout<<"2)  USN\n";
      cout<<"3)  SEMESTER\n";
      cout<<"4)  CGPA\n";
      cout<<"Enter your choice:- ";
      int choice;
      cin>>choice;
      if(usn==0||semester==0||name=='\0')
    {
    cout<<"Please enter details of the student"<<endl;
    }
    else
    {
      switch(choice)
      {
        case 1 : cout<<"\n\nEnter name     :- ";
             cin>>name;
             break;
        case 2 : cout<<"\n\nEnter usn      :- ";
             cin>>usn;
             break;
        case 3 : cout<<"\n\nEnter CGPA     :- ";
             cin>>cgpa;
             break;
        case 4 : cout<<"\n\nEnter Semester :- ";
             cin>>semester;
             break;
        default: cout<<"\n\nInvalid choice\n\n";
      }
    }
    };

    int upda()
    {
     FILE *fp, *ft;
    char another, choice;


    struct student
    {
        char first_name[50], last_name[50];
        char course[100];
        int section;
    };

    struct student e;
    char xfirst_name[50], xlast_name[50];
    long int recsize;

    fp=fopen("user.txt","rb+");

    if (fp == NULL)
    {
        fp = fopen("user.txt","wb+");

        if (fp==NULL)
        {
            puts("Cannot open file");
            return 0;
        }
    }


    recsize = sizeof(e);

    while(1)
    {
        system("cls");

        cout << "\n 1. Add    Records";
        cout << "\n 2. List   Records";
        cout << "\n 3. Modify Records";
        cout << "\n 4. Delete Records";
        cout << "\n 5. Exit   Program";
        cout << "\n\n";
        cout << " Select Your Choice :=> ";
        fflush(stdin);
        choice = getche();
        switch(choice)
        {
        case '1' :
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "Enter the Firt Name : ";
                cin >> e.first_name;
                cout << "Enter the Last Name : ";
                cin >> e.last_name;
                cout << "Enter the Course    : ";
                cin >> e.course;
                cout << "Enter the Section   : ";
                cin >> e.section;
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
        case '2':
            system("cls");
            rewind(fp);
            cout << "=== View the Records in the Database ===";
            cout << "\n";
            while (fread(&e,recsize,1,fp) == 1)
            {
                cout << "\n";
                cout <<"\n" << e.first_name << setw(10)  << e.last_name;
                cout << "\n";
                cout <<"\n" <<e.course <<  setw(8)  << e.section;
            }
            cout << "\n\n";
            system("pause");
            break;

        case '3' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the student : ";
                cin >> xlast_name;

                rewind(fp);
                while (fread(&e,recsize,1,fp) == 1)
                {
                    if (strcmp(e.last_name,xlast_name) == 0)
                    {
                        cout << "Enter new the Firt Name : ";
                        cin >> e.first_name;
                        cout << "Enter new the Last Name : ";
                        cin >> e.last_name;
                        cout << "Enter new the Course    : ";
                        cin >> e.course;
                        cout << "Enter new the Section   : ";
                        cin >> e.section;
                        fseek(fp, - recsize, SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                    else
                        cout<<"record not found";
                }
                cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;


        case '4':
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the student to delete : ";
                cin >> xlast_name;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while (fread (&e, recsize,1,fp) == 1)

                    if (strcmp(e.last_name,xlast_name) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("user .txt");
                rename("temp.dat","user.txt");

                fp=fopen("user.txt","rb+");

                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }

            break;

       case '5':
            fclose(fp);
            cout << "\n\n";
            exit(0);
        }
    }


    system("pause");
    }
};

*/
int main()
{
    office ob1;
    int choice;
    while(1)
    {

       cout<<"\nChoose Operation you want to perform\n";
       cout<<"1)  Create  Record\n";
       cout<<"2)  Display Record\n";
       cout<<"3)  Update  Record\n";
       cout<<"4)  Database\n";
       cout<<"5)  Exit\n";
       cout<<"\nEnter your choice:- ";
       cin>>choice;
       switch(choice)
       {
         case 1 : ob1.create();
              break;
         case 2 : ob1.display();
              break;
         case 3 : ob1.update();
              break;
         case 4 : ob1.upda();
         break;
        default : cout<<"\n\nInvalid Choice\nTry Again\n\n";
       }
    }
    return 0;
}

