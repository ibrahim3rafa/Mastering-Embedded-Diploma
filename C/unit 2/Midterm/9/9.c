/*
 * 9.c
 *
 *  Created on: Apr 28, 2023
 *      Author: ARAFA
 */


#include<stdio.h>
#include<string.h>
#define SIZE 100
void reverseWords(char str[], int len) {
    int start = 0;
    int end = len - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    start = 0;
    while (start < len) {
        while (str[start] == ' ' && start < len) {
            start++;
        }
        end = start;
        while (str[end] != ' ' && end < len) {
            end++;
        }
        int wordLen = end - start;
        for (int i = 0; i < wordLen / 2; i++) {
            char temp = str[start + i];
            str[start + i] = str[end - i - 1];
            str[end - i - 1] = temp;
        }
        start = end + 1;
    }

}
int main()
{
	char str[] = "mohamed gamal";
	int len = sizeof(str) / sizeof(str[0]);
	reverseWords(str, len);
	printf("%s\n", str);
}
