#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
int isArmstrong(int num) { 
int original = num; 
int sum = 0; 
int digits = 0; 
int temp = num; 

while (temp != 0) { 
digits++; 
temp /= 10; 
} 
temp = num; 

while (temp != 0) { 
int digit = temp % 10; 
int power = 1; 
for (int i = 0; i < digits; i++) { 
power *= digit; 
} 
sum += power; 
temp /= 10; 
} 
return sum == original; 
} 
int main() { 
int n; 
printf("Enter the value of n: "); 
scanf("%d", &n); 
pid_t pid = fork(); 
if (pid < 0) { 
printf("Fork failed\n"); 
return 1; 
} 
if (pid == 0) { 

printf("\nChild Process - Fibonacci numbers up to %d:\n", n); 
while (a <= n) { 
printf("%d ", a); 
c = a + b; 
a = b; 
b = c; 
} 
printf("\n"); 
} 
else { 
 
wait(NULL); 

printf("\nParent Process - Armstrong numbers from 1 to %d:\n", n); 
for (int i = 1; i <= n; i++) { 
if (isArmstrong(i)) { 
printf("%d ", i); 
} 
} 
printf("\n"); 
} 
return 0; 
}