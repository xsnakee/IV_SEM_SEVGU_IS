#include <stdio.h>
#include <conio.h>
#include <cstdlib>

int *randomFillArr(int *mainArr, size_t arrSize) {

	for (size_t i = 0; i < arrSize; ++i) {
		mainArr[i] = rand();
	}

	return mainArr;
}


void printArr(int *mainArr, size_t arrSize) {
	
	for (size_t i = 0; i < arrSize; ++i) {
		printf("%3d ", mainArr[i]);
	}

}


void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int *revertArr(int *mainArr, size_t arrSize) {
	
	for (size_t i = 0; i < (arrSize / 2); ++i) {
		swap(mainArr[i], mainArr[(arrSize - 1) - i]);
	}

	return mainArr;
}


int main() {
	size_t ARR_SIZE = 0;
	printf("Enter array size: ");
	scanf("%d", &ARR_SIZE);

	int *arr = (int*)malloc (sizeof(int)*ARR_SIZE);

	randomFillArr(arr, ARR_SIZE);
	printArr(arr, ARR_SIZE);
	putch('\n');

	revertArr(arr, ARR_SIZE);
	printArr(arr, ARR_SIZE);
	free(arr);
	return 0;
}
