#include<conio.h>
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include <malloc.h>
#include <string.h>
#include<time.h>
void create_account();
void DeleteAcc();
void Display();
void search();
void withdraw();
void Deposit_Amount();
void check_balance();
void total_customer();
void update_acc();
using namespace std;
SYSTEMTIME stime;
struct bank
{
long long int acc_no;
float deposit;
char acctype[20];
char name[20];
char father[20];
char mother[20];
char nationality[20];
char dob[20];
char date[20];
long long int phone;
long long int adhar;
char emailid[30];
char address[50];
struct bank *next;
};
struct bank *firstc=0,*currentc=0,*newc=0;
long long int countroll=350245100;

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
int main()
{
    FILE *datafile;
    char ch;
    firstc = NULL;
    datafile = fopen("contactdatabase.dat","r");

    if(datafile)
    {
	    firstc =(struct bank *)malloc(sizeof(struct bank));
	    currentc = firstc;
	    while(1)
     	    {
		    newc = (struct bank*)malloc(sizeof(struct bank));
		    fread(currentc,sizeof(struct bank),1,datafile);
		    if(currentc->next == NULL)
			    break;
		    currentc->next = newc;
		    currentc = newc;
	    }
	    fclose(datafile);
    }

    GetSystemTime(&stime);
	int a=1,i;
	while(a)
	{
	system("cls");
	string user,pass;
	system("color 9");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t WELLCOME  IN  BANK  OF  BARODRA  MANGLORE");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Enter Login Username:  ";
	fflush(stdin);
	cin>>user;
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t Enter Login Password:  ";
	fflush(stdin);
	cin>>pass;
	if(pass=="194046" && user=="Lavkush")
	{
		system("cls");
		system("color 9");
	    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t PASSWORD MATCHING LOADING");
        for(i=0;i<=8;i++)
        {
            fordelay(100000000);
            printf(".");
        }
	while(1)
	{
	system("cls");
	system("color 9");
	cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------------------";
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tWELLCOME IN THE MAIN MENU";
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t------------------------------------------";
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t01. Create New Account";
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t02. Search Customer Details\n\n\t\t\t\t\t\t\t\t\t\t\t03. Display List All Account";
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t04. Close Account\n\n\t\t\t\t\t\t\t\t\t\t\t05. Withdraw Amount";
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t06. Deposit Amount\n\n\t\t\t\t\t\t\t\t\t\t\t07. Check Balance";
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t08. Total Customer\n\n\t\t\t\t\t\t\t\t\t\t\t09. Update Customer Detail";
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t10. Exit";
	int a;
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tEnter your choice:  ";
	cin>>a;
	switch(a)
	{
		case 1:
			create_account();
			break;
		case 2:
			search();
			break;
		case 3:
			Display();
			break;
		case 4:
			DeleteAcc();
			break;
		case 5:
			withdraw();
			break;
		case 6:
			Deposit_Amount();
			break;
		case 7:
			check_balance();
			break;
		case 8:
			total_customer();
			break;
		case 9:
			update_acc();
			break;
		case 10:
            currentc = firstc;
            if(currentc == NULL)
	        return(0);
            datafile = fopen("contactdatabase.dat","w");
            while(currentc != NULL)
            {
	          fwrite(currentc,sizeof(struct bank),1,datafile);
	          currentc = currentc->next;
            }
             fclose(datafile);
			 exit(0);
		default:
				cout<<"Wrong Option ";
				getch();
		}
	}
}
  else
  {
	    system("cls");
	    system("color 9");
    	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t PASSWORD MATCHING LOADING");
        for(i=0;i<=8;i++)
        {
            fordelay(100000000);
            printf(".");
        }
	 cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t Wrong Password  ";
  }
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t Press 1 For Again Try Otherwise 0: ";
    cin>>a;
  }
}

