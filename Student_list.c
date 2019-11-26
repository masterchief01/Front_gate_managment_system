#include<stdio.h>
#include<stdlib.h>
struct myst1{
char id[15];
char name[15];
}st1;
void studentlist(void){
     FILE *p1;
     p1 = fopen("student","r");
     if(p1==NULL){
           printf("cannot open student file");
           exit(0);
     }
														//prints the list of registered students from students database				
     while(fread(&st1,sizeof(struct myst1),1,p1)) printf("  Student ID : %s Student name : %s\n",st1.id,st1.name);
     fclose(p1);
}   
