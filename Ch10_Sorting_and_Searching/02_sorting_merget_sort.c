/* Bubble sort code */

#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int elem){

    printf("    ");
    for (int c = 0; c < elem; c++)
        printf("%d, ", array[c]);

    printf("\n");
}



void merge(int *array,int *helper,int low,int middle,int high)
{

    //copy both halves into a helper array
    for(int i = low; i <= high; i++){
        helper[i] = array[i];
    }

    int helperLeft  = low;
    int helperRight = middle + 1;
    int current = low;

    //Iterate through helper array.
    //Compare the left and right half, copying back the smaller element from the two halves
    //into the orighinal array
    while(helperLeft <= middle && helperRight <= high)
    {
        if(helper[helperLeft] < helper[helperRight]){
            array[current] = helper[helperLeft];
            helperLeft++;
        }else{
            //if right element is smaller than left element
            array[current] = helper[helperRight];
            helperRight++;
        }
        current++;
    }

    //copy the rest of left side of the array into
    //the target array
    int remaining = middle - helperLeft;
    for(int i=0; i <=remaining; i++){
        array[current + i] =helper[helperLeft + i];
    }

}

//runtime: O(nlogn) avg, worst case
//Memory: depends
void merge_sort(int *array, int *helper,int low,int high)
{
    if(low < high)
    {
        int mid=(low + high)/2;
        merge_sort(array,helper,low,mid);        //left recursion
        merge_sort(array,helper,mid+1,high);    //right recursion
        merge(array,helper,low,mid,high);    //merging of two sorted sub-arrays
    }
}



int main()
{

    //create demo array
    int elem = 7;
    int array[elem];
    srand(1);

    //for(int i = 0; i<elem; i++){
    //    array[i]= rand()%50;
    //}
    array[0] = 38;
    array[1] = 27;
    array[2] = 43;
    array[3] = 3;
    array[4] = 9;
    array[5] = 82;
    array[6] = 10;


    printf("\nUnstored Array:\n");
    printArray(array,elem);



    //sorting, array, lowidx, hgighidx
    int helper[elem];
    merge_sort(array,helper,0,elem-1);


    //result
    printf("\nSorted list in ascending order:\n");
    printArray(array,elem);

    return 0;
}
