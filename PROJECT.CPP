/*
		AIRLINE RESERVATION
		~~~~~~~~~~~~~~~~~~~
	This Project is Made to Reserve Online Flights Tickets.
	The Menu of this Project contains 8 options to select,
	1.To Show Existing Flight Records to the User
	2.To Add Flight Records to the User
	3.To Change any pre inputted flight records
	4.To delete any Flight Records
	5.To Reserve any ticket to the User
	6.To Cancel any Flight to the User
	7.To Display Passenger Records
	8.To Display all Flight Records
*/
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>

class database   //for database
{
	char company[20];   //name of company
	char depcity[20];   //departure city
	char arrcity[20];   //arrival city
	float duration;     //daration of flight
	char depdate[16];   //dd/mm/yyyy
	char arrdate[16];   //dd/mm/yyyy
	char deptime[10];   //hh:mm
	char arrtime[10];   //hh:mm
	int seats;          //No. of Seats Available
	float ecprice;      //Price for Economy Class
	float buprice;      //Price for Business Class
	float childprice;   //Price for children from 2-11 years
	char depairport[50];//departure airport
	char arrairport[50];//arrival airport
	char code[10];      //Unique code for each flight
	public:
	database()          //constructor
	{
		strcpy(company,"none");
		strcpy(depcity,"none");
		strcpy(arrcity,"none");
		duration=0;
		strcpy(depdate,"none");
		strcpy(arrdate,"none");
		strcpy(deptime,"none");
		strcpy(arrtime,"none");
		seats=0;
		ecprice=0;
		buprice=0;
		childprice=0;
		strcpy(depairport,"none");
		strcpy(arrairport,"none");
		strcpy(code,"none");
	}
	void input();     //to input flight Details
	void display();  //to display flight records
	void display1(int,char[]); //to display the flight names matched ≥≥≥
	void existing();   //to show the details of existing flight
	void addflight();  //to add any flight record
	void changerecords();  //to change the flight records
	void deleterecord();  //to delete any flight record
	void f1record();   //to check the flight entered by user
	void cost(int,int,char[],char[]);    //to output the cost of travel
	void seat(int,int,char[]);  //to reduce the remaining seats after booking
	void frecords();      //to display all the records
	~database()    //destructor
	{         }

};
database d;
fstream f;

class reserve     //for general details of user
{       private:
		char departcity[30];
		char arrivecity[30];
		int nadult;  //no. of adults
		int nchild;   //2-11 years
		int ninfant;    //no. of infant
		char clatravel[30]; //class of travel
		long code;     //individual code for each reservation
		float cost;
	public:
		reserve()    //constructor
		{
			strcpy(departcity,"none");
			strcpy(arrivecity,"none");
			nadult=0;
			nchild=0;
			ninfant=0;
			strcpy(clatravel,"economy");
		}
		void input(char[],char[],char[],int&,int&,long);
		void display();
		void flightreserve(char[],char[],char[],int,char[]);    //booking a flight
		void records();   //to see details of passengers
		void list();   //to see the list of passengers
		void cost1(float,float,float,float);
		~reserve()      //detructor
		{	}
};
reserve r;

class passdetails      //for taking input and display of user
{
	private:
		char name[30]; //name of user
		int age;
		char add[50];  //address
		char email[30];
		char sex[6];
		char phone[11];
		long code;//Unique Code issued to the User
	public:
		passdetails()  //constructor
		{
			strcpy(name,"none");
			age=0;
			strcpy(add,"none");
			strcpy(email,"none");
			strcpy(sex,"none");
			strcpy(phone,"none");
		}
		void input1(long&);  //to input the details of user
		void display1(); //to display the details of user
		void passreserve(int,int);   //booking a ticket
		void passcancel();     //cancelling a flight
		void passrecords();    //to display all the passenger records
		~passdetails()      //destructor
		{	}
};
passdetails p;

class loc    //class for cursor control
{
	public:
	int x,y;
	loc()
	{
		x=56;
		y=10;
	};
	loc(int a,int b)
	{
		x=a;
		y=b;
	};
	void cursor (int xa,int xb,int ya,int yb,int dx,int dy,int &z);
};

void loc :: cursor (int xa,int xb,int ya,int yb,int dx,int dy,int &z)
{
	int a;
	int i;
	char c[8];
	if(xa<1)
		xa=1;
	if(xb>80)
		xb=80;
	if(ya<1)
		ya=1;
	if(yb>25)
		yb=25;
	if(dx<0)
		dx=1;
	if(dy<0)
		dy=1;
	gotoxy(x,y);
	do
	{
		a=getch();
		if(a==13)
		{
			z=y;
			break;
		}
		else if(a!=00)
			continue;
		a=getch();
		if(a==75)
		{
			if(x<=xa)
			{
				if(y>ya)
					y-=dy;
				else
					y=yb;
				x=xb;
			}
			else
				x-=dx;
			gotoxy(x,y);
		}
		if(a==77)
		{
			if(x>=xb)
			{
				if(y<yb)
					y+=dy;
				else
					y=ya;
				x=xa;
			}
			else
				x+=dx;
			gotoxy(x,y);
		}
		if(a==72)
		{
			if(y<=ya)
				y=yb;
			else
				y-=dy;
			gotoxy(x,y);
		}
		if(a==80)
		{

			if(y>=yb)
				y=ya;
			else
				y+=dy;
			gotoxy(x,y);
		}
	}while(a!=13);

}

