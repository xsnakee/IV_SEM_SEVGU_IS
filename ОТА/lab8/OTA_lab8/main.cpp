#include <iostream>
#include <vector>
using namespace std;

typedef vector<size_t> arr;
typedef vector<vector<size_t>> matrix;

const size_t INF = numeric_limits<size_t>::max(); // бесконечность
const size_t ROOT_AMOUNT = 9; // количествовершин

void fillMatr(matrix &rootMatr);
size_t solve(matrix &g, matrix &result, size_t startRoot = 0);
void printMatrix(matrix &a);

int  main() {
matrix ROOT_MATRIX(ROOT_AMOUNT, arr(ROOT_AMOUNT,0));
matrix PATHs(2, arr(ROOT_AMOUNT , INF));

fillMatr(ROOT_MATRIX);
size_t k = solve(ROOT_MATRIX, PATHs,0);

printMatrix(PATHs);
cout << endl << "Length of path: " << k;

return 0;
}

void fillMatr(matrix &rootMatr) {
rootMatr[0][1] = 9;
rootMatr[0][2] = 4;
rootMatr[1][2] = 7;
rootMatr[1][3] = 10;
rootMatr[2][5] = 4;
rootMatr[2][7] = 6;
rootMatr[3][2] = 6;
rootMatr[3][4] = 3;
rootMatr[4][6] = 1;
rootMatr[5][4] = 9;
rootMatr[5][7] = 7;
rootMatr[6][3] = 1;
rootMatr[6][5] = 8;
rootMatr[6][8] = 6;
rootMatr[7][8] = 4;

rootMatr[1][0] = 9;
rootMatr[2][0] = 4;
rootMatr[2][1] = 7;
rootMatr[3][1] = 10;
rootMatr[5][2] = 4;
rootMatr[7][2] = 6;
rootMatr[2][3] = 6;
rootMatr[4][3] = 3;
rootMatr[6][4] = 1;
rootMatr[4][5] = 9;
rootMatr[7][5] = 7;
rootMatr[3][6] = 1;
rootMatr[5][6] = 8;
rootMatr[8][6] = 6;
rootMatr[8][7] = 4;

}

size_t solve(matrix &g, matrix &result, size_t startRoot) {
	size_t path = 0;
	bool d[ROOT_AMOUNT] = { false }; // массив для пометок
	d[startRoot] = true;

	for (size_t i = 0; i < ROOT_AMOUNT; ++i) {
		
		bool flag = false;
		size_t minPath = INF;
		size_t startIndex = 0;
		size_t finishIndex = 0;
		for (size_t j = 0; j < ROOT_AMOUNT; ++j) {
			if (d[j]) {
				for (size_t k = 0; k < ROOT_AMOUNT; ++k) {

					if (!d[k] && g[j][k] && (g[j][k] < minPath)) {
						minPath = g[j][k];
						startIndex = j;
						finishIndex = k;
						flag = true;
					}

				}
			}
		}
		if (flag) {
			path += minPath;
		}
		result[0][i] = startIndex + 1;
		result[1][i] = finishIndex + 1;
		d[finishIndex] = true;
	}

 return path;
}


void printMatrix(matrix &a) {
	cout << "Start roots:  ";
	for (size_t i = 0; i < a[0].size()-1; ++i) {
		cout << a[0][i]<< " ";
	}
	cout << endl;
	cout << "Finish roots: ";
	for (size_t i = 0; i < a[0].size()-1; ++i) {
		cout << a[1][i] << " ";
	}
}