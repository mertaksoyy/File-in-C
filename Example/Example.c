#include <stdio.h>

int main()
{
	FILE *fp;
	
	char name[50];
	int i ,num,mark;
	
	printf("Enter num of student");
	scanf("%d",&num);
	
	if((fp=fopen("student.txt","w"))==NULL)
	{
		printf("File can't opened...'");
	}
	
	for(i = 0 ; i < num ; i++)
	{
		printf("Enter name for %d . student",i+1);
		scanf("%s",name);
		
		printf("Enter mark for %d . student",i+1);
		scanf("%d",&mark);
		
		fprintf(fp,"Name : %s , Mark : %d\n",name,mark);
	}
	fclose(fp);
	
	
}
