/*#include <iostream>
using namespace std;
int main() {
	for (int i = 0; i <= 9; i++) {
		for (int k = 1; k <= 10; k++) {
			cout << k + (10 * i) << "\t";
		}
		cout << "\n";
	}
}*/

/*#include <iostream>
using namespace std;
int main() {
	int a = 0;
	for (int i = 1; i <= 9; i++) {
		for (int k = 1; k <= 9; k++) {
			a = i * k;
			cout << k << 'x' << i << '=' << a << "\t";
		}
		cout << "\n";
	}
}*/
/*#include <iostream>
using namespace std;
int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	cout << "�� ���� �Է��϶�>>";
	cin >> a >> b;
	if (a >= b) {
		c = a;
	}
	else c = b;
	cout << c;
}*/
/*#include <iostream>
using namespace std;
int main() {
	double a[5], k = 0;
	cout << "5 ���� �Ǽ��� �Է��϶�>>";
	for (int i = 0; i <= 4; i++) {
		cin >> a[i];
	}
	k = a[0];
	for (int j = 0; j <= 4; j++) {
		if (a[j] >= k) {
			k = a[j];
		}
	}
	cout << "���� ū �� = " << k;
}*/
/*#include <iostream>
using namespace std;
int main() {
	cout << "���ڵ��� �Է��϶�(100���̸�)" << "\n";
	char a[100];
	int k = 0;
	cin.getline(a,100);
	for (int i = 0; i < sizeof(a); i++) {
		if (a[i] == 'x') {
			k++;
		}
	}
	cout << "x�� ������ " << k;
}*/
/*#include <iostream>
#include<cstring>
using namespace std;
int main() {
	char a[50];
	char b[50];
	cout << "�� ��ȣ�� �Է��ϼ���>>";
	cin >> a;
	cout << "�� ��ȣ�� �ٽ� �Է��ϼ���>>";
	cin >> b;

	if (strcmp(a,b)==0) {
		cout << "�����ϴ�";
	}
	else cout << "���� �ʽ��ϴ�";
}*/
/*#include <iostream>
#include<cstring>
using namespace std;
int main() {
	char a[50];
	while (1) {
		cout << "�����ϰ� ������ yes�� �Է��ϼ��� >>";
		cin.getline(a, 50);
		if (strcmp(a, "yes") == 0) {
			cout << "�����մϴ�...";
			break;
		}
	}
}*/
/*#include <iostream>
#include<cstring>
using namespace std;
int main() {
	char a[5][100];
	int b = 0;
	int c = 0;
	cout << "5 ���� �̸��� ';'���� �����Ͽ� �Է��ϼ���" << "\n" << ">>";
	for (int i = 0; i <= 4; i++) {
		cin.getline(a[i], 50, ';');
	}
	for (int k = 0; k <= 4; k++) {
		cout << 1 + k << ':' << a[k] << '\n';
		if (strlen(a[k]) >= b) {
			b = strlen(a[k]);
			c = k;
		}
	}
	cout << "���� �� �̸��� " << a[c];
}*/
/*#include <iostream>
#include<cstring>
using namespace std;
int main() {
	char a[50], b[50];
	int c;
	cout << "�̸���?";
	cin.getline(a, 50);
	cout << "�ּҴ�?";
	cin.getline(b,50);
	cout << "���̴�?";
	cin >> c;
	cout << a << ',' << b << ',' << c  << "��";
}*/
/*#include <iostream>
#include<cstring>
using namespace std;
int main() {
	char a[50];
	cout << "���ڿ��Է�>>";
	cin.getline(a, 100);

	for (int i = 0; i < strlen(a); i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << a[j];
		}
		cout << '\n';
	}
}*/
/*#include <iostream>
using namespace std;
int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	cout << "�� ���� �Է��ϼ��� >>";
	cin >> a;
	for (b = 1; b <= a; b++) {
		c += b;
	}
	cout << "1����" << a << "������ ���� " << c << "�Դϴ�.";
}*/
/*#include <iostream>
using namespace std;
int sum(int a, int b) {
	int c = 0;
	int d = 0;
	for (c = a; c <= b; c++) {
		d += c;
	}
	return d;
}
int main() {
	int d = 0;
	cout << "�� ���� �Է��ϼ��� >>";
	cin >> d;

	cout << "1����" << d << "������ ���� " << sum(1,d) << "�Դϴ�.";
}*/

