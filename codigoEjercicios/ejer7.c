#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
 int rcount = fork();
 
 if (rcount < 0) {
        fprintf(stderr, "Error al crear el fork\n");
        exit(1);
 } else if (rcount == 0) {
        printf("Hola, puedes escribir antes de cerrar(pid:%d) \n", (int) getpid());
        fclose(stdout);
        printf("Hola, ya no puedes escribir(pid:%d)", (int) getpid());
 } else {
        // parent goes down this path (original process)
        printf("Hola Soy el padre %d (pid:%d)\n",
        rcount, (int) getpid());
 }
 return 0;
}