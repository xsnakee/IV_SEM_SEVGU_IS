#include <iostream>
#include <vector>

using namespace std;

typedef vector<size_t> vec;

void modBubbleSort(vec &arr) {
	
	size_t n = arr.size();

	for (size_t i = 0; i < (n - 1); ++i) {
		
		bool flag = false;
		
		for (size_t j = i; j < (n - 1); ++j) {

			if (arr[j] < arr[j+1]) {
				swap(arr[i], arr[j]);
				flag = true;
			}

		}
		if (!flag) {
			break;
		}
	}
}


int main() {



	return 0;
}