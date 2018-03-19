#include <iostream>
#include <iomanip>
#include <vector>
#include <conio.h>

typedef std::vector<size_t> vectValue;


void refRandomFill(vectValue &REF, size_t &maxValue) {
	for (size_t i = 0; i < REF.size(); ++i) {
		REF[i] = 1 + (rand() % (maxValue));
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

int main() {
	size_t operAmount = 0, V = 0, maxRefValue = 0;

	//*
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
	//*/

	_getch();
	return 0;
}
