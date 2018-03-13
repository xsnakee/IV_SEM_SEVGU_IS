#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>



typedef std::vector<std::vector<size_t>> vectMatrix;
typedef std::vector<size_t> vectValue;


void refRandomFill(vectValue REF, size_t maxValue){
    for(size_t i = 0; i < REF.size(); ++i){
        REF[i]= 1 + (rand() % (maxValue - 1));
    }
}


void arrRandomFill(vectMatrix matrix){
    for(size_t i = 0; i < matrix.size(); ++i){
        for(size_t j = 0; j < matrix[i].size(); ++j){
        }
    }
}

bool isZero(size_t val){
    if (val == 0) {
        return true;
    } else {
        return false;
    }
}

bool isExist(vectMatrix matrix, size_t colNum, size_t val){
    for(size_t i = 0; i < matrix.size(); ++i){
        if (matrix[i][colNum] == val) return true;
    }
    return false;
}

size_t tryFIFO(vectMatrix matrix, vectValue REF){

    size_t operCount = REF.size();

    vectValue tempIndexes(matrix.size());

    for (size_t k = 0; k < operCount; ++k) {
        for (size_t i = 0; i < matrix.size(); ++i) {

            bool searchResult = isExist(matrix,i,REF[k]);

            if (isZero(matrix[i][k])){
                matrix[i][k] = REF[k];
                tempIndexes[i] = i;
            } else if (searchResult){
                continue;
            } else if (!searchResult){
                matrix[i][k] = REF[k];
                tempIndexes[i] = i;
            } else {
                matrix[(*tempIndexes.begin())][k] = REF[k];
                tempIndexes.erase(tempIndexes.begin());
            }

        }
    }
}


void printMatrix(vectMatrix matrix){
    std::cout << "-----------------------------------------------------------------"<< std::endl;
    std::cout << "|";

    for(size_t i = 0; i < matrix.size(); ++i){
        for(size_t j = 0; j < matrix[i].size(); ++j){

            if (matrix[i][j] == 0){
                std::cout << std::setw(3) << " " << " | ";
            }
            std::cout << std::setw(3) << matrix[i][j] << " | ";
        }
        std::cout << std::endl;
    }

    std::cout << "-----------------------------------------------------------------"<< std::endl;
}

int main() {
    size_t operAmount, V, maxRefValue;


    std::cout << "Enter RAM volume: ";
    std::cin >> V;
    std::cout << "Enter  maxRefValue: ";
    std::cin >> maxRefValue;
    std::cout << "Enter operation amount: ";
    std::cin >> operAmount;

    vectValue REF(operAmount);

    vectMatrix FIFO_ARR(V, std::vector<size_t>(operAmount));
    vectMatrix BIFO_ARR(V, std::vector<size_t>(operAmount));



    size_t F1 = 0, F2 = 0;

    std::cout << "Hello, World!" << std::endl;

    return 0;
}