/*#include <iostream>
using namespace std;
int main() {
	int a = 0;
	int b = 0;
	cout << "***** �¸��忡 ���Ű� ȯ���մϴ� *****" << "\n";
	while (1) {
		cout << "«��:1, ¥��:2, ������:3, ����:4"<<">>";
		cin >> a;
		if (a == 1) {
			cout << "���κ�?";
			cin >> b;
			cout << "«��" << b << "�κ� ���Խ��ϴ�."<<'\n';
		}
		else if (a == 2) {
			cout << "���κ�?";
			cin >> b;
			cout << "¥��" << b << "�κ� ���Խ��ϴ�." << '\n';
		}
		else if (a == 3) {
			cout << "���κ�?";
			cin >> b;
			cout << "������" << b << "�κ� ���Խ��ϴ�." << '\n';
		}
		else if (a == 4) {
			cout << "���� ������ �������ϴ�." << '\n';
			break;
		}
		else cout << "�ٽ� �ֹ��ϼ���!!" << '\n';
	}
}
/*#include <iostream>
using namespace std;
int main() {
	char a[100];
	int b = 0;
	int c = 0;
	int d = 0;
	cout << "���������� 2000��, �Ƹ޸�ī�� 2300��, īǪġ�� 2500���Դϴ�."<<"\n";
	while (c <= 20000) {
		cout << "�ֹ� ";
		cin >> a >> b;
		if (strcmp(a, "����������") == 0) {
			d = 2000 * b;
			cout << d << "�� �Դϴ�. ���ְ� �弼��" << "\n";
		}
		else if (strcmp(a, "�Ƹ޸�ī��") == 0) {
			d = 2300 * b;
			cout << d << "�� �Դϴ�. ���ְ� �弼��" << "\n";
		}
		else if (strcmp(a, "īǪġ��") == 0) {
			d = 2500 * b;
			cout << d << "�� �Դϴ�. ���ְ� �弼��" << "\n";
		}
		c += d;
	}
	cout << "����" << c << "���� �Ǹ��Ͽ� ī�並 �ݽ��ϴ�. ���Ϻ���~~~";
}*/
/*#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
using namespace std;
int main() {
	int a = 0;
	int b = 0;
	char* c;
	while (1) {
		cout << "?";
		char s[50];
		cin.getline(s,50);
		a = atoi(strtok(s, " "));
		c = strtok(NULL, " ");
		b = atoi(strtok(NULL, " "));
		if (*c == '+') {
			cout << a << '+' << b << "="<< a + b << '\n';
		}
		if (*c == '-') {
			cout << a << '-' << b << "=" << a - b << '\n';
		}
		if (*c == '*') {
			cout << a << '*' << b << "=" << a * b << '\n';
		}
		if (*c == '/') {
			cout << a << '/' << b << "=" << a / b << '\n';
		}
		if (*c == '%') {
			cout << a << '%' << b << "=" << a % b << '\n';
		}
	}
}*/
/*#include <iostream>
using namespace std;
int main() {
	char a[10000];
	int b = 0;
	cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�."<<"\n";
	cout << "�ý�Ʈ�� ���� ; �Դϴ�. 10000���� �����մϴ�." << "\n";
	cin.getline(a, 10000, ';');
	for (int i = 0; i < 10000; i++) {
		if (isalpha(static_cast<unsigned char>(a[i]))) {
			a[i] = tolower(a[i]);
			b++;
		}
	}
	cout << "�Ѿ��ĺ� ��" << b << "\n" << "\n";
	for (char c = 'a'; c <= 'z'; c++) {
		b = 0;
		for (int i = 0; i < 10000; i++) {
			if (a[i] == c) {
				b++;
			}
		}
		cout << c << "(" << b << ")    :";
		for (int i = 0; i < b; i++) {
			cout << "*";
			}
		cout << "\n";
	}
}*/