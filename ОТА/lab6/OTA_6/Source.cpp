#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>

using namespace std;

const unsigned int MAX_COURSE = 5;

struct student_t {
	string FIO;
	unsigned int course : 3;
	string fac;
};

typedef vector<student_t> vec;
typedef vec::iterator vecIter;


size_t modBubbleSort(vec &arr) {

	size_t opCounter = 0;
	size_t n = arr.size();

	bool flag = false; // + 1
	opCounter += 1;

	for (size_t i = n; ((i > 0) && (!flag)); --i) { //1 + 3 * N		
		flag = true;

		size_t topBorder = (i - 1); // + 1
		opCounter += 1 + 2;

		for (size_t j = 0; j < topBorder; ++j) { // 1 + 3 * (N/2)

			if (arr[j].course < arr[j+1].course) {//+4
				swap(arr[j+1], arr[j]);//+3 + 3
				flag = false;//+1

				opCounter += 7;
			}

			opCounter += 4;
		}

		opCounter += 1 + 3 * (n / 2);
	}
	opCounter += 1 + 3 * n;

	return opCounter;
}


size_t selectionSort(vec &arr) {
	size_t opCounter = 0;

	size_t n = arr.size();

	for (size_t i = 0; i < n; ++i) { // 1 + 3 * N

		size_t maxIndex = i; // + 1
		opCounter += 1;

		for (size_t j = (n - 1); j > i; --j) { // 2 + 3 * (n / 2)
			if (arr[j].course > arr[maxIndex].course) { // + 3
				maxIndex = j; // + 1
				opCounter += 1;
			}

			opCounter += 3;
		}


		if (maxIndex != i) {
			swap(arr[i], arr[maxIndex]); // 2 + 3
			opCounter += 5;
		}

		opCounter += 1;
		opCounter += 2 + 3 * (n / 2);
		
	}
	opCounter += 1 + 3 * n;

	return opCounter;
}

bool cmp(const student_t & a, const student_t& b) {
	return (a.course > b.course);
}


size_t quickSort(student_t &pv, vecIter left, vecIter right) {
	size_t opCounter = 0;

	student_t v = *(left + ((right - left) / 2)); //+ 4
	opCounter += 4;
	vecIter f = left;
	vecIter l = right;
	opCounter += 2;

	do {
		while ((f < right) && cmp(*f, v)) {// 3*n
			++f;
			opCounter += 4;
		}
		opCounter += 3;

		while ((l > left) && cmp(v, *l)) {
			--l;
			opCounter += 4;
		}
		opCounter += 3;

		if (f <= l) {// + 2
			std::swap(*f, *l);//+ 3
			++f; // + 1
			--l; // + 1
			opCounter += 5;
		}

		opCounter += 2;

		opCounter += 1;
	} while (f <= l);//^ + 1

	opCounter += 1;

	if (l > left) // + 1
		opCounter += quickSort(v, left, l);

	opCounter += 1;

	if (right > f) // +1
		opCounter += quickSort(v, f, right);

	opCounter += 1;

	return opCounter;
}




bool checkOrder(vec &arr) {
	for (size_t i = 1; i < arr.size(); ++i) {
		if (arr[i - 1].course < arr[i].course) 
			return false;
	}
	return true;
}

void randomFill(vec &arr) {
	for (size_t i = 0; i < arr.size(); ++i) {
		arr[i].course = 1 + (rand() % MAX_COURSE);
	}
}


int main() {
	size_t time = 0;
	size_t timeInmSec = 0;
	/*
	vec mainArr = {
		{ "Иванов И. И", 1, "ИС"},
		{ "Петров И. И", 5, "УТС" },
		{ "Сидоров И. И", 3, "УТС" },
		{ "Панасиенко И. И", 2, "ИТиКС" },
		{ "Клименко И. И", 1, "ИС" },
		{ "Артамонов И. И", 1, "УТС" },
		{ "Герилович И. И", 1, "ИТиКС" },
		{ "Москаленко И. И", 4, "ИТиКС" },
	};
	//*/
	
	vec mainArr(2000);

	randomFill(mainArr);

	vec tempArr(mainArr);


	//*
	assert(!checkOrder(tempArr));
	cout << "Buble sort amount operation: " << modBubbleSort(tempArr) << endl;
	time = clock();
	timeInmSec = (static_cast<float>(time)) / 10;
	cout << "Sort duration: " << timeInmSec << " ms" << endl;
	assert(checkOrder(tempArr));
	cout << "Buble sort min amount operation: " << modBubbleSort(tempArr) << endl << endl;
	

	//*/


	/*
	tempArr.clear();
	tempArr = mainArr;
	assert(!checkOrder(tempArr));
	cout << "Selection sort amount operation: " << selectionSort(tempArr) << endl;
	
	time = clock();
	timeInmSec = (static_cast<float>(time)) / 10;
	cout << "Sort duration: " << timeInmSec << " ms" << endl;

	assert(checkOrder(tempArr));
	cout << "Selection sort min amount operation: " << selectionSort(tempArr) << endl << endl;
	//*/

	/*
	tempArr.clear();
	tempArr = mainArr;
	assert(!checkOrder(tempArr));
	cout << "Quick sort amount operation: " << quickSort(*(tempArr.begin()),tempArr.begin(),(tempArr.end()-1)) << endl;
	
	time = clock();
	timeInmSec = (static_cast<float>(time)) / 10;
	cout << "Sort duration: " << timeInmSec << " ms" << endl;

	assert(checkOrder(tempArr));
	cout << "Quick sort min amount operation: " << quickSort(*(tempArr.begin()), tempArr.begin(), (tempArr.end() - 1)) << endl << endl;
	
	//*/
	return 0;
}