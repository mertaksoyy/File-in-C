#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 50


int main()
{
		
	int a,i,sayi=0,ust = 0,alt = 0,sum=0;
	char arr[SIZE];
	
	printf("enter sentence:");
	
	fgets(arr,sizeof(arr),stdin);
	
	
	
	for(i= 0 ; i <SIZE ; i++)
	{
		a = arr[i];
		
		if(isdigit(a))
		{
			sayi++;
		}
		if(isupper(a))
		{
			ust++;
		}
		if(islower(a))
		{
			alt++;
		}
		
	}
	
	sum = alt+ust;
	
	printf("%d\n",sum);
	printf("%d\n",sayi);
	printf("%d\n",ust);
	printf("%d\n",alt);


}
	
