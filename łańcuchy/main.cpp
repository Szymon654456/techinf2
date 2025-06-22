#include <stdio.h>

void changeToSmall(char *text) {
    while (*text) {
        if ('A' <= *text && *text <= 'Z') {
            *text += ('a' - 'A');
        }
        text++;
    }
}
void changeToBig(char *text) {
    while (*text) {
        if ('a' <= *text && *text <= 'z') {
            *text -= ('a' - 'A');
        }
        text++;
    }
}

void changeOddToBig(char *text) {
    int temp = 0;
    while (*(text+temp)) {
        if ('a' <= *(text+temp) && *(text+temp) <= 'z' && temp % 2 != 0) {
            *(text+temp) -= ('a' - 'A');
        }
        temp++;
    }
}

void changeOddToSmall(char *text) {
    int temp = 0;
    while (*(text+temp)) {
        if ('A' <= *(text+temp) && *(text+temp) <= 'Z' && temp % 2 != 0) {
            *(text+temp) += ('a' - 'A');
        }
        temp++;
    }
}

int lengthOf(char *text) {
    int length = 0;
    while (*text) {
        length++;
        text++;
    }
    return length-1;
}

int combineStrings(char *source1, char *source2, char *destination, int maxSize) {
    int size = 0;
    while (*source1) {
        *destination=*source1;
        destination++;
        source1++;
        size++;
    }
    destination--;

    while (*source2) {
        *destination=*source2;
        destination++;
        source2++;
        size++;
    }
    if (maxSize < size) {
        return 1;
    }
    *destination = '\0';
    return 0;
}

int main() {
    char text1[50];
    char text2[50];
    char text[100];
    printf("Podaj tekst 1:\n");
    fgets(text1, sizeof(text1), stdin);
    printf("Podaj tekst 2:\n");
    fgets(text2, sizeof(text2), stdin);
    combineStrings(text1, text2, text, 100);
    printf("Podany tekst:%s", text);
    printf("Dlugosc lancucha to %d\n", lengthOf(text));
    changeToSmall(text);
    printf("Zamiana liter duzych na male:\n%s\n", text);
    changeOddToBig(text);
    printf("Zamiana liter z parzystym indeksem na duze:\n%s\n", text);
    changeToBig(text);
    printf("Zamiana liter malych na duze:\n%s\n", text);
    changeOddToSmall(text);
    printf("Zamiana liter z parzystym indeksem na male:\n%s\n", text);
}