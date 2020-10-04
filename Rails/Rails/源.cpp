#include<iostream>
using namespace std;
#define N 1002

int a[N], b[N], sk[N];

int main() {
	int n, i, j, top;
	for (i = 0; i < N; i++) a[i] = i + 1;
	while (cin >> n && n) {
		while (cin >> b[0] && b[0]) {
			for (i = 1; i < n; i++) cin >> b[i];
			top = 0; j = 1;
			for (i = 0; i < n && j <= n + 1;) {
				if (j == b[i]) {
					j++, i++;
				}
				else if (top && sk[top - 1] == b[i]) {
					top--, i++;
				}
				else {
					sk[top++] = j++;
				}
			}
			if (i < n) cout << "No\n";
			else cout << "yes\n";
		}
		cout << endl;
	}
}