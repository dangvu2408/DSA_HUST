#include <bits/stdc++.h>
using namespace std;

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
} //hàm đổi chỗ hai số nguyên

void makeSubHeap(int arr[], int r, int n) {
    if (2 * r + 1 >= n) return; //r là nút lá thì kết thúc
    int maxChild = arr[2 * r + 1]; //giả sử nút con trái là lớn nhất
    int c = 2 * r + 1;
    if (2 * r + 2 < n) { //nếu tồn tại nút con phải
        if (arr[2 * r + 2] > arr[2 * r + 1]) {
            maxChild = arr[2 * r + 2];
            c = 2 * r + 2;
        }
    }
    if (arr[r] < arr[c]) {
        swap(arr[r], arr[c]);
        makeSubHeap(arr, c, n);
    }
} //hàm cài thủ tục vun đống cho một cây con

void makeHeap(int arr[], int n) {
    if (n < 2) return;
    int m = n/2 - 1; //vị trí nút trong ngoài cùng
    for (int i = m; i >= 0; i--) {
        makeSubHeap(arr, i, n);
    }
} //hàm tạo cây heap

void heapSort(int arr[], int n) {
    if (n < 2) return;
    makeHeap(arr, n);
    for (int i = 1; i < n; i++) {
        swap(arr[0], arr[n - i]);
        makeSubHeap(arr, 0, n - i);
    }
} //hàm sắp xếp vun đống

int main(){
	int arr[] = {5, 3, 1, 2, 6, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, n);
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;


	return 0;
}

