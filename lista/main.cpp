#include <iostream>
#include "list.h"

void clear(void) {
    while (getchar() != '\n');
}

void menu(void) {
    printf("SIMPLE LINKED LIST using structures\n");
    printf("1. Add an element at the front\n");
    printf("2. Add an element at the back\n");
    printf("3. Add an element after a certain node\n");
    printf("4. Delete the first element\n");
    printf("5. Delete the last element\n");
    printf("6. Delete a certain element\n");
    printf("7. Print the list\n");
    printf("8. Search for an element\n");
    printf("9. Clear list\n\n");
    printf("0. Exit\n\n");
}

int main()
{
    int value = 0, index = 0, option = 0, errorCode = 0;

    while (1) {
        menu();
        while (!scanf("%d", &option)) {
            printf("Not an integer! Input an integer: ");
            clear();
        }
        switch (option) {
            case 1: // add at the front
                system("cls");
                printf("Input a number: ");
                while (!scanf("%d", &value)) {
                    printf("Not an integer! Input an integer: ");
                    clear();
                }
                errorCode = insertFront(value);
                !errorCode ? printf("Added successfully!\n\n") : printf("Failed to add.\n\n");
                break;

            case 2: // add at the back
                system("cls");
                printf("Input a number to be added: ");
                while (!scanf("%d", &value)) {
                    printf("Not an integer! Input an integer: ");
                    clear();
                }
                errorCode = insertBack(value);
                !errorCode ? printf("Added successfully!\n\n") : printf("Failed to add.\n\n");
                break;

            case 3: // add after a certain node
                system("cls");
                printf("Input after which element would you like to add a number: ");
                while (!scanf("%d", &index)) {
                    printf("Not an integer! Input an integer: ");
                    clear();
                }
                printf("Input a number to be added: ");
                while (!scanf("%d", &value)) {
                    printf("Not an integer! Input an integer: ");
                    clear();
                }
                errorCode = insertAfterNode(index, value);
                !errorCode ? printf("Added successfully!\n\n") : printf("Failed to add.\n\n");
                break;

            case 4: // delete the first element
                system("cls");
                errorCode = deleteFront();
                !errorCode ? printf("First element deleted successfully!\n\n") : printf("Failed to delete the first element.\n\n");
                break;

            case 5: // delete the last element
                system("cls");
                errorCode = deleteBack();
                !errorCode ? printf("Last element deleted successfully!\n\n") : printf("Failed to delete the last element.\n\n");
                break;

            case 6: // delete a certain element
                system("cls");
                if (getNodesCount()) {
                    printf("Input which element would you like to delete: ");
                    while (!scanf("%d", &index)) {
                        printf("Not an integer! Input an integer: ");
                        clear();
                    }
                    errorCode = deleteNode(index);
                }
                else {
                    errorCode = EXIT_FAILURE;
                }
                !errorCode ? printf("Element no. %d deleted successfully!\n\n", index) : printf("Failed to delete the element.\n\n");
                break;

            case 7: // print the list
                system("cls");
                printf("List: ");
                printList();
                printf("\n%d elements\n\n", getNodesCount());
                break;

            case 8: // find an element
                system("cls");
                printf("Input the element you would like to find: ");
                while (!scanf("%d", &value)) {
                    printf("Not an integer! Input an integer: ");
                    clear();
                }
                errorCode = searchList(value);
                !errorCode ? printf("The element %d is in the list.\n\n", value) : printf("There is no element %d in the list.\n\n", value);
                break;

            case 9: // clear the list
                system("cls");
                freeList();
                printf("List cleared.\n");
                break;

            case 0:
                freeList();
                return 0;

            default:
                system("cls");
                printf("Wybierz wlasciwa opcje.\n\n");
                break;
        }
    }
    freeList();
    return 0;
}