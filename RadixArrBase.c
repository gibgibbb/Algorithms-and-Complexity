#include <stdio.h>
#include <stdlib.h>

void radixSort(int arr[], int n);

void radixSort(int arr[], int n){
    int i;

    /* ---------------------------
       STEP 1: Find minimum value
    ----------------------------*/
    int min = arr[0];
    for(i = 1; i < n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }

    /* ---------------------------
       STEP 2: Shift if negative
    ----------------------------*/
    int shift = 0;
    if(min < 0){
        shift = -min;
        for(i = 0; i < n; i++){
            arr[i] += shift;
        }
    }

    /* ---------------------------
       STEP 3: Find maximum value
       (after shifting)
    ----------------------------*/
    int max = arr[0];
    for(i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    /* ---------------------------
       STEP 4: Standard Radix Sort
    ----------------------------*/
    for(int exp = 1; max / exp > 0; exp *= 10){

        int output[n];
        int count[10] = {0};

        /* Count digit occurrences */
        for(i = 0; i < n; i++){
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        /* Convert to cumulative count */
        for(i = 1; i < 10; i++){
            count[i] += count[i - 1];
        }

        /* Build output array (stable) */
        for(i = n - 1; i >= 0; i--){
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        /* Copy back */
        for(i = 0; i < n; i++){
            arr[i] = output[i];
        }
    }

    /* ---------------------------
       STEP 5: Shift back
    ----------------------------*/
    if(shift != 0){
        for(i = 0; i < n; i++){
            arr[i] -= shift;
        }
    }
}

int main(){
	

	
	int arr[10] = {21, 54, -3, 10, -12, 142, 139, -19, 75, 214};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Unsorted\n");
	int x;
	for(x = 0; x < size; x++){
		printf("%d ", arr[x]);
	}
	
	radixSort(arr, size);
	printf("\nSorted\n");
	for(x = 0; x < size; x++){
		printf("%d ", arr[x]);
	}
	
	
	return 0;
}
