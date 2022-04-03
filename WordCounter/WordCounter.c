#include <stdio.h>
#include <string.h>
#include <ctype.h>

FILE *fp;

int main()
{
	char word[50];
	char file_word[100];
	int i;
	int count=0;
	int countlast;
	int sayac=0;
	int sayaclast=0;
	
	printf("Enter world : ");
	scanf("%s",word);
		
	if((fp=fopen("robinson.txt","r"))==NULL){
		printf("File couldn't opened '"); //Dosyanýn açýlýp açýlmadýðýný kontrol ettiðimiz kýsým.
		return 0;
		}
		
	for(i = 0 ; i <strlen(word);i++)
	{
		word[i]=tolower(word[i]); //kullanicidan aldigimiz kelimenin hepsini kucuk harfe cevirdik
	}
	
	
	while(!feof(fp))	
	{
		sayac=0;
		sayaclast=0;
		fscanf(fp,"%s",file_word);
		
		for(i = 0 ; i <strlen(word); i ++)
		{
			file_word[i] = tolower(file_word[i]); //Fýle icerisindeki butun kelimeleri kucuk harfe cevirdik
		}
		
		if(strcmp(word,file_word) == 0)
		{
			count++; // kullanicidan istedigimiz kelime ile dosya icerisindeki kelime aynimi kontrol ettik
		}
		else
		{ 
			for(i = 0 ; i <strlen(file_word); i++)
			{
				if(file_word[i] == '.' || file_word[i] == ',') //virgul veya nokta olmasý durumunda kontrol ettiðimiz kýsým
				{
					sayac=1;
				}
				
			}
			if (sayac = 1 ) // kelimenin içerisinde nokta(.) veya virgul(,) varsa
			{
				for(i = 0 ; i <strlen(file_word); i++)
				{
					if(file_word[i] == word[i])
					{
						sayaclast++;
					}
				}
				
				if(sayaclast == strlen(file_word)-1 && sayaclast == strlen(word))
				{
					count++;
				}
			}	
		}	
	}
	printf("%d",count);
	fclose(fp);
	
}
