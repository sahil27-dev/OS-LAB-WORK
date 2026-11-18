#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
int main() { 
pid_t pid; 
pid = fork(); 
if (pid < 0) { 
printf("Fork failed\n"); 
return 1; 
} 
else if (pid == 0) {  
printf("Child process: PID = %d\n", getpid()); 
printf("Child process is terminating...\n"); 
exit(0); 
} 
else {  
printf("Parent process: PID = %d\n", getpid()); 
printf("Parent is sleeping without calling wait().\n"); 
sleep(20); 
printf("Parent process is now terminating.\n"); 
} 
return 0; 
}