void outerborder(int x=2,int y=2,int z=79,int m=24,float n=41,float p=2,int o=25)
{
	    //x=leftcolumn z=rightcolumn y=upperrow m=lowerrow
	      //n=no.of horizontal rotations p=no.of vertical rotations o=delay
	int a=0;
	a=random(14)+1;
	textcolor(a);
	gotoxy(x,y);
	      cprintf("…");
	gotoxy(z,y);
	      cprintf("ª");
	gotoxy(x,m);
	      cprintf("»");
	gotoxy(z,m);
	      cprintf("º");
	for(int i=x+1,j=z-1,k=m-1,l=y+1;i<=n;j--,i++,k--,l++)
	{
	      gotoxy(i,y); cprintf("Õ");
	      gotoxy(j,y); cprintf("Õ");
	      gotoxy(i,m); cprintf("Õ");
	      gotoxy(j,m); cprintf("Õ");
	      if(i<=n/p)
	      {
			gotoxy(x,l); cprintf("∫");
			gotoxy(z,l); cprintf("∫");
			gotoxy(x,k); cprintf("∫");
			gotoxy(z,k); cprintf("∫");
	      }
	      delay(o);
	}
}

void innerborder(int x=5,int y=4,int z=76,int m=22,float n=13,float o=1.5,int p=25)
{
	//x=leftcolumn z=rightcolumn y=upperrow m=lowerrow
	      //n=no.of horizontal rotations p=no.of vertical rotations o=delay
	textcolor(12);
	gotoxy(x,y);
	      cprintf("⁄");
	gotoxy(z,y);
	      cprintf("ø");
	gotoxy(x,m);
	      cprintf("¿");
	gotoxy(z,m);
	      cprintf("Ÿ");
	for(int i=x+1,j=z-1,k=m,l=y+1;i<=n;j--,i++,k--,l++)
	{
	      gotoxy(i,y); cprintf("ƒ");
	      gotoxy(j,y); cprintf("ƒ");
	      gotoxy(i,m); cprintf("ƒ");
	      gotoxy(j,m); cprintf("ƒ");
	      if(i<=n/o)
	      {
			gotoxy(x,l); cprintf("≥");
			gotoxy(z,l); cprintf("≥");
			gotoxy(x,k-1); cprintf("≥");
			gotoxy(z,k-1); cprintf("≥");
	      }
	      delay(p);
	}
}

void aero()    //function to run aeroplane
{
	  clrscr();
	  outerborder(2,2,79,24,41,2,10);
	  textcolor(9);
	  gotoxy(3,3); cprintf("  ‹ﬂﬂﬂﬂ‹‹ﬂ‹‹      ‹ﬂﬂﬂﬂ‹‹ﬂ‹‹    ‹ﬂﬂﬂﬂ‹‹ﬂ‹‹      ‹ﬂﬂﬂﬂ‹‹ﬂ‹‹    ‹ﬂﬂﬂﬂ‹‹ﬂ‹‹");
	  gotoxy(3,4); cprintf(" ‹ﬂ         ﬂﬂ‹ ‹ﬂ         ﬂﬂ‹ ‹ﬂ         ﬂﬂ‹ ‹ﬂ          ﬂ‹ ‹ﬂ         ﬂﬂ‹");
	  gotoxy(3,5); cprintf(" ﬂ‹         ‹ﬂﬂ  ﬂ‹        ‹ﬂﬂ  ﬂ‹        ‹ﬂ  ﬂ‹         ‹ﬂ  ﬂ‹         ‹ﬂﬂ");
	  gotoxy(3,6); cprintf("   ﬂ‹‹‹ﬂ‹  ‹ﬂ       ﬂ‹‹‹ﬂ‹  ‹ﬂ   ﬂ‹‹‹ﬂ‹  ‹ﬂ      ﬂ‹‹‹ﬂ‹  ‹ﬂ   ﬂ‹‹‹ﬂ‹  ‹ﬂ");
	  gotoxy(3,7); cprintf("         ﬂﬂ               ﬂﬂ           ﬂﬂ              ﬂﬂ           ﬂﬂ  ");
	  textcolor(10);
	  gotoxy(6,16);  cprintf("    ‹ﬂ‹ﬂﬂ‹‹                                             ‹ﬂ‹ﬂﬂ‹‹    ");
	  gotoxy(6,17);  cprintf("  ‹ﬂ       ﬂﬂ‹                                        ‹ﬂ       ﬂﬂ‹ ");
	  gotoxy(6,18);  cprintf("  ﬂ‹        ﬂ‹                                        ﬂ‹        ﬂ‹ ");
	  gotoxy(6,19);  cprintf("  ﬂ‹       ‹ﬂ                                         ﬂ‹       ‹ﬂ  ");
	  gotoxy(6,20);  cprintf("    ﬂ‹   ‹ﬂ                                             ﬂ‹   ‹ﬂ    ");
	  textcolor(BROWN);
	  gotoxy(6,21);  cprintf("      €€€                                                 €€€      ");
	  gotoxy(6,22);  cprintf("      €€€                                                 €€€      ");
	  gotoxy(6,23);  cprintf("      €€€                                                 €€€      ");
	  for(int i=45;i>0;i--)
	  {
		outerborder(2,2,79,24,41,2,0);
		textcolor(LIGHTMAGENTA);
		gotoxy(i,9); cprintf("                  ‹ﬂ‹ﬂ‹ﬂ        ‹ﬂ‹€ ");
		gotoxy(i,10);cprintf("                ‹ﬂ‹ﬂ‹ﬂ        ‹ﬂ‹ﬂ‹€ ");
		gotoxy(i,11);cprintf("      ‹ ‹ ‹ ‹ ‹ﬂ‹ﬂ‹ﬂ‹ ‹ ‹ ‹ ‹ﬂ‹ﬂ‹ﬂ‹€ ");
		gotoxy(i,12);cprintf("    ‹ﬂ          ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹€ ");
		gotoxy(i,13);cprintf("  ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹€ ");
		gotoxy(i,14);cprintf("               ﬂ‹ﬂ‹ﬂ‹ ");
		gotoxy(i,15);cprintf("                 ﬂ‹ﬂ‹ﬂ‹ ");
		delay(70);
	 }
}

