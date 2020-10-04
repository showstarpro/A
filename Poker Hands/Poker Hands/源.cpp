#include<iostream>
#include<algorithm>
using namespace std;
class Poker {
	//��ʾ�˿��Ƶ����
public:
	int num, suit;     //��� ����ɫ
	Poker(int a = 0, int b = 0) {
		num = a, suit = b;
	}
	bool operator<(const Poker P) const {
		//�ȽϺ���
		if (num == P.num) return  suit < P.suit;
		return num < P.num;
	}
};  

class Person {
public:
	Poker p[5];   //ÿ��5����
	//�����ж���Ҫ��һЩ����
	int pairs[2], three, four, straight, flush, full_house, str_flush, pos;
	Person(){}
	void regular() {
		//�������ϵĲ���
		int arr[15] = { 0 };
		sort(p, p + 5);
		for (int i = 0; i < 5; i++) arr[p[i].num]++;
		pos = pairs[0] = pairs[1] = three = four = full_house = str_flush = 0;
		for (int i = 14; i > 1; i--)
			if (arr[i] == 4) four = i;
			else if (arr[i] == 3) three = i;
			else if (arr[i] == 2) pairs[pos++] = i;
		straight = flush = p[4].num;
		for (int i = 0; i < 4; i++) {
			if (p[i].num + 1 != p[i + 1].num) straight = 0;
			if (p[i].suit != p[i + 1].suit) flush = 0;

		}
		str_flush = (straight && flush);
		if (three && pairs[0]) full_house = three;

	}
};

char cc[4], num_char[17] = { "..23456789TJQKA" };
Person pa, pb;
Poker getcc() {
	//���������ֵ����ӳ�䣬�������ڱȽϴ�С
	int a, b = 4;
	for (int i = 2; i < 15; i++)
		if (num_char[i] == cc[0]) a = i;
	if (cc[1] == 'C') b = 1;
	else  if (cc[1] == 'D') b = 2;
	else if (cc[1] == 'H') b = 3;
	return Poker(a, b);
}

int high_card(int e = 4) {
	//�Ƚϵ�һ����
	for (int i = e; i > 0; i--)
		if (pa.p[i].num > pb.p[i].num) return 1;
		else if (pa.p[i].num < pb.p[i].num) return -1;
	return 0;
}

int compare() {
	//�����������Ƚ������ƵĴ�С��-1�����һ����С��0����һ����1��ʾ��һ���Ƚϴ�
	if (pa.str_flush || pb.str_flush)    // ����Straight flush
		if (pa.str_flush && pb.str_flush) return high_card();
		else if (pa.str_flush) return 1;
		else return -1;
	if (pa.four || pb.four)    //����four of a kind
		return (pa.four > pb.four) * 2 - 1;
	if (pa.full_house || pb.full_house)   //���� Full house
		return (pa.full_house > pb.full_house) * 2 - 1;
	if (pa.flush || pb.flush) {     //����flush
		if (pa.flush && pb.flush)  return high_card();
		return pa.flush * 2 - 1;
	}
	if (pa.straight || pb.straight) {  //����straight
		if (pa.straight > pb.straight)  return 1;
		else if (pa.straight == pb.straight) return 0;
		return -1;
	}
	if (pa.three || pb.three)  //����three of a kind
		return(pa.three > pb.three) * 2 - 1;
	if (pa.pos || pb.pos) {
		//pos��ʾ���м�������
		if (pa.pos > pb.pos) return 1;
		if (pa.pos < pb.pos) return -1;
		if (pa.p[0].num > pb.p[0].num) return 1;
		else if (pa.p[0].num < pb.p[0].num) return -1;
		else {
			if (pa.p[1].num > pb.p[1].num) return 1;
			else if (pa.p[1].num < pb.p[1].num) return -1;
			else {
				int t1 = 0, t2 = 0;
				for (int i = 0; i<5; i++) {
					if (pa.p[i].num != pa.pairs[0] && pa.p[i].num != pa.pairs[1])
						pa.p[t1++].num = pa.p[i].num;
					if (pb.p[i].num != pb.pairs[0] && pb.p[i].num != pb.pairs[1])
						pb.p[t2++].num = pb.p[i].num;
				}
				if (pa.pos == 1) return high_card(0);
				else return high_card(2);
			}
		}
	}
	return high_card(1);
}


int main()
{
	while (cin >> cc) {
		pa.p[0] = getcc();
		for (int i = 1; i<5 && cin >> cc; i++) pa.p[i] = getcc();
		for (int i = 0; i<5 && cin >> cc; i++) pb.p[i] = getcc();
		pa.regular();
		pb.regular();
		int ans = compare();
		if (ans == 1) cout << "Black Win." << endl;
		else if (ans == -1) cout << "White Win." << endl;
		else cout << "Tie." << endl;
	}
	return 0;
}