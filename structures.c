#include<stdio.h>
#include<string.h>
#include<process.h>
struct student
{
    int roll_no;
    char name[30];
    int marks;
    char grade;
}s[5];
int main()
{
    int i,n;
    char sname[30];
    printf("enter number of students");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter student details\n");
        printf("enter student roll number\n");
        scanf("%d",s[i].roll_no);
        printf("enter student name\n");
        scanf("%s",s[i].name);
        printf("enter student marks\n");
        scanf("%d",s[i].marks);
        printf("enter student grade\n");
        scanf("%c",s[i].grade);
    }
    printf("enter student name for searching\n");
    scanf("%c",sname);
    for(i=0;i<n;i++)
    {
        if(strcmp(s[i].name,sname)==0)
        {
            printf("name= %s \n",s[i].name);
            printf("roll no.= %d \n",s[i].roll_no);
            printf("marks= %d \n",s[i].marks);
            printf("grade= %c \n",s[i].grade);
        }
        else
        {
            printf("search is unsuccessful \n");
            exit(0);
        }
    }
}
