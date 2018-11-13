/* Bubble sort code */

#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int elem){

    printf("    ");
    for (int c = 0; c < elem; c++)
        printf(" %d, ",c);
    printf("\n");

    printf("    ");
    for (int c = 0; c < elem; c++)
        printf("----");
    printf("\n");

    printf("    ");
    for (int c = 0; c < elem; c++)
        printf("%d, ", array[c]);

    printf("\n");
}

int getMax(int *arr, int n) {
    int mx = arr[0];
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
//stable sorts
//Time: O(n+k), n is elements, k is the digit range ex: 0~9 or 0~3
//Space: O(n+k)

void countSort(int *arr, int n, int exp) {
    int output[n]; // output array
    //10 is because the base is 10
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++){
        count[(arr[i] / exp) % 10]++;

    }
    //debug
    for (i = 0; i < 10; i++){
        printf("count[%d]=%d, ",i, count[i]);
    }
    printf("\n");


    //record the element number before i,
    //ex: count[2] = 3, means there are 3 elements before the element which has digit 2
    //which means, digt 0, digt 1 might totally added up with 3 elements.
    // count[] become an index map for putting array to output array
    for (i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
    //debug
    for (i = 0; i < 10; i++){
        printf("count[%d]=%d, ",i, count[i]);
    }
    printf("\n");
    // Build the output array
    // go through the original array and following the count array to write
    // result to output array. (when you write a new element, need +1 for count array)

    //instead, if we start from the end of array, we need -- the count array .
    for (i = n - 1; i >= 0; i--) {
        int dig = (arr[i] / exp) % 10;
        printf("output[count[%d]] = arr[%d] = %d\n",dig,i,arr[i]);
        output[count[dig] - 1] = arr[i];
        count[dig]--;
    }
    //debug
    for (i = 0; i < 10; i++){
        printf("count[%d]=%d, ",i, count[i]);
    }
    printf("\n");
    //copy back to original array
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}



//LSD(Least Significant Digital): from right digit to left ex: 173-> 3, 7, 1
//MSD(Most Significant Digital): from left to right

// The main function to that sorts arr[] of size n using Radix Sort
void radix_sort(int *arr, int n) {
    int m = getMax(arr, n);

    int exp;
    for (exp = 1; m / exp > 0; exp *= 10){
        printf("exp:%d\n",exp);
        countSort(arr, n, exp);
        printArray(arr,n);

    }
}

int main()
{

    //create demo array
    //int elem = 7;
    //int array[elem];
    //sand(1);

    //for(int i = 0; i<elem; i++){
    //    array[i]= rand()%50;
    //}

    int array[] = { 38, 277, 43, 216, 9, 82, 99};
    int elem = sizeof(array)/sizeof(array[0]);

    printf("\nUnstored Array:\n");
    printArray(array,elem);



    //sorting, array, lowidx, hgighidx
    radix_sort(array,elem);


    //result
    printf("\nSorted list in ascending order:\n");
    printArray(array,elem);

    return 0;
}
