#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char clear[10]="clear";  //Command to clear the screen. Depends from os to os
struct Contact{
   char name[100],phone[100],email[100];
}x;

void Input(struct Contact*); //Inputs the data from user. Defined by Swagatam Burai
void Disp(struct Contact); //Display the function yo user. Defined by Swagatam Burai
void Insert(int);  //Write a record to .dat file. Defined by Sautik Mitra
void Delete(char*);  //Delete a record from the .dat file. Defined by Saptarshi Dey
void Update(char*);  //Updates a record. Defined by Saptarshi Dey
void Search(char*);  //Search a record. Defined by Dipanjan Biswas
void ShowALL();  //Shows the list of all existing records. Defined by Dipanjan Biswas
int isValidNum(char*); //Validates a Phone Number. Defined by Rishav Gupta
int isPresentMail(char*);  //Checks if the given mail id is already present. Defined by Saptarshi Dey
int isPresentName(char*);  //Checks if the given name is already present. Defined by Saptarshi Dey
int isPresentNumber(char*);  //Checks if the given phone number is already present. Defined by Rishav Gupta

int main(){
   START: system(clear);
   int opt=0; char name[100],ch;
   printf("1. Enter new Users\n2. Search for a User\n3. Update a User\n4. Delete a User\n5. Show all Users\n");
   opt=getchar()-48; getchar();
   switch(opt){
     case 1:{
         printf("\nEnter the number of Users : ");
         scanf("%d",&opt);
         getchar();
         Insert(opt);
         break;
     }
     case 2:{
         printf("\nEnter the name, email or phone number of User: ");
         scanf("%[^\n]%*c", name);
         Search(name);
         break;
     }
     case 3:{
         printf("\nEnter the name, email or phone number of User: ");
         scanf("%[^\n]%*c", name);
         Update(name);
         break;
     }
     case 4:{
         printf("\nEnter the name, email or phone number of User: ");
         scanf("%[^\n]%*c", name);
         Delete(name);
         break;
     }
     case 5:{ ShowALL(); break; }
     default: printf("\nPlease Enter a valid choice");
   }
   printf("\nDo you wish to continue? (Y/N)");
   scanf("%c",&ch);
   if(ch=='y'||ch=='Y'){ getchar(); goto START; }
   return 0;
}

void Input(struct Contact *x){
    name: printf("\nEnter the Name : "); scanf("%[^\n]%*c", x->name);
    if(isPresentName(x->name)) goto name;
    num: printf("Enter Phone Number : +91 "); scanf("%s",x->phone);
    if(!isValidNum(x->phone)) goto num;
    else if(isPresentNumber(x->phone)) goto num;
    mail: printf("Enter Email : "); scanf("%s",x->email);
    if(isPresentMail(x->email)) goto mail;
    getchar();
}

void Disp(struct Contact x){
    printf("\nName : %s",x.name);
    printf("\nPhone Number : +91 %s",x.phone);
    printf("\nEmail : %s\n",x.email);
}

void Insert(int n){
    FILE *fptr = NULL;
    for(int i=0;i<n;i++){
       fptr=fopen("Contacts.dat","a");
       Input(&x);
       fwrite (&x, sizeof(x), 1, fptr);
       fclose(fptr);
    }
    printf("%d Users have been added",n);
}

void Search(char* str){
   FILE* fptr = fopen("Contacts.dat","r");
   int cnt=0;
   if(fptr!=NULL){
     while(fread(&x, sizeof(x), 1, fptr)){
        if(strcmp(x.name,str)==0 || strstr(x.name,str) || strcmp(x.email,str)==0 || strstr(x.email,str) || strcmp(x.phone,str)==0 || strstr(x.phone,str)){
            Disp(x); cnt++;
        }
     }
     if(!cnt) printf("\nThere are no such users\n");
     else printf("\nThere are %d users in total\n",cnt);
     fclose(fptr);
   }
   else printf("\nContacts.dat file not found!!!\n");
}

void ShowALL(){
   int cnt=0;
   FILE* fptr = fopen("Contacts.dat","r");
   if(fptr!=NULL){
     while(fread(&x, sizeof(x), 1, fptr)){
        cnt++; Disp(x);
     }
     printf("\nThere are %d contacts in total\n",cnt);
     fclose(fptr);
   }
   else printf("\nContacts.dat file not found!!!\n");
}

