#include "functions.h"
int i=0,valid=0;// global variable for validation
char Esc=0x1b;// definition for ESC key
char choice=0;// global char choice for switch
int target=0;
int search=0;
int found=0;


FILE *fz,*tz;

struct customer
{
	
char full_name[20];
char address[40];
char gender;
char date[20];
char time;
int id;
int age;
char contact[10];
int room;
}ad,nw;
//list of global variable
void menu()
{
	system("cls");
	int select;
	printf("\n\n******************* DATA RECORDS *********************");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2	1. Add Records      \xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB  \n\n");
	printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2	2. Delete Records   \xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB  \n\n");
	printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2	3. Search Records   \xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB  \n\n");
	printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2	4. View Records     \xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB  \n\n");
	printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2	5. Update Info	    \xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB  \n\n");
	printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2	6. Room	            \xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB  \n\n");
	printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2	7. Exit	            \xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB  \n\n");
	
	printf(" Choose a given number to proccedefurthur : ");
	scanf("%i",&select);
	switch(select)
	{
		case 1:
			add();
			break;
			
		case 2:
			remove_record();
			break;
		
		case 3:
			find();
			break;
		
		case 4:
			p_list();
			break;
		
		case 5:
			edit();
			break;
		
		case 6:
			room();	
			break;
		
		case 7:
			exitt();
			break;
		
		default:
			printf("\nInvalid entry!!! Input a number between given choice.");
			getch();
			menu();
			
	}
}


void add()
{
	system("cls");
	printf("\n\n \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB   ENTER DETAILS   \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB \n\n");
	
	FILE *fz;
	fz=fopen("D:\\Assignment.dat","a");	
	printf("\n");


	I:
	if((fz = fopen("D:\\Assignment.dat","r+"))!=NULL)// chechs if the file is empty
	{
	printf("\n ID         : ");
		scanf("%i",&nw.id);
		while(fscanf(fz,"%i %s %s %i %c %s %s %i \n",&ad.id,ad.full_name,ad.address,&ad.age,&ad.gender,ad.contact,ad.date,&ad.room)!=EOF)// retrieve the data unitl the pointer reaches the end
		{
			if(nw.id == ad.id)// if inputted number matches the ad.id
			{
				printf("\n The id number already exist.\n");
				goto I;
			}
		}
		ad.id = nw.id;
	}
	else
	{
		printf("\n ID         : ");
		scanf("%i",&ad.id);	
	}
	printf("\n");
	
	fflush(stdin);
	printf(" Name       : ");
	name_valid_check();
	printf("\n");
	
	fflush(stdin);
	printf(" Address    : ");
	fflush(stdin);
	gets(ad.address);
	printf("\n");
	
	fflush(stdin);
	printf(" Age        : ");
	scanf("%i",&ad.age);
	printf("\n");
	
	fflush(stdin);
	printf(" Gender     : ");
	scanf("%c",&ad.gender);
	printf("\n");
	
	printf(" Contact No : ");
	fflush(stdin);
	gets(ad.contact);
	printf("\n");
	
	printf(" Room No    : ");
	scanf(" %i",&ad.room);
	printf("\n");
	printf("\n");
	
	fprintf(fz,"%i %s %s %i %c %s %i \n",ad.id,ad.full_name,ad.address,ad.age,ad.gender,ad.contact,ad.room);
	fclose(fz);
	printf("\n\n");
	printf(" \xDB\xDB\xDB\xDB\xDB\xDB DATA RECORDED SUCCESSFULLY \xDB\xDB\xDB\xDB\xDB\xDB \n\n");
	
	getch();
	menu();
}

void name_valid_check()
{
	int valid, index;
	N://loop untill the string contain valid character
	do
	{
		fflush(stdin);
		gets(ad.full_name); // get input string
		//iterate for every character in string
		for (index=0; index<strlen(ad.full_name); ++index)
		{	//check if character is valid or not
			if(isalpha(ad.full_name[index]))
				valid = 1;
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf(" Name contain invalid character. Please enter again\n\n");
			getch();
			printf(" Name       : ");
			goto N;	
		}
	}while(!valid);	//while end here
}//function input_string ends here

