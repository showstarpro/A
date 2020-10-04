#include<iostream>
#include<string>
#include<iomanip>


using namespace std;

int n, sline, eline, pos_s, p1, p2, p3;
char separator;
string text[105], command, lastreplace, repla, replaceby;
bool changed;
void reget(int &s, int &e, string str) {
	//��ȡ��Ҫ���滻���ı���Χ
	int p = str.find(',');      //��ʼ�кź���ֹ�кű����ŷָ�
	s = 0;
	//��ȡ��ʼ�к� 
	for (int i = 0; i < p; i++) {
		s *= 10;
		s += str[i] - '0';
	}
	e = 0;
	//��ȡ��ֹ�к�
	for (int i = p + 1; i < str.length(); i++) {
		e *= 10;
		e += str[i] - '0';
	}
}

int main()
{
	cin >> n;
	cin.get();     //������ĩ���з�����֤getline()�����Ķ�ȡ�ı�

	if (n == 0) return 0;
	for (int i = 1; i <= n; i++)
		getline(cin, text[i]);
	lastreplace = "";
	int flag = false;
	while (getline(cin, command)) {
		if (flag) cout << endl;
		flag = true;
		pos_s = command.find('s');     //s��λ��
		if (pos_s == 2) {
			sline = 1;
			eline = n;
		}                    //��ʾ�滻�������е���
		else {
			reget(sline, eline, command.substr(1, pos_s - 1));
		}

		separator = command[pos_s + 1];            //s������ַ����滻����ķָ���
		p1 = pos_s + 1;
		p2 = command.find(separator, p1 + 1);
		p3 = command.find(separator, p2 + 1);
		repla = command.substr(p1 + 1, p2 - p1 - 1);
		replaceby = command.substr(p2 + 1, p3 - p2-1);

		//���{pattern}Ϊ�գ���ʹ���ϴβ�Ϊ�յ�
		if (repla == "")
			repla = lastreplace;
		else lastreplace = repla;
		changed = false;

		int re_len = repla.length(), reby_len = replaceby.length();
		for (int i = sline; i <= eline; i++) {
			bool c = 0;
			int p = text[i].find(repla, 0);
			while (p != -1) {
				text[i].replace(p, re_len, replaceby);
				p = text[i].find(repla, p + reby_len);
				changed = true;
				c = 1;
			}
			//����к�ռ���ĸ��ַ����������ַ���������滻����ı�
			if (c) cout << setw(4) << i << "  " << text[i] << endl;

		}

		if (!changed) cout << "Pattern not found " << endl;

	}

	return 0;
}