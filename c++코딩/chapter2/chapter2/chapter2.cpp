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
	cout << "두 수를 입력하라>>";
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
	cout << "5 개의 실수를 입력하라>>";
	for (int i = 0; i <= 4; i++) {
		cin >> a[i];
	}
	k = a[0];
	for (int j = 0; j <= 4; j++) {
		if (a[j] >= k) {
			k = a[j];
		}
	}
	cout << "제일 큰 수 = " << k;
}*/
/*#include <iostream>
using namespace std;
int main() {
	cout << "문자들을 입력하라(100개미만)" << "\n";
	char a[100];
	int k = 0;
	cin.getline(a,100);
	for (int i = 0; i < sizeof(a); i++) {
		if (a[i] == 'x') {
			k++;
		}
	}
	cout << "x의 개수는 " << k;
}*/
/*#include <iostream>
#include<cstring>
using namespace std;
int main() {
	char a[50];
	char b[50];
	cout << "새 암호를 입력하세요>>";
	cin >> a;
	cout << "새 암호를 다시 입력하세요>>";
	cin >> b;

	if (strcmp(a,b)==0) {
		cout << "같습니다";
	}
	else cout << "같지 않습니다";
}*/
/*#include <iostream>
#include<cstring>
using namespace std;
int main() {
	char a[50];
	while (1) {
		cout << "종료하고 싶으면 yes를 입력하세요 >>";
		cin.getline(a, 50);
		if (strcmp(a, "yes") == 0) {
			cout << "종료합니다...";
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
	cout << "5 명의 이름을 ';'으로 구분하여 입력하세요" << "\n" << ">>";
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
	cout << "가장 긴 이름은 " << a[c];
}*/
/*#include <iostream>
#include<cstring>
using namespace std;
int main() {
	char a[50], b[50];
	int c;
	cout << "이름은?";
	cin.getline(a, 50);
	cout << "주소는?";
	cin.getline(b,50);
	cout << "나이는?";
	cin >> c;
	cout << a << ',' << b << ',' << c  << "세";
}*/
/*#include <iostream>
#include<cstring>
using namespace std;
int main() {
	char a[50];
	cout << "문자열입력>>";
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
	cout << "끝 수를 입력하세요 >>";
	cin >> a;
	for (b = 1; b <= a; b++) {
		c += b;
	}
	cout << "1에서" << a << "까지의 합은 " << c << "입니다.";
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
	cout << "끝 수를 입력하세요 >>";
	cin >> d;

	cout << "1에서" << d << "까지의 합은 " << sum(1,d) << "입니다.";
}*/

/*#include <iostream>
using namespace std;
int main() {
	int a = 0;
	int b = 0;
	cout << "***** 승리장에 오신걸 환영합니다 *****" << "\n";
	while (1) {
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4"<<">>";
		cin >> a;
		if (a == 1) {
			cout << "몇인분?";
			cin >> b;
			cout << "짬뽕" << b << "인분 나왔습니다."<<'\n';
		}
		else if (a == 2) {
			cout << "몇인분?";
			cin >> b;
			cout << "짜장" << b << "인분 나왔습니다." << '\n';
		}
		else if (a == 3) {
			cout << "몇인분?";
			cin >> b;
			cout << "군만두" << b << "인분 나왔습니다." << '\n';
		}
		else if (a == 4) {
			cout << "오늘 영업은 끝났습니다." << '\n';
			break;
		}
		else cout << "다시 주문하세요!!" << '\n';
	}
}
/*#include <iostream>
using namespace std;
int main() {
	char a[100];
	int b = 0;
	int c = 0;
	int d = 0;
	cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다."<<"\n";
	while (c <= 20000) {
		cout << "주문 ";
		cin >> a >> b;
		if (strcmp(a, "에스프레소") == 0) {
			d = 2000 * b;
			cout << d << "원 입니다. 맛있게 드세요" << "\n";
		}
		else if (strcmp(a, "아메리카노") == 0) {
			d = 2300 * b;
			cout << d << "원 입니다. 맛있게 드세요" << "\n";
		}
		else if (strcmp(a, "카푸치노") == 0) {
			d = 2500 * b;
			cout << d << "원 입니다. 맛있게 드세요" << "\n";
		}
		c += d;
	}
	cout << "오늘" << c << "원을 판매하여 카페를 닫습니다. 내일봐요~~~";
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
	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다."<<"\n";
	cout << "택스트의 끝은 ; 입니다. 10000까지 가능합니다." << "\n";
	cin.getline(a, 10000, ';');
	for (int i = 0; i < 10000; i++) {
		if (isalpha(static_cast<unsigned char>(a[i]))) {
			a[i] = tolower(a[i]);
			b++;
		}
	}
	cout << "총알파벳 수" << b << "\n" << "\n";
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