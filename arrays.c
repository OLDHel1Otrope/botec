#include <stdio.h>
#include <stdlib.h>

void print(int *arr, int size);
void bubblesort(int *arr, int size);
void insertionsort(int *arr, int size);
void linearsearch(int *arr, int size, int key);
int binarysearchloop(int *arr, int size, int key);
int binarysearchrecurr(int *arr, int ln, int rn, int key);
int insertelement(int *arr, int size);
int deleteelement(int *arr, int size);
void selectionsort(int *arr, int size);

int main()
{
    int arr[1000];
    int size;
    int i;
    int choice, choice2;
    int state;
    int index, element;

    printf("Enter the size of the array \t");
    scanf("%d", &size);

    printf("Enter the elements of the array");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Given array is as follows:\n");
    for (i = 0; i < size; i++)
        printf("%d\t", arr[i]);

    // menu goes here
    do
    {
        printf("\nEnter the number of your prefferred choice\n1. Traversal\n2. Insertion\n3. Deletion\n4. Searching\n5. Sorting\n6. Exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            print(arr, size);
            break;
        case 2:
            state = insertelement(arr, size);
            size++;
            break;
        case 3:
            state = deleteelement(arr, size);
            size--;
            break;
        case 4:
            printf("enter the method you want to use for searching (1)Linear Search (2)Binary search ");
            scanf("%d", &choice2);
            switch (choice2)
            {
            case 1:
                printf("\n enter the element to be searched\t");
                scanf("%d", &element);
                linearsearch(arr, size, element);
                break;
            case 2:
                printf("\n enter the element to be searched\t");
                scanf("%d", &element);
                printf("\n element found at index %d", binarysearchloop(arr, size, element));
                break;
            case3:
                printf("/n enter the element to be searched\t");
                scanf("%d", &element);
                printf("\n element found at index %d", binarysearchrecurr(arr, 0, size, element));
                break;
            }
            break;
        case 5:
            printf("enter the method you want to use for sorting (1)Bubble Sort (2)Insertion Sort (3)Selection Sort");
            scanf("%d", &choice2);
            switch (choice2)
            {
            case 1:
                bubblesort(arr, size);
                break;
            case 2:
                insertionsort(arr, size);
                break;
            case 3:
                selectionsort(arr, size);
                break;

            default:
                break;
            }
            break;
        case 6:
            exit(0);
            break;
        }

    } while (1);
    return 0;
}

//----------------------------------------traversal
void print(int *arr, int size)
{
    int i = 0;
    printf("array is as follows:\n");
    for (i = 0; i < size; i++)
        printf("%d\t", arr[i]);
}

//----------------------------------------inserting element

int insertelement(int *arr, int size)
{
    int position;
    int value;
    printf("enter the position and the value you want to insert there");
    scanf("%d", &position);
    if (position > size)
    {
        return -1;
    }
    scanf("%d", &value);
    int i;
    for (i = size - 1; i >= position - 1; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[position - 1] = value;
    return 1;
}

//----------------------------------------deleting element
int deleteelement(int *arr, int size)
{
    int position;
    printf("\nenter the position of the value to be deleted");
    scanf("%d", &position);
    if (position > size)
    {
        return -1;
    }
    int i;
    for (i = position - 1; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}

//----------------------------------------bubblesort element
void bubblesort(int *arr, int size)
{
    int i, j, temp, flag;
    for (i = 0; i < size - 1; i++)
    {
        flag = 0;

        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
        if (flag != 1)
            break;
    }
}

//----------------------------------------insertionsort element
void insertionsort(int *arr, int size)
{
    int i, temp, j;
    for (i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (arr[j] > temp && j > -1)
        {

            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

//----------------------------------------selection sort
void selectionsort(int *arr, int size)
{
    int i;
    int j;
    int smallest;
    int si;
    int temp;
    for (i = 0; i < size - 1; i++)
    {
        smallest = arr[i];
        si = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < smallest)
            {
                smallest = arr[j];
                si = j;
            }
        }
        temp = arr[i];
        arr[i] = smallest;
        arr[si] = temp;
    }
}

//----------------------------------------linear element
void linearsearch(int *arr, int size, int key)
{
    int i;
    int flag = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            if (flag == 0)
                printf("element found at index:");
            flag = 1;
            printf("\t%d", i);
        }
    }
}

//----------------------------------------binary search using loop
int binarysearchloop(int *arr, int size, int key)
{
    int ln = 0;
    int rn = size - 1;

    while (ln <= rn)
    {
        int mid = ln + (rn - ln) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            rn = mid - 1;
        else if (arr[mid] < key)
            ln = mid + 1;
    }
    return -1;
}

//----------------------------------------binary search using recursion
int binarysearchrecurr(int *arr, int ln, int rn, int key)
{
    int mid = ln + (rn - ln) / 2;
    if (arr[mid] == key)
        return mid;
    else if (ln > rn)
        return -1;
    else if (ln == rn && arr[mid] != key)
        return -1;
    else if (arr[mid] > key)
        return binarysearchrecurr(arr, ln, mid - 1, key);
    else
        return binarysearchrecurr(arr, mid + 1, rn, key);
}
