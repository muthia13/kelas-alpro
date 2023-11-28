#include <stdio.h>

void main()
{
    char buff[255];
    FILE *fptr;

    if ((fptr = fopen("puisi.txt", "r")) == NULL)
    {
        printf("Error: File tidak ada!");
        exit(1);
    }

    fgets(buff, sizeof(buff), fptr);
    printf("%s", buff);
    fgets(buff, sizeof(buff), fptr);
    printf("%s", buff);
    fgets(buff, sizeof(buff), fptr);
    printf("%s", buff);
    fgets(buff, sizeof(buff), fptr);
    printf("%s", buff);

    fclose(fptr);
}
