#include<iostream>
#include<string>
#include<iomanip>


using namespace std;

int n, sline, eline, pos_s, p1, p2, p3;
char separator;
string text[105], command, lastreplace, repla, replaceby;
bool changed;
void reget(int &s, int &e, string str) {
	//获取将要被替换的文本范围
	int p = str.find(',');      //起始行号和终止行号被逗号分隔
	s = 0;
	//获取起始行号 
	for (int i = 0; i < p; i++) {
		s *= 10;
		s += str[i] - '0';
	}
	e = 0;
	//获取终止行号
	for (int i = p + 1; i < str.length(); i++) {
		e *= 10;
		e += str[i] - '0';
	}
}

int main()
{
	cin >> n;
	cin.get();     //输入行末换行符，保证getline()正常的读取文本

	if (n == 0) return 0;
	for (int i = 1; i <= n; i++)
		getline(cin, text[i]);
	lastreplace = "";
	int flag = false;
	while (getline(cin, command)) {
		if (flag) cout << endl;
		flag = true;
		pos_s = command.find('s');     //s的位置
		if (pos_s == 2) {
			sline = 1;
			eline = n;
		}                    //表示替换的是所有的行
		else {
			reget(sline, eline, command.substr(1, pos_s - 1));
		}

		separator = command[pos_s + 1];            //s后面的字符是替换命令的分隔符
		p1 = pos_s + 1;
		p2 = command.find(separator, p1 + 1);
		p3 = command.find(separator, p2 + 1);
		repla = command.substr(p1 + 1, p2 - p1 - 1);
		replaceby = command.substr(p2 + 1, p3 - p2-1);

		//如果{pattern}为空，则使用上次不为空的
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
			//输出行号占用四个字符，空两个字符，在输出替换后的文本
			if (c) cout << setw(4) << i << "  " << text[i] << endl;

		}

		if (!changed) cout << "Pattern not found " << endl;

	}

	return 0;
}