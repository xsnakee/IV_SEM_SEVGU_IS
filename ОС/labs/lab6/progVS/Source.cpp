#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <list>
#include <conio.h>

typedef std::vector<size_t> vectValue;
typedef std::vector<std::vector<size_t> > matrix;

void matrixRandomFill(matrix &matrix, size_t maxValue) {
	for (size_t i = 0; i < matrix.size(); ++i) {
		for (size_t j = 0; j < matrix[i].size(); ++j) {
			matrix[i][j] = 1 + (rand() % (maxValue - 1));
		}
	}
}

void refRandomFill(vectValue &REF, size_t &maxValue) {
	for (size_t i = 0; i < REF.size(); ++i) {
		REF[i] = 1 + (rand() % (maxValue - 1));
	}
}


bool isZero(size_t &val) {
	if (val == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool isExist(vectValue &vect, size_t &val, size_t firstIndex, size_t lastIndex) {
	for (size_t i = firstIndex; i < lastIndex; ++i) {
		if (vect[i] == val) return true;
	}
	return false;
}


void printVector(vectValue &vect, size_t firstIndex, size_t lastIndex) {
	std::cout << "-------" << std::endl;
	for (size_t i = firstIndex; i < lastIndex; ++i) {

		if (isZero(vect[i])) {
			std::cout << "| " << std::setw(6) << " | " << std::endl;
		}
		else {
			std::cout << "| " << std::setw(3) << vect[i] << " | " << std::endl;
		}
		std::cout << "-------" << std::endl;
	}
}

bool FIFO(vectValue &vect, size_t processNUm, matrix &REF, size_t colNum, size_t indexOfFirst, size_t indexOfLast) {
	static std::vector<size_t> temp(REF.size());
	static std::vector<bool> tempResult(REF.size());
	std::cout << "task" << processNUm + 1 << std::endl;
	bool Fresult = false;

		if (!isExist(vect, REF[processNUm][colNum], indexOfFirst, indexOfLast)) {
			size_t tempIndex = indexOfFirst + temp[processNUm]++;
			vect[tempIndex] = REF[processNUm][colNum];

			if (temp[processNUm] == (indexOfLast - indexOfFirst) || (temp[processNUm] == vect.size())){//(indexOfLast - indexOfFirst)) {
				tempResult[processNUm] = true;
				temp[processNUm] = 0;
			}
			if (tempResult[processNUm]) {
				Fresult = true;
			}
		}
	

		std::cout << REF[processNUm][colNum] << std::endl;
		printVector(vect, indexOfFirst, indexOfLast);

		std::cout << std::endl;

		return Fresult;;
}

size_t tryFIFO(vectValue &vect, vectValue &REF, size_t indexOfFirst, size_t indexOfLast) {
	size_t Fcounter = 0;

	size_t tempIndex = 0;

	bool fullestFlag = false;
	bool fFlag = false;

	for (size_t k = 0; k < REF.size(); ++k) {

		if (!isExist(vect, REF[k], 0, vect.size())) {
			vect[tempIndex++] = REF[k];
			fFlag = true;
			if (!fullestFlag) {
				fFlag = false;
			}
		}
		else {
			fFlag = false;
		}

		std::cout << std::setw(5) << "T = " << (k + 1) << std::endl;
		std::cout << REF[k] << std::endl;
		printVector(vect, 0, vect.size());
		if (fFlag) {
			++Fcounter;
			std::cout << std::setw(3) << "F" << std::endl;
		}

		if (tempIndex == vect.size()) {
			tempIndex = 0;
			fullestFlag = true;
		}
		std::cout << std::endl;
		_getch();
	}

	return Fcounter;

}

size_t tryBIFO(vectValue &vect, matrix &REF, size_t taskAmount, vectValue taskDiv) {
	size_t Fcounter = 0;

	for (size_t k = 0; k < REF[0].size(); ++k) {
		std::cout << std::setw(5) << "T = " << (k + 1) << std::endl;

		for (size_t i = 1; i <= taskAmount; ++i) {
			Fcounter += FIFO(vect, i-1, REF, k, taskDiv[i - 1], taskDiv[i]);
		}
		_getch();
	}


	return Fcounter;
}

int main() {
	//size_t operAmount = 0, V = 0, maxRefValue = 0;

	/*
	std::cout << "Enter RAM volume: ";
	std::cin >> V;
	std::cout << "Enter  maxRefValue: ";
	std::cin >> maxRefValue;
	std::cout << "Enter operation amount: ";
	std::cin >> operAmount;

	vectValue REF(operAmount);
	refRandomFill(REF, maxRefValue);


	vectValue FIFO_ARR(V);
	size_t F1 = tryFIFO(FIFO_ARR, REF, 0, FIFO_ARR.size());
	std::cout << "Amount of breaks FIFO: " << F1 << std::endl;
	*/

	size_t operAmount = 0, V = 0, maxRefValue = 0;
	size_t processesAmount = 0;
	std::cout << "Enter RAM volume: ";
	std::cin >> V;
	std::cout << "Enter  maxRefValue: ";
	std::cin >> maxRefValue;
	std::cout << "Enter processes amount: ";
	std::cin >> processesAmount;
	std::cout << "Enter operation amount: ";
	std::cin >> operAmount;

	vectValue taskDiv(processesAmount + 1);
	for (size_t i = 1; i < (processesAmount); ++i) {
		std::cout << "Enter pages amount for " << (i) << " process:";
		size_t task = 2;
		std::cin >> task;
		taskDiv[i] = taskDiv[i - 1] + task;
	}
	taskDiv[processesAmount] = V-1;

	vectValue BIFO_ARR(V);

	matrix BIFO_REF(processesAmount, std::vector<size_t>(operAmount));
	matrixRandomFill(BIFO_REF, maxRefValue);

	size_t F2 = tryBIFO(BIFO_ARR, BIFO_REF, processesAmount, taskDiv);
	std::cout << "Amount of breaks BIFO: " << F2 << std::endl;

	return 0;
}
