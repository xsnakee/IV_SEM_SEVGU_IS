#include <iostream>
#include <vector>

bool kyky(std::vector<int> S, size_t N, int V, std::vector<bool> &Cnt, size_t &elOpCounter) {

	bool fl = false; // 1(<-)
	int i = 0; // 1(<-)
	elOpCounter += 2;	

	size_t lastIndex = N - 1; // 1(-)+1(<-)
	elOpCounter += 2;

	Cnt[lastIndex] = 1; // 1(lastIndex)+1(<-)
	elOpCounter += 2;

	do {
		int Sum = 0; // 1(<-)
		i = 0; // 1(<-)
		elOpCounter += 2;

		do {
			Sum = Sum + S[i] * Cnt[lastIndex - i]; // 1(<-)+1(+)+2(i)+1(*)+1(-)
			i = i + 1; // 1(<-) + 1(+)
		} while (i < N); // 1(<)
			// 8*N
		elOpCounter += 9 * N;

		if (Sum == V) { // 1(==)
			fl = true; // 1(<-)
			++elOpCounter;

			return fl;
		}
		++elOpCounter;

		int j = lastIndex; // 1(<-)
		++elOpCounter;

		while (Cnt[j] == 1) { // 1(j)+1(==)
			Cnt[j] = 0; // 1(j)+1(<-)
			j = j - 1; // 1(<-) + 1(-)
			// 4
			elOpCounter += 4;
		}
		elOpCounter += (N - j) * 2;

		Cnt[j] = 1; // 1(j)+1(<-)
		elOpCounter += 2;
		elOpCounter += 2;
	} while (Cnt[0] != 1); //1(0)+1(!=)

	return fl;
}

std::vector<int> randomFill(std::vector<int> arr) {
	
	for (size_t i = 0; i < arr.size(); ++i) {
		arr[i] = rand() % 90;
	}

	return arr;
}

template <class T>
void printArr(std::vector<T> arr) {
	for (size_t i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << " ";
	}
}

void clearTheArray(std::vector<int> &arr) {
	size_t i = 0;
	do {
		arr[i] = 0; 
		i = i + 1; 
	} while (i < arr.size()); 
}
int main() {
	const size_t ARR_SIZE = 13;
	const int V = 25;

	std::vector<int> mainArr(ARR_SIZE);
	std::vector<bool> Counter(ARR_SIZE);

	mainArr = randomFill(mainArr);

	printArr(mainArr);
	std::cout << std::endl;
	printArr(Counter);
	std::cout << std::endl;
	
	size_t elOpCounter = 0;
	kyky(mainArr, ARR_SIZE, V, Counter, elOpCounter);

	printArr(mainArr);
	std::cout << std::endl;
	printArr(Counter);
	std::cout << std::endl;
	
	std::cout << elOpCounter*2;

	return 0;

}