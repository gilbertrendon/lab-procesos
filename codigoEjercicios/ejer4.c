
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>


int main(int argc, char *argv[]) {
  pid_t pid_h1;
  int status;
  pid_h1 = fork();
  if(pid_h1 == 0) {
    printf("Iniciando subprograma\n");
    execl("./ejer1.out","./ejer1.out",NULL);
  }
    else {
      wait(&status);
      printf("Fin del programa\n");
    }
  return 0;
}
