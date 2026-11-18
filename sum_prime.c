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
int n; 
printf("Enter the number of elements: "); 
scanf("%d", &n); 
int arr[n]; 
printf("Enter %d integers:\n", n); 
for (int i = 0; i < n; i++) { 
scanf("%d", &arr[i]); 
} 
pid_t pid = fork(); 
if (pid < 0) { 
printf("Fork failed\n"); 
return 1; 
} 
if (pid == 0) { 
int sum = 0; 
for (int i = 0; i < n; i++) { 
sum += arr[i]; 
} 
printf("\nChild Process:\n"); 
printf("Sum of array = %d\n", sum); 
if (isPrime(sum)) 
printf("%d is a prime number.\n", sum); 
else 
printf("%d is not a prime number.\n", sum); 
} 
else { 
wait(NULL); 
printf("\nParent Process:\n"); 
printf("Child process has completed successfully.\n"); 
} 
return 0; 
}