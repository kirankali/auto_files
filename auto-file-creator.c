#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef MAX
#define MAX 100
#endif

int main(int argc, char *argv[]) {
    int limit;
    printf("Enter limit:");
    scanf("%d",&limit);
    const char* str1 = "file_";
    const char* str3 = ".txt";
    for(int i=1;i<=limit;i++){
    int n1 = i;
    FILE * fPtr;
    char *num;
    char buffer[MAX];

    if (asprintf(&num, "%d", n1) == -1) {
        perror("asprintf");
    } else {
        strcat(strcpy(buffer, str1), num);
        strcat(buffer, str3);
        printf("%s\n", buffer);
        fPtr = fopen(buffer, "w");
        /* fopen() return NULL if last operation was unsuccessful */
    if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
/* Write data to file */
    fputs("file created.", fPtr);
   /* Close file to save file data */
    fclose(fPtr);
        free(num);
    } }

    exit(EXIT_SUCCESS);
}
