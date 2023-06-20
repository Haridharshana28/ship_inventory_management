#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

void addNewItem(Item items[], int *itemCount) {
    if (*itemCount == MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    Item newItem;

    printf("Enter item name: ");
    scanf("%s", newItem.name);

    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    items[*itemCount] = newItem;
    (*itemCount)++;

    printf("Item added successfully.\n");
}

void displayInventory(Item items[], int itemCount) {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("Inventory:\n");
    printf("--------------------------------------------------------\n");
    printf("| %-30s | %-10s | %-10s |\n", "Item Name", "Quantity", "Price");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < itemCount; i++) {
        printf("| %-30s | %-10d | $%-9.2f |\n", items[i].name, items[i].quantity, items[i].price);
    }

    printf("--------------------------------------------------------\n");
}

int main() {
    Item items[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    do {
        printf("Inventory Management System\n");
        printf("1. Add new item\n");
        printf("2. Display inventory\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewItem(items, &itemCount);
                break;
            case 2:
                displayInventory(items, itemCount);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}

