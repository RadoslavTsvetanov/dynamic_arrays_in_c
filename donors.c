#include <stdio.h>
#include <stdlib.h>
#include "dynarr.h"

void add_donator(DynamicArray *donators, double egn)
{
    pushback(donators, egn);
    printf("Donator with EGN %.0lf added.\n", egn);
}

void remove_donator(DynamicArray *donators, double egn)
{
    int index = -1;
    for (int i = 0; i < donators->size; i++)
    {
        if (getel(donators, i) == egn)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Donator with EGN %.0lf not found.\n", egn);
    }
    else
    {
        pop(donators, index);
        printf("Donator with EGN %.0lf removed.\n", egn);
    }
}

void list_donators(DynamicArray *donators)
{
    printf("Donators:\n");
    for (int i = 0; i < donators->size; i++)
    {
        printf("%.0lf\n", getel(donators, i));
    }
}

int main(void)
{
    DynamicArray donators = init(10);

    while (1)
    {
        printf("\n1. Add donator\n2. Remove donator\n3. List donators\n4. Exit\n\nEnter option: ");
        int option;
        scanf("%d", &option);

        if (option == 1)
        {
            printf("Enter EGN of donator: ");
            double egn;
            scanf("%lf", &egn);
            add_donator(&donators, egn);
        }
        else if (option == 2)
        {
            printf("Enter EGN of donator to remove: ");
            double egn;
            scanf("%lf", &egn);
            remove_donator(&donators, egn);
        }
        else if (option == 3)
        {
            list_donators(&donators);
        }
        else if (option == 4)
        {
            break;
        }
        else
        {
            printf("Invalid option.\n");
        }
    }

    free(donators.buffer);
    printf("Exiting program...\n");

    return 0;
}
