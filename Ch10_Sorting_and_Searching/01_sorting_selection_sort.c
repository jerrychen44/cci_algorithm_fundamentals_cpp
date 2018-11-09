/* Bubble sort code */

#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int elem){

    printf("    ");
    for (int c = 0; c < elem; c++)
        printf("%d, ", array[c]);

    printf("\n");
}

//runtime O(n^2) avg, worst case
//Memory O(1) for int swap
void selection_sort(int *array,int n){

    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          // record the min_idx
          if (array[j] < array[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        // if min_idx == i we don't have to swap
        printf("step %d, val = %d \n",i,array[i]);
        printf("min_idx = %d, val = %d \n",min_idx,array[min_idx]);

        int swap = array[i];
        array[i] = array[min_idx];
        array[min_idx] = swap;

        printArray(array,n);

    }
}

int main()
{

    //create demo array
    int elem = 10;
    int array[elem];
    srand(1);

    for(int i = 0; i<elem; i++){
        array[i]= rand()%50;
    }
    printf("\nUnstored Array:\n");
    printArray(array,elem);



    //sorting
    selection_sort(array,elem);


    //result
    printf("\nSorted list in ascending order:\n");
    printArray(array,elem);

    return 0;
}
