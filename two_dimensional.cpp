/*sort the 2-dimensional array contain integers that elements
increase in rows and also increase in columns*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 4;

void mergeArrays(int arr[], int m, int n, int p) {
    int i = m, j = n + 1;
    while (i < j && j <= p) {
        if (arr[i] <= arr[j]) i++;
        else {
            int x = arr[j];
            for (int k = j - 1; k >= i; k--) {
                arr[k + 1] = arr[k];
            }
            arr[i] = x;
            i++; j++;
        }
    }
} //merge array procedure

void merge(int arr[], int first, int last) {
    if (first >= last) return;
    int m = (first + last)/2;
    merge(arr, first, m);
    merge(arr, m + 1, last);
    mergeArrays(arr, first, m, last);
} //merge procedure

void mergeSort(int arr[], int n) {
    if (n < 2) return;
    merge(arr, 0, n - 1);
} //merge sort function

void sort(int mat[][MAX], int m, int n, int arr[]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i * n + j] = mat[i][j];
		}
	} //"make flat" the 2-dimentional array
	int x = m * n;
	mergeSort(arr, x); //sort the 1-dimentional array (Merge Sort)
	for (int i = 0; i < m * n; i++) {
		mat[i / n][i % n] = arr[i];
	} //"deflat" the 1-dimentional array
} /*function: sort the 2-dimentional array (Merge Sort) -
"make flat" the 2-dimentional array, convert to 1-dimentional
array then sort it. after all, "deflat" the 1-dimentional arr
to 2-dimentional array*/

int main(){
	int matrix[MAX][MAX] = { {1, 5, 4, 7},
						 	 {2, 6, 3, 2},
							 {5, 8, 0, 9},
							 {9, 4, 7, 5} };
	int arr[MAX * MAX];
	sort(matrix, MAX, MAX, arr);
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
/* note: bigO notation: O(nlogn) <Merge Sort> */