void front1()
{
	clrscr();
	outerborder();
	innerborder();
	textcolor(LIGHTMAGENTA);
	gotoxy(6,6);	cprintf("                   ≤≤≤≤≤ ≤≤≤ ≤≤≤≤≤ ≤   ≤≤≤ ≤   ≤ ≤≤≤≤           ");
	gotoxy(6,7);	cprintf("                   ≤   ≤  ≤  ≤   ≤ ≤    ≤  ≤≤  ≤ ≤              ");
	gotoxy(6,8);	cprintf("                   ≤≤≤≤≤  ≤  ≤≤≤≤≤ ≤    ≤  ≤ ≤ ≤ ≤≤≤            ");
	gotoxy(6,9);	cprintf("                   ≤   ≤  ≤  ≤ ≤   ≤    ≤  ≤  ≤≤ ≤              ");
	gotoxy(6,10);	cprintf("                   ≤   ≤ ≤≤≤ ≤  ≤‹ ≤≤≤ ≤≤≤ ≤   ≤ ≤≤≤≤           ");
	textcolor(LIGHTRED);
	gotoxy(4,13);	cprintf("       ≤≤≤≤≤ ≤≤≤≤ ≤≤≤≤≤ ≤≤≤≤ ≤≤≤≤≤ ≤     ≤ ≤≤≤≤≤ ≤≤≤≤≤ ≤≤≤  ≤≤≤≤ ≤   ≤  ");
	gotoxy(4,14);	cprintf("       ≤   ≤ ≤    ≤     ≤    ≤   ≤ ≤     ≤ ≤   ≤   ≤    ≤   ≤  ≤ ≤≤  ≤  ");
	gotoxy(4,15);	cprintf("       ≤≤≤≤≤ ≤≤≤  ﬂ≤≤≤‹ ≤≤≤  ≤≤≤≤≤  ≤   ≤  ≤≤≤≤≤   ≤    ≤   ≤  ≤ ≤ ≤ ≤  ");
	gotoxy(4,16);	cprintf("       ≤ ≤   ≤        ≤ ≤    ≤ ≤     ≤ ≤   ≤   ≤   ≤    ≤   ≤  ≤ ≤  ≤≤  ");
	gotoxy(4,17);	cprintf("       ≤  ≤‹ ≤≤≤≤ ≤≤≤≤ﬂ ≤≤≤≤ ≤  ≤‹    ≤    ≤   ≤   ≤   ≤≤≤  ≤≤≤≤ ≤   ≤  ");
	textcolor(10+BLINK);
	gotoxy(34,23);
	cprintf("PRESS ANY KEY");
	getch();
	clrscr();
}

void front2()
{
	clrscr();
	textcolor(10);
	gotoxy(2,3);	cprintf("≤≤≤≤ ≤≤≤ ≤≤≤ ≤  ≤≤≤ ≤  ≤ ≤≤≤    ≤≤≤ ≤≤≤ ‹≤≤ ≤≤≤ ≤≤≤ ≤   ≤ ≤≤≤ ≤≤≤ ≤≤≤ ≤≤≤ ≤  ≤\r\n");
	gotoxy(2,4);	cprintf("≤  ≤  ≤  ≤ ≤ ≤   ≤  ≤≤ ≤ ≤‹     ≤ ≤ ≤‹  ≤   ≤‹  ≤ ≤ ≤   ≤ ≤ ≤  ≤   ≤  ≤ ≤ ≤≤ ≤\r\n");
	gotoxy(2,5);	cprintf("≤≤≤≤  ≤  ≤≤≤ ≤   ≤  ≤ ≤≤ ≤      ≤≤≤ ≤    ﬂ≤ ≤   ≤≤≤  ≤ ≤  ≤≤≤  ≤   ≤  ≤ ≤ ≤ ≤≤\r\n");
	gotoxy(2,6);	cprintf("≤  ≤ ≤≤≤ ≤ﬂ‹ ≤≤ ≤≤≤ ≤  ≤ ≤≤≤    ≤ﬂ‹ ≤≤≤ ≤≤≤ ≤≤≤ ≤ﬂ‹   ≤   ≤ ≤  ≤  ≤≤≤ ≤≤≤ ≤  ≤\r\n");
	cout<<endl;
	innerborder(20,8,65,18,45,1.6,0);
	textcolor(5);
	gotoxy(25,10);	cprintf("                  ‹ﬂ‹ﬂ‹ﬂ        ‹ﬂ‹ﬂ€\r\n");
	gotoxy(25,11);	cprintf("                ‹ﬂ‹ﬂ‹ﬂ        ‹ﬂ‹ﬂ‹ﬂ€\r\n");
	gotoxy(25,12);	cprintf("      ‹ ‹ ‹ ‹ ‹ﬂ‹ﬂ‹ﬂ‹ ‹ ‹ ‹ ‹ﬂ‹ﬂ‹ﬂ‹ﬂ€\r\n");
	gotoxy(25,13);	cprintf("    ‹ﬂ          ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ€\r\n");
	gotoxy(25,14);	cprintf("  ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ‹ﬂ€\r\n");
	gotoxy(25,15);	cprintf("               ﬂ‹ﬂ‹ﬂ‹\r\n");
	gotoxy(25,16);	cprintf("                 ﬂ‹ﬂ‹ﬂ‹\r\n");
	textcolor(9);
	gotoxy(7,19);	cprintf("MADE BY :-");  delay(30);
	textcolor(13);
	gotoxy(9,20);	cprintf("PRAKHAR AGARWAL");delay(30);
	gotoxy(9,21);	cprintf("PRATEEK AGARWAL ");  delay(30);
	gotoxy(9,22);	cprintf("UTKARSH LAKHERA"); delay(30);
	textcolor(9);
	gotoxy(53,19);	cprintf("UNDER GUIDENCE OF:-");delay(30);
	textcolor(13);
	gotoxy(55,20);	cprintf("Mr. SHAKTIRISH K.AGARWAL");
	delay(30);
	gotoxy(30,23);  cprintf("ENTER ANY KEY...");
	getch();
}

