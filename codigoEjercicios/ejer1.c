#include <stdio.h>
#include <unistd.h>

int main (void){
  char rol;
  int x = 10;
  int i;
  printf("Iniciando proceso %d\n", getpid());  
  if(fork() == 0) {
     // Codigo hijo
     rol = 'Hijo';
     printf("Iniciando proceso %d\n", getpid()); 
     printf("El valor inicial de x para el hijo es: %d\n", x);
     x = x + 4;
     for(i = 0; i < x; i++) {
       sleep(1);
       printf("%c -> i = %d\n",rol ,i);
       
     }
     printf("El valor final de x para el hijo es: %d\n", x);
   }
   else {
     // Codigo padre
     rol = 'Padre';
     printf("el valor inicial de x para el padre es: %d\n", x);
     x = x - 1;
     for(i = 0; i < x; i++) {
       sleep(1);
       printf("%c -> i = %d\n",rol ,i);
       
     }
     printf("el valor final de x para el padre es: %d\n", x);
   }
   // Codijo ejecutado por ambos (para el caso)
   printf("%c -> i = %d\n",rol ,i);
   printf("Fin %d\n", getpid());
   return 0;
}
