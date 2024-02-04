#include <stdio.h>

// Constants
const int ITEMS_PER_STACK = 64;
const int STACKS_PER_SHULKER_BOX = 27;

// Function to calculate stacks and shulker boxes needed
void calculateStorage(int items, int &stacks, int &remainingItems, double &shulkerBoxes) {
    // Calculate the number of stacks
    stacks = items / ITEMS_PER_STACK;

    // Calculate the remaining items after filling the stacks
    remainingItems = items % ITEMS_PER_STACK;

    // Calculate the number of shulker boxes as a floating-point value
    shulkerBoxes = static_cast<double>(stacks) / STACKS_PER_SHULKER_BOX;
}

// Function to calculate items and shulker boxes needed
void calculateItemsAndShulkerBoxes(int stacks, int &items, double &shulkerBoxes) {
    // Calculate the total items
    items = stacks * ITEMS_PER_STACK;

    // Calculate the number of shulker boxes as a floating-point value
    shulkerBoxes = static_cast<double>(stacks) / STACKS_PER_SHULKER_BOX;
}

// Function to calculate stacks and items needed
void calculateStacksAndItems(double shulkerBoxes, int &stacks, int &items) {
    // Calculate the total stacks
    stacks = static_cast<int>(shulkerBoxes * STACKS_PER_SHULKER_BOX);

    // Calculate the total items
    items = stacks * ITEMS_PER_STACK;
}

int main() {
    char calculateAgain;

    do {
        int operation;
        printf("Choose operation:\n");
        printf("1. items to stacks and shulker boxes\n");
        printf("2. stacks to items and shulker boxes\n");
        printf("3. shulker boxes to stacks and items\n");
        printf("Enter the operation number: ");
        scanf("%d", &operation);

        switch (operation) {
        case 1:
            // Translate items to stacks and shulker boxes
            int items;
            printf("Enter the amount of items: ");
            scanf("%d", &items);

            int stacks, remainingItems;
            double shulkerBoxes;
            calculateStorage(items, stacks, remainingItems, shulkerBoxes);

            printf("Number of stacks needed: %d\n", stacks, "and ", remainingItems, " items");
            printf("Number of shulker boxes needed: %.2f\n", shulkerBoxes);
            break;

        case 2:
            // Translate stacks to items and shulker boxes
            int inputStacks;
            printf("Enter the amount of stacks: ");
            scanf("%d", &inputStacks);

            int translatedItems;
            double translatedShulkerBoxes;
            calculateItemsAndShulkerBoxes(inputStacks, translatedItems, translatedShulkerBoxes);

            printf("Total items: %d\n", translatedItems);
            printf("Number of shulker boxes needed: %.2f\n", translatedShulkerBoxes);
            break;

        case 3:
            // Translate shulker boxes to stacks and items
            double inputShulkerBoxes;
            printf("Enter the amount of shulker boxes: ");
            scanf("%lf", &inputShulkerBoxes);

            int translatedStacks, translatedItems2;
            calculateStacksAndItems(inputShulkerBoxes, translatedStacks, translatedItems2);

            printf("Total stacks: %d\n", translatedStacks);
            printf("Total items: %d\n", translatedItems2);
            break;

        default:
            printf("Invalid operation. Please choose a valid operation number.\n");
            break;
        }

        // Ask if the user wants to calculate again
        printf("Do you want to calculate again? (y/n): ");
        scanf(" %c", &calculateAgain);

    } while (calculateAgain == 'y' || calculateAgain == 'Y');

    return 0;
}
