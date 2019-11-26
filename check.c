#include<stdio.h>
#include<string.h>
#include<stdlib.h>

extern struct myst1{
	char id[15];
	char name[15];
}st1;

int check(char c[]){
	FILE *p1;
	struct myst1 st1;
	p1 = fopen("student","ab+");				//open student database
	if (p1==NULL){
		printf("Cannot open the student file\n");	//if file cannot be opened 
		exit(0);
	}

	while(fread(&st1,sizeof(struct myst1),1,p1))		//check if the the given student is already registered or not 
	{
		if (strcmp(st1.id,c)==0)			//returns zero if not registered
		{
			fclose(p1);
			return 1;
		}
	}
	fclose(p1);

	return 0;
}