void Update(char* str){
   FILE *fptr = fopen("Contacts.dat","r+");
   int isFound=0,opt;
   char data[100];
   if(fptr!=NULL){
     while(fread(&x, sizeof(x), 1, fptr)){
        if(strcmp(x.name,str)==0 || strcmp(x.email,str)==0 || strcmp(x.phone,str)==0){
            isFound=1;
            fseek(fptr,(-1)*sizeof(x),SEEK_CUR);
            system(clear);
            printf("What do you want to Update?\n1. Name\n2. Phone Number\n3. Email\n");
            opt=getchar()-48; getchar();
            check: switch(opt){
               case 1:{
                  nameUP: printf("\nEnter the Name : "); scanf("%[^\n]%*c", x.name);
                  if(isPresentName(x.name)) goto nameUP;
                  break;
               }
               case 2:{
                  numUP: printf("Enter Phone Number : +91 "); scanf("%s",x.phone);
                  if(!isValidNum(x.phone)) goto numUP;
                  else if(isPresentNumber(x.phone)) goto numUP;
                  getchar(); break;
               }
               case 3:{
                  mailUP: printf("Enter Email : "); scanf("%s",x.email);
                  if(isPresentMail(x.email)) goto mailUP;
                  getchar(); break;
               }
               default: {
                  printf("\nPlease enter a valid choice or enter any value to exit");
                  scanf("%d",&opt); getchar();
                  if(opt==1 || opt==2 || opt==3) goto check;
                  else{
                     fclose(fptr);
                     return;
                  }
               }
            }
            fwrite(&x, sizeof(x), 1, fptr);
            break;
        }
     }
     if(!isFound) printf("\nUser doesn't exist\n");
     fclose(fptr);
   }
   else printf("\nContacts.dat file not found!!!\n");
}

void Delete(char* str){
   FILE *fptr = fopen("Contacts.dat","r");
   FILE *wptr = fopen("Temp.dat","a");
   int isFound=0;
   if(fptr!=NULL){
     while(fread(&x, sizeof(x), 1, fptr)){
        if(!(strcmp(x.name,str)==0 || strcmp(x.email,str)==0 || strcmp(x.phone,str)==0))
            fwrite(&x,sizeof(x),1,wptr);
        else isFound=1;
     }
     if(!isFound) printf("\nUser doesn't exist\n");
   }
   fclose(fptr);
   fclose(wptr);
   remove("Contacts.dat"); rename("Temp.dat","Contacts.dat");
}

int isValidNum(char* num){
   int len=strlen(num);
   if(len!=10){
    printf("Number of digits can't be lass or more than 10\n");
    return 0;
   }
   for(int i=0;i<len;i++){
     if(!isdigit(num[i])){
        printf("Number can't contain alphabets\n");
        return 0;
     }
   }
   return 1;
}

int isPresentNumber(char* num){
   FILE* fptr = fopen("Contacts.dat","r");
   struct Contact y;
   if(fptr!=NULL){
     while(fread(&y, sizeof(x), 1, fptr)){
        if(strcmp(y.phone,num)==0){
            printf("Number already present\n");
            fclose(fptr);
            return 1;
        }
     }
     fclose(fptr);
   }
   return 0;
}

int isPresentMail(char* mail){
   FILE* fptr = fopen("Contacts.dat","r");
   struct Contact y;
   if(fptr!=NULL){
     while(fread(&y, sizeof(x), 1, fptr)){
        if(strcmp(y.email,mail)==0){
            printf("Email already present\n");
            fclose(fptr);
            return 1;
        }
     }
     fclose(fptr);
   }
   return 0;
}

int isPresentName(char* name){
   FILE* fptr = fopen("Contacts.dat","r");
   struct Contact y;
   if(fptr!=NULL){
     while(fread(&y, sizeof(x), 1, fptr)){
        if(strcmp(y.name,name)==0){
            printf("Name already present");
            fclose(fptr);
            return 1;
        }
     }
     fclose(fptr);
   }
   return 0;
}
