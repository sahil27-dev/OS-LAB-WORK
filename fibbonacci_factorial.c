#include <stdio.h> 
#include <unistd.h> 
int main() { 
pid_t pid; 
int n, num; 
printf("Enter number of Fibonacci terms: "); 
scanf("%d", &n); 
printf("Enter a number for factorial: "); 
scanf("%d", &num); 
pid = fork(); 
if (pid < 0) { 
printf("Fork failed\n"); 
} 
else if (pid == 0) {  
int a = 0, b = 1, c; 
printf("\nChild Process - Fibonacci Series:\n"); 
for (int i = 0; i < n; i++) { 
printf("%d ", a); 
c = a + b; 
a = b; 
b = c; 
} 
printf("\n"); 
} 
else {  
long long factorial = 1; 
for (int i = 1; i <= num; i++) { 
factorial *= i; 
} 
printf("\nParent Process - Factorial:\n"); 
printf("Factorial of %d = %lld\n", num, factorial); 
} 
return 0; 
}