void front3()
{
	clrscr();
	innerborder();
	textcolor(10);
	gotoxy(10,10);	cprintf("  ≤≤   ≤≤   ≤≤ ≤≤≤≤≤ ≤≤      ≤≤≤≤≤  ≤≤≤≤≤   ≤≤≤    ≤≤≤ ≤≤≤≤≤"); delay(30);
	gotoxy(10,11);	cprintf("  ≤≤   ≤≤   ≤≤ ≤≤    ≤≤     ≤≤     ≤≤   ≤≤  ≤≤≤≤  ≤≤≤≤ ≤≤"); delay(30);
	gotoxy(10,12);	cprintf("  ≤≤  ≤≤≤≤  ≤≤ ≤≤≤≤  ≤≤    ≤≤     ≤≤     ≤≤ ≤≤ ≤≤≤≤ ≤≤ ≤≤≤≤"); delay(30);
	gotoxy(10,13);	cprintf("  ≤≤ ≤≤  ≤≤ ≤≤ ≤≤    ≤≤    ≤≤     ≤≤     ≤≤ ≤≤  ≤≤  ≤≤ ≤≤"); delay(30);
	gotoxy(10,14);	cprintf("  ≤≤≤≤    ≤≤≤≤ ≤≤    ≤≤     ≤≤     ≤≤   ≤≤  ≤≤      ≤≤ ≤≤"); delay(30);
	gotoxy(10,15);	cprintf("  ≤≤≤      ≤≤≤ ≤≤≤≤≤ ≤≤≤≤≤≤  ≤≤≤≤≤  ≤≤≤≤≤   ≤≤      ≤≤ ≤≤≤≤≤"); delay(30);
	gotoxy(37,22);
	textcolor(13);
	cprintf("PROCESSING");
	for(int j=0;j<=4;j++)
	{
		cprintf(".");delay(300);
	}
}

void frontpage()       //function to call the functions of front page
{
	aero();
	front1();
	clrscr();
	outerborder();
	front2();
	front3();
	clrscr();
}

void menu()
{
	textcolor(14);
	gotoxy(40,5);
	cprintf("MENU");
	gotoxy(39,6);cprintf("~~~~~~");
	textcolor(15);
	gotoxy(26,10);	cprintf("1. EXISTING FLIGHT RECORDS");
	gotoxy(26,11);	cprintf("2. ADDING FLIGHT RECORDS");
	gotoxy(26,12);	cprintf("3. CHANGING FLIGHT RECORDS");
	gotoxy(26,13);	cprintf("4. DELETING FLIGHT RECORDS");
	gotoxy(26,14);	cprintf("5. PASSENGER RESERVATION");
	gotoxy(26,15);	cprintf("6. PASSENGER CANCELLATION");
	gotoxy(26,16);	cprintf("7. LIST OF PASSENGERS");
	gotoxy(26,17);	cprintf("8. FLIGHT RECORDS");
	gotoxy(26,19);	cprintf("   EXIT  ");
}

void enter()      //function to display the details of menu function
{
	gotoxy(28,21);
	textcolor(15);
	cprintf("Press ");
	textcolor(10);
	cprintf(" Enter ");
	textcolor(15);
	cprintf(" to Select");
	gotoxy(28,22);
	cprintf("Use Arrow Keys to MOVE Cursor");
}

void pr1(int &c)      //function to call menu function
{
	outerborder(24,3,59,23,58,1.5,10);
	innerborder(2,2,79,24,41,2,5);
	menu();
	enter();
	_setcursortype(_SOLIDCURSOR);
	loc j;
	j.cursor(56,56,10,19,1,1,c);
}

void showflight()      //function to make table showing flight details
{
	outerborder();
	gotoxy(33,3);
	cprintf("AVAILABLE FLIGHTS");
	gotoxy(33,4);
	cprintf("~~~~~~~~~~~~~~~~~~");
	innerborder(3,5,78,8,41,10,0);
	innerborder(3,5,78,20,35,2,0);
	innerborder(3,5,10,20,9,0,0);
	innerborder(10,5,22,20,21,1,0);
	innerborder(22,5,34,20,30,1,0);
	innerborder(34,5,46,20,42,1,0);
	innerborder(46,5,58,20,54,1,0);
	innerborder(58,5,71,20,66,1,0);
	textcolor(15);
	gotoxy(5,7);	cprintf("SNO.");
	gotoxy(13,7);	cprintf("FLIGHT");
	gotoxy(25,7);	cprintf("DEPARTS");
	gotoxy(37,7);	cprintf("ARRIVES");
	gotoxy(48,7);	cprintf("DEPARTURE");
	gotoxy(59,7);	cprintf("PRICE IN INR");
	gotoxy(73,7);	cprintf("CODE");
	textcolor(14);
	gotoxy(26,23);	cprintf("PRESS ENTER KEY TO SELECT");
}

void getp(char name[])  //function to enter password to access database functions
{
	for(int i=0;;i++)
	{
		name[i]=getch();
		if(name[i]==13)
			break;
		if(name[i]==8)
		{
			cout<<char(8)<<" "<<char(8);
			i-=2;
			continue;
		}
		cout<<"*";
	}
	name[i]='\0';
}

void processing()  //function to show some time gap to user
{
	clrscr();
	_setcursortype(_NOCURSOR);
	for(int i=0;i<4;i++)
	{              textcolor(13);
		gotoxy(30,11);
		cprintf("WAIT FOR A MOMENT");
		gotoxy(25,13);
		cprintf("WE ARE SEARCHING FLIGHTS FOR YOU");
		gotoxy(34,16);
		cprintf("PLEASE WAIT");
		outerborder(2,2,79,24,41,2,0);
		innerborder(10,8,70,18,40,2.2,0);
		gotoxy(45,16);
		for(int j=0;j<=4;j++)
		{
			textcolor(13);
			cprintf(".");delay(300);
		}
		clrscr();
	}
	_setcursortype(_SOLIDCURSOR);
}


long randm(long b)    //function to return a random value of long type
{
	b=random(10000)+1000;
	return b;
}

