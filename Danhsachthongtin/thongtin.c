#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Infor{
    char name[50];
    char phone[20];
    char address[100];
};
void addinfor(struct Infor a[],int *number){
    int i;
    struct Infor infor;
    printf("Enter name: ");
    fgets(infor.name,sizeof(infor.name),stdin);
    printf("Enter your phone number: ");
    scanf("%s",&infor.phone);
    while(getchar() != '\n' );
    printf("Enter your address: ");
    fgets(infor.address,sizeof(infor.address),stdin);
    a[*number]=infor;
    (*number)++;
};

void searchfor(struct Infor a[], int n, char vt[]){
    int i;
    for(i=0; i<n;i++){
        if(strcmp(a[i].name,vt)==0){
            printf("Contact found: \n");
            printf("%d. Name: %s\n",i+1,a[i].name);
        	printf("Phone: %d\n",a[i].phone);
        	printf("Address: %s\n",a[i].address);
        	printf("\n");
        }
        else printf("No information in Contact Manager!");
    }

};
void readfile(struct Infor a[],int n, char filename[]){
    int i=0;
    FILE * fp;
    char arr[255];
    fp = fopen ("information.txt","r");
     if(fp == NULL)
   {
      printf("File can not open!\n");   
      exit(1);             
   }
    while (fgets(arr, 255, fp) != NULL)
    {
        //Xuất từng dòng ra màn hình
        printf("%s", arr);
    }
   
    fclose (fp);
};
int isempty(struct Infor a[],char filename[]){
    int i=0;
    char arr[255];
    FILE * fp;
    fp = fopen ("information.txt","r");
     if(fp == NULL)
   {
      printf("File can not open!\n");   
      exit(1);             
   }
   while(fgets(arr, 255, fp) != NULL){
        i++;
   }
   return i;
}
void writefile(struct Infor a[], int n, char filename[]){
	FILE * fp;
    fp = fopen ("information.txt","a+");
    if(fp == NULL)
   {
      printf("File can not open!\n");   
      exit(1);             
   }
    for(int i = 0;i<n;i++){
        fprintf(fp, "%d. Name: %s",i+1,a[i].name);
        fprintf(fp,"Phone: %d\n",a[i].phone);
        fprintf(fp,"Address: %s\n",a[i].address);
    }
    fclose (fp);
	};
int main(){
    int key,kt;
    int number=0;
    char search[100];
    char filename[]="information.txt";
    struct Infor *a;
    a = (struct Infor *)malloc(number*sizeof(struct Infor));
    kt=isempty(a,filename);
    printf("Welcome to the Contact Manager!\n");
    while (1){
    printf("1. Add a new contact\n");
    printf("2. Display all contacts\n");
    printf("3. Search for a contact\n");
    printf("4. Exit\n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d",&key);
    while(getchar() != '\n' );
    switch (key)
    {
    case 1:
        addinfor(a,&number);
        printf("Contact added successfully!\n");
        printf("\n");
        writefile(a,number,filename);
        break;
    case 2:
        if(kt>0){
        printf("Contact List:\n");
        readfile(a,number,filename);}
        else{
            printf("Contact manager is empty\n");
            printf("\n");
        }
        break;
    case 3:
        if(kt>0){
            printf("Enter name to search for: ");
            fgets(search,sizeof(search),stdin);
            searchfor(a,number,search);
        }
        else{
            printf("No information in Contact Manager!");
            printf("\n");
        }
        break;
    case 4:
        printf("Good bye!");
        return 0;
    default:
        printf("This function is not available. Please choice the appropriate function !");
        break;
    }
    }
    return 0;
};