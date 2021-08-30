#include <iostream>
#include <string>
#include <time.h>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;
static int p = 0;
class registration
{
public:
int uid, fare;
char name[20], from[25], to[25];
int pnum, otp;
char pass[10];
int status;
char vnumber[10];
void putdataureg();
void putdatadtrg();

registration()
{
status = 0;
fare = 0;
}
void reg()
{
int op1;
cout<<endl<<"\t\t\t -------- REGISTRATION FORM --------";
cout<<endl<<"\n\t\t\t\t 1.USER REGISTATION \n\t\t\t\t 2.DRIVER REGISTRATION \n\n\t\t\t\t ENTER YOUR CHOICE : ";
cin>>op1;
switch(op1)
{
case 1 : putdataureg();
break;
case 2 : putdatadtrg();
break;
default : cout<<"\n\t\t\t INVALID CHOICE !!!\n"<<endl;
}
}
};
class validation : public registration
{
int op;
int tid1, tid2;
char tpass1[20], tpass2[20];

public:
void ucheck();
void dcheck();
void customers();
}s1[100];
void registration :: putdatadtrg()
{
cout<<endl<<"\t\t\t -------- DRIVER REGISTRATION FORM --------"<<endl;
cout<<"\n\t\t\t ENTER YOUR NAME : ";
cin>>s1[p].name;
cout<<endl<<"\t\t\t ENTER YOUR VECHILE NUMBER : ";
cin>>s1[p].vnumber;
cout<<endl<<"\t\t\t ENTER YOUR PASSWORD : ";
cin>>s1[p].pass;
cout<<endl<<"\t\t\t ENTER THE SOURCE PLACE : ";
cin>>s1[p].from;
cout<<endl<<"\t\t\t ENTER THE DESTINATION PLACE : ";
cin>>s1[p].to;
cout<<endl<<"\t\t\t ENTER THE COST : ";
cin>>s1[p].fare;
cout<<endl<<"\t\t\t ***********************************";
cout<<endl<<"\t\t\t YOU HAVE SUCCESFULLY REGISTERD !!!";
cout<<endl<<"\t\t\t ***********************************"<<endl;
 srand(time(0));

s1[p].uid = rand()%1000;
s1[p].status = 1;
cout<<endl<<"\t\t\t YOUR ID : "<<s1[p].uid<<endl;
cout<<endl<<"\t\t\t YOUR NAME : "<<s1[p].name<<endl;
cout<<endl<<"\t\t\t YOUR VECHILE NUMBER : "<<s1[p].vnumber<<endl;
cout<<endl<<"\t\t\t YOUR PASSWORD : "<<s1[p].pass<<endl;
cout<<endl<<"\t\t\t YOU CAN LOGIN NOW !!!";
cout<<endl<<"\t\t\t **********************\n"<<endl;
p++;
}
void registration :: putdataureg()
{
cout<<endl<<"\t\t\t -------- USER REGISTRATION FORM --------"<<endl;
cout<<"\n\t\t\t ENTER YOUR NAME : ";
cin>>s1[p].name;
cout<<endl<<"\t\t\t ENTER YOUR PHONE NUMBER (ONLY 10 DIGITS) : ";
cin>>s1[p].pnum;
cout<<endl<<"\t\t\t ENTER YOUR PASSWORD : ";
cin>>s1[p].pass;
cout<<endl<<"\t\t\t ENTER YOUR SOURCE PLACE : ";
cin>>s1[p].from;
cout<<endl<<"\t\t\t ***********************************";
cout<<endl<<"\t\t\t YOU HAVE SUCCESFULLY REGISTERD !!!";
cout<<endl<<"\t\t\t ***********************************"<<endl;
srand(time(0));

s1[p].status = 0;
s1[p].uid = rand()%1000;
cout<<endl<<"\t\t\t YOUR ID : "<<s1[p].uid<<endl;
cout<<endl<<"\t\t\t YOUR NAME : "<<s1[p].name<<endl;
cout<<endl<<"\t\t\t YOUR PHONE NUMBER : "<<s1[p].pnum<<endl;
cout<<endl<<"\t\t\t YOUR PASSWORD : "<<s1[p].pass<<endl;
cout<<endl<<"\t\t\t YOU CAN LOGIN NOW !!!";
cout<<endl<<"\t\t\t **********************\n"<<endl;
p++;
}
void validation :: dcheck()
{
int tid, i = 0;
char t1pass[20];
cout<<endl<<"\t\t\t -------- LOGIN PORTAL --------"<<endl;
cout<<"\n\t\t\t\t ENTER DRIVERS ID : ";
cin>>tid;
cout<<"\n\t\t\t\t ENTER PASSWORD : ";
cin>>t1pass;
for(int n=0; n<p; n++)
{
if(( s1[n].uid == tid ) && ( strcmp(s1[n].pass,t1pass ) == 0 ))
{
cout<<"\n\t\t\
t-------------------------------------------------------------------------------"<<endl;
cout<<"\t\t\t DRIVER'S ID : "<<s1[n].uid;

cout<<"\t\t NAME : "<<s1[n].name;
cout<<"\t\t AMOUNT : "<<s1[n].fare<<endl;
cout<<"\t\t\
t-------------------------------------------------------------------------------"<<endl;
int kotp;
cout<<endl<<"\t\t\t ENTER THE CUSTOMER OTP : ";
cin>>kotp;
for(int n=0; n<p; n++)
{
if( s1[n].otp == kotp )
{
cout<<"\n\t\t\
t-------------------------------------------------------------------------------"<<endl;
cout<<"\t\t\t NAME : "<<s1[n].name;
cout<<"\t ID : "<<s1[n].uid;
cout<<"\t PH.NO. : "<<s1[n].pnum;
cout<<"\t OTP IS : "<<s1[n].otp<<endl;
cout<<"\t\t\
t-------------------------------------------------------------------------------"<<endl;
i = 1;
}
}
}
}
if( i == 0 )
{
cout<<endl<<"\n\t\t\t INVALID CREDENTIALS OR NO TICKETS RAISED !!!\
n"<<endl;}
}
void validation :: ucheck()
{
int id, op, i = 0;

char password[20];
cout<<endl<<"\t\t\t -------- LOGIN PORTAL --------"<<endl;
cout<<"\n\t\t\t\t ENTER ID NUMBER : ";
cin>>id;
cout<<"\n\t\t\t\t ENTER PASSWORD : ";
cin>>password;
for(int n=0; n<=p; n++)
{
if(( s1[n].uid == id) && ( strcmp( s1[n].pass,password ) == 0 ))
{
for(int l=0; l<p; l++)
{
if(( s1[l].status == 1 ) && ( strcmp( s1[l].from,s1[n].from ) == 0) )
{
cout<<"\n\t\t\t----------------------------------------------------------------------"<<endl;
cout<<"\t\t\t DRIVER'S ID : "<<s1[l].uid;
cout<<"\t\t NAME : "<<s1[l].name;
cout<<"\t\tFARE : "<<s1[l].fare<<endl;
cout<<"\t\t\
t----------------------------------------------------------------------"<<endl;
cout<<"\n\t\t\t SOURCE PLACE : "<<s1[l].from<<"\t\t DESTINATION PLACE : "<<s1[l].to<<endl;
cout<<"\n\t\t\t DO YOU WANT TO ENTER ?(IF YES, CLICK 1) : ";
cin>>op;
switch(op)
{
case 1:{ //--------------------------------------------------
s1[l].status=2;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


cout<<"\n\n"<<endl;
cout<<"\n\t\t\t/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|";
cout<<endl<<"\t\t\t\t TICKET "<<endl;
cout<<"\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
cout<<"\n\t\t\t SIT AUTORICKSHAWA BOOKINGS "<<endl;
cout<<"\n\t\t\t FROM : "<<s1[l].from<<"\t\t TO :"<<s1[l].to;
cout<<endl<<"\t\t\t TOTAL FARE : "<<s1[l].fare<<endl;
cout<<"\n\t\t\t THANK YOU, \t\t VISIT AGAIN"<<endl;
cout<<"\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout<<"\t\t\t****************************"<<endl;
srand(time(0));
s1[n].otp=rand()%10000;
cout<<"\t\t\t TICKET GENERATED SUSSUFULLY \t OTP :"<<s1[n].otp<<endl;
cout<<"\t\t\t****************************"<<endl;
cout<<"\t\t\t|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/|/"<<endl;
cout<<"\n\n"<<endl;
i = i+1;
}
break;
default : cout<<"\n\t\t\t INVALID CHOICE !!!";
}
break;
}
}
}
}

if (i==0)
{
cout<<endl<<"\n\t\t\t INVALID CREDENTIALS OR AUTO IS CURRENTLY UNAVAILABLE !!!\n"<<endl;}
}
int main()
{
int ichoice,op;
cout << "\n\t\t\t\t STAY HOME STAY SAFE"<<endl;
cout<<"\t\t\t AUTO RIKSHA MANAGEMENT SYSTEM, TUMAKURU"<<endl;
while(1)
{
cout<<"\n\t\t\t\t 1.REGISTRATION\n\t\t\t\t 2.LOGIN\n\t\t\t\t 3.EXIT\n"<<endl;
cout<<"\t\t\t\t ENTER YOUR CHOICE : ";
cin>>ichoice;
switch(ichoice)
{
case 1: s1[p].reg();
break;
case 2: cout<<"\n\t\t\t -------- LOGIN FORM --------\n"<<endl;
cout<<"\t\t\t\t 1.USER LOGIN\n\t\t\t\t 2.DRIVER LOGIN"<<endl;
cout<<"\n\t\t\t\t ENTER YOUR CHOICE : ";
cin>>op;
switch(op)
{
case 1:s1[p].ucheck();
break;

case 2:{s1[p].dcheck();}
break;
default: cout<<"\n\t\t\t\t INVALID CHOICE !!!"<<endl;
}
break;
case 3:exit(0);
break;
default:{cout<<"\n\t\t\t\t INVALID CHOICE !!!"<<endl;}
}
}
return 0;
}
