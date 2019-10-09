#include<stdio.h>
struct courses_detail{
char id[50];
char subject[50];
int  credit;
int score;
};

struct student_detail{
	char name[100];
	char id[10];
	struct courses_detail course[50];
   };


int main(){
	int studentsNo;
	int coursesNo;
	printf("Enter the number of students \n");
	scanf("%d",&studentsNo);
	printf("Enter the number of courses \n");
	scanf("%d",&coursesNo);
	struct student_detail student[studentsNo];
	int i;
	printf("******student registration form***********\n\n");

	for(i=0;i<studentsNo;i++)
	{
		printf("enter the id of   student %d :\n\n",i+1);
	    scanf("%s",&student[i].id);
		printf("enter the name of  student  %d:\n\n",i+1);
	    scanf("%s",&student[i].name);
	   

//storing courses
int j;
	for(j=0;j<coursesNo;j++)
	{
		printf("enter the id of number %d Course \n\n",j+1);
	    scanf("%s",&student[i].course[j].id);
		printf("enter the subject of number %d course \n\n",j+1);
	    scanf("%s",&student[i].course[j].subject);
	    printf("Enter the credit of number %d course \n\n",j+1);
	    scanf("%d",&student[i].course[j].credit);
	     printf("Enter the score of number %d course \n\n",i+1);
	    scanf("%d",&student[i].course[j].score);

	}
}

	display(student,studentsNo,coursesNo);
	}


//	y to be the number of courses and courses are gonna be displayed separaely;
void display(struct student_detail student[], int n ,int y){

	int i;
	char sid[10];
	


//	printf("%s",sid);
	for(i=0;i<n;i++){
	    printf(" UNIVERSITY GRADE REPORT\n");
	    printf("Student Grade Report\n");
	   printf("====================\n");
		printf(" Id: %s\n",student[i].id);
		printf(" Name: %s \n\n",student[i].name);
		
	
        printf("Code      Grade\n");
		int j;
      
  for(j=0;j<y;j++){
	printf("%s           ",student[i].course[j].id);
	if(student[i].course[j].score >=85){
	                    
			             printf("A");
	                     	}
	             	else if(student[i].course[j].score >=75&&student[i].course[j].score<85){
		            	printf("B");
	                   	}
	             	else if(student[i].course[j].score >=65&&student[i].course[j].score<75){
			            printf("C");
	               	}
		                 else if(student[i].course[j].score >=45&&student[i].course[j].score<65){
		                  	printf("D");
		                       }	
							   else{
                             printf("F");
                         }
                         printf("\n");

}
        


 printf("\nCourse Matrix\n");
	printf("\nCode    Course name     Credit\n");
	int k;
	for(k=0;k<y;k++){
		printf("%s        %s              %d\n",student[k].course[k].id,student[k].course[k].subject,student[k].course[k].credit);
		}


}
}



