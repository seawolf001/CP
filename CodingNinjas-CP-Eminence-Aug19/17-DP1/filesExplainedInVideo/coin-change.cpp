#include <iostream>
using namespace std;

int coin_change(int n, int* d, int numD, int** output) {
	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}
	if (numD == 0) {
		return 0;
	}
	if (output[n][numD] > -1) {
		return output[n][numD];
	}
	int first = coin_change(n - d[0], d, numD);
	int second = coin_change(n, d + 1, numD - 1);
	output[n][numD] = first + second;
	return first + second;
}

int main() {
	int d[2] = {1,2};
	// allocate 2d array here, n + 1 * numD + 1
	// put all -1
	cout << coin_change(4, d, 2) << endl;
}

