#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>


using namespace std;

struct matrixIndexes {
	int i;
	int j;
};

typedef std::vector<int> vect;
typedef std::vector<std::vector<int>> matr;

typedef std::vector<bool> taskVect;



void arrReset(vect &arr) {
	for (auto &elem : arr) {
		elem = 0;
	}
}

void matrixReset(matr &m) {
	for (size_t i = 0; i < m.size(); ++i) {
		for (size_t j = 0; j < m[0].size(); ++j) {
			m[i][j] = 0;
		}
	}
}

void printArr(vect &a){
    for (auto &i : a){
        std::cout << i << " ";
    }
}

int minIndex(const vect &a, const taskVect &t) {

	int minIndex = 0;

	while (t[minIndex]) {
		++minIndex;
	}

	for (size_t i = 0; i < a.size(); ++i) {
		if (a[i] < a[minIndex] && t[i] == false) {
			minIndex = i;
		}
	}

	return minIndex;
}

/*
if (min(0) or min(2) <= max(1)) return 1 else return 0

*/
int checkAlgorithm(const matr &m) {
	if (m.size() != 3){
		return false;
	}

	vect tempVal(3, 0);


	for (size_t i = 0; i < m.size(); ++i) {

		int index = 0;
		if (i != 1) {

			for (size_t j = 0; j < m[0].size(); ++j) {
				if (m[i][j] < m[i][index]) {
					index = j;
				}
			}
		}
		else {
			for (size_t j = 0; j < m[0].size(); ++j) {
				if (m[i][j] > m[i][index]) {
					index = j;
				}
			}
		}

		tempVal[i] = index;
	}

	if ((m[0][tempVal[0]] >= m[1][tempVal[1]]) || (m[2][tempVal[2]] >= m[1][tempVal[1]])) {
		return 1;
	}

	return 0;
	
}

vect matrColumnSum(const matr &m,const size_t col1, const size_t col2) {
	vect temp;

	for (size_t i = 0; i < m[0].size(); ++i) {
		temp.push_back(m[col1][i] + m[col2][i]);
	}

	return temp;
}

int min(const int &a, const int &b) {
	return (a > b) ? b : a;
}

vect generateJonsonOrder(const matr &m) {
	if (m.size() != 2) {
		throw "invalid vector size";
	}
	
	vect orderedVect(m[0].size(), 0);

	taskVect tasks(m[0].size(), false);
	
	int forwardIter = 0;
	int backIter = orderedVect.size() - 1;



	while (forwardIter <= backIter) {
		int minI = 0, minJ = 0;

		while (tasks[minJ] == true) {
			++minJ;
		}

		for (size_t i = 0; i < m.size(); ++i) {
			for (size_t j = minJ + 1; j < m[0].size(); ++j) {
				if (tasks[j] == false && m[i][j] < m[minI][minJ]) {
					minI = i;
					minJ = j;
				}
			}
		}

		int minVal = m[minI][minJ];

		for (size_t i = 0; i < m[0].size(); ++i) {
		    if (tasks[i] == false){
		         
			if (m[0][i] == minVal) {

				orderedVect[forwardIter++] = i;
				tasks[i] = true;
			} else if (m[1][i] == minVal) {

				orderedVect[backIter--] = i;
				tasks[i] = true;
			}
		    }
		   
		}

	}
	
	return orderedVect;
}

vect frontOrder(const vect &a) {
	vect temp = a;
	sort(temp.begin(), temp.end());

	return temp;
}

vect BackOrder(const vect &a) {
	vect temp = a;
	sort(temp.begin(), temp.end(), greater<int>());

	return temp;
}

vect generateFrontOrder(const vect &a) {
	vect temp;

	taskVect tasks(a.size(), false);
	
	for (size_t i = 0; i < a.size(); ++i){
		int tempIndex = minIndex(a, tasks);
		temp.push_back(tempIndex);
		tasks[tempIndex] = true;
	}

	return temp;
}


int MaxValIndex(const vect &a) {
	int index = 0;

	for (size_t i = 0; i < a.size(); ++i) {
		if (a[i] > a[index]) {
			index = i;
		}
	}

	return index;
}


vect runExactAlgo(matr &m) {
	vect temp;

	if (checkAlgorithm(m)) {
		vect A = matrColumnSum(m, 0, 1);
		vect B = matrColumnSum(m, 1, 2);
		matr T = { A , B};

		temp = generateJonsonOrder(T);
		
		return temp;
	}
	
	
	throw "Error";
}

vect runEvristicAlgo(matr &m){
    
    vect temp;
    	vect colSumVal(m.size(),0);
		for (size_t i = 0; i < m.size(); ++i) {
			colSumVal[i] = accumulate(m[i].begin(), m[i].end(),0);
		}
		
		int changeEvristicAlg = MaxValIndex(colSumVal);

		switch (changeEvristicAlg) {
		case 0: {
			vect tempSumCol1Col2 = matrColumnSum(m,1,2);
			temp = generateFrontOrder(tempSumCol1Col2);
			reverse(temp.begin(), temp.end());
			break;
		}
		case 1: {
			m.erase(m.begin() + 1);
			temp = generateJonsonOrder(m);
			break;
		}
		case 2: {
			vect tempSumCol1Col2 = matrColumnSum(m, 0, 1);
			temp = generateFrontOrder(tempSumCol1Col2);
			break;
		}
		}
		return temp;
}

int main() {
	
	vect A = { 2, 1, 4, 5, 3 };
	vect B = { 3, 1, 2, 3, 4 };
	vect C = { 4, 5, 5, 7, 6 };

	matr J = { A, B, C };
	
	vect temp1 = runExactAlgo(J);
	vect temp2 = runEvristicAlgo(J);
	printArr(temp1);
	cout << endl;
	printArr(temp2);
	return 0;
}