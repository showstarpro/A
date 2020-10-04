#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

class Node {
public:
	int name, num;
	Node(int n = 0, int u= 0) {
		name = n;
		num = u;
	}
	bool operator<(const Node n)const {
		//����С�ں�
		if (num == n.num) return name > n.name;
		return num<n.num;
	}
};

int n, h, ti[40], fi[50], di[50], ans[50];
int fishing(int p) {
	memset(ans, 0, sizeof(ans));
	int time = h * 12, result = 0;
	for (int i = 0; i < p; i++) time -= ti[i]; //��ȥ·���õ���ʱ��
	priority_queue<Node>que;     //���ȶ���ά����ǰ�ܹ������������ĺ���
	for (int i = 0; i <= p; i++)
		if (fi[i] > 0)
			que.push(Node(i, fi[i]));
	Node node;
	while (time>0)
	{    //ֻҪ��ʣ���ʱ������ܵ������ĺ�������
		if (que.empty()) break;  //�����ٵ�����ж�
		time--;
		node = que.top();    //ѡȡ�ܵ������ĺ���
		que.pop();
		result += node.num;
		node.num -= di[node.name];      //ÿ�ε�������´��ܹ������������
		if (node.num > 0) que.push(node);
		ans[node.num ] += 5;


	}
	return result;
}


int main() {
	bool flag = 0;
	while (cin >> n && n) {   //�������������
		if (flag) cout << '\n';  //���ڵ��������һ������
		flag = 1;
		cin >> h;
		for (int i = 0; i < n; i++)  cin >> fi[i];
		for (int i = 0; i < n; i++) cin >> di[i];
		for (int i = 0; i < n - 1; i++) cin >> ti[i];
		int ma = 0, manum = 0, s;
		for (int i = 0; i < n; i++) {
			s = fishing(i);
			if (ma < s) {
				ma = s;
				manum = i;
			}
		}
		fishing(manum);
		int sum = 0;
		for (int i = 0; i < n; i++) sum += ans[i];
		for (int i = 0; i < manum; i++) sum += ti[i] * 5;
		sum = h * 60 - sum;
		cout << ans[0] + sum;
		for (int i = 0; i < n; i++) cout << "," << ans[i];
		cout << '\n' << "Number of fish expected:" << ma << endl;
	}
	return 0;
}