void database :: input() //function to input details of database
{
	clrscr();
	outerborder();
	textcolor(11);
	gotoxy(6,5);	 cprintf("Code:");
	gotoxy(45,5);    cprintf("Company:");
	gotoxy(6,7);	 cprintf("Depart city:");
	gotoxy(45,7);    cprintf("Arrive city:");
	gotoxy(6,9);     cprintf("Depart date(dd/mm/yyyy) : ");
	gotoxy(45,9);    cprintf("Arrive date(dd/mm/yyyy) :");
	gotoxy(6,11);    cprintf("Depart time:");
	gotoxy(45,11);   cprintf("Arrive time:");
	gotoxy(6,13);    cprintf("Seats:");
	gotoxy(45,13);   cprintf("Economic price:");
	gotoxy(6,15);    cprintf("Bussiness price:");
	gotoxy(45,15);   cprintf("Price for children(2-11years) :");
	gotoxy(6,17);    cprintf("Depart airport:");
	gotoxy(45,17);   cprintf("Arrive airport:");
	textcolor(10);
	gotoxy(8,6);     gets(d.code);
	gotoxy(47,6);	 gets(d.company);
	gotoxy(8,8);     gets(d.depcity);
	gotoxy(47,8);  	 gets(d.arrcity);
	gotoxy(8,10);    gets(d.depdate);
	gotoxy(47,10);   gets(d.arrdate);
	gotoxy(8,12);    gets(d.deptime);
	gotoxy(47,12);   gets(d.arrtime);
	gotoxy(8,14);    cin>>d.seats;
	gotoxy(47,14);   cin>>d.ecprice;
	gotoxy(8,16);    cin>>d.buprice;
	gotoxy(47,16);   cin>>d.childprice;
	gotoxy(8,18);    gets(d.depairport);
	gotoxy(47,18);   gets(d.arrairport);
}

void database :: display()    //function to display details to user
{
	clrscr();
	outerborder();
	textcolor(12);
	gotoxy(6,5);	 cprintf("Code:");
	gotoxy(45,5);    cprintf("Company:");
	gotoxy(6,7);	 cprintf("Depart city:");
	gotoxy(45,7);    cprintf("Arrive city:");
	gotoxy(6,9);     cprintf("Depart date(dd/mm/yyyy) : ");
	gotoxy(45,9);    cprintf("Arrive date(dd/mm/yyyy) :");
	gotoxy(6,11);    cprintf("Depart time:");
	gotoxy(45,11);   cprintf("Arrive time:");
	gotoxy(6,13);    cprintf("Seats:");
	gotoxy(45,13);   cprintf("Economic price:");
	gotoxy(6,15);    cprintf("Bussiness price:");
	gotoxy(45,15);   cprintf("Price for children(2-11years) :");
	gotoxy(6,17);    cprintf("Depart airport:");
	gotoxy(45,17);   cprintf("Arrive airport:");
	textcolor(11);
	gotoxy(8,6);     puts(d.code);
	gotoxy(47,6);	 puts(d.company);
	gotoxy(8,8);     puts(d.depcity);
	gotoxy(47,8);  	 puts(d.arrcity);
	gotoxy(8,10);    puts(d.depdate);
	gotoxy(47,10);   puts(d.arrdate);
	gotoxy(8,12);    puts(d.deptime);
	gotoxy(47,12);   puts(d.arrtime);
	gotoxy(8,14);    cout<<d.seats;
	gotoxy(47,14);   cout<<d.ecprice;
	gotoxy(8,16);    cout<<d.buprice;
	gotoxy(47,16);   cout<<d.childprice;
	gotoxy(8,18);    puts(d.depairport);
	gotoxy(47,18);   puts(d.arrairport);
}

void database :: existing()   //function to display selected flight records to the user
{
	innerborder(20,8,50,16,35,1.8,20);
	gotoxy(25,12);
	textcolor(15);
	cprintf("Enter Password : ");
	char ge[20];
	getp(ge);
	if(strcmp(ge,"flight")==0)
	{
		int x=0;
		clrscr();
		textcolor(15);
		char ch[10],ar='y';
		outerborder(20,8,50,16,35,2.5,20);
		gotoxy(22,12);
		textcolor(15);
		cprintf("Enter flight code:");
		gets(ch);
		f.open("flights.txt",ios::binary|ios::in);
		f.seekg(0);
		while(f.read((char *)&d,sizeof(d)))
		{
			if(strcmp(ch,code)==0)
			{
				d.display();
				x++;
			}
		}
		f.close();
		if(x==0)
		{
			gotoxy(8,8);
			cprintf("REQUIRED RECORD NOT FOUND");
		}
		getch();
		clrscr();
		outerborder();
		gotoxy(25,10);
		cprintf("Press Y/N : ");
		cin>>ar;
		clrscr();
		if(ar=='y'||ar=='Y')
			d.existing();
	}
	else
	{
		textcolor(15);
		gotoxy(27,12);
		cout<<"INVALID PASSWORD";
	}
}

void database :: addflight()   //function to add flight records
{
	innerborder(20,8,50,16,35,1.8,20);
	gotoxy(25,12);
	textcolor(15);
	cprintf("Enter Password : ");
	char ge[20];
	getp(ge);
	if(strcmp(ge,"flight")==0)
	{
		textcolor(15);
		char ar='y';
		f.open("flights.txt",ios::binary|ios::app);
		d.input();
		f.write((char *)&d,sizeof(d));
		f.close();
		clrscr();
		outerborder();
		gotoxy(25,10);
		textcolor(10);
		cprintf("Press Y/N To Enter Again : ");
		cin>>ar;
		clrscr();
		if(ar=='y'||ar=='Y')
			d.addflight();
	}
	else
	{
		textcolor(15);
		gotoxy(27,12);
		cprintf("INVALID PASSWORD");
	}
}

