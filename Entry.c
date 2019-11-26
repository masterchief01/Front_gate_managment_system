#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"check.h"
					//Entry file to register the entry time of a student
struct myst2{
char id[15];
time_t t;
}st1,st2;

struct myst3{
char id[15];
int checker;
}st3;
	
struct myst4{
char id[15];
}st4;

void Entrytime(void){

    int k=0;				//flag to check if student is registered or not
    char b[15];
    char c[15];
    FILE *En,*ch,*wa;
    ch = fopen("status","ab+");
    
    if(ch==NULL){
        printf("Cannot open Entry file");
        exit(0);
    }

    printf("  Enter the student ID number: ");
    scanf("%s",c);
    strcpy(st1.id,c);

    if (check(c)==1){
    while(fread(&st3,sizeof(struct myst3),1,ch))
    {
       if (strcmp(st3.id,st1.id)==0){
             k=st3.checker;
        }
    }
    fclose(ch);

    if (k==1){
    En = fopen("Entry","ab+");
    ch = fopen("status","ab+");
    while(fread(&st3,sizeof(struct myst3),1,ch))
    {
       if (strcmp(st3.id,st1.id)==0){
             st3.checker=0;
             fwrite(&st3,sizeof(struct myst3),1,ch);
       }
    }
    st1.t = time(NULL);
    fwrite(&st1,sizeof(struct myst2),1,En);
    fclose(En);fclose(ch);
    }

    else {
                 En = fopen("Entry","ab+");
                 ch = fopen("status","ab+");
                 printf("  Warning previous entry time not registered\n");
                 printf("  Do you want to continue (Y/N)?: ");
                 scanf("%s",b);
                 if (strcmp(b,"Y") == 0)
                 {
                  wa = fopen("warnings","ab+");
                  strcpy(st4.id,c);
                  fwrite(&st4,sizeof(struct myst4),1,wa);
                  fclose(wa);
                  strcpy(st2.id,c);
                  st2.t=time(NULL);
                  if(En==NULL){
                     printf("\tCannot open the Entry file\n");
                     exit(0);
                 }
                while(fread(&st3,sizeof(struct myst3),1,ch))
                {
                   if (strcmp(st3.id,st1.id)==0){
                       st3.checker=0;
                       fwrite(&st3,sizeof(struct myst3),1,ch);
                   }
                }
                fwrite(&st2, sizeof(struct myst2),1,En);
                }
                else if (strcmp(b,"N") == 0){
                printf("  Entry time not registered\n");
                }
                else
                {
                      printf("  Unrecognised command\n");
                } 
    fclose(En);fclose(ch);
   }
}

   else if (check(c)==0){
       printf("  %s not registered\n",c);
   }
}
