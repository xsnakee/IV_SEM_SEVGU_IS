#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int **fillArr(int **arr, size_t nRow, size_t nCol){

	for (size_t i = 0; i < nRow; ++i)
		for(size_t j = 0; j < nCol; ++j){
			scanf("%d",&arr[i][j]);
		}

	return arr;
}

void printMatrix (int **arr, size_t nRow, size_t nCol){

	for (size_t i = 0; i < nRow; ++i){
		for(size_t j = 0; j < nCol; ++j){
			printf("%+.3d ", arr[i][j]);
		}
		puts("\n");
	}

}

int *searchZero(int **arr, size_t nRow, size_t nCol){

	int *zeroArr = (int*) calloc(nRow,sizeof(int));


	for (size_t i = 0; i < nRow; ++i){

    size_t zeroCount = 0;

		for(size_t j = 0; j < nCol; ++j){

      		if (arr[i][j] == 0) {

			++zeroCount;

			}
		}
    zeroArr[i] = zeroCount;

  }

  return zeroArr;

}


void printArr(int *arr,size_t size){

	for(size_t j = 0; j < size; ++j){
			printf("%+.3d ", arr[j]);
		}

}

int main(){
//clrscr();
system("cls");
size_t nRow = 0, nCol = 0;

printf("Enter size of matrix: \n");
printf("Enter Row count: ");
scanf("%d", &nRow);
printf("Enter Col couunt: ");
scanf("%d", &nCol);

int **arr = (int**) calloc(nRow, sizeof(int));

for(size_t i = 0; i < nCol; ++i){
	arr[i] = (int*) calloc(nCol, sizeof(int));
}

fillArr(arr, nRow, nCol);

printMatrix(arr, nRow, nCol);

int *zeroArr;
zeroArr = searchZero(arr,nRow,nCol);


printf("#��ப�|���-�� �㫥� \n");

for(size_t i = 0; i < nRow; ++i){
	printf("%6d %8d \n", (i+1), zeroArr[i]);
}

//printArr(zeroArr, nRow);

for(size_t i = 0; i < nRow; ++i){
	free(arr[i]);
}


free(arr);
free(zeroArr);

getch();
return 0;
}
