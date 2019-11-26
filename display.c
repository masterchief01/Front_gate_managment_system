#include<stdio.h>
#include<stdlib.h>

void display(void)					//to display the options menu given in display.txt if we enter number 10
{
	FILE *fp;
	fp = fopen("display.txt","r");			//open file in readonly MODE
	char c;

	if (fp == NULL)
	{
		printf("Cannot open the file\n");	
		exit(0);
	}
	c = fgetc(fp);					
		
	while (c!=EOF)
	{
		printf("%c",c);				//print till the end of file
		c = fgetc(fp);
	}
	fclose(fp);
}
