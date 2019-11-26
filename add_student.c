#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct myst1{
char id[15];
char name[15];
}st1,st2;

struct myst3{
char id[15];
int checker;
}st3;
		
void Add_student(void){
    FILE *s,*ch;
    s = fopen("student","ab+");
	if(s==NULL){
        printf("Cannot open the student file");
        exit(0);
    }									//student registration function

    ch = fopen("status","ab+"); 
    if(ch==NULL){
        printf("Cannot open the student file");
        exit(0);
    }
    printf("  Enter student ID number: ");
    int flag=0;
    scanf("%s",st1.id);
    while(fread(&st2,sizeof(struct myst1),1,s))				//read string and register in the structure than write in the database
    {
	    if (strcmp(st1.id,st2.id)==0)
	    {
		    flag=1;
                    printf("  ID Number already exists\n");
		    break;
	    }
    }
    if (flag==0)							//check if name is already registered or not 
    {
	    printf("  Enter the student name: ");
	    scanf(" %[^\n]s",st1.name);
            printf("\n");
	    fwrite(&st1,sizeof(struct myst1),1,s);
    }
    strcpy(st3.id,st1.id);
    st3.checker=0;
    fwrite(&st3,sizeof(struct myst3),1,ch);
    fclose(s);fclose(ch); 
}
