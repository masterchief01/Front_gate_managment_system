#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct myst4{
char id[15];
}st1;
							//to display warnings to the ones who skipped an entry or exit 

struct myst1{
char id[15];
char name[15];
}st2;

void warnings(void){
	FILE *p1,*p2;
	char c[15];
        char b[15];
        printf("  Enter the student ID number: ");
	scanf("%s",c);
	int count=0;
        p2 = fopen("student","rb+");
        while(fread(&st2,sizeof(struct myst1),1,p2)){
           if (strcmp(c,st2.id)==0){
               strcpy(b,st2.name);
               break;
           }}
	p1 = fopen("warnings","ab+");
	while(fread(&st1,sizeof(struct myst4),1,p1))
	{
		if(strcmp(st1.id,c)==0)
		{
			count++;
		}
	}
	if (count==0)
	{
		printf("  %s has no warnings\n",b);
	}
	else
	{
		printf("  %s has %d warnings\n",b,count);
	}
}

	