void create_account()
{
	system("COLOR E");
	currentc = firstc;
	while(currentc!=0)
	{
	countroll++;
	currentc=currentc->next;
    }
	system("cls");
    newc = (struct bank *)malloc(sizeof(struct bank));
    if(firstc==NULL)
      firstc = currentc = newc;
    else
    {
        currentc = firstc;
        while(currentc->next != NULL)
		currentc = currentc->next;
        currentc->next = newc;
        currentc = newc;
    }
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t--------------Enter Customer Details-------------------\n";
	currentc->acc_no=countroll;
	fflush(stdin);
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer  Name:         ";
	gets(currentc->name);
	fflush(stdin);
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\tAccount Opening Date:         ";
	gets(currentc->date);
	fflush(stdin);
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tEnter Account Type:           ";
	gets(currentc->acctype);
	fflush(stdin);
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer Father Name:   ";
	gets(currentc->father);
	fflush(stdin);
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer Mother Name:   ";
	gets(currentc->mother);
	fflush(stdin);
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer Nationality:   ";
	gets(currentc->nationality);
	fflush(stdin);
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer D.O.B:         ";
	gets(currentc->dob);
	fflush(stdin);
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer Phone:         ";
	cin>>currentc->phone;
	fflush(stdin);
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer Adhar Number:  ";
	cin>>currentc->adhar;
	fflush(stdin);
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer Email Id:      ";
	gets(currentc->emailid);
	fflush(stdin);
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer Address:       ";
	gets(currentc->address);
	fflush(stdin);
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tEnter Deposit Amount Rs:      ";
	cin>>currentc->deposit;
	fflush(stdin);
    currentc->next = NULL;
    system("cls");
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Successfuly Created "<<"\n";
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tYour Account Number:  "<<countroll<<"\n";
	getch();
}

void Display()
{
	int a=0;
	system("COLOR A");
	int cn=0;
	system("cls");
       if(firstc==NULL)
       {
   	   system("cls");
        cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tNo Any Record Avalibale ";
        getch();
        return;
		 }
    else
    {
        currentc=firstc;
        do
        {
        	a++;
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t--------------Customer Details:-" <<a<<"---------------\n";
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Account Number:   %lld",currentc->acc_no);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Name:             %s",currentc->name);
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Account Type:              %s",currentc->acctype);
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Account Opening Date:      %s",currentc->date);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Coustomer Father Name:     %s",currentc->father);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Mother Name:      %s",currentc->mother);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Nationality:      %s",currentc->nationality);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer D.O.B:            %s",currentc->dob);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Phone Number:     %lld",currentc->phone);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Adhar Number:     %lld",currentc->adhar);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Email Id:         %s",currentc->emailid);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Address:          %s",currentc->address);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Total Amount Rs:           %.2f",currentc->deposit);

        }while((currentc=currentc->next) != NULL);
    }
    getch();
}

void DeleteAcc()
{
	system("COLOR 4");
	system("COLOR 4");
	system("cls");
    long long int key;
    int cnt=0;
    struct bank *previousa;
    if(firstc==NULL)
    {
    system("cls");
    cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t No Any Record Avalibale  "<<"\n";
    getch();
    return;
    }
    cout<<"\n\n\t\t\t\t\t\t\t\t\tEnter Account Number:  ";
	cin>>key;
    currentc = firstc;

    while(currentc != NULL)
    {
        if(currentc->acc_no == key)
	    {
	    if(currentc == firstc)
		firstc=currentc->next;
	    else
		previousa->next = currentc->next;
        free(currentc);
	    cout<<"\n\n\t\t\t\t\t\t\t\t\tAccount Scussfully Close\n";
	    cnt++;
	    getch();
	    return;
	}
	else{
        previousa = currentc;
	    currentc = currentc->next;
	  }
    }
    if(cnt==0)
	{
    system("cls");
    cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tRecord Not Avalibale  "<<"\n";
	getch();
	return;
	}
 }

