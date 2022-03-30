
//Question:There are 10 Social Security Numbers (SSN) in “S1.txt” and “S2.txt” files.
//Write a C program that saves the common SSNs in the two files to the S3.txt file.


#include <stdio.h>
#include <string.h>

FILE *fp,*fp2,*fp3;



int main()
{
	char num[100],num2[100];
	
	if((fp=fopen("S1.txt","r"))==NULL)
	{
		printf("File can't opened...'");
		return 0;
		
	}
	
	if((fp2=fopen("S2.txt","r"))==NULL)
	{
		printf("File can't opened...'");
		return 0;
		
	}
	if((fp3=fopen("S3.txt","w"))==NULL)
	{
		printf("File can't opened...'");
		return 0;	
	}
	
	while(!feof(fp))
	{
		fscanf(fp,"%s",num);
		rewind(fp2);
		
		while(!feof(fp2))
		{
			fscanf(fp2,"%s",num2);
			if(strcmp(num,num2)==0)
			{
				fprintf(fp3,"%s\n",num);
			}	
		}
	}			
}
