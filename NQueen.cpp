#include <bits/stdc++.h>
using namespace std;
int N, X[100], col[100], d1[100], d2[100];
int arr[100][100];

void display() {
	memset(arr, 0, sizeof(arr));
	for (int i = 1; i <= N; i++) {
		arr[i][X[i]] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Try(int i) {
	for (int j = 1; j <= N; j++) {
		if(col[j] == 1 && d1[i - j + N] == 1 && d2[i + j - 1] == 1) {
			X[i] = j;
			col[j] = d1[i - j + N] = d2[i + j - 1] = 0;
			if(i == N) {
				display();
			} else {
				Try(i + 1);
			}
			col[j] = d1[i - j + N] = d2[i + j - 1] = 1;
		}
	}
}

int main(){
	cin >> N;
	for (int i = 1; i <= 99; i++) {
		col[i] = d1[i] = d2[i] = 1;
	}
	Try(1);
	return 0;
}

