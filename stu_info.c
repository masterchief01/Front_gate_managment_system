#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct myst1{
char id[15];
char name[15];
}st1,temp,t1;
struct myst2{
char id[15];
time_t t;
}st2,temp1,temp2;
void Stu_info(void){
    char c[15];
    FILE *s,*En,*Ex,*rd;
    int count1=0,count2=0;
    struct tm *ptr; 
    printf("  Enter the student roll number: ");
    scanf("%s",c);
    s = fopen("student","r");
    if(s==NULL){
        printf("cannot open student file");
        exit(0);
    }
    En = fopen("Entry","r");
    if(En==NULL){
        printf("cannot open Entry file");
        exit(0);
    }
    Ex = fopen("Exit","r");
    if(Ex==NULL){
        printf("cannot open Exit file");
        exit(0);
    }
    rd = fopen("red_stu","a");
    if(rd==NULL){
        printf("cannot open the red_stu file");
        exit(0);
    }
    while(fread(&st1,sizeof(struct myst1),1,s)){
        if(strcmp(c,st1.id)==0) {printf("  %s\n",st1.name);break;}
    }
    rewind(s);
    while(fread(&st2,sizeof(struct myst2),1,Ex)){
        if(strcmp(c,st2.id)==0) count1++;
    }
    rewind(Ex);
    printf("  %s left the campus %d times\n",st1.name,count1);
    while(fread(&temp1,sizeof(struct myst2),1,En)){
        if(strcmp(c,temp1.id)==0){
            ptr = localtime(&temp1.t);
            if((ptr->tm_hour < 6) || (ptr->tm_hour >= 22)){
                while(fread(&temp,sizeof(struct myst1),1,s)){
                    if(strcmp(c,temp.id)==0) fwrite(&temp,sizeof(struct myst1),1,rd);
                }
                rewind(s);
            }
        }
    }
    while(fread(&temp2,sizeof(struct myst2),1,Ex)){
        if(strcmp(c,temp2.id)==0){
            ptr = localtime(&temp2.t);
            if((ptr->tm_hour < 6) || (ptr->tm_hour > 22)){
                while(fread(&temp,sizeof(struct myst1),1,s)){
                    if(strcmp(c,temp.id)==0) fwrite(&temp,sizeof(struct myst1),1,rd);
                }
                rewind(s);
            }
        }
    }
    fclose(rd);
    rd = fopen("red_stu","r");
    if(rd==NULL){
        printf("cannot open the red_stu2 file");
        exit(0);
    }
    while(fread(&t1,sizeof(struct myst1),1,rd)){
        if(strcmp(c,t1.id)==0) count2++;
    }
    printf("  %d times was arrived/left in curfew hours\n",count2);
    fclose(s);fclose(En);fclose(Ex);fclose(rd);
}
