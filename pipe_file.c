#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <fcntl.h> 
#include <stdlib.h> 
int main() { 
pid_t pid; 
pid = fork(); 
if (pid < 0) { 
printf("Fork failed\n"); 
return 1; 
} 
if (pid > 0) { 
FILE *file; 
file = fopen("input.txt", "w"); 
if (file == NULL) { 
printf("Error creating file\n"); 
return 1; 
} 
fprintf(file, "Name: Om Sai Patra\n"); 
fprintf(file, "University Roll Number: 240112030\n"); 
fprintf(file, "Class: BTech CSE 5th Semester\n"); 
fclose(file); 
printf("Parent: Data written to input.txt successfully.\n"); 
wait(NULL); 
} 
else {  
FILE *file; 
char line[200]; 
sleep(1); 
file = fopen("input.txt", "r"); 
if (file == NULL) { 
printf("Child: Error opening file\n"); 
return 1; 
} 
printf("\nChild: Contents of input.txt:\n"); 
while (fgets(line, sizeof(line), file) != NULL) { 
printf("%s", line); 
} 
fclose(file); 
} 
return 0; 
}