/*
 * 10.c
 *
 *  Created on: Apr 28, 2023
 *      Author: ARAFA
 */

#include<stdio.h>
int maxOnesBetweenZeros(int arr[], int len) {	// fun to calculate max zeros
    int maxOnes = 0;
    int onesCount = 0;
    int zeroFound = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] == 0) {
            if (zeroFound) {
                if (onesCount > maxOnes) {
                    maxOnes = onesCount;
                }
                onesCount = 0;
            } else {
                zeroFound = 1;
            }
        } else {
            if (zeroFound) {
                onesCount++;
            }
        }
    }
    return maxOnes;
}
int main(){
	int arr[] = {1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1};
	int len = sizeof(arr) / sizeof(arr[0]);
	int maxOnes = maxOnesBetweenZeros(arr, len);
	printf("Max number of ones between two zeros: %d\n", maxOnes);

	return 0;
}
