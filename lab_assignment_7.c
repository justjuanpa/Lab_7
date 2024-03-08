#include <stdio.h>

typedef struct {
    int num;
    int swaps;
} Element;

void selectionSort(Element arr[], int n);
void bubbleSort(Element arr[], int n);

int main(void) 
{
    Element array1[] = {{97, 0}, {16, 0}, {45, 0}, {63, 0}, {13, 0}, {22, 0}, {7, 0}, {58, 0}, {72, 0}};
    Element array2[] = {{90, 0}, {80, 0}, {70, 0}, {60, 0}, {50, 0}, {40, 0}, {30, 0}, {20, 0}, {10, 0}};
    Element array3[] = {{97, 0}, {16, 0}, {45, 0}, {63, 0}, {13, 0}, {22, 0}, {7, 0}, {58, 0}, {72, 0}};
    Element array4[] = {{90, 0}, {80, 0}, {70, 0}, {60, 0}, {50, 0}, {40, 0}, {30, 0}, {20, 0}, {10, 0}};

    int n = 9;

    printf("array1 selection sort:\n");
    selectionSort(array1, n);

    printf("\narray1 bubble sort:\n");
    bubbleSort(array3, n);

    printf("\narray2 selection sort:\n");
    selectionSort(array2, n);

    printf("\narray2 bubble sort:\n");
    bubbleSort(array4, n);

}


void selectionSort(Element arr[], int n) 
{
    int min = 100;
    int minIndx;
    Element tmp;
    int totalSwaps = 0;

    for (int i = 0; i < n; i++)
    {
        int min = 100;

        for(int j = i; j < n; j++)
        {
            if (arr[j].num < min)
            {
                min = arr[j].num;
                minIndx = j;
            }
        }

        if (min != arr[i].num)
        {
            totalSwaps++;
        }
        
        tmp = arr[i];
        arr[i] = arr[minIndx];
        arr[minIndx] = tmp;

        arr[i].swaps++;
        arr[minIndx].swaps++;
    }

    printf("Total swaps: %d\n", totalSwaps);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d:  %d\n", arr[i].num, arr[i].swaps);
    }

}

void bubbleSort(Element arr[], int n) 
{
    Element tmp;
    int totalSwaps = 0;

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j].num > arr[j + 1].num) 
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                arr[j].swaps++;
                arr[j + 1].swaps++;
                totalSwaps++;
            }
        }
    }

    printf("Total swaps: %d\n", totalSwaps);

    for (int i = 0; i < n; i++)
    {
        printf("%d:  %d\n", arr[i].num, arr[i].swaps);
    }
}
