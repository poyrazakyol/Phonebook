#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

struct directory{
	char name[30];
	char address[60];
	char tel_no[30];
	char email[100];
};

void menu(){
	system("cls");
	char num;
	printf("\t\t    ***PHONEBOOK***\t\t");
	printf("\n\t\t\t Menu\t\t\n");
	printf("\t1-Add New   \t2-List   \t3-Search\n  \t\t\t4-Exit");
	num=getch();
	if(num=='1'){
		addRecord();
	}
	if (num=='2'){
		listRecord();
	}
	if (num=='3'){
		searchRecord();
	}
	if (num=='4'){
		exit(0);
	}
	else{
		system("cls");
		printf("\nPLEASE Enter number between 1 and 4");
		printf("\nEnter any key ");
		getch();
		menu();
	}
}

void addRecord(){
	system("cls");
	FILE *f;
	struct directory p;
	f=fopen("phonebook.dat","ab+");
	printf("\nEnter name: ");
	scanf("%s",p.name);
	printf("\nEnter address: ");
	scanf("%s",p.address);
	printf("\nEnter phone number: ");
	scanf("%s",p.tel_no);
	printf("\nEnter e-mail: ");
	scanf("%s",p.email);
	fwrite(&p,sizeof(p),1,f);
	printf("\nRECORD SAVED!");
	fclose(f);
	printf("\n\nEnter any key");
	getch();
    system("cls");
    menu();
}

void listRecord(){
	system("cls");
	struct directory p;
	FILE *f;
	f=fopen("phonebook.dat","rb");
	if(f==NULL){
		printf("ERROR WHILE LISTING OPERATOR!");
		exit(0);
	}
	while(fread(&p,sizeof(p),1,f)==1){
		printf("\n\nYour record is: \n\n");
		printf("\nName=%s\nAddress=%s\nMobile no=%s\nE-mail=%s",p.name,p.address,p.tel_no,p.email);
		getch();
		system("cls");
	}
	fclose(f);
	printf("\n\nEnter any key");
	getch();
    system("cls");
    menu();
}

void searchRecord(){
	struct directory p;
	FILE *f;
	char name[60];
	f=fopen("phonebook.dat","rb");
	if(f==NULL){
		printf("ERROR WHILE SEARCHING OPERATOR!");
		exit(1);
	}
	printf("\nEnter the name you want to search: \n");
	scanf("%s",name);
	while(fread(&p,sizeof(p),1,f)==1){
		if(strcmp(p.name,name)==0){
			printf("\t\tInformation about %s:",name);
			printf("\nName=%s\nAddress=%s\nMobile no=%s\nE-mail=%s",p.name,p.address,p.tel_no,p.email);
			break;
		}
	}
	fclose(f);
	printf("\n Enter any key");
	getch();
    system("cls");
	menu();
}

int main(){
	system("color 17");
	menu();
	return 0;
}
