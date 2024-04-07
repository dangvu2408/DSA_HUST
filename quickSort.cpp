#include <bits/stdc++.h>
using namespace std;

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
} //swap

/* void partition(int arr[], int first, int last) {
    if (first >= last) return;
    int c = arr[first];
    int i = first + 1, j = last;
    while (i <= j) {
        while (arr[i] <= c && i <= j) i++;
        while (arr[j] > c && i <= j) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[first], arr[j]);
    partition(arr, first, j - 1);
    partition(arr, j + 1, last);
} //partition func

void quickSort(int arr[], int n) {
    partition(arr, 0, n - 1);
} //quicksort func */

int partition (int arr[], int left, int right) {
	int pivot = arr[left];
	int l = left + 1, r = right;
	while (l <= r) {
		while (arr[l] <= pivot) l++;
		while (arr[r] > pivot) r--;
		swap(arr[l], arr[r]);
	}
	swap(arr[left], arr[l]);
	return l;
} //quickSort powered by Pham Doan Tinh

void quickSort(int arr[], int left, int right) {
	if (left < right) {
		int pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
} //quickSort powered by Pham Doan Tinh

int main(){
	int arr[] = {5, 3, 1, 2, 6, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