void search()
{
	system("COLOR 5");
    int cnt=0;
	system("cls");
	currentc = firstc;
	if(firstc==0)
	{
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tNo Any Record Avalibale  ";
	getch();
    return;
	}
	long long int key;
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Account Number:  ";
	cin>>key;
	currentc = firstc;
    while(currentc != NULL)
    {
        if(currentc->acc_no==key)
	    {
	    system("cls");
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t--------------Customer Details---------------\n";
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Account Number:   %lld",currentc->acc_no);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Name:             %s",currentc->name);
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Account Type:              %s",currentc->acctype);
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Account Opening Date:      %s",currentc->date);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Coustomer Father Name:     %s",currentc->father);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Mother Name:      %s",currentc->mother);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Nationality:      %s",currentc->nationality);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer D.O.B:            %s",currentc->dob);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Phone Number:     %lld",currentc->phone);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Adhar Number:     %lld",currentc->adhar);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Email Id:         %s",currentc->emailid);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Address:          %s",currentc->address);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Total Amount Rs:           %.2f",currentc->deposit);
		cnt++;
		getch();
		return;
		}
		currentc = currentc->next;
	}
	getch();
	if(cnt==0)
	{
    system("cls");
    cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tRecord Not Avalibale  ";
	getch();
	}
}

void update_acc()
{
	system("COLOR C");
        system("cls");
        int a,cnt=0;
	    long long int key;
    currentc = firstc;
	if(firstc==0)
	{
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t No Any Record Avalibale  ";
    getch();
    return;
    }
    else
    {
    	cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Account Number:  ";
	    cin>>key;
    	while(currentc!=0)
	    {
	     if(currentc->acc_no==key)
	     {
    	system("cls");
    	cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------------------";
	    cout<<"\n\t\t\t\t\t\t\t\t\t\t\tWELLCOME IN THE UPDATE MENU";
	    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t------------------------------------------";
	    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 01. Customer Name:          ";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 02. Account Type:           ";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 03. Account Opening Date:   ";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 04. Coustomer Father Name:  ";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 05. Customer Mother Name:   ";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 06. Customer Nationality:   ";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 07. Customer D.O.B:         ";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 08. Customer Phone Number:  ";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 09. Customer Adhar Number:  ";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 10. Customer Email Id:      ";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 11. Customer Address:       ";
	    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Enter Update Option:        ";
	   cin>>a;
    switch(a)
    {
	case 1:
		system("cls");
	     cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer  Name:  ";
	     fflush(stdin);
	     gets(currentc->name);
	     cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Update Successfull  ";
	     break;
	case 2:
		system("cls");
	     cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Account Type :    ";
	     fflush(stdin);
	     gets(currentc->acctype);
	     cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Update Successfull  ";
	     break;
	case 3:
		system("cls");
	     cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Opening Date:  ";
	     fflush(stdin);
	     gets(currentc->date);
	     cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Update Successfull  ";
	     break;
	case 4:
		system("cls");
	      cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer Father Name:  ";
	      fflush(stdin);
	      gets(currentc->father);
	      cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Update Successfull  ";
	      break;
	case 5:
		system("cls");
	     cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer Mother Name:  ";
	     fflush(stdin);
       	gets(currentc->mother);
       	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Update Successfull  ";
	    break;
	case 6:
		system("cls");
	     cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer Nationality:  ";
	     fflush(stdin);
	     gets(currentc->nationality);
	     cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Update Successfull  ";
	     break;
	case 7:
		system("cls");
	     cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer D.O.B:  ";
	     fflush(stdin);
	     gets(currentc->dob);
	     cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Update Successfull  ";
	     break;
	case 8:
		system("cls");
       	cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer Phone:  ";
       	fflush(stdin);
    	cin>>currentc->phone;
    	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Update Successfull  ";
	    break;
	case 9:
		system("cls");
	     cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer Adhar Number:  ";
	     fflush(stdin);
	     cin>>currentc->adhar;
	     cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Update Successfull  ";
	     break;
    case 10:
    	system("cls");
	     cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer Email Id:  ";
	     fflush(stdin);
	     gets(currentc->emailid);
	     cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Update Successfull  ";
	     break;
	case 11:
		system("cls");
	      cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Customer Address:  ";
	      fflush(stdin);
	      gets(currentc->address);
	      cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Update Successfull  ";
	      break;
    }

	   getch();
	   return;
    }
    currentc = currentc->next;
}
   	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Number Not Exist "<<"\n";
   	getch();
   	return;
 }
}

