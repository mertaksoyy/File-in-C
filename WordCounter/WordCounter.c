/*Write a C program that finds the number of appearances the word received from the user occurs 
in the file. It can be used the robinson.txt file to test the program. The program should increase 
the number of appearances if the exact same word is received from the user in the file, it should 
not increase the number of appearances when a part of the word or a letter is given as input. 

Stage 1: Open file and read data
Stage 2: Getting the search word from the user
Stage 3: Transferring the data read from the file to the string
Stage 4: Searching for word in string
Stage 5: Calculating and then printing the number of appearances*/

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
		printf("File couldn't opened '"); //Dosyanın açılıp açılmadığını kontrol ettiğimiz kısım.
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
			file_word[i] = tolower(file_word[i]); //Fıle icerisindeki butun kelimeleri kucuk harfe cevirdik
		}
		
		if(strcmp(word,file_word) == 0)
		{
			count++; // kullanicidan istedigimiz kelime ile dosya icerisindeki kelime aynimi kontrol ettik
		}
		else
		{ 
			for(i = 0 ; i <strlen(file_word); i++)
			{
				if(file_word[i] == '.' || file_word[i] == ',') //virgul veya nokta olması durumunda kontrol ettiğimiz kısım
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
