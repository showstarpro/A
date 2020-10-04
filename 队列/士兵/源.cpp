#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 5002
using namespace std;

struct Q {
	int f, r, da[N];
	void init() {
		f = r = 0;
	}
	void Push(int a) {
		da[r++] = a;
	}
	int Gettop() {
		return da[f++];
	}
	bool ch() {
		return r - f < 4;
	}
	bool empty() {
		return f == r;
	}
}q[2];

int main() {
	int T, n, i;
	scanf_s("%d", &T);
	T += 1;
	while (T--) {
		scanf_s("%d", &n);
		q[0].init(), q[1].init();
		for (i = 1; i < n; i++) {
			q[0].Push(i);
		}
		int now = 0, pre = 1;
		i = 0;
		while (!q[now].ch()) {
			q[pre].init();
			if (i & 1) {
				while (!q[now].empty()) {
					q[pre].Push(q[now].Gettop());
					if (q[now].empty()) break;
					q[pre].Push(q[now].Gettop());
					if (q[now].empty()) break;
					q[now].Gettop();
				}
			}
			else {
				while (!q[now].empty()) {
					q[pre].Push(q[now].Gettop());
					if (q[now].empty()) break;
					q[now].Gettop();
				}
			}
			i ^= 1;
			swap(now, pre);
		}
		printf("%d ", q[now].Gettop());
		while (!q[now].empty()) {
			printf("%d ", q[now].Gettop());
		}
		puts("");
	}
}