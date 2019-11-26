#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"check.h"

struct myst3{
char id[15];
int checker;
}st3;
	
struct myst1{
char id[15];
char name[15];
}st1;

void Student_status(void){
      int k;
      char c[15],b[15];
      FILE *p1,*p2;
      printf("  Enter the student ID number:");
      scanf("%s",c);
      if(check(c)==1){						//flag to check if student is registered or not 
      p2 = fopen("student","r");
      p1 = fopen("status","r");

      while(fread(&st1,sizeof(struct myst1),1,p2)){		//look for the registered  name in registered student database 
            if (strcmp(st1.id,c)==0){
                strcpy(b,st1.name);break;}}
      while(fread(&st3,sizeof(struct myst3),1,p1)){
          if(strcmp(st3.id,c)==0){
             k = st3.checker;
          }
      }

      if (k==1)
      {
           printf("  %s is not in the campus\n",b);
      }

      else if(k==0)
      {
           printf("  %s is in the campus\n",b);
      }

      fclose(p1);fclose(p2);
      }

      else if (check(c)==0){
          printf("  Student not registered\n");
      }
}
