#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

struct myst1{
char id[15];
char name[15];
}temp;

struct myst2{
char id[15];
time_t t;
}temp1,temp2;

void studenthistory(void)
{       char c[15];
        struct tm *ptr;
        FILE *p1,*p2,*p3;
        int enh=0,enm=0,ens=0,exh=0,exm=0,exs=0,his=0;
        printf("  Enter the roll number: ");
        scanf("%s",c);
        p1 = fopen("student","rb+");
        if(p1==NULL){
            printf("\tCannot open the student file\n");
            exit(0);
        }
        p2 = fopen("Entry","ab+");
        if(p2==NULL){
            printf("\tCannot open the student file\n");
        }
        p3 = fopen("Exit","ab+");
        if(p3==NULL){
            printf("\tCannot open the student file\n");
        }
        while(fread(&temp,sizeof(struct myst1),1,p1)){
            if(strcmp(temp.id,c)==0){
                printf("  Student name : %s\n",temp.name);
                break;}}
                printf("  Entry time list\n");
                his=0;

        while(fread(&temp1,sizeof(struct myst2),1,p2)){  
                    if(strcmp(c,temp1.id)==0){
			his=1;
                        ptr = localtime(&temp1.t);
                        printf("     Entry Time is: ");					//print entry time 
                        printf("%dHrs ", ptr->tm_hour);
                        printf("%dMnts ", ptr->tm_min);
                        printf("%dSecs \n", ptr->tm_sec);
                        enh =  ptr->tm_hour;enm =  ptr->tm_min;ens = ptr->tm_sec;                  
                     }
                }

        if (his == 0){
                       printf("     No History Available\n");
                }

        else{
              printf("  Latest entry time registered: %dHrs %dMnts %dSecs \n",enh,enm,ens);
            }
        printf("  Exit time list\n");
        his=0;

        while(fread(&temp2,sizeof(struct myst2),1,p3)){            
                            if(strcmp(c,temp2.id)==0){
				his=1;
                                ptr = localtime(&temp2.t);
                                printf("     Exit  Time is: ");
                                printf("%dHrs ", ptr->tm_hour);
                                printf("%dMnts ", ptr->tm_min);
                                printf("%dSecs \n", ptr->tm_sec);
                                exh =  ptr->tm_hour;exm= ptr->tm_min;exs= ptr->tm_sec;
                              
                    } 
                }

       if (his == 0){
                 printf("     No History Available\n");
        }
       else{
            printf("  Latest exit time registered: %dHrs %dMnts %dSecs \n",exh,exm,exs); }
         fclose(p1);fclose(p2);fclose(p3);
}
