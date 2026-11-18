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
printf("Child Process:\n"); 
printf("PID  = %d\n", getpid()); 
printf("PPID before parent terminates = %d\n", getppid()); 
sleep(5); 
printf("\nParent process has terminated.\n"); 
printf("PPID after parent terminates = %d\n", getppid()); 
} 
else { 
printf("Parent Process:\n"); 
printf("PID = %d\n", getpid()); 
sleep(2); 
printf("Parent process terminating...\n"); 
exit(0); 
} 
return 0; 
}