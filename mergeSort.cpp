#include <bits/stdc++.h>
using namespace std;
//Trộn 2 dãy con đã được sắp xếp
//L1 = arr[m], arr[m + 1],. . ., arr[n];
//L2 = arr[n + 1], arr[n + 2],. . ., arr[p];
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
} //thủ tục trộn

void merge(int arr[], int first, int last) {
    if (first >= last) return;
    int m = (first + last)/2;
    merge(arr, first, m);
    merge(arr, m + 1, last);
    mergeArrays(arr, first, m, last);
} //sắp xếp trộn mảng tổng

void mergeSort(int arr[], int n) {
    if (n < 2) return;
    merge(arr, 0, n - 1);
} //hàm sắp xếp trộn

int main(){
	int arr[] = {5, 3, 1, 2, 6, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, n);
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;



	return 0;
}

