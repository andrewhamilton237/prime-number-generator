/***********************************************************
Andrew Hamilton - 3/8/2019                                 *
Program to generate and print prime numbers for            *
60 seconds and then print total number of primes generated *
***********************************************************/

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

char StartScreen(void)
{	
	char local_var;
	
	printf("This program will continuously generate prime numbers in order for 60 seconds, before displaying the total number generated.  Useful for assessing processor speed.\n");
	
	do
	{
		printf("\n Press S to start or Q to quit : \n");
		scanf("%c%*c", &local_var);
		local_var = tolower(local_var);

		if ((local_var != 'q') && (local_var != 's'))
			printf("Invalid input.  Answer must be S or Q.\n");
	} while ((local_var != 'q') && (local_var != 's'));
	
	return local_var;
}
		
int PrimeTest(int currnum)
{	
	int counter;
		
	if(currnum == 2)
	{
		printf("%d\n", currnum);
		return(1);
	}
	
	if(currnum % 2 == 0)
		return(0);
	
	for (counter = 3; counter <= sqrt(currnum); counter++)
	{
		if(currnum % counter == 0)
			return(0);
	}	
	
	printf("%d\n", currnum);	
	
	return(1);
}

int main()
{	
	time_t secs = 60;
	int counter = 2;
	int tot = 0;
	char start;
		
	start = StartScreen();
		
	if(start == 's')
	{
		time_t startTime = time(NULL);
		
		while (time(NULL) - startTime < secs)
		{
			tot = tot + PrimeTest(counter);	
			counter++;	
		}
	} 
	
	printf("Total number of prime numbers generated in 60 seconds: %d\n", tot);
		
	return(0);
}
