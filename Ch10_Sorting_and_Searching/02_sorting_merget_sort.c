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

    printf("    merge===\n");
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

    //compare use helperleft/right indx on helper array
    //and update result to array
    while(helperLeft <= middle && helperRight <= high)
    {
        printf("       helperLeft %d, middle %d, helperRight %d, high %d,current %d\n",
                                            helperLeft, middle, helperRight, high,current);

        //put smaller to the array
        if(helper[helperLeft] < helper[helperRight]){
            printf("           helper[%d] %d < helper[%d] %d\n",helperLeft,helper[helperLeft],helperRight,helper[helperRight]);
            printf("           array[current] = helper[helperLeft] %d, helperLeft++\n",helper[helperLeft]);
            array[current] = helper[helperLeft];
            helperLeft++;
        }else{
            //if right element is smaller than left element
            printf("           helper[%d] %d >= helper[%d] %d\n",helperLeft,helper[helperLeft],helperRight,helper[helperRight]);
            printf("           array[current] = helper[helperRight] %d, helperRight++\n",helper[helperRight]);
            array[current] = helper[helperRight];
            helperRight++;
        }
        current++;
    }

    //copy the left half of the helper array into
    //the target array, to maintain the full array
    //(right half is arleady here as the same with array)
    int remaining = middle - helperLeft;
    for(int i=0; i <=remaining; i++){
        printf("      copy remaining element, array[%d] = helper[%d] %d\n",current + i,helperLeft + i,helper[helperLeft + i]);
        array[current + i] = helper[helperLeft + i];
    }

}

//runtime: O(nlogn) avg, worst case
//Memory: O(n), use helper array to help merge result
//Not a inplace sort
void merge_sort(int *array, int *helper,int low,int high)
{

    if(low < high)
    {
        //printArray(helper,10);

        int mid=(low + high)/2;
        printf("merge_sort: %d ~ %d, mid %d\n",low, high,mid);

        printf("    call for left\n");
        merge_sort(array,helper,low,mid);        //left recursion
        printf("    call for right\n");
        merge_sort(array,helper,mid+1,high);    //right recursion
        printf("    call for merge %d ~ %d\n",low,high);
        merge(array,helper,low,mid,high);    //merging of two sorted sub-arrays
        printArray(array,7);

    }else{
        printf("merge_sort: low %d !< high %d, skip\n",low, high);
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
    for(int i =0; i <elem; i++)
        helper[i] = 0;
    merge_sort(array,helper,0,elem-1);


    //result
    printf("\nSorted list in ascending order:\n");
    printArray(array,elem);

    return 0;
}
