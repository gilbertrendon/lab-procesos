#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h> 

extern int errno; 
char rol;
int i, A, B;
int x = 10;


int main() 
{      
    
    int fd = open("PRUEBA.txt", O_WRONLY | O_RDONLY | O_CREAT);  
      
    printf("fd = %d/n", fd); 
      
    if (fd ==-1) 
    { 
        printf("Error Number % d\n", errno);  
        perror("Program");                  
    } else{
    if(fork() == 0) {
     rol = 'Hijo';
     printf("Empezando proceso hijo%d\n", getpid()); 
     read(fd);
     printf("Ingreso de hijo a fd: %d\n", fd);
    x = x - 1;
     for(i = 0; i < x; i++) {
       sleep(1);
       A = write(fd, "Hello hijo\n",strlen("Hello hijo\n" ));
       printf("Ingreso de hijo a fd: %d\n", fd);
     }
   }
   else {
     // Codigo padre
     rol = 'Padre';
     printf("Iniciando proceso padre%d\n", getpid()); 
     read(fd);
     printf("Ingreso de padre a fd: %d\n", fd);
     for(i = 0; i < x; i++) {
       sleep(1);
       B = write(fd, "Hello padre\n",strlen("Hello padre\n" ));
       printf("Ingreso de padre a fd: %d\n", fd);
     }
   }
}
    return 0; 
} 