void database :: changerecords() //function to change flight records
{

	innerborder(20,8,50,16,35,1.8,20);
	gotoxy(25,12);
	textcolor(15);
	cprintf("Enter Password : ");
	char ge[20];
	getp(ge);
	if(strcmp(ge,"flight")==0)
	{
		clrscr();
		textcolor(15);
		char ch[10],ar='y';
		outerborder(20,8,65,17,41,2.5,20);
		gotoxy(28,12);
		textcolor(15);
		cprintf("  Enter the Flight Code ");
		gotoxy(28,13);
		cprintf("whose records to be changed : ");
		gets(ch);
		fstream f1,f;
		f.open("flights.txt",ios::binary|ios::in);
		f1.open("tempo.txt",ios::binary|ios::out);
		f.seekg(0);
		while(f.read((char*)&d,sizeof(d)))
		{
			if(strcmp(ch,d.code)!=0)
				f1.write((char*)&d,sizeof(d));
		}
		f1.close();
		f.close();
		remove("flights.txt");
		rename("tempo.txt","flights.txt");
		fstream f3;
		f3.open("flights.txt",ios::binary|ios::app);
		d.input();
		f3.write((char*)&d,sizeof(d));
		f3.close();
		clrscr();
		innerborder(20,8,65,17,45,2.5,20);
		gotoxy(30,10);
		cprintf("Press Y/N : ");
		cin>>ar;
		clrscr();
		if(ar=='y'||ar=='Y')
			changerecords();
	}
	else
	{
		textcolor(15);
		gotoxy(27,12);
		cprintf("INVALID PASSWORD");
	}
}

void database :: deleterecord()   //function to delete flight record from file
{
	innerborder(20,8,50,16,35,1.8,20);
	gotoxy(25,12);
	textcolor(15);
	cprintf("Enter Password : ");
	char ge[20];
	int a=0;
	getp(ge);
	if(strcmp(ge,"flight")==0)
	{
		clrscr();
		outerborder();
		textcolor(15);
		char ch[10],ar='y';
		gotoxy(20,8);
		cprintf("Enter code to be deleted : ");
			gets(ch);
		fstream f1,f;
		f.open("flights.txt",ios::binary|ios::in);
		f1.open("tempo.txt",ios::binary|ios::out);
		f.seekg(0);
		while(f.read((char*)&d,sizeof(d)))
		{
			if(strcmp(ch,d.code)!=0)
			{
				f1.write((char*)&d,sizeof(d));
				a++;
			}
			else
			{
				gotoxy(25,10);
				cout<<"Code "<<d.code<<" is deleted\n\n";
			}
		}
		if(a==0)
		{
			gotoxy(25,10);
			cprintf("Wrong Flight Code");
		}
		f1.close();
		f.close();
		remove("flights.txt");
		rename("tempo.txt","flights.txt");
		gotoxy(25,12);
		textcolor(11);
		cprintf("Press Y/N : ");
		cin>>ar;
		clrscr();
		if(ar=='y'||ar=='Y')
			d.deleterecord();
	}
	else
	{
		textcolor(15);
		gotoxy(27,12);
		cprintf("INVALID PASSWORD");
	}
}

void database :: display1(int b,char clas[]) //function to display flight details
					     //according to user requirements
{
	static int c=9;
	gotoxy(6,c); cout<<b;
	gotoxy(13,c);cout<<company;
	gotoxy(25,c);cout<<depcity;
	gotoxy(37,c);cout<<arrcity;
	gotoxy(50,c);cout<<deptime;
	if(strcmpi(clas,"Economy")==0)
	{
		gotoxy(63,c);
		cout<<ecprice;
	}
	else if(strcmpi(clas,"BUSINESS")==0)
	{
		gotoxy(63,c);
		cout<<buprice;
	}
	gotoxy(73,c);cout<<code;
	c+=2;
}

void database :: f1record()     //function to take flight details from user
{
	clrscr();
	char dep[30],arr[30],clas[20],code1[10];
	outerborder(24,3,65,15,58,1.9,10);
	textcolor(15);
	gotoxy(27,6);   cprintf("Enter DEPARTURE City : ");
	gotoxy(27,8);   cprintf("Enter ARRIVAL City : ");
	gotoxy(27,10);   cprintf("Enter Class of Plane : ");
	gotoxy(27,12);  cprintf("(ECONOMY or BUSINESS) : ");
	textcolor(10);
	gotoxy(51,6);  gets(dep);
	gotoxy(51,8);  gets(arr);
	gotoxy(51,10);  gets(clas);
	processing();
	clrscr();
	fstream f;
	f.open("flights.txt",ios::binary|ios::in);
	int b=1;
	f.seekg(0);
	while(f.read((char*)&d,sizeof(d)))
	{
		if(strcmpi(d.depcity,dep)==0&&strcmpi(d.arrcity,arr)==0)
		{
			showflight();
			d.display1(b,clas);
				b++;
		}
	}
	f.close();
	if(b==1)
	{
		gotoxy(5,5);
		cprintf("NO FLIGHTS AVAILABLE");
		gotoxy(10,10);
		cprintf("TRY AGAIN PRESS ANY KEY");
		getch();
		d.f1record();
	}
	int a=0,book;
	gotoxy(10,21);cout<<"Enter the Flight Code from Above List : ";
	gets(code1);
	clrscr();
	f.open("flights.txt",ios::binary|ios::in);
	f.seekg(0);
	while(f.read((char*)&d,sizeof(d)))
	{
		if(strcmpi(d.code,code1)==0)
		{
			textcolor(15);
			d.display();
			a=d.seats;
		}
	}
	f.close();
	gotoxy(10,20);
	textcolor(11);
	cprintf("Press Enter To Book The Flight ");
	book=getch();
	clrscr();
	if(book==13)
		r.flightreserve(dep,arr,clas,a,code1);
}

void database :: cost(int a,int c,char code1[],char clas[])
{            //function to access cost1 function to display total cost
	fstream f;
	f.open("flights.txt",ios::binary|ios::in);
	f.seekg(0);
	while(f.read((char*)&d,sizeof(d)))
	{
		if(strcmp(d.code,code1)==0)
		{
			if(strcmpi(clas,"ECONOMY")==0)
				r.cost1(a,c,d.ecprice,d.childprice);
			else if(strcmpi(clas,"BUSINESS")==0)
				r.cost1(a,c,d.buprice,d.childprice);
		}
	}
}

