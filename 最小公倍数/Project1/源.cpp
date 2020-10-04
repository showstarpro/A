#include<iostream>

using namespace std;
//利用欧几里得算法计算最大公约数
int gcd(int a, int b) {
	if (a < b)  swap(a, b);
	if (a%b == 0)  return b;
	return gcd(b, a%b);
}

int main()
{
	int a, b;
	while (cin >> a >> b) {
		cout << a * b / gcd(a, b) << endl;
	}
	return 0;
}
