#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
        int estado;
    pid_t pid_hijo;
    printf("El pid del programa principal es: %d\n",(int)getpid());
    switch(pid_hijo=fork()) {
        case -1: /* caso de error*/
            printf("Error al crear el proceso");
            return -1;
        case 0: /*  hijo */
            wait(&estado);
            printf("Hijo: PID del proceso %d\n",(int)pid_hijo);
            printf("Hijo: Mi PID %d\n",(int)getpid());
            printf("Hijo: PID del padre %d\n",(int)getppid());
            exit(0);
            printf("Esto nunca se ejecutará en el proceso hijo\n");
            break;
        default: /* padre */
            printf("Padre: el proceso hijo %d finalizó con el estado %d \n",(int)pid_hijo, estado);
            printf("Padre: Mi PID %d\n",(int)getpid());            
            printf("Padre: PID de mi padre %d\n",(int)getppid());
    }
    return 0;
}