void p_list()
{
	system("cls");
	FILE*fz;
	fz=fopen("D:\\Assignment.dat","r");
	printf("\n\n\n\n%-5s |"," ID ");// information design for listing the data
	printf(" %-15s |","Full Name");
	printf(" %-15s |","Address");
	printf(" %-4s |","Age");
	printf(" %-6s |","Gender");
	printf(" %-10s |","Phone No");
	printf("%-4s ","Room NO");
	printf("================================================================================\n");
	while(fscanf(fz,"%i %s %s %i %s %s %i",&ad.id,ad.full_name,ad.address,&ad.age,&ad.gender,ad.contact,&ad.room)!=EOF)
	{
		printf(" %-5i|",ad.id);
		printf(" %-15s |",ad.full_name);
		printf(" %-15s |",ad.address);
		printf(" %-4i |",ad.age);
		printf(" %-6s |",&ad.gender);
		printf(" %-10s |",ad.contact);
	printf(" %-4i ",ad.room);
	printf("\n");
	}
	
	
	fclose(fz);
	printf("\n\n Enter any key to return to Main Menu...");
getch();
menu();
}

void find()
{
	system("cls");
	FILE *fz;// file pointer for Shipment.txt
	fz = fopen("d:\\Assignment.dat","r");
	printf("\n Enter patient ID : ");
	scanf("%i",&target);
	while(fscanf(fz,"%i %s %s %i %c %s %i",&ad.id,ad.full_name,ad.address,&ad.age,&ad.gender,ad.contact,&ad.room)!=EOF)// reading the data until the end of cursor
	{
		if(target==ad.id)// if target matches the s.sno from the file then following lines are executed
		{
			printf("\n Record Found.\n");
			printf("\n ID        \t: %i",ad.id);
			printf("\n Name      \t: %s",ad.full_name);
			printf("\n Address   \t: %s",ad.address);
			printf("\n Age       \t: %i",ad.age);
			printf("\n Gender    \t: %c",ad.gender);
			printf("\n Contact No\t: %s",ad.contact);
			printf("\n Room NO   \t: %i",ad.room);
		}
	}
	if(target!=ad.id)// if target is not found 
	{
		
		printf("\n NO RECORD FOUND.");
	}
	fclose(fz);// closing the file sfile
	
	printf("\n\n Press any key to continue...");
	getch();
	menu();
}

void id_valid_check()
{
	int id,no;
	FILE *fz;
	fz = fopen("D:\\Assignment.dat","r");
	
	I:
	if((fz = fopen("d:\\Assignment.dat","r+"))!=NULL)// chechs if the file is empty
	{
		printf("\t\t\tID :");
		scanf("%i",&ad.id);
			while(fscanf(fz,"%i %s %s %i %c %s %i",&ad.id,ad.full_name,ad.address,&ad.age,&ad.gender,ad.contact,&ad.room)!=EOF)// retrieve the data unitl the pointer reaches the end
		{
			if(no==ad.id)// if inputted number matches the ad.id
			{
				printf("\n ID already exist.Please type another ID.");
				
				goto I;
			}
		}
		ad.id=no;
	}
	else
	{
		printf("\n\t\tID : ");
		scanf("%i",&ad.id);	
	}
}


void remove_record()
{
	int found =0;
	system("cls");
	FILE *fz, *tz;
	fz = fopen("d:\\Assignment.dat", "r");
	printf("\n\n\tEnter ID to remove : ");
	scanf("%i",&target);
	tz = fopen("d:\\Temp_file.dat", "w+");
	if(fz==NULL)
	{
		printf("\n\tCan not open file.");
		getch();
		menu();
	}
	else
	{
		while(fscanf(fz,"%i %s %s %i %c %s %i\n",&ad.id,ad.full_name,ad.address,&ad.age,&ad.gender,ad.contact,&ad.room)!=EOF)
		{
			if(target!=ad.id)
			{
				fprintf(tz,"%i %s %s %i %c %s %i\n",ad.id,ad.full_name,ad.address,ad.age,ad.gender,ad.contact,ad.room);
			}
			else
			{
				found = 1;
			
			printf("\n\t\t Record Found.\n");
			printf(" ID         : %i\n",ad.id);
			printf(" Name       : %s\n",ad.full_name);
			printf(" Address    : %s\n",ad.address);
			printf(" Age        : %i\n",ad.age);
			printf(" Gender     : %c\n",ad.gender);
			printf(" Contact No : %s\n",ad.contact);
			
			break;
			}
		}
		if (!found)// if the value of found is 0
		{
			printf("\n Record not found.");
			fclose(fz);
			fclose(tz);		
		}
		else
		{
			printf("\n Record deleted.");
			fclose(fz);
			fclose(tz);
			remove("d:\\Assignment.dat");
			rename("d:\\Temp_file.dat","d:\\Assignment.dat");	
		
		}
remove("d:\\Assignment.dat");
rename("d:\\Temp_file.dat","d:\\Assignment.dat");	
		
		
		
	}
	getch();
	S:
	printf("\n\n Press esc to go back to staff menu.... ");
	choice=getch();
	if(choice == Esc)
	{
		menu();
	}
	else
	{
		printf("\n\n ****Invalid key.*****");
		goto S;
	}
}

