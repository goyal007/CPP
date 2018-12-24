#include <stdio.h>
#include <error.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    if (argc == 1) 
    {
        puts("File Argument Missing");
        exit(EXIT_FAILURE);
    }
    fp = fopen(argv[1],"r");
// perror() simplifies reporting of such specific errors to user. It’s prototype is as follows
//   prototype:: void perror(char const *message);
    if (fp == NULL) 
    {
        perror("File Not Found");
        exit(EXIT_FAILURE);
    }	
    return 0;
}
