#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int data(const char * dataname, const char * rtf)
{
	int range = 1;
	int position = 1;
	int found = 0;

	char arr[512];
	char *brn;
	char *line;

	FILE * data;
	data = fopen(dataname,"r");

	
	if (data != NULL)
	{
		
		while(fgets(arr,512,data) != NULL)
		{
			
			brn = strtok(arr," ");
			int wI = 0; 

			
			while (brn != NULL)
			{
				line = strstr(brn,rtf);


				if(line != NULL)
				{
					position = (strlen(arr) - strlen(line)) + (wI * (strlen(line)) + 1);
					printf("%d:%d %s\n", range, position, rtf);
					found++;
				}

				brn = strtok(NULL, " ");
				wI++;
			}

			range++;
		}
	}
	else
	{
		printf("data is not opened successfully");
		return 1;
	}

	if (found == 0)
	{
		printf("No matches\n");
	}
	else
		printf("quantity of matches: %d", found);

	fclose(data);
	return 0;
}



int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		
		if (strstr(argv[1], ".txt") == NULL)
		{
		    printf("data is not txt\n");
		    exit (1);
		}
		else
			data(argv[1],argv[2]);

	}
	else
	{
		printf("Correct form: %s data.txt rtfression\n", argv[0]);
		exit (1);
	}

	return 0;
}
