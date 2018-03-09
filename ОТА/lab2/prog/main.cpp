#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <cmath>

using namespace std;

struct result_t{
	size_t assigmentCounter = 0;
	size_t minIndex = 0;	
};

const size_t ARR_SIZE1 = 250, 
			 ARR_SIZE2 = 300,
			 ARR_SIZE3 = 400;
			 
const int MAX_VAL = 950;

int *randomArrFill(int * const arr, const size_t arrSize, const int MAX_VAL){
	
	for (size_t i = 0; i < arrSize; ++i){
		
		
		arr[i] = rand() % MAX_VAL;
		
	}
	
	return arr;
}

void printArr(const int * const arr, const size_t arrSize){
	
	for (size_t i = 0; i < arrSize; ++i){		
		cout << arr[i] << " ";
		
	}	
}

result_t findMin(const int * const arr, const size_t arrSize){
	
	result_t result;
	
	result.minIndex = 0;
	result.assigmentCounter = 0;
	
	for(size_t i = 1; i < arrSize; ++i){
		
		if (arr[i] < arr[result.minIndex]){
			
			result.minIndex = i;
			++result.assigmentCounter;
		}
	}
	
	
	return result;
	
}

double harmonicN(size_t arrSize){
	double result = 0.0;
	
	for(size_t i = 1; i < arrSize; ++i){
		result += 1.0/static_cast<double>(i);
	}
	
	return result;
}

int main(){
	
	srand(time(0)); //randomize function
	
	int arr1[ARR_SIZE1] = {0},
		arr2[ARR_SIZE2] = {0},
		arr3[ARR_SIZE3] = {0};
	
	randomArrFill(arr1, ARR_SIZE1, MAX_VAL);
	randomArrFill(arr2, ARR_SIZE2, MAX_VAL);
	randomArrFill(arr3, ARR_SIZE3, MAX_VAL);
	double Hn1 = 0.0,
			Hn2 = 0.0,
			Hn3 = 0.0;
			
	Hn1 = harmonicN(ARR_SIZE1);
	Hn2 = harmonicN(ARR_SIZE2);
	Hn3 = harmonicN(ARR_SIZE3);	
	
	result_t test1, test2, test3;	
	
	test1 = findMin(arr1, ARR_SIZE1);
	test2 = findMin(arr2, ARR_SIZE2);
	test3 = findMin(arr3, ARR_SIZE3);
	
	cout.precision(2);
	cout << "ARRAY SIZE |" << " MIN VALUE |" << " ASSIGMENT AMOUNT |" << " HARMONIC" << endl;
	cout << setw(7) << ARR_SIZE1 << setw(10) <<arr1[test1.minIndex] << setw(14) <<test1.assigmentCounter << setw(18) << Hn1 << endl;
	cout << setw(7) << ARR_SIZE2 << setw(10) <<arr2[test2.minIndex] << setw(14) <<test2.assigmentCounter << setw(18) << Hn2 <<endl;
	cout << setw(7) << ARR_SIZE3 << setw(10) <<arr3[test3.minIndex] << setw(14) <<test3.assigmentCounter << setw(18) << Hn3 <<endl;
	
	
	
	return 0;
}
