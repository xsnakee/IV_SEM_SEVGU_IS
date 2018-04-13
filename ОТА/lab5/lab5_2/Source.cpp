#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

typedef vector<size_t> arr;
typedef vector<vector<size_t>> matrix;

const size_t ROOT_AMOUNT = 9;

size_t min(size_t a, size_t b) {
	return (a > b) ? b : a;
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

size_t dfs(const size_t v, const matrix g, vector<bool> &used, arr &top, size_t &l);
size_t topSort(const matrix g, vector<bool> &used, arr &top);
size_t solve(const matrix &g, arr &top, arr &d, const size_t s, const size_t fRoot);


size_t main() {
	size_t startTime = clock();

	matrix ROOT_MATRIX(ROOT_AMOUNT, arr(ROOT_AMOUNT));

	fillMatr(ROOT_MATRIX);

	arr top(ROOT_AMOUNT);
	arr d(ROOT_AMOUNT);
	vector<bool> used(ROOT_AMOUNT);
	topSort(ROOT_MATRIX, used, top);
	size_t weight = solve(ROOT_MATRIX, top, d, 0, ROOT_AMOUNT-1);
	cout << "Min path from 1 to 9 root: " << weight;

	


	size_t endTime = clock();
	size_t result = (endTime - startTime);
	cout << endl << result;
	return 0;
}


size_t dfs(const size_t v,const matrix g, vector<bool> &used, arr &top, size_t &l) {
	size_t n = g.size();
if (used[v])
		return 0;
used[v] = true;
for (size_t to = 0; to < n; to++)
	if (g[v][to])
		dfs(to, g, used, top, l);
top[l++] = v; // добавление вершины v в отсортированный список
}


size_t topSort(const matrix g, vector<bool> &used, arr &top) {
	size_t n = g.size();
	size_t l = 0; // номер добавляемой вершины в отсортированный список
	for (size_t i = 0; i < n; i++)
		dfs(i,g,used,top,l); // запустить пробежку из всех вершин
	reverse((top.begin()), (top.begin() + l)); // развернуть массив
	return 0;
}


size_t solve(const matrix &g, arr &top, arr &d, size_t s, const size_t fRoot) {
	size_t i, j;
	size_t n = g.size();
	fillArr(d);

	d[s] = 0;
	for (i = 1; i < n; i++)
		for (j = 0; j < i; j++)
			if (g[top[j]][top[i]])
				d[top[i]] = min(d[top[i]], d[top[j]] + g[top[j]][top[i]]);
	return d[fRoot];
}