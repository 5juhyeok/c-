/*#include <iostream>
#include <string>
using namespace std;
class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	Book& operator +=(int price) {
		this->price += price;
		return *this;
	}	Book& operator -=(int price) {
		this->price -= price;
		return *this;
	}
};
int main() {
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
}*/
/*#include <iostream>
#include <string>
using namespace std;
class Book;
Book& operator +=(Book& b, int price);
Book& operator -=(Book& b, int price);
class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	friend Book& operator +=(Book& b, int price);
	friend Book& operator -=(Book& b, int price);
};
Book& operator +=(Book& b, int price) {
	b.price += price;
	return b;
}
Book& operator -=(Book& b, int price) {
	b.price -= price;
	return b;
}
int main() {
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();

	return 0;
}*/
/*#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	bool operator ==(int price);
	bool operator ==(string title);
	bool operator ==(Book& b);
};
bool Book::operator ==(int price) {
	if (this->price == price) return true;
	else return false;
}
bool Book::operator ==(string title) {
	if (this->title.compare(title) == 0) return true;
	else return false;
}
bool Book::operator ==(Book& b) {
	if (this->title.compare(b.title) == 0
		&& this->price == b.price
		&& this->pages == b.pages) return true;
	else return false;
}
int main() {
	Book a("명품 C++", 30000, 500), b("고품 c++", 30000, 500);
	if (a == 30000)cout << "정가 30000원" << endl;
	if (a == "명품 C++")cout << "명품 C++ 입니다." << endl;
	if (a == b)cout << "두 책이 같은 책입니다." << endl;
}*/
/*#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Book;
bool operator ==(Book a, int price);
bool operator ==(Book a, string title);
bool operator ==(Book a, Book& b);
class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	friend bool operator ==(Book a, int price);
	friend bool operator ==(Book a, string title);
	friend bool operator ==(Book a, Book& b);
};
bool operator ==(Book a, int price) {
	if (a.price == price) return true;
	else return false;
}
bool operator ==(Book a, string title) {
	if (a.title.compare(title) == 0) return true;
	else return false;
}
bool operator ==(Book a, Book& b) {
	if (a.title.compare(b.title) == 0
		&& a.price == b.price
		&& a.pages == b.pages) return true;
	else return false;
}
int main() {
	Book a("명품 C++", 30000, 500), b("고품 c++", 30000, 500);
	if (a == 30000)cout << "정가 30000원" << endl;
	if (a == "명품 C++")cout << "명품 C++ 입니다." << endl;
	if (a == b)cout << "두 책이 같은 책입니다." << endl;

}*/
/*#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	bool operator !() {
		if (this->price == 0) return true;
		else return false;
	}
};
int main() {
	Book book("벼룩시장", 0, 50);
	if (!book) cout << "공짜다";
}*/
/*#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Book;
bool operator < (string str, Book b);
class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	friend bool operator < (string str, Book b);
};
bool operator < (string str, Book b) {
	if (str.compare(b.title) < 0) return true;
	else return false;
}
int main() {
	Book a("청춘", 20000, 300);
	string b;
	cout << "책 이름을 입력하세요>>";
	getline(cin, b);
	if (b < a)
		cout << a.getTitle() << "이 " << b << "보다 뒤에 있구나!";
}*/
/*#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Color {
	int red;
	int green;
	int blue;
public:
	Color() :Color(0, 0, 0) {}
	Color(int r, int g, int b) {
		this->red = r; this->green = g; this->blue = b;
	}
	void show() {
		cout << red << ' ' << green << ' ' << blue << endl;
	}
	Color operator +(Color c) {
		Color tmp;
		tmp.red = this->red + c.red;
		tmp.green = this->green + c.green;
		tmp.blue = this->blue + c.blue;
		return tmp;
	}
	bool operator ==(Color c) {
		if (this->red == c.red && this->green == c.green && this->blue == c.blue) return true;
		else return false;
	}
};
int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();
	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음" << endl;
	else
		cout << "보라색 아님" << endl;
}*/
/*#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Color;
Color operator +(Color c1, Color c2);
bool operator ==(Color c1, Color c2);
class Color {
	int red;
	int green;
	int blue;
public:
	Color() :Color(0, 0, 0) {}
	Color(int r, int g, int b) {
		this->red = r; this->green = g; this->blue = b;
	}
	void show() {
		cout << red << ' ' << green << ' ' << blue << endl;
	}
	friend Color operator +(Color c1, Color c2);
	friend bool operator ==(Color c1, Color c2);
};
Color operator +(Color c1, Color c2) {
	Color tmp;
	tmp.red = c1.red + c2.red;
	tmp.green = c1.green + c2.green;
	tmp.blue = c1.blue + c2.blue;
	return tmp;
}
bool operator ==(Color c1, Color c2) {
	if (c1.red == c2.red && c1.green == c2.green && c1.blue == c2.blue) return true;
	else return false;
}
int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();
	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음" << endl;
	else
		cout << "보라색 아님" << endl;
}*/
/*#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Matrix {
	int m[2][2];
public:
	Matrix() : Matrix(0, 0, 0, 0) {}
	Matrix(int m1, int m2, int m3, int m4) {
		m[0][0] = m1;
		m[0][1] = m2;
		m[1][0] = m3;
		m[1][1] = m4;
	}
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				cout << m[i][j] << ' ';
		cout << "}" << endl;
	}
	Matrix operator +(Matrix mat) {
		Matrix tmp;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				tmp.m[i][j] = m[i][j] + mat.m[i][j];
		return tmp;
	}
	Matrix& operator +=(Matrix mat) {
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				m[i][j] += mat.m[i][j];
		return *this;
	}
	bool operator ==(Matrix mat) {
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				if (m[i][j] != mat.m[i][j]) return false;
		return true;
	}
};
int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same";
}*/
/*#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Matrix;
Matrix operator +(Matrix mat1, Matrix mat2);
Matrix& operator +=(Matrix& mat1, Matrix mat2);
bool operator ==(Matrix mat1, Matrix mat2);
class Matrix {
	int m[2][2];
public:
	Matrix() : Matrix(0, 0, 0, 0) {}
	Matrix(int m1, int m2, int m3, int m4) {
		m[0][0] = m1;
		m[0][1] = m2;
		m[1][0] = m3;
		m[1][1] = m4;
	}
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				cout << m[i][j] << ' ';
		cout << "}" << endl;
	}
	friend Matrix operator +(Matrix mat1, Matrix mat2);
	friend Matrix& operator +=(Matrix& mat1, Matrix mat2);
	friend bool operator ==(Matrix mat1, Matrix mat2);
};
Matrix operator +(Matrix mat1, Matrix mat2) {
	Matrix tmp;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			tmp.m[i][j] = mat1.m[i][j] + mat2.m[i][j];
	return tmp;
}
Matrix& operator +=(Matrix& mat1, Matrix mat2) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			mat1.m[i][j] += mat2.m[i][j];
	return mat1;
}
bool operator ==(Matrix mat1, Matrix mat2) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (mat1.m[i][j] != mat2.m[i][j]) return false;
	return true;
}
int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same";
}*/
/*#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Matrix {
	int m[4];
public:
	Matrix() : Matrix(0, 0, 0, 0) {}
	Matrix(int m1, int m2, int m3, int m4) {
		m[0] = m1;
		m[1] = m2;
		m[2] = m3;
		m[3] = m4;
	}
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 4; i++)
			cout << m[i] << ' ';
		cout << "}" << endl;
	}
	void operator >>(int mat[4]) {
		for (int i = 0; i < 4; i++)
			mat[i] = m[i];
	}
	Matrix& operator <<(int mat[4]) {
		for (int i = 0; i < 4; i++)
			m[i] = mat[i];
		return *this;
	}
};
int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;
	for (int i = 0; i < 4; i++) cout << x[i] << ' ';
	cout << endl;
	b.show();
}*/
/*#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Matrix;
void operator >>(Matrix mat1, int mat2[4]);
Matrix& operator <<(Matrix& mat1, int mat2[4]);
class Matrix {
	int m[4];
public:
	Matrix() : Matrix(0, 0, 0, 0) {}
	Matrix(int m1, int m2, int m3, int m4) {
		m[0] = m1;
		m[1] = m2;
		m[2] = m3;
		m[3] = m4;
	}
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 4; i++)
			cout << m[i] << ' ';
		cout << "}" << endl;
	}
	friend void operator >>(Matrix mat1, int mat2[4]);
	friend Matrix& operator <<(Matrix& mat1, int mat2[4]);
};
void operator >>(Matrix mat1, int mat2[4]) {
	for (int i = 0; i < 4; i++)
		mat2[i] = mat1.m[i];
}
Matrix& operator <<(Matrix& mat1, int mat2[4]) {
	for (int i = 0; i < 4; i++)
		mat1.m[i] = mat2[i];
	return mat1;
}
int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;
	for (int i = 0; i < 4; i++) cout << x[i] << ' ';
	cout << endl;
	b.show();
}*/
/*#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Circle;
Circle& operator ++(Circle& c);			
Circle operator ++(Circle& c, int x);	
class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " 인 원" << endl; }
	friend Circle& operator ++(Circle& c);
	friend Circle operator ++(Circle& c, int x);
};
Circle& operator ++(Circle& c) {
	c.radius++;
	return c;
}
Circle operator ++(Circle& c, int x) {
	Circle tmp = c;
	c.radius++;
	return tmp;
}
int main() {
	Circle a(5), b(4);
	++a;
	b = a++;
	a.show();
	b.show();
}*/
/*#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Circle;
Circle operator +(int r, Circle c);
class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " 인 원" << endl; }
	friend Circle operator +(int r, Circle c);
};
Circle operator +(int r, Circle c) {
	Circle tmp;
	tmp.radius = r + c.radius;
	return tmp;
}
int main() {
	Circle a(5), b(4);
	b = 1 + a;
	a.show();
	b.show();
}*/
/*#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Statistics {
	int* statistic;
	int size;
public:
	Statistics(int size = 0) { this->size = size; this->statistic = new int[size]; }
	Statistics& operator <<(int x) {
		size++;
		Statistics tmp(size);
		for (int i = 0; i < size - 1; i++)
			tmp.statistic[i] = statistic[i];
		tmp.statistic[size - 1] = x;
		delete[] this->statistic;
		this->statistic = new int[size];
		for (int i = 0; i < size; i++)
			this->statistic[i] = tmp.statistic[i];
		return *this;
	}
	Statistics& operator ~() {
		for (int i = 0; i < size; i++)
			cout << statistic[i] << ' ';
		cout << endl;
		return *this;
	}
	Statistics& operator >>(int& avg) {
		int sum = 0;
		for (int i = 0; i < size; i++)
			sum += statistic[i];
		avg = sum / size;
		return *this;
	}
	bool operator !() {
		if (size == 0) return true;
		else return false;
	}
};
int main() {
	Statistics stat;
	if (!stat) cout << "현재 통계 데이터가 없습니다." << endl;
	int x[5];
	cout << "5개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++) cin >> x[i];
	for (int i = 0; i < 5; i++) stat << x[i];
	stat << 100 << 200;
	~stat;
	int avg;
	stat >> avg;
	cout << "avg=" << avg;
}*/
/*#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Stack {
	int s[100];
	int top;
public:
	Stack() { top = -1; }
	bool operator !() {
		if (top == -1) return true;
		else return false;
	}
	Stack& operator<<(int x) {
		s[++top] = x;
		return *this;
	}
	Stack& operator>>(int& x) {
		x = s[top--];
		return *this;
	}
};
int main() {
	Stack stack;
	stack << 3 << 5 << 10;
	while (true) {
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
}*/
/*#include <iostream>
#include <string>
using namespace std;
class SortedArray {
	int size;
	int* p;
	void sort();
public:
	SortedArray();
	SortedArray(SortedArray& src);
	SortedArray(int p[], int size);
	~SortedArray();
	SortedArray operator +(SortedArray& op2);
	SortedArray& operator =(const SortedArray& op2);
	void show();
};
void SortedArray::sort() {
	int tmp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (p[j] > p[j + 1]) {
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}
SortedArray::SortedArray() {
	this->size = 0;
	this->p = NULL;
}
SortedArray::SortedArray(SortedArray& src) {
	this->size = src.size;
	this->p = new int[size];
	for (int i = 0; i < size; i++) {
		this->p[i] = src.p[i];
	}
	sort();
}
SortedArray::SortedArray(int p[], int size) {
	this->size = size;
	this->p = new int[size];
	for (int i = 0; i < size; i++) {
		this->p[i] = p[i];
	}
	sort();
}
SortedArray::~SortedArray() {
	delete[] p;
}
SortedArray SortedArray::operator +(SortedArray& op2) {
	SortedArray tmp;
	tmp.size = this->size + op2.size;
	tmp.p = new int[tmp.size];
	int ind = 0;
	for (int i = 0; i < this->size; i++) {
		tmp.p[ind++] = this->p[i];
	}
	for (int i = 0; i < op2.size; i++) {
		tmp.p[ind++] = op2.p[i];
	}
	sort();
	return tmp;
}
SortedArray& SortedArray::operator =(const SortedArray& op2) {
	delete[] this->p;
	this->size = op2.size;
	this->p = new int[this->size];
	for (int i = 0; i < size; i++) {
		this->p[i] = op2.p[i];
	}
	sort();
	return *this;
}
void SortedArray::show() {
	cout << "배열 출력 : ";
	for (int i = 0; i < size; i++) {
		cout << p[i] << ' ';
	}
	cout << endl;
}
int main() {
	int n[] = { 2,20,6 };
	int m[] = { 10,7,8,30 };
	SortedArray a(n, 3), b(m, 4), c;
	c = a + b;
	a.show();
	b.show();
	c.show();
}*/