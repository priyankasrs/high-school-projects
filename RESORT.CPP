#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
//to enable data base management thru a suitabe eg. of a resort
int i=0;
struct date
{int dd,mm,yy;};

struct room_cust
{char name[20],addr[80],type[40];
long int ph;
double cost;
int rooms,bed_perroom,days;
double taxes;
int custno;
date d;
}c;

struct indian
{char name[80];
int price;
}ind[10];

struct italian
{char name[80];
int price;
}ita[10];
struct chinese
{char name[80];
int price;
}chi[10];

struct hotelcust
{int tno;
char name[80];
char dish[10][80];
int price[10];
long int bill;
}hc;

fstream f;
void recieve_reception()
{int q;
textcolor(7);
textbackground(6);
int cho;
clrscr();
cout<<"ARE YOU A \n1.USER?\nOR\n2.MANAGEMENT STAFF?";
cin>>q;
if(q==1)
{cout<<"Please select any of the following options:-\n\n1."
<<"book a room\n\n2.cancel room reservation\n\n"
<<"3.View details\n\n4.Exit\n\n";
cin>>cho;
if(cho==1)
{::i++;
clrscr();
f.open("resort.dat",ios::in|ios::app|ios::binary);
cout<<"\a\a\a\a\n\nDEAR CUSTOMER\n\nENTER THE FOLLOWING DETAILS:-\n\n";
c.custno=i;
cout<<"Cust_id:"<<c.custno;
cout<<"\n\nName:";
gets(c.name);
cout<<"Address:";
gets(c.addr);
cout<<"Phone:";
cin>>c.ph;
date dt;
cout<<"Assuming this is a non-leap year,\n";
while(1)
{
cout<<"Check-in date(dd-mm-yy):";
cin>>dt.dd>>dt.mm>>dt.yy;
if(dt.mm==9||dt.mm==4||dt.mm==6||dt.mm==11)
{if(dt.dd>0&&dt.dd<31&&dt.yy>12)
c.d=dt;
break;
}
else
if(dt.mm==1||dt.mm==3||dt.mm==5||dt.mm==7||dt.mm==8||dt.mm==10||dt.mm==12)
{if(dt.dd>0&&dt.dd<=31&&dt.yy>12)
c.d=dt;
break;
}
else
if(dt.mm==2&&dt.dd>=0&&dt.dd<29&&dt.yy>12)
{c.d=dt;
break;}
else
cout<<"Invalid date!!";
}
int days;
while(1)
{cout<<"No of days of stay:";
cin>>days;
if(days<=30)
{c.days=days;
break;}
else cout<<"Invalid";
}
while(1)
{int choice;
cout<<"Type:-"
<<"\n\n1.royal suite\n\n2.villa experience\n\n3.ac cum delux suite\n\n"
<<"4.ac suite\n\n5.economy suite\n\nEnter ur choice:";
cin>>choice;
if(choice==1)
{int rooms,rs=6,bed_perroom;
strcpy(c.type,"royal suite");
while(1)
{cout<<"No of rooms:";
cin>>rooms;
cout<<"Beds per room:";
cin>>bed_perroom;
if(rooms<=rs&&bed_perroom<=15)
{c.rooms=rooms;
c.bed_perroom=bed_perroom;
break;}
else
cout<<"\nThese no:of rooms/beds are not available\n"; }
c.taxes=10000;
break;}
else if(choice==2)
{int rooms,ve=10,bed_perroom;
strcpy(c.type,"villa experience");
cout<<"No of rooms:";
cin>>rooms;
cout<<"Beds per room:";
cin>>bed_perroom;
if(rooms<=ve&&bed_perroom<=9)
{c.rooms=rooms;
c.bed_perroom=bed_perroom;
break;}
else
cout<<"These no:of rooms/beds are not available";
c.taxes=8000;
break;}
else if(choice==3)
{int rooms,acd=12,bed_perroom;
strcpy(c.type,"ac cum delux suite");
cout<<"No of rooms:";
cin>>rooms;
cout<<"Beds per room:";
cin>>bed_perroom;
if(rooms<=acd&&bed_perroom<=5)
{c.rooms=rooms;
c.bed_perroom=bed_perroom;
break;}
else
cout<<"These no:of rooms/beds are not available";
c.taxes=4000;
break;}
else if(choice==4)
{int rooms,ac=14,bed_perroom;
cout<<"No of rooms:";
cin>>rooms;
cout<<"Beds per room:";
cin>>bed_perroom;
if(rooms<=ac&&bed_perroom<=3)
{c.rooms=rooms;
c.bed_perroom=bed_perroom;
break;}
else
cout<<"These no:of rooms/beds are not available";
strcpy(c.type,"ac suite");
c.taxes=2000;
break;
}
else
if(choice==5)
{int rooms,eco=18,bed_perroom;
strcpy(c.type,"economy suite");
cout<<"No of rooms:";
cout<<"Beds per room:";
cin>>bed_perroom;
cin>>rooms;
if(rooms<=eco&&bed_perroom<=3)
{c.rooms=rooms;
c.bed_perroom=bed_perroom;
break;}
else
cout<<"These no:of rooms are not available";
c.taxes=1000;
break;}
else
{cout<<"Wrong choice!enter again:";}}
c.cost=c.bed_perroom*500+c.rooms*3000+c.taxes;
cout<<"The cost for your booking is:Rs."<<c.cost<<"/day";
int ch;
cout<<"\n\nSelect ur mode of payment\n\n1.thru cash\n\n2.thru cheque\n\n"
<<"3.thru credit card"
<<"\n\n4.thru debit card\n\n5.exit";
cin>>ch;
if(ch==5)
{cout<<"THANK YOU FOR UR VISIT!YOU ARE WELCOME!";
getch();
return;}
else
{f.write((char*)&c,sizeof(c));
cout<<"\n\nYOUR ROOMS HAVE BEEN BOOKED!\n\n"
<<"THANK YOU FOR CHOOSING ANTEEDOTE!!!HOPE YOU ENJOY YOUR STAY HERE!!!";
getch();}
f.close();}

else
if(cho==2)
{f.open("resort.dat",ios::in|ios::out|ios::binary);
fstream f1("temp.dat",ios::out|ios::binary);
int cust;
cout<<"Enter custno:";
cin>>cust;
int h=0;
while(f.read((char*)&c,sizeof(c)))
{if(c.custno==cust)
h++;
if(c.custno!=cust)
f1.write((char*)&c,sizeof(c));
}
f.close();
f1.close();
f.open("resort.dat",ios::out|ios::binary);
f1.open("temp.dat",ios::in|ios::binary);
while(f1.read((char*)&c,sizeof(c)))
f.write((char*)&c,sizeof(c));
f.close();
f1.close();
remove("temp.dat");
if(h)
cout<<"Your reservation has been cancelled";
else
cout<<"The cust id does not exist!!!";
getch();
}
else
if(cho==3)
{f.open("resort.dat",ios::binary|ios::in);
int cust,l=0;
cout<<"Enter custno:";
cin>>cust;
while(f.read((char*)&c,sizeof(c)))
if(c.custno==cust)
{l++;
cout<<"\nName:";
puts(c.name);
cout<<"Address:";
puts(c.addr);
cout<<"Phone:";
cout<<c.ph;
cout<<"\nRooms:";
cout<<c.rooms;
cout<<"\nType:";
cout<<c.type;
getch();
}
f.close();
if(l==0)
cout<<"Not found";
getch();
}}
else if(q==2)
{clrscr();
char mngpass[80];
strcpy(mngpass,"anteedote");
cout<<"The Management Password:";
char str[80],ch;
gets(str);
if(strcmp(mngpass,str)!=0)
{cout<<"Invalid password";
getch();
}
else
{clrscr();
cout<<"\n\t\t\t\tMAINTENANCE\n\n";
cout<<"Enter your options:-\n\n1.verification and modification\n\n"
<<"2.View details\n\n3.Exit\n\n";
int cho;
cin>>cho;
if(cho==1)
{f.open("resort.dat",ios::binary|ios::in|ios::out);
int cust;
cout<<"Enter the cust id:";
cin>>cust;
int s,h=0;
while(f.read((char*)&c,sizeof(c)))
{if(cust==c.custno)
{h++;
cout<<"enter the detail type to be modified:-\n\n1.Address\n\n2.Type of room\n\n"
<<"3.phone number\n\n4.number of rooms\n\n5.beds per room\n\n6.no of days\n\n";
cin>>s;
cout<<"\n\nEnter new detail:";
if(s==1)
gets(c.addr);
else if(s==2)
{char type[80];
gets(type);
if(strcmp(type,"villa experience")==0)
strcpy(c.type,type);
else if(strcmp(type,"ac cum  delux suite")==0)
strcpy(c.type,type);
else if(strcmp(type,"royal suite")==0)
strcpy(c.type,type);
else if(strcmp(type,"ac suite")==0)
strcpy(c.type,type);
else if(strcmp(type,"economy suite")==0)
strcpy(c.type,type);
else
{cout<<"invalid choice";
break;}
}
else if(s==3)
cin>>c.ph;
else if(s==4)
cin>>c.rooms;
else if(s==5)
cin>>c.bed_perroom;
else if(s==6)
cin>>c.days;
long int z=sizeof(c);
f.seekp(-z,ios::cur);
f.write((char*)&c,sizeof(c));
cout<<"Your details have been modified";
getch();
break;}}
if(h==0)
cout<<"Not found";
getch();
f.close();}
else
if(cho==2)
{f.open("resort.dat",ios::binary|ios::in);
int cust,l=0;
cout<<"Enter custno:";
cin>>cust;
while(f.read((char*)&c,sizeof(c)))
if(c.custno==cust)
{l++;
cout<<"\nName:";
puts(c.name);
cout<<"Address:";
puts(c.addr);
cout<<"Phone:";
cout<<c.ph;
cout<<"\nRooms:";
cout<<c.rooms;
cout<<"\nType:";
cout<<c.type;
getch();}
f.close();
if(l==0)
cout<<"Not found";
getch();}
else
exit(0);}}
else
{cout<<"Invalid!!!";
getch();}}
int zz=0;
void heaven_brink()
{
fstream f1;
textcolor(1);
textbackground(6);
clrscr();
int ch;
int q;
cout<<"ARE YOU A 1.USER OR 2.STAFF?";
cin>>q;
if(q==1)
{zz++;
f1.open("hotel.dat",ios::out);
cout<<"WELCOME TO 'THE HEAVEN'S BRINK'!\n\n"
<<"HERE YOU WILL FIND THE CHOICEST OF FOODS ALONG WITH"
<<" EXQUISITE FLAVOURS\n\nAND TASTES!\n\n";
cout<<"ENTER YOUR NAME:";
gets(hc.name);
cout<<"\n\nEnter your choice of table:-(_)represents no:of seats";
cout<<"\n\n\n\t______1\t\t______2\n\n____3\t____4\t____5\t____6"
<<"\t____7\t____8"
<<"\n\n\t__7\t\t__8\t\t__9\n\n____10\t____11\t____12\t"
<<"____13\t____14\t____15"
<<"\n\n\t______16\t\t______17\n\n";
while(1)
{cin>>ch;
if(ch<18)
break;
else
cout<<"Invalid entry.Re-enter:";
}
hc.tno=ch;
int ch1;
int cost=0,d=0,p=0;
x:
clrscr();
cout<<"\n\nNOW THAT YOU'VE DECIDED THE TABLE,SELECT THE CUISINE YOU WANT\n\n"
<<"1.INDIAN\n\n2.ITALIAN\n\n3.CHINESE\n\nEnter your choice:";
cin>>ch1;
if(ch1==1)
{int ch2;
clrscr();
strcpy(ind[0].name,"Butter chicken");
strcpy(ind[1].name,"Palak paneer with naan/chappathi");
strcpy(ind[2].name,"Kashmiri Pulao");
strcpy(ind[3].name,"Masala dosa");
strcpy(ind[4].name,"Sorpotel");
strcpy(ind[5].name,"Rogan josh");
strcpy(ind[6].name,"Kaali dal");
strcpy(ind[7].name,"Lauki ke kofte");
strcpy(ind[8].name,"Undhiyo");
strcpy(ind[9].name,"Hyderabadi dum Biriyani");
ind[0].price=200;
ind[1].price=260;
ind[2].price=320;
ind[3].price=100;
ind[4].price=240;
ind[5].price=210;
ind[6].price=180;
ind[7].price=190;
ind[8].price=310;
ind[9].price=300;
cout<<"PLEASE SELECT YOUR DISH FROM THE MENU\n\n\tMENU\n\n"
<<"1.Butter chicken\t\t\tRs.200\n\n2.Palak paneer with naan/chappathi\tRs.260\n\n"
<<"3.Kashmiri Pulao\t\t\tRs.320\n\n4.Masala dosa\t\t\t\tRS.100"
<<"\n\n5.Sorpotel\t\t\t\tRs.240\n\n6.Rogan josh\t\t\t\tRs.210\n\n7."
<<"Kaali dal\t\t\t\tRs.180\n\n8.Lauki ke kofte\t\t\tRs.190"
<<"\n\n9.Undhiyo\t\t\t\tRs.310\n\n10.Hyderabadi dum Biriyani\t\tRs.300";
cout<<"\n\nEnter your choice:";
while(1)
{cin>>ch2;
strcpy(hc.dish[d++],ind[ch2-1].name);
hc.price[p++]=ind[ch2-1].price;
cost+=ind[ch2-1].price;
if(ch2<11)
{char c;
cout<<"\n\nYOUR ORDER HAS BEEN MADE."
<<"\n\nPLEASE WAIT FOR SOME TIME FOR THE DISH TO BE READY!";
cout<<"\n\nMEANWHILE DO YOU WANT TO ORDER MORE(y/n)?";
cin>>c;
if(c=='n')
{hc.bill=cost;
cout<<"\n\nYOUR BILL AMT IS:Rs."<<cost;
break;}
else goto x;}
else
cout<<"Wrong choice:Enter again:";
}}
else if(ch1==2)
{int ch2;
clrscr();
strcpy(ita[0].name,"Grilled fresh tomato pizza with cheese");
strcpy(ita[1].name,"Pasta with Bolognese sauce");
strcpy(ita[2].name,"Winter minestrone");
strcpy(ita[3].name,"Polanta with beef ragout");
strcpy(ita[4].name,"Chicken parmesan pronto");
strcpy(ita[5].name,"Baked chicken Cacciatore");
strcpy(ita[6].name,"Osso Buco");
strcpy(ita[7].name,"Classic lasagna");
strcpy(ita[8].name,"Classic spaggetti and meatballs");
strcpy(ita[9].name,"Clam Risotto");
ita[0].price=200;
ita[1].price=260;
ita[2].price=320;
ita[3].price=300;
ita[4].price=240;
ita[5].price=210;
ita[6].price=180;
ita[7].price=190;
ita[8].price=310;
ita[9].price=300;
cout<<"PLEASE SELECT YOUR DISH(ONE AT A TIME) FROM THE MENU\n\n\tMENU\n\n"
<<"1.Grilled fresh tomato pizza with cheese\tRs.200"
<<"\n\n2.Pasta with Bolognese sauce\t\t\tRs.260\n\n"
<<"3.Winter minestrone\t\t\t\tRs.320\n\n4.Polanta with beef ragout\t\t\tRS.300"
<<"\n\n5.Chicken parmesan pronto\t\t\tRs.240\n\n"
<<"6.Baked chicken Cacciatore\t\t\tRs.210\n\n7."
<<"Osso Buco\t\t\t\t\tRs.180\n\n8.Classic lasagna\t\t\t\tRs.190\n\n"
<<"9.Classic spaggetti and meatballs\t\tRs.310\n\n"
<<"10.Clam Risotto\t\t\t\t\tRs.300";
cout<<"\n\nEnter your choice:";
while(1)
{cin>>ch2;
strcpy(hc.dish[d++],ind[ch2-1].name);
hc.price[p++]=ind[ch2-1].price;
cost+=ita[ch2-1].price;
if(ch2<11)
{char c;
cout<<"\n\nYOUR ORDER HAS BEEN MADE."
<<"\n\nPLEASE WAIT FOR SOME TIME FOR THE DISH TO BE READY!";
cout<<"\n\nMEANWHILE DO YOU WANT TO ORDER MORE(y/n)?";
cin>>c;
if(c=='n')
{hc.bill=cost;
cout<<"\n\nYOUR BILL AMT IS:Rs."<<cost;
break;}
else goto x;}
else
cout<<"Wrong choice:Enter again:";}}
else if(ch1==3)
{clrscr();
int ch2;
clrscr();
strcpy(chi[0].name,"Egg rolls");
strcpy(chi[1].name,"Chicken fried rice");
strcpy(chi[2].name,"Beef with broccoli");
strcpy(chi[3].name,"Chaumein");
strcpy(chi[4].name,"Hot and sour soup");
strcpy(chi[5].name,"Jiaozi dumplings");
strcpy(chi[6].name,"Fortune cookies");
strcpy(chi[7].name,"Egg drop soup");
strcpy(chi[8].name,"Sweet and sour pork");
strcpy(chi[9].name,"Potstickers");
chi[0].price=200;
chi[1].price=260;
chi[2].price=320;
chi[3].price=100;
chi[4].price=240;
chi[5].price=210;
chi[6].price=100;
chi[7].price=190;
chi[8].price=310;
chi[9].price=300;
cout<<"PLEASE SELECT YOUR DISH FROM THE MENU\n\n\tMENU\n\n"
<<"1.Egg rolls\t\t\t\tRs.200\n\n2.Chicken fried rice\t\t\tRs.260\n\n"
<<"3.Beef with broccoli\t\t\tRs.320\n\n4.Chaumein\t\t\t\tRS.100"
<<"\n\n5.Hot and sour soup\t\t\tRs.240\n\n6.Jiaozi dumplings\t\t\tRs.210\n\n7."
<<"Fortune cookies\t\t\tRs.100\n\n8.Egg drop soup\t\t\t\tRs.190"
<<"\n\n9.Sweet and sour pork\t\t\tRs.310\n\n10.Potstickers\t\t\t\tRs.300";
cout<<"\n\nEnter your choice:";
while(1)
{cin>>ch2;
strcpy(hc.dish[d++],ind[ch2-1].name);
hc.price[p++]=ind[ch2-1].price;
cost+=chi[ch2-1].price;
if(ch2<11)
{char c;
cout<<"\n\nYOUR ORDER HAS BEEN MADE."
<<"\n\nPLEASE WAIT FOR SOME TIME FOR THE DISH TO BE READY!";
cout<<"\n\nMEANWHILE DO YOU WANT TO ORDER MORE(y/n)?";
cin>>c;
if(c=='n')
{hc.bill=cost;
cout<<"\n\nYOUR BILL AMT IS:Rs."<<cost;
break;}
else goto x;}
else
cout<<"Wrong choice:Enter again:";
}}
else
{cout<<"Wrong choice;Enter again:";
getch();
goto x;}
f1.write((char*)&hc,sizeof(hc));
f1.close();
getch();
}
else if(q==2)
{char pass[80];
cout<<"Management password:";
gets(pass);
if(strcmp(pass,"brink")==0)
{int g;
clrscr();
cout<<"Enter option:-\n1.View previous orders\n2.exit\n";
cin>>g;
if(g==1&&zz)
{f1.open("hotel.dat",ios::in);
while(f1.read((char*)&hc,sizeof(hc)))
{cout<<"Name:";
puts(hc.name);
cout<<"Bill amt:"<<hc.bill;}
f1.close();
getch();}
else
{cout<<"No customers till now...";
getch();
}}}
else
{cout<<"Invalid!!!";
getch();
}}
void main()
{
int ch;
do
{textcolor(1);
textbackground(7);
clrscr();
cprintf("\r\n");
textcolor(2) ;
cprintf("HELLO!WELCOME TO ANTEEDOTE!");
cout<<"\n\nIT IS CONSIDERED TO BE ONE OF THE "
<<"LEADING RESORTS IN THE COUNTRY!\n\nHERE YOU"
<<" WILL BE REVELLING IN THE LAP OF LUXURY"
<<"\n\nIT IS HERE WHERE EVERY DAY IS\a A";
cprintf("\r\n\n");
textcolor(2);
textbackground(7);
cprintf("CELEBRATION ");
cout<<"AND";
cprintf(" YOU ARE THE");
cout<<"\a\a";
cprintf(" OCCASSION");
cout<<"...";
cout<<"\n\nDEAR GUEST,\n\nIT'S TIME YOU DECIDE WHAT YOU WANNA DO NOW...\n\n"
<<"SELECT ANY ONE OF THE FOLLOWING OPTIONS";
cprintf("\r\n");
textcolor(4);
textbackground(7);
cprintf("\n\n1.Room Reservation");
cout<<"\n\n";
cprintf("2.Enter restaurant:-'HEAVEN'S BRINK'");
cout<<"\n\n";
cprintf("3.Exit\n\n");
cin>>ch;
if(ch==1)
recieve_reception();
else if(ch==2)*/
heaven_brink();
else
break;}
while(ch<4);
getch();
}






























