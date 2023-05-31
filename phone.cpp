 #include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
using namespace std; 
void Addcontacts(); 
void Displaycontacts(); 
void SearchBySrNo(); 
void deletecontact(); 
void modifycontact(); 
class contact{
int srno;
char fname[25];
char lname[25];
char mobile[15];
char email[30];
char add[50];
public:
void storeData()
{
cout<<"\n...............CREATE NEW PHONE RECORD...............\n";
cout<<"Enter Serial Number : "; 
cin>>srno; cin.ignore();
cout<<"Enter first Name : "; 
cin.getline(fname,25);
cout<<"Enter last Name : "; 
cin.getline(lname,25);
cout<<"Enter Mobile Number : "; 
cin.getline(mobile,15);
cout<<"Enter E-Mail I.D. : "; 
cin.getline(email,30);
cout<<"Enter address : "; 
cin.getline(add,50);
cout<<endl;
}
void showData()
{
cout<<endl;
cout<<"Sr. No. : "<<srno<<endl;
cout<<"first Name : "<<fname<<endl;
cout<<"last Name : "<<lname<<endl;
cout<<"Mobile No. : "<<mobile<<endl;
cout<<"Email ID : "<<email<<endl;
cout<<"address : "<<add<<endl;
}
int getSrNo() 
{
return srno;
}
}b;
void Addcontacts()
{
ofstream fout;
fout.open("h.txt",ios::out|ios::binary|ios::app);
b.storeData();
fout.write((char*)&b,sizeof(b));
fout.close();
cout<<"\n Contact saved successfully\n";
}
void Displaycontacts()
{
cout<<"\n...............PHONE BOOK RECORD...............\n";
ifstream fin;
fin.open("h.txt",ios::out|ios::binary|ios::app);
while(fin.read((char*)&b,sizeof(b)))
{
b.showData();
}
fin.close();
cout<<"\nReading contact is Completed......\n";
}
void SearchBySrNo()
{
ifstream fin;
int n, flag=0;
fin.open("h.txt",ios::out|ios::binary|ios::app);
cout<<"Enter Serial Number of Record To Display: ";
cin>>n;
while(fin.read((char*)&b,sizeof(b)))
{
if(n==b.getSrNo())
{
b.showData();
flag++;
cout<<"\n\n***Record Found and Displaed**\n";
}
}
fin.close();
if(flag==0)
cout<<"\nThe Record of Serial Number "<<n<<" is not in file....\n";
cout<<"\nReading of contact File Completed......\n";
}
void deletecontact()
{
ifstream fin;
ofstream fout;
int n, flag=0;
fin.open("h.txt",ios::out|ios::binary|ios::app);
fout.open("h.dat",ios::out|ios::binary);
cout<<"Enter Serial Number of Record To Delete : ";
cin>>n;
while(fin.read((char*)&b,sizeof(b)))
{
if(n==b.getSrNo())
{
cout<<"\n***The Following record is deleted**\n";
b.showData();
flag++;
}
else
{
fout.write((char*)&b,sizeof(b));
}
}
fin.close();
fout.close();
if(flag==0)
cout<<"\nThe Record of Serial Number "<<n<<" is not in file....\n";
cout<<"\nReading of contact File Completed......\n";
remove("h.dat");
rename("h.dat","h.dat");
}
void modifycontact()
{
fstream fio;
int n, flag=0,pos;
fio.open("h.txt",ios::out|ios::binary|ios::in);
cout<<"Enter Serial Number of Record To Modify : ";
cin>>n;
while(fio.read((char*)&b,sizeof(b)))
{
pos=fio.tellg();
if(n==b.getSrNo())
{
cout<<"\nThe Following record will be modified....\n";
b.showData();
flag++;
cout<<"\nRe-Enter the New Details.....\n";
b.storeData();
fio.seekg(pos-sizeof(b));
fio.write((char*)&b,sizeof(b));
cout<<"\n....Data Modified Successfully....\n";
}
}
fio.close();
if(flag==0)
cout<<"\nThe Record of Serial Number "<<n<<" is not in file....\n";
cout<<"\nReading of contact File Completed......\n";
}
int main()
{
int choice;
system("color 0A");
cout<<"\n****************welcome to phone contact management system***************** \n";
while(1)
{
cout<<"================================================";
cout<<"\n1:add a contact\n2:display the contact\n3:search a contact\n4:delete a contact\n5:edit a contact\n6:exit\n";
cout<<"================================================";
cout<<"\nEnter your choice:\n";
cin>>choice;
switch(choice)
{
case 1: Addcontacts();
break;
case 2: Displaycontacts();
break;
case 3: SearchBySrNo();
break;
case 4: deletecontact(); 
break;
case 5: modifycontact();
break;
case 6:{
cout<<"thank you";
exit(0);
}
default:cout<<"\ninvalid choice\n";
}
}
return 0;
}
