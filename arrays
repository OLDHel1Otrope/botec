#include <stdio.h>

int main()
{
    int x[25] = {3, 6, 9, 45, 78, 89};
    int max_size = 25;
    int size = 6;
    int item;
    int position;
    int i;
    printf("The item and the position of the element, the position should be less than or equal to %d \n", size);
    scanf("%d %d", &item, &position);
    if (position <= size + 1)
    {
        printf("new value to be added: %d  position to be added at in the array: %d", item, position);
        for (i = size - 1; i >= position - 1; i--)
        {
            x[i + 1] = x[i];
        }
        x[position - 1] = item;
        size++;
    }
    else
    {
        printf("invalid position");
    }

    for (i = 0; i < size; i++)
    {
        printf("\nthe %dth value is %d ", i + 1, x[i]);
    }

    return 0;
}
