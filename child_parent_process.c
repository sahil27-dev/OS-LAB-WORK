#include <stdio.h> 
#include <unistd.h> 
int main() { 
pid_t pid; 
pid = fork(); 
if (pid < 0) { 
printf("Fork failed\n"); 
} 
else if (pid == 0) { 
printf("Hello World\n"); 
} 
else { 
printf("Hello World\n"); 
} 
return 0; 
}