void database :: seat(int a,int c,char code1[])
{             //function to reduce seats after booking
	fstream f1;
	f1.open("flights.txt",ios::binary|ios::out);
	f1.seekp(0);
	while(f1.read((char*)&d,sizeof(d)))
	{
		if(strcmp(code,code1)==0)
		{
			seats=seats-(a+c);
			f1.write((char*)&d,sizeof(d));
		}
	}
	f1.close();
}

void reserve :: input(char dep[],char arr[],char clas[],int &a,int &b,long code1)
{            //funciton to input general by user
       clrscr();
       innerborder(24,3,59,15,58,1.9,10);
       textcolor(15);
       gotoxy(27,6);     cprintf("Number of Adults   :");
       gotoxy(27,8);     cprintf("Number of Children : ");
       gotoxy(27,9);     cprintf("(2-11 years)");
       gotoxy(27,11);    cprintf("Number of Infants  : ");
       gotoxy(27,12);    cprintf("(Under 2 years)");
       textcolor(13);
       gotoxy(49,6);     cin>>nadult;
       gotoxy(49,8);     cin>>nchild;
       gotoxy(49,11);    cin>>ninfant;
       strcpy(departcity,dep);
       strcpy(arrivecity,arr);
       strcpy(clatravel,clas);
       a=nadult;
       b=nchild;
       code=code1;
}

void reserve :: flightreserve(char dep[],char arr[],char clas[],int b,char code1[])
{
	//function to access different functions according to the condition
	int a=0,c=0;
	long ar;
	textcolor(15);
	ar=randm(ar);
	f.open("passengers.txt",ios::binary|ios::app);
	r.input(dep,arr,clas,a,c,ar);
	f.write((char*)&r,sizeof(r));
	if(b>=(a+c))
	{
		p.passreserve(a,c);
		d.cost(a,c,code1,clas);
		d.seat(a,c,code1);
	}
	else
		cout<<"Required Number of SEATS are not Available";
	f.close();
}

void reserve::cost1(float a,float c,float aprice,float cprice)
{
	//function to calculate cost and display to the user
	float x,y,z;
	x=aprice*a;
	y=cprice*c;
	getch();
	clrscr();
	innerborder(6,6,70,18,41,3,10);
	textcolor(15);
	gotoxy(30,8);
		cprintf("TRANSACTION");
	gotoxy(8,13);
		cprintf("TOTAL COST OF ");
		cout<<a;
		cprintf(" ADULT : ");
		cout<<x;
	gotoxy(8,14);
		cprintf("TOTAL COST OF ");
		cout<<a;
		cprintf(" CHILDREN : ");
		cout<<x;
	gotoxy(8,15);
		cprintf("Total Payable Amount : ");
	z=x+y;
	cout<<z;
	getch();
	fstream f1;
	f1.open("pass1.txt",ios::binary|ios::out);
	r.cost=z;
	f1.write((char*)&p,sizeof(p));
	f1.close();
}

void passdetails::input1(long &ar) //function to input details of user
{
	outerborder(22,6,64,20,58,2,10);
	textcolor(15);
	gotoxy(26,8);    cprintf("NAME         : ");
	gotoxy(26,10);   cprintf("SEX          : ");
	gotoxy(26,12);   cprintf("AGE          : ");
	gotoxy(26,14);   cprintf("ADDRESS      : ");
	gotoxy(26,16);   cprintf("PHONE NUMBER : ");
	gotoxy(26,18);   cprintf("Email        : ");
	gotoxy(41,8);    gets(name);
	gotoxy(41,10);   gets(sex);
	gotoxy(41,12);   cin>>age;
	gotoxy(41,14);   gets(add);
	gotoxy(41,16);   gets(phone);
	gotoxy(41,18);   gets(email);
	ar++;
	code=ar;
}

void passdetails :: display1()  //function to display details inputted by user
{
	clrscr();
	getch();
	outerborder(22,6,64,21,58,2,10);
	textcolor(15);
	gotoxy(26,8);    cprintf("NAME         : ");
	gotoxy(26,10);   cprintf("SEX          : ");
	gotoxy(26,12);   cprintf("AGE          : ");
	gotoxy(26,14);   cprintf("ADDRESS      : ");
	gotoxy(26,16);   cprintf("PHONE NUMBER : ");
	gotoxy(26,18);   cprintf("Email        : ");
	gotoxy(26,20);   cprintf("Code         : ");
	gotoxy(41,8);    cout<<name;
	gotoxy(41,10);   cout<<sex;
	gotoxy(41,12);   cout<<age;
	gotoxy(41,14);   cout<<add;
	gotoxy(41,16);   cout<<phone;
	gotoxy(41,18);   cout<<email;
	gotoxy(41,20);   cout<<code;
}

void passdetails :: passreserve(int a,int c)  //function to store user details in DFH file
{
	//a=no. of adults ,c=no. of chlidern
	clrscr();
	long co;
	co=randm(co);
	fstream f;
	f.open("passen.txt",ios::binary|ios::app);
	for(int i=1;i<=a;i++)
	{
		gotoxy(8,3);
		textcolor(15);
		cprintf("Enter the Details of ");
		cout<<i;
		cprintf(" ADULT : ");
		p.input1(co);
		f.write((char*)&p,sizeof(p));
		gotoxy(15,22);
		textcolor(15);
		cprintf("Kindly Note Down Your RESERVATION CODE");
		gotoxy(25,23);
		cout<<co;
		getch();
		clrscr();
	}
	for(i=1;i<=c;i++)
	{
		gotoxy(8,3);
		textcolor(15);
		cprintf("Enter the Details of ");
		cout<<i;
		cprintf(" CHILD : ");
		p.input1(co);
		f.write((char*)&p,sizeof(p));
		gotoxy(15,22);
		textcolor(15);
		cprintf("Kindly Note Down Your RESERVATION CODE");
		gotoxy(25,23);
		cout<<co;
		getch();
		clrscr();
	}
	f.write((char*)&p,sizeof(p));
	f.close();
	gotoxy(10,10);
	textcolor(13);
	cprintf("*******************************");
	gotoxy(10,12);
	textcolor(14);
	cprintf("!!!!Your SEATS are Reserved!!!!");
	gotoxy(10,14);
	textcolor(13);
	cprintf("*******************************");
}

