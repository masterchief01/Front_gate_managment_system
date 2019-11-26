#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"warnings.h"
#include"add_student.h"
#include"Entry.h"
#include"Exit.h"
#include"Student_status.h"
#include"stu_info.h"
#include"Student_history.h"
#include"Student_list.h"
#include"check.h"
#include"display.h"

struct myst1{
char id[15];
char name[15];
};

struct myst2{
char id[15];
time_t t;
};
	
struct myst3{
char id[15];
int checker;
};

struct myst4{
char id[15];
};

int main(){
        int s;
        char c[15];
        int p;

        system("clear");
        printf("\t\t MY GATE \t\t\n");
        printf("\t******************************\n");
        printf("\t 1.Add student\n");
        printf("\t 2.Add student entry time\n");
        printf("\t 3.Add student exit time\n");
        printf("\t 4.Student status\n");
        printf("\t 5.Student details\n");
        printf("\t 6.student history\n");
        printf("\t 7.student list\n");
        printf("\t 8.Student registration check\n"); 
        printf("\t 9.No.of warnings\n");
        printf("\t 10.display all options\n");
        printf("\t 0.QUIT\n");
        printf("\t******************************\n");

        for(;s!=0;){     	  
	       printf("Enter your option : ");
	       scanf("%d",&s);
               printf("\n");
           switch(s){
               case 1: Add_student();break;
               case 2: Entrytime();break;
               case 3: Exittime();break;
               case 4: Student_status();break;
               case 5: Stu_info();break;
               case 6: studenthistory();break;
               case 7: studentlist();break; 
               case 8: {
                                 printf("  Enter the student roll number: ");
                                 scanf("%s",c);
                                 p = check(c);
                                 if (p==0) printf("  student not registered\n");
                                 else if (p==1) printf("  student is registered\n");break;
                        }
               case 9: warnings();break;
               case 10: display();
               case 0: break;
               default:break;
           }
        }
return 0;
}
