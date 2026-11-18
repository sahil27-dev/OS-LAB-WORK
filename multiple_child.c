#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
int main() { 
pid_t pid; 
for (int i = 1; i <= 3; i++) { 
pid = fork(); 
if (pid < 0) { 
printf("Fork failed\n"); 
exit(1); 
} 
else if (pid == 0) { 
printf("Child %d: PID = %d, PPID = %d\n", 
i, getpid(), getppid()); 
exit(0);  
} 
} 

for (int i = 1; i <= 3; i++) { 
wait(NULL); 
} 
printf("Parent: All three child processes have terminated.\n"); 
return 0; 
} 