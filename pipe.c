#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
int isPrime(int num) { 
if (num <= 1) 
return 0; 
for (int i = 2; i * i <= num; i++) { 
if (num % i == 0) 
return 0; 
} 
return 1; 
} 
int main() { 
int arr[] = {2, 4, 6, 3, 8}; 
int n = sizeof(arr) / sizeof(arr[0]); 
int pipefd[2]; 
int sum = 0;  
if (pipe(pipefd) == -1) { 
printf("Pipe creation failed\n"); 
return 1; 
} 
pid_t pid = fork(); 
if (pid < 0) { 
printf("Fork failed\n"); 
return 1; 
} 
if (pid > 0) { 
close(pipefd[0]);  
for (int i = 0; i < n; i++) { 
sum += arr[i]; 
} 
printf("Parent: Sum of array = %d\n", sum); 

write(pipefd[1], &sum, sizeof(sum)); 
close(pipefd[1]);  
wait(NULL);       
} 
else { 

close(pipefd[1]); 
read(pipefd[0], &sum, sizeof(sum)); 
printf("Child: Received sum = %d\n", sum); 
if (isPrime(sum)) 
printf("Child: %d is a Prime Number.\n", sum); 
else 
printf("Child: %d is Not a Prime Number.\n", sum); 
close(pipefd[0]);  
} 
return 0; 
}