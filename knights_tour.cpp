#include <bits/stdc++.h>
#define MAX 8
//using namespace std;
int A[MAX][MAX] = { 0 };
int X[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int Y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int n;
int count = 0;
void display() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << A[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void move(int x, int y) {
	++count;
	A[x][y] = count;
	for (int i = 0; i < 8; i++) {
		if (count == n * n) {
			std::cout << "Result: " << std::endl;
			display();
			exit(0);
		}
		int u = x + X[i];
		int v = y + Y[i];
		if (u >= 0 && u < n && v >= 0 && v < n && A[u][v] == 0)
			move(u, v);
	}
	--count;
	A[x][y] = 0;
}

int main(){
	int a, b;
	std::cout << "Enter n: "; std::cin >> n;
	std::cout << "Enter the begin point - x: "; std::cin >> a;
	std::cout << "Enter the begin point - y: "; std::cin >> b;
	move(a, b);
	std::cout << "Way not found!!!" << std::endl; 
	return 0;
}

