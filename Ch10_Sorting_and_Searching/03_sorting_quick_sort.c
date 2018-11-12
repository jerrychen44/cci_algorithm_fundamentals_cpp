/* Bubble sort code */

#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int elem){

    printf("    ");
    for (int c = 0; c < elem; c++)
        printf("%d, ", array[c]);

    printf("\n");
}

void swap(int *array,int left,int right){
    printf("    swap, left %d, right %d\n",left, right);

    int tmp = array[left];
    array[left] = array[right];
    array[right] = tmp;
}


int partition(int *array,int left,int right){

    printf("partition~\n");
    int pivot_value = array[(left + right) / 2];//pick a pivot point
    printf("    pivot_value: =  array[%d] = %d\n",(left + right) / 2,pivot_value);

    while(left <= right){
        printf("    left %d, right %d \n",left,right);
        //Find element on left taht should be on right
        printf("    array[left]:%d, array[right]:%d, pivot_value:%d\n",array[left],array[right], pivot_value);
        while(array[left] < pivot_value){
            //let left keep going increasing,
            //it will stop increasing when we find
            //the element > pivot_value
            //we will use this left index to swap later
            printf("    array[%d]=%d < pivot_value: %d, left++ = %d\n",left,array[left],pivot_value, left+1);
            left++;
        }

        //the same as above
        //Find element on right that should be on left
        while( array[right] > pivot_value){
            printf("    array[%d]=%d > pivot_value: %d, right-- = %d\n",right,array[right],pivot_value, right-1);

            right --;
        }


        //now we have the index left and right which
        //is the item need to be swap
        if(left <= right){
            swap(array, left, right);//swaps element value
            printArray(array,7);

            //keep chaning the index to ready for next round.
            left++;
            right--;
        }


    }

    //after finishing the while above, left index will be a
    //index that the value can split the array.
    return left;
}


//runtime:
//Memory:
//In place sort
void quick_sort(int *array,int left,int right){

    int index = partition(array, left, right);
    printf("index: %d\n",index);

    if(left < index -1){
        printf("left~\n");
        quick_sort(array,left,index-1);
    }

    if(index < right){
        printf("right~\n");
        quick_sort(array,index,right);
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
    quick_sort(array,0,elem-1);


    //result
    printf("\nSorted list in ascending order:\n");
    printArray(array,elem);

    return 0;
}
