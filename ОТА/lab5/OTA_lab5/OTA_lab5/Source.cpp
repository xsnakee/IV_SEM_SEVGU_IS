#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

typedef vector<size_t> arr;
typedef vector<vector<size_t>> matrix;

const size_t ROOT_AMOUNT = 9;

size_t solve(matrix g, size_t s, size_t f);
size_t sum(arr d) {
	size_t temp = 0;
	for (size_t i = 0; i < d.size(); ++i) {
		temp += d[i];
	}

	return temp;
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
}

void fillArr(arr &d) {
	for (size_t i = 0; i < d.size(); ++i) {
		d[i] = std::numeric_limits<size_t>::max();
	}
}


size_t main() {

	size_t startTime = clock();
	
	matrix ROOT_MATRIX(ROOT_AMOUNT, arr (ROOT_AMOUNT));
	
	fillMatr(ROOT_MATRIX);

	arr d;
	vector<bool> used(ROOT_AMOUNT);
	size_t shortestPath = solve(ROOT_MATRIX, 0, ROOT_AMOUNT-1);
	cout << "Shortest path from 1 to 9 root: " << shortestPath;

	size_t endTime = clock();
	size_t result = (endTime - startTime);
	cout << endl << result;

	return 0;
}

size_t solve(matrix g, size_t s, size_t f) {
	// n - ���������� ������
	// g[n][n] - ������� ���������, g[i][j] = 0, ���� �������� ����� ���
	// d[n] - ������ �������// s - ��������� �������
// used - ������ ��� ������� ������
int i, j, // i-� ��������, j - ��� ������ �����������
v, // ����������� �������
to, // ����� �� ������� v � to
len; // ����� len

size_t n = g.size();
arr d(n);
fillArr(d);

vector<bool> used(n);

d[s] = 0;
for (i = 0; i < n; i++) {
	v = -1;
	for (j = 0; j < n; j++) // ����� ������� � ����������� d[j]
		if (!used[j] && (v == -1 || d[j] < d[v])){
			v = j;
		}
		else if (!used[j] && (d[j] < d[v])) {
			v = j;
		}

	used[v] = true; // ������� �������
	for (to = 0; to < n; to++) {
		if (g[v][to]) {
			len = g[v][to];
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
			}
		}
	}
}
return d[f];
}