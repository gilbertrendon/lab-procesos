#include <stdio.h>
#include <unistd.h>

int main (void){
  char rol;
  printf("Empezando proceso %d\n", getpid());  
  if(fork() == 0) {
    rol = 'Hijo';
    printf("Hello %d\n", getpid()); 
     
   }
   else {
    rol = 'Padre';
    sleep(1);
    printf("goodbye: %d\n");
   }
   printf("%c -> i = %d\n",rol);
   printf("analizando proceso %d\n", getpid());
   return 0;
}