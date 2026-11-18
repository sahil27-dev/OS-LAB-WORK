#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
int main() { 
pid_t pid; 
int status; 
pid = fork(); 
if (pid < 0) { 
printf("Fork failed\n"); 
return 1; 
} 
else if (pid == 0) { 
printf("Child process is terminating with exit status 10.\n"); 
exit(10); 
} 
else { 
wait(&status); 
if (WIFEXITED(status)) { 
printf("Child process terminated normally.\n"); 
printf("Child exit status = %d\n", WEXITSTATUS(status)); 
} 
} 
return 0; 
}