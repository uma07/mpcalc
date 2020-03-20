/***
	
	8A) 	Write a program called mpcalc (multi process calc) that will compare two expressions of the form ab and cd and will print out 			which is less than (or equal to) which. These numbers (a, b, c & d) should be accepted from the user (standard input).

	    	This program should be implemented using multiple processes so that the main process can spawn another process to do the 			calculation and allow the user to specify another such expression comparison.

		The main process should exit when the user indicates that he wants to quit. Accept a maximum of 10 expression comparison 			commands (exit automatically after the 10th expression comparison is specified).


***/


#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{


	char ch = 'y';

	for(int i = 0; i < 10; i++)
	{
		while(ch == 'y' || ch == 'Y')
		{
			long int a, b, c, d, temp1, temp2;
			pid_t pid;

			temp1 = 1;
			temp2 = 1;

			printf("Enter the values of a and b : \n");
			scanf("%ld", &a);
			scanf("%ld", &b);

			printf("Enter the values of c and d : \n");
			scanf("%ld", &c);
			scanf("%ld", &d);

			if( (pid = fork()) < 0 )
				err_sys("Sorry !!! fork() error.\n");

			else if(pid == 0)
			{
				for(int j = 0; j < b; j++)
					temp1 = temp1 * a;

				for(int j = 0; j < d; j++)
					temp2 = temp2 * c;

				if(temp1 <= temp2)
					printf("RESULT : %ld(a^b) <= %ld(c^d)\n", temp1, temp2);

				else if(temp2 <= temp1)
					printf("RESULT : %ld(c^d) <= %ld(a^b)\n", temp2, temp1);

				sleep(3);
				_exit(0);
			}

			wait(NULL);
			printf("Do you want to enter one more time (y | n) : \n");
			getchar();
			scanf("%c", &ch);
		}
	}

	return 0;


}
