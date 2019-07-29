#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int status1, status2;
	pid_t pid1, pid2;

	if ( (pid1=fork()) == 0 )
	{ /* hijo */
		printf("Hijo 1 (%d, hijo de %d)\n",  getpid(), getppid());
	}
	else
 	{ /*  padre */
 		if ( (pid2=fork()) == 0 )
 		{ /* segundo hijo  */
 			printf("Hijo 2 (%d, hijo de %d)\n",  getpid(), getppid());
		}
		else
		{ /* padre */
/* Esperamos al primer hijo */
			waitpid(pid1, &status1, 0);
/* Esperamos al segundo hijo */
			waitpid(pid2, &status2, 0);
			printf("Padre (%d, hijo de %d)\n", getpid(), getppid());
 		}
	}
	return 0;
}
