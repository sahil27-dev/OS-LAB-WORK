// To check whether given no. is prime or not in the child process and in the parent process
// calculate the factorial of the given no. print parent id and process id.

#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int n, i, prime = 1;
    unsigned long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }


    if (pid == 0)
    {
        printf("\n--- Child Process ---\n");
        printf("Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());

        if (n <= 1)
        {
            prime = 0;
        }
        else
        {
            for (i = 2; i <= n / 2; i++)
            {
                if (n % i == 0)
                {
                    prime = 0;
                    break;
                }
            }
        }

        if (prime)
            printf("%d is a Prime Number.\n", n);
        else
            printf("%d is Not a Prime Number.\n", n);
    }

 
    else
    {
        wait(NULL);

        printf("\n--- Parent Process ---\n");
        printf("Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());

        for (i = 1; i <= n; i++)
        {
            fact = fact * i;
        }

        printf("Factorial of %d = %llu\n", n, fact);
    }

    return 0;
}