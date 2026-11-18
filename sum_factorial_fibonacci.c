#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
int main() { 
int n; 
printf("Enter the value of n: "); 
scanf("%d", &n); 

pid_t child1 = fork(); 
if (child1 < 0) { 
printf("Fork failed\n"); 
return 1; 
} 
if (child1 == 0) { 

int a = 0, b = 1, c; 
printf("\nChild 1 - First %d Fibonacci terms:\n", n); 
for (int i = 0; i < n; i++) { 
printf("%d ", a); 
c = a + b; 
a = b; 
b = c; 
} 
printf("\n"); 
return 0; 
} 

wait(NULL); 

pid_t child2 = fork(); 
if (child2 < 0) { 
printf("Fork failed\n"); 
return 1; 
} 
if (child2 == 0) { 
long long factorial = 1; 
for (int i = 1; i <= n; i++) { 
factorial *= i; 
} 
printf("\nChild 2 - Factorial:\n"); 
printf("%d! = %lld\n", n, factorial); 
return 0; 
} 

wait(NULL); 
int sum = 0; 
for (int i = 1; i <= n; i++) { 
sum += i; 
} 
printf("\nOriginal Parent - Sum of first %d natural numbers:\n", n); 
printf("Sum = %d\n", sum); 
return 0; 
} 