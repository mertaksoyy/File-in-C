#include <stdio.h>


struct Movie{
	char name[50];
	int year;
	float imdb;
};



int main()
{
	FILE *fp;
	struct Movie movie[50];
	
	int i=0,a;
	float maximdb=0.0;
	
	if((fp=fopen("Source.txt","r"))==NULL)
	{
		printf("Filed can't opened....'");
		return 0;
	}
	
	
	while(!feof(fp))
	{
		fscanf(fp,"%s %d %f",movie[i].name,&movie[i].year,&movie[i].imdb);
		
		if(movie[i].imdb>maximdb)
		{
			a=i;
			maximdb=movie[i].imdb;
		}
		i++;
	}
	
	printf("\n %s %d %f",movie[a].name,movie[a].year,movie[a].imdb);
	
	fclose(fp);
	return 0;
	
	
	
}
