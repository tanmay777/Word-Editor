#include<iostream>
#include<conio.h>
#include<string.h>
#include<iomanip>//for setw
#include<windows.h>//for sleep
#include<stdio.h>//for gotoxy

using namespace std;
struct line{
    struct line *prev,*next;
    char arr[80];
}*start,*newptr,*save,*ptr,*rear,*curr,*temp,*paste_line;

COORD coord={0,0}; // this is global variable
                  //center of axis is set to the top left corner of the screen
void gotoxy(int x,int y)
{
 coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void intro();
void input_data(int);
void lin();
line* createnewline(char[]);
void add(line*);
void del(int);
void copy_paste(int,int,int);
void cut_paste(int,int,int);
void display();
void rev();
void exit();

int main()
{   int l;
    intro();
    start=NULL;
    rear=NULL;
    int a,c,p,d;
    int k=1;
    while(k!=0)
        {
            cout<<"\n\n\n";
            lin();
            cout<<"\n\n";
            cout<<setw(43)<<"Main Menu"<<endl;
            cout<<endl;
            cout<<setw(47)<<"1.Input Data"<<endl<<endl;
            cout<<setw(52)<<"2.Copy and Paste."<<endl<<endl;
            cout<<setw(43)<<"3.Delete"<<endl<<endl;
            cout<<setw(50)<<"4.Cut and Paste"<<endl<<endl;
            cout<<setw(44)<<"5.Display"<<endl<<endl;
            cout<<setw(52)<<"6.Reverse Display"<<endl<<endl;
            cout<<setw(41)<<"0.Exit"<<endl<<endl;
            cout<<"\n\n";
            lin();
            cout<<endl;
            cout<<"Enter your choice : ";
            cin>>k;
            switch(k)
            {
                case 1:{
                    cout<<"Enter the no. of line: ";
                    cin>>l;
                    input_data(l);
                    break;
                }
                case 2:{
                    cout<<"Enter the line you want to copy ?";
                    cin>>c;
                    cout<<"\nAfter which line you want to paste";
                    cin>>p;
                    copy_paste(c,p,l);
                    l++;// To increment the length of the line which is using in copy paste logic.
                    break;
                       }
                case 3:{
                    cout<<"Enter the line,you want to delete?\n";
                    cin>>d;
                    del(d);
                    break;
                       }
                case 4:{
                    cout<<"Enter the line you want to cut?";
                    cin>>c;
                    cout<<"\nAfter which line you want to paste";
                    cin>>p;
                    cut_paste(c,p,l);
                    break;
                        }

                case 5: {
                        display();
                        cout<<endl;
                        break;
                        }
                case 6: {
                    rev();
                    cout<<endl;
                    break;
                }
                case 0: {
                        exit();
                        k=0;
                        break;
                        }
                default: cout<<"Enter valid input\n";
           }
        }
return 0;
}

void intro()
{
int e=0,f=0;
char pwd[20];
system("cls");
cout<<"\n\n\n\n\n";
lin();
cout<<"\n\n";
cout<<setw(43)<<"Welcome"<<endl;
cout<<setw(45)<<"DSA Project"<<endl;
cout<<"\n\n";
lin();
cout<<endl<<endl;
cout<<"Please enter the password : ";

while(e<3)
{
cin>>pwd;
if(strcmp(pwd,"tanmay22")==0)
f++;
if(strcmp(pwd,"kartik96")==0)
f++;
if(f)
{
system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<setw(50)<<"LOADING YOUR PROJECT"<<endl;
cout<<setw(50)<<"PLEASE WAIT.........";
Sleep(500);
gotoxy(1,20);
cout<<"10 % completed..";
Sleep(500);
gotoxy(1,20);
cout<<"20 % completed...";
Sleep(500);
gotoxy(1,20);
cout<<"30 % completed....";
Sleep(500);
gotoxy(1,20);
cout<<"40 % completed.....";
Sleep(500);
gotoxy(1,20);
cout<<"50 % completed......";
Sleep(500);
gotoxy(1,20);
cout<<"60 % completed.......";
Sleep(500);
gotoxy(1,20);
cout<<"70 % completed........";
Sleep(500);
gotoxy(1,20);
cout<<"80 % completed.........";
Sleep(500);
gotoxy(1,20);
cout<<"90 % completed..........";
Sleep(500);
gotoxy(1,20);
cout<<"100 % completed...........";
Sleep(800);
break;
}
else if(e==1)
{
cout<<endl;
cout<<"Incorrect password.(Last attemp) Enter again: ";
e++;
}
else if(e==2)
{
exit(0);
}
else
{
e++;
cout<<endl;
cout<<"Incorrect password. Enter again: ";
}
}
system("cls");
}

void input_data(int k)
{
    cout<<"Enter the data:\n";
    int i=0;
    char arr[80];
    while(i!=k)
    {
        cin.getline(arr,80,'.');
        newptr=createnewline(arr);
        add(newptr);
        i++;
    }
}

line* createnewline(char arr[])
{
    ptr=new line;
    ptr->prev=NULL;
    ptr->next=NULL;
    strcpy(ptr->arr,arr);
    return ptr;
}

void add(line* n)
{
    if(start==NULL)
    {
        start=n;   //Will the start will be declared here work or not?
        rear=n; //Will the start will be declared here work or not?
    }
    else
    {
        rear->next=n;
        n->prev=rear;
        rear=n;
    }
}

void copy_paste(int c,int p,int l)
{
    struct line *curr_c=start; //storing the value curr for copy.
    int i=0;
    while(i!=c-1)
    {
        curr_c=curr_c->next;
        i++;
    }
    struct line *curr_l=start; //after curr_l , curr_c will be pasted.
    i=0;
    while(i!=p-1)
    {
        curr_l=curr_l->next;
        i++;
    }

  if(p==l)
  {
      paste_line=createnewline(curr_c->arr);
      paste_line->next=curr_l->next;
      paste_line->prev=curr_l;
      curr_l->next=paste_line;
      rear=paste_line;
  }

  if(p!=l)
  {

      paste_line=createnewline(curr_c->arr);
      temp=curr_l->next;
      paste_line->next=curr_l->next;
      paste_line->prev=curr_l;
      curr_l->next=paste_line;
      temp->prev=paste_line;
  }

}

void del(int d)
{

    struct line *curr_d=start; //storing the value curr for copy.
    int i=1;


    if(d==1)
    {
      temp=start ;
      start=temp->next;
      delete(temp);

    }
    else
        {
            while(i!=d)
    {
        curr_d=curr_d->next;
        i++;
    }


        if(curr_d->next==NULL)
    {
        temp=curr_d;
        temp->prev->next=NULL;
        delete(temp);

    }
    else

    {
        curr_d->prev->next=curr_d->next;
    curr_d->next->prev=curr_d->prev;
}
}
}

void cut_paste(int c,int p,int k)
{
    struct line *curr_c=start; //storing the value curr for copy.
    int i=0;
    while(i!=c-1)
    {
        curr_c=curr_c->next;
        i++;
    }
    struct line *pt;
    pt=curr_c;

    curr_c->prev->next=curr_c->next; // CUTTING THE LIST
    curr_c->next->prev=curr_c->prev;
    struct line *curr_l=start; //after curr_l , curr_c will be pasted.
    i=1;
    while(i!=p-1)
    {
        curr_l=curr_l->next;
        i++;
    }
if (curr_l->next == NULL)
    {
        curr_l->next = pt;
        pt->next = NULL;
        pt->prev = curr_l;
    }
    else
    {
        temp=curr_l->next;
        curr_l->next=pt;
        pt->prev=curr_l;
        pt->next=temp;
        pt=temp->prev;

    }
}


void display()
{
    curr=start;
    while(curr!=NULL)
    {
        cout<<curr->arr;
        curr=curr->next;
    cout<<".";
    }
}

void lin()
{

    cout<<"________________________________________________________________________________";
}

void rev()
{
    curr=rear;
    while(curr!=NULL)
    {
        cout<<curr->arr;
        curr=curr->prev;
        cout<<".";
}
}

void exit()
{
cout<<"\n\n\n\n";
lin();
cout<<"\n\n";
cout<<setw(44)<<"Thank you"<<endl;
cout<<setw(43)<<"Made by"<<endl;
cout<<setw(51)<<"Tanmay Jha(15BCE0618)"<<endl;
cout<<setw(54)<<"Kartik Sharma(15BCE0721)"<<endl;
cout<<"\n\n";
lin();
cout<<endl;
cout<<endl;
system("pause");
}


