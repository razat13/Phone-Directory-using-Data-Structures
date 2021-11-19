#include<iostream>
#include<fstream>
#include<conio.h>
#include <string>
#include <windows.h>
using namespace std;
fstream myfile;
struct clients
{
string name;
string number;
string aadhaar;
clients*link;
 clients()
 {
 link=NULL;
 }
};
class directory
{
clients *start,*cur,*temp;
public:

directory()
{
 start=NULL;
}
creat_file (string n,string num,string aadhaarno)
{
 if(start==NULL)
 {
 start=new clients;
 start->link=NULL;
 start->name=n;
 start->number=num;
 start->aadhaar=aadhaarno;
 myfile.open ("directory.txt",ios::out | ios::app);
myfile<<"--------Contact-------"<<"Name_:_"<<start->name<<"__|__Aadhaar No:_"<<start->aadhaar<<"__|__Phone Number_:_"<<start->number<<endl;
myfile.close();
 }
 else
 {
 cur=start;
 while(cur->link!=NULL)
 {
 cur=cur->link;
 }
 temp=new clients;
 temp->name=n;
temp->number=num;
 temp->aadhaar=aadhaarno;
 temp->link=NULL;
 cur->link=temp;
 myfile.open ("directory.txt",ios::out | ios::app);
 myfile<<"--------Contact-------"<<"Name_:_"<<temp->name<<"__|__Aadhaar No: _"<<temp->aadhaar<<"__|__Phone Number:_"<<temp->number<<endl;
myfile.close();
 }
 }
void terminating_file(string n)
 {
 cur=start;
 if(start->name==n)
 {
 temp=start;
 start=start->link;
 delete temp;
 }
 else
 {
 while(cur->name!=n)
 {
 if(cur->link==NULL)
 {
 	cout<<"Any case of"<<n<<" does not exist"<<endl;
 return ;
 }
 temp=cur;
 cur=cur->link;
 }
 temp->link=cur->link;
 delete cur;
 }

}
 void print_now()
 {
 cur=start;
 int c;
 cout<<"Person #"<<" ---> Name \tNumber \tAadhaar"<<endl;
 for(c=1;cur->link!=NULL;c++)
 {
 	cout<<"Person "<<c<<" ---> "<<cur->name<<"\t"<<cur->number<<"\t"<<cur->aadhaar<<endl;
 cur=cur->link;
 }
 cout<<"Person "<<c<<" ---> "<<cur->name<<"\t"<<cur->number<<"\t"<<cur->aadhaar<<endl;
}
void update(string n)
{
cur=start;
while(cur!=NULL)
{
if(cur->name==n)
{
char mod;
cout<<"\n\t_________DATA FOUND__________\n\n";
cout<<"Name : "<<cur->name<<endl;
cout<<"Aadhaar : "<<cur->aadhaar<<endl;
cout<<"Phone # : "<<cur->number<<endl;
cout<<"\nDo You want to modify Phone Number (y/n) : ";
cin>>mod;
if(mod=='y' || mod=='Y')
{
cout<<"Enter New Phone Number ";
cin>>cur->number;
cout<<"\n\t_________Data Updated________"<<endl;
}
break;
}
cur=cur->link;
}
if(cur==NULL)
cout<<"\n\t_______DATA NOT FOUND_________\n\n";
}

void search(string n)
{
cur=start;
while(cur!=NULL)
{
if(cur->name==n)
{
cout<<"\n\t_________DATA FOUND__________\n\n";
cout<<"Name : "<<cur->name<<endl;
cout<<"Aadhaar : "<<cur->aadhaar<<endl;
cout<<"Phone # : "<<cur->number<<endl;
}
cur=cur->link;
}
}
void searchbyletter(char n)
{
cur=start;
while(cur!=NULL)
{
if(cur->name[0]==n)
{
cout<<"\n\t_________DATA FOUND__________\n\n";
cout<<"Name : "<<cur->name<<endl;
cout<<"Aadhaar : "<<cur->aadhaar<<endl;
cout<<"Phone # : "<<cur->number<<endl;
}
cur=cur->link;
}
}
void searchbynumber(char n)
{
cur=start;
while(cur!=NULL)
{
if(cur->number[0]==n)
{
cout<<"\n\t_________DATA FOUND__________\n\n";
cout<<"Name : "<<cur->name<<endl;
cout<<"Aadhaar : "<<cur->aadhaar<<endl;
cout<<"Phone # : "<<cur->number<<endl;
}
cur=cur->link;
}
}


void print()
{
char s;
myfile.open("directory.txt",ios::in);
while(!myfile.eof())
{
myfile>>s;
cout<<s;
}
myfile.close();
}
};
int main()
{
directory l1;
system("color F0");
CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = 0;
cfi.dwFontSize.Y = 19;
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
std::wcscpy(cfi.FaceName, L"Consolas");
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
int nooffiles,i,p,ch;
string n,nm,aadhaar;
cout<<"\t\t\t PHONE DIRECTORY SYSTEM\n";
cout<<"\n\tFOLLOWING ARE SOME OF THE FUNCTIONS YOU CAN USE IN THIS DIRECTORY SYSTEM\n\n";
cout<<"\n\t1- SAVE NUMBERS\n";
cout<<"\n\t2- CAN SEARCH A NUMBER\n";
cout<<"\n\t3- CAN DELETE A NUMBER\n";
cout<<"\n\t4-CAN SEE ALL THE LIST ANY TIME\n";
cout<<"\n\t5-CAN UPDATE A NUMBER\n";
cout<<"\n\t6-CAN SEARCH BY STARTING LETTER\n";
cout<<"\n\t7-CAN SEARCH BY STARTING NUMBER\n";
cout<<"\n\tFIRST YOU HAVE TO SAVE SOME NUMBERS\n"<<endl;
cout<<"\tHow many numbers you want to save?\n\t";
cin>>nooffiles;
for(i=1;i<=nooffiles;i++)
{
 cout<<"\n\tEnter Name \t";
 cin>>n;
 cout<<"\n\tEnter Phone number \t";
 cin>>nm;
 cout<<"\n\tEnter Aadhaar No.\t";
 cin>>aadhaar;
 l1.creat_file(n,nm,aadhaar);
 }
system("CLS");
do
{
cout<<"\n\nWhat You want to do with your cases now"<<endl;
cout<<"\n1-Save new phone number\n";
cout<<"2-Delete any number"<<endl;
cout<<"3-Search"<<endl;
cout<<"4-See All list"<<endl;
cout<<"5-Update a number."<<endl;
cout<<"6-Search by starting letter"<<endl;
cout<<"7-Search by starting number"<<endl;
cout<<"8-Exit"<<endl;
cin>>ch;
system("CLS");
switch(ch)
{
 case 1:
 cout<<"\n\t============================SAVE NEW  NUMBER============================\n\n";
 cout<<"Enter Data to insert new person's data'"<<endl;
 cout<<"\nEnter Name \t";
 cin>>n;
 cout<<"\nEnter Phone number \t";
 cin>>nm;
 cout<<"Enter Aadhaar \t";
 cin>>aadhaar;
 l1.creat_file(n,nm,aadhaar);
 cout<<"Number of "<<n<<" has been Saved in your phone directory "<<endl;
 break;
 case 2:
 cout<<"\n\t=========================DELETE NUMBER============================\n\n";
 cout<<"\nEnter name of person whose number you want to delete\n"<<endl;
 cin>>n;
 l1.terminating_file(n);
 cout<<"\nNumber of "<<n<<" Has been removed from your list"<<endl;
 break;
 case 3:
 cout<<"\n\t=====================SEARCH AND UPDATE NUMBER=====================\n\n";
 cout<<"Enter NAME of Person to search it from list\t";
 cin>>n;
 l1.search(n);
 break;
case 4:
cout<<"\n\t=====================PRINTING ALL LIST============================\n\n";
 l1.print();
 break;
 case 5:
   cout<<"\n\t=====================UPDATE ANY NUMBER============================\n\n";
   cout<<"\nEnter NAME of the person to update\t";
   cin>>n;
   l1.update(n);
 break;
 case 6:
   cout<<"\n\t=====================SEARCH BY LETTER============================\n\n";
   cout<<"\nEnter the first letter\t";
   char g;
   cin>>g;
   l1.searchbyletter(g);
 break;
 case 7:
   cout<<"\n\t=====================SEARCH BY LETTER============================\n\n";
   cout<<"\nEnter the first number\t";
   char h;
   cin>>h;
   l1.searchbynumber(h);
 break;
 case 8:
 cout<<"\n\t====================LIST OF Numbers added now======================\n\n";
 l1.print_now();
 break;
 default:
 cout<<"\t----------Invalid----------"<<endl;
}
}
while(ch!=5);
cout<<"\nTHANK YOU"<<endl;
getch();
} 
