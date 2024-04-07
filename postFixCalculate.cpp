#include <bits/stdc++.h>
#define max 200
using namespace std;

class Stack {
	public:
		int top;
		int arr[max];
		Stack() {
			top = -1;
		}
		
		int isFull() {
			return top == max - 1;
		} //Stack is full when top is equal to the last index

		int isEmpty() {
			return top == -1;
		} //Stack is empty when top is equal to -1
		
		void push(int item) {
		    if (isFull()) return;
		    arr[++top] = item;
		} //add an item to stack
		
		int pop() {
		    if (isEmpty()) return INT_MIN;
		    return arr[top--];
		} //remove an item from stack
		
		int peek() {
		    if (isEmpty()) return INT_MIN;
		    return arr[top];
		} //return the top from stack without removing it
};

int Precedence(char x) {
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1 ;
	if (x == '*' || x == '/' || x == '%')
		return 2;
	return 3;
} //

void infixToPostfix (char infix[], char postfix[]) {
	Stack S;
	char x, token;
	int i = 0, j = 0;    // i - index of infix, j - index of postfix
	for (i = 0; infix[i] != '\0'; i++) {
		token = infix[i];
		if (isalnum(token))
			postfix[j++] = token;
		else {
			if (token == '(')
				S.push('(');
			else {
				if (token == ')')
					while ((x = S.pop()) != '(')
						postfix[j++] = x;
				else {
					while (Precedence(token) <= Precedence(S.peek()) && !S.isEmpty()) {
						x = S.pop();
						postfix[j++] = x;
					}
					S.push(token);
				}
			}	
		}	
	}
	while (!S.isEmpty()) {
		x = S.pop();
		postfix[j++] = x;
	}
	postfix[j] = '\0';
}

int calculate(char *Postfix) {
	Stack S;
	char *p;
	int op1, op2, result;
	p = &Postfix[0];

	while (*p != '\0') {
		while (*p == ' ' || *p == '\t') {
			p++;
		}
		if (isdigit(*p)) {
			int num = 0;
			while (isdigit(*p)) {
				num = num * 10 + *p - 48;
				*p++;
			}
			S.push(num);
		}
		else {
			op1 = S.pop();
			op2 = S.pop();
			switch (*p) {
				case '+':
					result = op2 + op1;
					break;
				case '-':
					result = op2 - op1;
					break;
				case '/':
					result = op2 / op1;
					break;
				case '*':
					result = op2 * op1;
					break;
				default:
					printf("\nInvalid Operator");
					return 0;
			}
			S.push(result);
		}
		p++;
	}

	result = S.pop();
	return result;
}

int main(){
	char A[max], B[max];
	cout << "Infix: ";
	gets(A);
	infixToPostfix (A, B);
	cout << "Postfix: " << B << endl;
	int x = calculate(&B[0]);
	cout << "Result: " << x << endl;
	return 0;
}

