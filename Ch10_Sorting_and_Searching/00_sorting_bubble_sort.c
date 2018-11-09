/* Bubble sort code */

#include <stdio.h>
#include <stdlib.h>


void bubble_sort(int *array,int n){
    //the last item doesn't need to swap, so i to n-1
    //first loop only provide the looping , doesn't effect the index
    //ex: we have 10 number , we need sort 9 times
    for (int i = 0 ; i < n - 1; i++)
    {
        //less and less element you need to handle
        // j to n -i "-1" is beause the j+1 will over the array index.
        for (int j = 0 ; j < n - 1 - i; j++)
        {
            // For decreasing order use <
            if (array[j] > array[j+1])
            {
                int swap   = array[j];
                array[j]   = array[j+1];
                array[j+1] = swap;
            }
        }
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
        printf("%d, ", array[i]);
    }



    //sorting
    bubble_sort(array,elem);


    //result
    printf("\nSorted list in ascending order:\n");

    for (int c = 0; c < elem; c++)
        printf("%d, ", array[c]);

    printf("\n");
    return 0;
}