void passdetails :: passrecords()  //function to display user details according to user
{
	long ar;
	gotoxy(3,3);
	cout<<"Enter your RESERVATION CODE : ";
	cin>>ar;
	f.open("passen.txt",ios::binary|ios::in);
	while(f.read((char*)&p,sizeof(p)))
	{
		if(ar==code)
			p.display1();
	}
	f.close();
}

void passdetails :: passcancel()   //function to cancel user booking
{
	char ar='y';
	long co;
	int a=0;
	textcolor(15);
	gotoxy(20,8);
	cprintf("Enter the Reservation Code : ");
	cin>>co;
	fstream f,f1;
	f.open("passen.txt",ios::binary|ios::in);
	f1.open("tempo2.txt",ios::binary|ios::out);
	f.seekg(0);
	while(f.read((char*)&p,sizeof(p)))
	{
		if(code!=co)
		{
			f1.write((char*)&p,sizeof(p));
			a++;
		}
		else
		{
			gotoxy(25,10);
			cout<<"Reservation for "<<p.code<<" is Cancelled\n\n";
		}
	}
	if(a==0)
	{
		gotoxy(10,10);
		textcolor(14);
		cprintf("Wrong Reservation Code");
	}
	f1.close();
	f.close();
	remove("passen.txt");
	rename("tempo2.txt","passen.txt");
	getch();
	clrscr();
	gotoxy(10,12);
	cprintf("Press Y/N : ");
	cin>>ar;
	clrscr();
	if(ar=='y'||ar=='Y')
		p.passcancel();
}
void database :: frecords()  //function to display all flight records
{
	char ar[20];
	innerborder(20,8,50,16,35,1.8,20);
	gotoxy(25,12);
	textcolor(15);
	cprintf("Enter Password : ");
	getp(ar);
	if(strcmp(ar,"flight")==0)
	{
		getch();
		textcolor(15);
		f.open("flights.txt",ios::binary|ios::in);
		f.seekg(0);
		while(f.read((char *)&d,sizeof(d)))
		{
			d.display();
			getch();
		}
		f.close();
	}
	else
	{
		gotoxy(27,12);
		cprintf("INCORRECT PASSWORD");
	}
}

void pr2(int c)    //function to access all functions according to the given conditions
{
	x:
	char ar='Q';
	outerborder(24,3,59,23,58,1.5,15);
	innerborder(2,2,79,24,41,2,10);
	pr1(c);
	if(c==10)
	{       clrscr();
		outerborder();
		d.existing();
		clrscr();
		innerborder(10,8,70,20,40,2,20);
		gotoxy(14,12);
		textcolor(14);
		cprintf("Enter 'Q' to back to the Main Menu : ");
		cin>>ar;
		clrscr();
		if(ar=='Q'||ar=='q')
			goto x;
	}
	else if(c==11)
	{       clrscr();
		textcolor(15);
		outerborder();
		d.addflight();
		clrscr();
		innerborder(10,8,70,20,40,2,20);
		gotoxy(14,12);
		textcolor(14);
		cprintf("Enter Q to back to the Main Menu : ");
		cin>>ar;
		clrscr();
		if(ar=='Q'||ar=='q')
			goto x;
	}
	else if(c==12)
	{
		clrscr();
		outerborder();
		d.changerecords();
		clrscr();
		innerborder(10,8,70,20,40,2,20);
		gotoxy(14,12);
		textcolor(14);
		cprintf("Enter Q to back to the Main Menu : ");
		cin>>ar;
		clrscr();
		if(ar=='Q'||ar=='q')
			goto x;
	}
	else if(c==13)
	{
		clrscr();
		outerborder();
		d.deleterecord();
		clrscr();
		innerborder(10,8,70,20,40,2,20);
		gotoxy(14,12);
		textcolor(14);
		cprintf("Enter Q to back to the Main Menu : ");
		cin>>ar;
		clrscr();
		if(ar=='Q'||ar=='q')
			goto x;
	}
	else if(c==14)
	{
		clrscr();
		outerborder();
		d.f1record();
		clrscr();
		innerborder(10,8,70,20,40,2,20);
		gotoxy(14,12);
		textcolor(14);
		cprintf("Enter Q to back to the Main Menu : ");
		cin>>ar;
		clrscr();
		if(ar=='Q'||ar=='q')
			goto x;
	}
	else if(c==15)
	{
		clrscr();
		outerborder();
		p.passcancel();
		getch();
		clrscr();
		innerborder(10,8,70,20,40,2,20);
		textcolor(14);
		gotoxy(14,12);
		cprintf("Enter Q to back to the Main Menu : ");
		cin>>ar;
		clrscr();
		if(ar=='Q'||ar=='q')
			goto x;
	}
	else if(c==16)
	{
		clrscr();
		outerborder();
		p.passrecords();
		getch();
		clrscr();
		innerborder(10,8,70,20,40,2,20);
		gotoxy(14,12);
		textcolor(14);
		cprintf("Enter Q to back to the Main Menu : ");
		cin>>ar;
		clrscr();
		if(ar=='Q'||ar=='q')
			goto x;
	}
	else if(c==17)
	{
		clrscr();
		d.frecords();
		clrscr();
		innerborder(10,8,70,20,40,2,20);
		gotoxy(14,12);
		textcolor(14);
		cprintf("Enter Q to back to the Main Menu : ");
		cin>>ar;
		clrscr();
		if(ar=='Q'||ar=='q')
			goto x;
	}
	else if(c==19||c==18)
		exit(0);
}

void main ()
{
	randomize();
	clrscr();
	int c=0;
	_setcursortype(_NOCURSOR);  //changes the appearence of cursor
	frontpage();
	pr2(c);//to call menu function
	getch();
}