void withdraw()
{
	system("COLOR 2");
	system("cls");
    long long int key;
    double amount,cnt=0;
    currentc = firstc;
	if(firstc==0)
	{
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tNo Any Record Avalibale  ";
	getch();
    return;
	}
	else
	{
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Enter Account Number:  ";
	cin>>key;
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Enter Amount:          ";
	cin>>amount;
	while(currentc!=0)
	{
	 if(currentc->acc_no==key)
   	{
		if(currentc->deposit<amount)
	   {
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Insufficient Balance";
		cnt++;
		getch();
		return;
	   }
	   else
	   {
		currentc->deposit=currentc->deposit-amount;
		system("cls");
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Withdraw Successful:";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Account Number:    "<<currentc->acc_no;
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Name:     "<<currentc->name;
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Withdraw amount:   "<<amount;
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Avalabile Balance: "<<currentc->deposit;
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Withdraw Date : %d/%d/%d",stime.wDay,stime.wMonth,stime.wYear);
		cnt++;
		getch();
		return;
	  }
}
  currentc=currentc->next;
}
 }
 if(cnt==0)
     {
     cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Account Not Avalibale  ";
	 getch();
	 return;
    }
}

void Deposit_Amount()
{
	system("COLOR 6");
	char name1[20];
	system("cls");
	long long int key;
    int amount=0,cnt=0;
	 currentc = firstc;
	if(firstc==0)
	{
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tNo Any Record Avalibale  ";
	getch();
    return;
	}
	else
	{
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Enter Account Number:  ";
	cin>>key;
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Enter Customer Nmae:   ";
	fflush(stdin);
	gets(name1);
	fflush(stdin);
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Enter Deposit Date:    ";
	gets(currentc->date);
	fflush(stdin);
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Enter Amount:          ";
	fflush(stdin);
	cin>>amount;
	while(currentc!=0)
	{
	if(currentc->acc_no==key && strcmp(currentc->name,name1) == 0)
	{
		currentc->deposit=currentc->deposit+amount;
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Deposit Successful:  ";
		cnt++;
		getch();
		return;
	}
	currentc=currentc->next;
}
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Not Avalibale  ";
	getch();
}
}

void check_balance()
{
	system("COLOR D");
	int cnt=0;
	system("cls");
    long long int key;
	currentc = firstc;
	if(currentc==0)
	{
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tNo Any Record Avalibale  ";
	getch();
    return;
	}
	else
	{
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Enter Account Number:  ";
	cin>>key;
	while(currentc!=0)
    {
	if(currentc->acc_no==key)
	{
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Account Number:  "<<currentc->acc_no;
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Customer Name:   "<<currentc->name;
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Total Balance:   %.2f",currentc->deposit);
		cnt++;
		getch();
		return;
	}
	currentc=currentc->next;
}
    system("cls");
    cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tAccount Not Avalibale  ";
	getch();
	return;
  }
}
void total_customer()
{
	system("COLOR 7");
	int count=0;
	system("cls");
    currentc = firstc;
	if(currentc==0)
	{
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tNo Any Record Avalibale  ";
	getch();
    return;
	}
    else
    {
	while(currentc!=0)
	{
		currentc=currentc->next;
		count++;
	}
	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t--------------------------";
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t Total Customer: "<<count;
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t--------------------------";
	getch();
    }
}

