#include<iostream>

using namespace std;
//����ŷ������㷨�������Լ��
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
