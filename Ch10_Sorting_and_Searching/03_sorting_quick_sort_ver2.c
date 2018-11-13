/* Bubble sort code */

#include <stdio.h>
#include <stdlib.h>

int elem = 7;

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

void swap(int *array,int a,int b){
    printf("    swap, a %d, b %d\n",a, b);

    int tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}


int partition(int *array,int start,int end){

    //we force select last element as pivot
    int pivot = array[end];
    printf("pivot:%d\n",pivot);
    int partitionIndex = start;//initially set start as its value
    //loop over the array
    printf("loop start~end, find smaller one\n");
    for(int i=start; i<end;i++){
        //find the smaller one to swap
        if(array[i] <= pivot){
            swap(array,i,partitionIndex);
            printArray(array,elem);

            partitionIndex++;
        }
    }

    //must swap pivot element to the middle to
    //split the array
    printf("the middle swap\n");
    swap(array,partitionIndex,end);
    printArray(array,elem);

    return partitionIndex;

}

// 1.Divide and conquer
// 2.Recursive
// 3.Not stable sorting
// 4.In-place
//runtime:Best O(nlogn), worst O(n^2), Avg use randomPivot O(nlogn)
//Memory: O(logn)
void quick_sort(int *array,int start,int end){

    printf("quick_sort,start=%d, end=%d\n",start, end);
    if(start < end){
        int partitionIndex = partition(array,start,end);//call partition to split left and right
        quick_sort(array,start,partitionIndex-1);
        quick_sort(array,partitionIndex+1,end);
    }else
        printf("start > end, do nothing!\n");

}



int main()
{

    //create demo array
    //int elem = 7;
    int array[elem];
    srand(1);

    //for(int i = 0; i<elem; i++){
    //    array[i]= rand()%50;
    //}
    array[0] = 38;
    array[1] = 27;
    array[2] = 43;
    array[3] = 16;
    array[4] = 9;
    array[5] = 82;
    array[6] = 10;


    printf("\nUnstored Array:\n");
    printArray(array,elem);



    //sorting, array, lowidx, hgighidx
    quick_sort(array,0,elem-1);


    //result
    printf("\nSorted list in ascending order:\n");
    printArray(array,elem);

    return 0;
}
