#include <stdio.h>

void main()
{
    char buff[255];
    char text[255];
    FILE *fptr;

    fptr = fopen("puisi.txt", "w");

    printf("Inputkan isi file: ");
    fgets(text, sizeof(text), stdin);

    fputs(text, fptr);

    printf("File berhasil ditulis\n");

    fclose(fptr);
}