void room()
{
	system("cls");
	FILE *fz;// file pointer for Shipment.txt
	fz = fopen("d:\\Assignment.dat","r");
	
	printf("\n Enter Room NO : ");
	scanf("%i",&target);
	while(fscanf(fz,"%i %s %s %i %c %s %i",&ad.id,ad.full_name,ad.address,&ad.age,&ad.gender,ad.contact,&ad.room)!=EOF)// reading the data until the end of cursor
	{
		if(target==ad.room)// if target matches the s.sno from the file then following lines are executed
		{
			
			printf("\n Room has been already reserved.");
			
			printf("\n ID        \t: %i",ad.id);
			
			printf("\n Name      \t: %s",ad.full_name);
			
			printf("\n Address   \t: %s",ad.address);
			
			printf("\n Age       \t: %i",ad.age);
			
			printf("\n Gender    \t: %c",ad.gender);
			
			printf("\n Contact No\t: %s",ad.contact);
			
		
			break;
		}
	}
	if(target!=ad.room)// if target is not found 
	{
		
		printf("\n Room is available.");
	}
	fclose(fz);// closing the file sfile
	
	printf("\n\n Press any key to continue...");
	getch();
	menu();
}
void edit(void)
{
	system("cls");
int choice, test=0;
char select;
	FILE *fz, *tz;
fz=fopen("D:\\Assignment.dat","r");
tz=fopen("D:\\Temp_file.dat","a");

printf("\n Enter the account no. of the patient : ");
scanf("%i",&nw.id);
    while(fscanf(fz,"%i %s %s %i %c %s %i",&ad.id,ad.full_name,ad.address,&ad.age,&ad.gender,ad.contact,&ad.room)!=EOF)
    {
if (ad.id==nw.id)
        {
		test=1;
printf("\n Which information do you want to change? \n\n 1.Address \n 2.Contact number \n 3.Gender \n 4.Age \n 5.Room number \n 6.Return to menu ");
printf("\n\n Choose any number listed above : ");
			scanf("%d",&choice);
			printf("\n");

if(choice==1)
                {
				printf(" Enter the new address:");
fflush(stdin);
gets(ad.address);

printf("\n Changes saved!");

				}
else if(choice==2)
                {
printf(" Enter the new contact number:");
	fflush(stdin);
					gets(ad.contact);
	
	printf("\n Changes saved!");
	}
else if(choice==3)
                {
printf(" Enter the new Gender : ");
fflush(stdin);
					scanf("%c",&ad.gender);
	
	
		printf("\n Changes saved!");
	}
			else if(choice==4)
                {
printf(" Enter the new age : ");
					scanf("%i",&ad.age);
	
	printf("\n Changes saved!");
	}
			else if(choice==5)
                {
printf(" Enter the new room number:");
	scanf("%i",&ad.room);
	
					printf("\n Changes saved!");
	}
			else if(choice==6)
				{
					fprintf(tz,"%i %s %s %i %c %s %i\n",ad.id,ad.full_name,ad.address,ad.age,ad.gender,ad.contact,ad.room);
					printf("\n Changing has been cancel...returning to the menu");
					getch();
					menu();
				 }
				fprintf(tz,"%i %s %s %i %c %s %i\n",ad.id,ad.full_name,ad.address,ad.age,ad.gender,ad.contact,ad.room);
		}
else
fprintf(tz,"%i %s %s %i %c %s %i\n",ad.id,ad.full_name,ad.address,ad.age,ad.gender,ad.contact,ad.room);
    }
fclose(fz);
fclose(tz);
remove("D:\\Assignment.dat");
rename("D:\\Temp_file.dat","D:\\Assignment.dat");

if(test!=1)
        {   
printf("\nRecord not found!!\a\a\a");
            X:
printf("\n Enter 0 to try again,1 to return to main menu and 2 to exit:");
scanf("%d",&select);
if (select==1)
menu();
else if (select==2)
exitt();
else if(select==0)
edit();
else
                    {printf("\nInvalid!\a");
goto X;}
        }
else
        {printf("\n\n\n Enter 1 to go to the main menu and 2 to continue editing :");
scanf("%d",&select);

if (select==1)
menu();
else if (select==2) 
edit();
		else
			{
				
			printf(" Invalid entry!!! Exiting program..");
			getch();
			exitt();
		}
		}
}

char* exitt(void)
{
	/*system("cls");
	printf("EXITING THE PROGRAM ");*/
	char* message="EXITING THE PROGRAM";
    return message;
	 
}