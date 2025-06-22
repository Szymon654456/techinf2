#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char *program_name) {
    printf("Sposob uzycia: %s <komunikat> <#powtorzen>\n", program_name);
    exit(1);
}

int main(int argc, char *argv[]) {
    int Result;
    int FirstNumber;
    int SecondNumber;
    FILE *file;

    if (argc < 4)
        usage(argv[0]);
    FirstNumber = atoi(argv[1]);
    SecondNumber = atoi(argv[3]);

    file = fopen("wyniki.txt", "a");
    if (file == NULL) {
        printf("Nie można otworzyć pliku do zapisu.\n");
        return 1;
    }

    if (strcmp(argv[2], "add") == 0) {
        Result = FirstNumber + SecondNumber;
        printf("%d + %d = %d", FirstNumber, SecondNumber, Result);
        fprintf(file, "%d + %d = %d\n", FirstNumber, SecondNumber, Result);
    }
    else if (strcmp(argv[2], "substract") == 0) {
        Result = FirstNumber - SecondNumber;
        printf("%d - %d = %d", FirstNumber, SecondNumber, Result);
        fprintf(file, "%d - %d = %d\n", FirstNumber, SecondNumber, Result);
    }
    else if (strcmp(argv[2], "multiply") == 0) {
        Result = FirstNumber * SecondNumber;
        printf("%d * %d = %d", FirstNumber, SecondNumber, Result);
        fprintf(file, "%d * %d = %d\n", FirstNumber, SecondNumber, Result);
    }
    else if (strcmp(argv[2], "divide") == 0) {
        if (SecondNumber == 0) {
            printf("Nie mozna dzielic przez 0\n");
            fprintf(file, "Dzielenie przez 0\n");
        } else {
            Result = FirstNumber / SecondNumber;
            printf("%d / %d = %d", FirstNumber, SecondNumber, Result);
            fprintf(file, "%d / %d = %d\n", FirstNumber, SecondNumber, Result);
        }
    }
    else {
        printf("Nieznana operacja");
        fprintf(file, "Nieznana operacja: %s\n", argv[2]);
    }

    fclose(file);
    return 0;
}