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

int binary_serach(int *array, int targetvalue,int elenum){

    //int elenum = sizeof(array)/sizeof(array[0]);
    //printf("elenum %d\n",elenum);

    int lowidx = 0;
    int highidx = elenum -1;
    int mididx;

    while(lowidx<=highidx){
        mididx = (lowidx + highidx)/2;

        if(array[mididx] < targetvalue){
            lowidx = mididx +1;
        }else if(array[mididx] > targetvalue){
            highidx = mididx-1;
        }else{
            return mididx;
        }
    }


    //all lowidx and highidx are running out but not found
    return -1; //Error
}


int binary_search_recursive(int *array, int targetvalue, int lowidx, int highidx){

    //base case
    if(lowidx > highidx)
        return -1;

    int mididx = (lowidx + highidx)/2;


    if( array[mididx] < targetvalue) {
        return binary_search_recursive(array, targetvalue, mididx+1, highidx);
    }else if(array[mididx] > targetvalue){
        return binary_search_recursive(array, targetvalue, lowidx, mididx -1);
    }else {
        return mididx;
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

    int array[] = {9,33,54,78,132,198,243};
    int elem = sizeof(array)/sizeof(array[0]);

    printf("\nStored Array, elem %d:\n",elem);
    printArray(array,elem);


    //seraching
    int targetvalue = 33;
    int result_idx = binary_serach(array,targetvalue,elem);
    printf("result_idx= %d, value = %d\n", result_idx, array[result_idx]);

    int result_idx_rec = binary_search_recursive(array,targetvalue,0,elem-1);
    printf("result_idx_rec= %d, value = %d\n", result_idx_rec, array[result_idx_rec]);


    return 0;
}
