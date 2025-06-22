
#include <stdio.h>
#include "kolejka.h"

void menu(void)
{
    printf("\n");
    printf("1 - wstaw liczbe do kolejki (Wstaw)\n");
    printf("2 - odczytaj wartosc z poczatku kolejki (Pierwszy)\n");
    printf("3 - usun liczbe z kolejki (Usun)\n");
    printf("4 - sprawdz czy kolejka jest pusta\n");
    printf("5 - sprawdz czy kolejka jest pelna\n");
    printf("6 - koniec programu\n");
    printf("\n");
}

int main()
{
    int temp = 0;
    int option = 0;
    printf("KOLEJKA - implementacja w tablicy statycznej\n");
    while (1)
    {
        menu();
        scanf("%d", &option);


        switch (option)
        {
            case 1:
                if ( !isQueueFull() ){
                    printf("Podaj wartosc: ");
                    scanf("%d", &temp);
                    wstaw(temp);
                }
                else {
                    printf("operacja niedozwolona KOLEJKA pelna!!!\n\n");
                }

                break;

            case 2:
                if (!isQueueEmpty()) {
                    temp = pierwszy();
                    printf("Odczytana wartosc: %d", temp);
                }
                else {
                    printf("operacja niedozwolona KOLEJKA pusta!!!\n\n");
                }

                break;

            case 3:
                if (!isQueueEmpty()) {
                    temp = usun();
                    printf("Odczytana wartosc: %d", temp);
                }
                else {
                    printf("operacja niedozwolona KOLEJKA pelna!!!\n\n");
                }
                break;

            case 4:
                if (isQueueEmpty()) {
                    printf("KOLEJKA jest pusta.\n");
                }
                else {
                    printf("KOLEJKA nie jest pusta.\n");
                }
                break;

            case 5:
                if (isQueueFull()) {
                    printf("KOLEJKA jest pelna.\n");
                }
                else {
                    printf("KOLEJKA nie jest pelna.\n");
                }
                break;

            case 6:
                //zakonczenie programu
                return 0;

            default:
                printf("Wybierz wlasciwa opcje.\n\n");
                break;
        }
    }

    return 0;
}