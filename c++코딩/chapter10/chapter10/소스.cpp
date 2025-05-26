/*#include <iostream>
#include <string>
using namespace std;
template <class T>
T biggest(T x[], int y) {
	T biggest = x[0];
	for (int i = 0; i < y; i++) {
		if (biggest < x[i])
			biggest = x[i];
	}
	return biggest;
}
int main() {
	int a[] = { 1, 10, 100, 5, 4 };
	char b[] = { 'a', 'x', 't', 'u', 'o' };
	cout << biggest(a, 5) << endl;
	cout << biggest(b, 5) << endl;
}*/
/*#include <iostream>
#include <string>
using namespace std;

template <class T>
void reverseArray(T x[], int y) {
	for (int i = 0; i < y / 2; i++) {
		T tmp = x[i];
		x[i] = x[y - i - 1];
		x[y - i - 1] = tmp;
	}
}

int main() {
	int x[] = { 1, 10, 100, 5, 4 };
	reverseArray(x, 5);
	for (int i = 0; i < 5; i++) cout << x[i] << ' ';
}*/
/*#include <iostream>
using namespace std;
template <class T>
T* concat(T a[], int sizea, T b[], int sizeb) {
	T* p = new T[sizea + sizeb];
	for (int i = 0; i < sizea; i++)
		p[i] = a[i];
	for (int i = 0; i < sizeb; i++)
		p[i + sizea] = b[i];
	return p;
}
int main(){
	int xInt[] = { 1, 2, 3, 4, 5 }; // 정수형 배열일 경우
	int yInt[] = { 6, 7, 8, 9, 10 };

	int xSize = size(xInt);
	int ySize = size(yInt);
	int sizeT = xSize + ySize;
	auto* p = concat(xInt, xSize, yInt, ySize);

	for (int i = 0; i < sizeT; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	delete[] p;
	double xDouble[] = { 1.1, 2.2, 3.3, 4.4, 5.5 }; // 실수형 배열일 경우
	double yDouble[] = { 6.6, 7.7, 8.8, 9.9, 10.1 };
	xSize = size(xDouble);
	ySize = size(yDouble);
	sizeT = xSize + ySize;
	auto* q = concat(xDouble, xSize, yDouble, ySize);
	for (int i = 0; i < sizeT; i++)
	{
		cout << q[i] << " ";
	}
	cout << endl;
	delete[] q;
}*/
/*#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
};
Circle bigger(Circle a, Circle b) {
	if (a.getRadius() > b.getRadius()) return a;
	else return b;
}
template <class T>
T bigger(T a, T b) {
	if (a > b) return a;
	else return b;
}
int main() {
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20과 50중 큰 값은 " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.getRadius() << endl;
}*/
/*#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> v;
	int num;
	double sum{};
	while (true)
	{
		cout << "정수를 입력하세요(0을 입력하면 종료) >> ";
		cin >> num;
		if (num == 0)
			return 0;
		v.push_back(num);
		for (int i = 0; i < size(v); i++) {
			cout << v[i] << " ";
			sum += v[i];
		}
		cout << endl;
		double regular = sum / size(v);
		cout << "평균 = " << regular << endl;
		sum = 0;	
	}
}*/
/*#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Book {
protected:
	string name;
	int year;
	string writer;
public:
	Book(int year, string name, string writer)
	{
		this->year = year;
		this->name = name;
		this->writer = writer;
	}
	string getName()
	{
		return name;
	}
	string getWriter()
	{
		return writer;
	}
	int getYear()
	{
		return year;
	}
};
int main() {
	vector<Book> bv;
	string name;
	string writer;
	int year;
	cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 종료합니다. " << endl;
	while (true)
	{
		cout << "년도 >> ";
		cin >> year;
		if (year == -1) {
			cout << "총 입고된 책은 " << size(bv) << "입니다. " << endl;
			break;
		}
		cin.ignore();
		cout << "책 이름 >> ";
		getline(cin, name);

		cout << "저자 >> ";
		getline(cin, writer);

		Book book(year, name, writer);
		bv.push_back(book);
	}
	cin.ignore();
	cout << "검색하고자 하는 책의 저자 이름을 입력하세요 >> ";
	getline(cin, writer);
	for (int i = 0; i < size(bv); i++)
	{
		if (bv[i].getWriter() == writer)
			cout << bv[i].getYear() << ", " << bv[i].getName() << ", " << bv[i].getWriter() << endl;
	}
	cout << "검색하고자 하는 책의 출간 연도를 입력하세요 >> ";
	cin >> year;
	for (int i = 0; i < size(bv); i++)
	{
		if (bv[i].getYear() == year)
			cout << bv[i].getYear() << ", " << bv[i].getName() << ", " << bv[i].getWriter() << endl;
	}
}*/
/*#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
	int choice, score;
	string name;
	map <string, int> dic;
	cout << "***** 점수관리 프로그램 HIGH SCORE을 시작합니다. *****" << endl;
	while (true) {
		cout << "입력 : 1, 조회 : 2, 종료 : 3 >> ";
		cin >> choice;
		if (choice == 1) {
			cout << "이름과 점수 >> ";
			cin >> name >> score;
			dic[name] = score;
		}
		else if (choice == 2) {
			cout << "이름 >> ";
			cin >> name;
			if (dic.find(name) == dic.end())
				cout << "찾을 수 없습니다.";
			else
				cout << name <<"의 점수는 " << dic[name] << endl;
		}
		else if (choice == 3)
			break;
	}
	cout << "종료합니다..";
}*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Circle {
	string name;
	int radius;
public:
	Circle(int radius, string name) {
		this->radius = radius;
		this->name = name;
	}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};
int main() {
	int choice, radius;
	string name;
	vector<Circle*> v;
	cout << "원을 삭제하고 삽입하는 프로그램입니다. \n";
	while (true) {
		cout << "삽입 : 1, 삭제 : 2, 모두복기 : 3, 종료 : 4 >> ";
		cin >> choice;
		if (choice == 1) {
			cout << "생성하고자 하는 원의 반지름과 이름은 >> ";
			cin >> radius >> name;
			v.push_back(new Circle(radius, name));
		}
		else if (choice == 2) {
			vector<Circle*>::iterator it;
			it = v.begin();
			cout << "삭제하고자 하는 원의 이름은 >> ";
			cin >> name;
			for (int i = 0; i < size(v); i++)
			{
				if (v[i]->getName() == name) {
					it = v.erase(it);
					break;
				}
				it++;
			}
		}
		else if (choice == 3) {
			for (int i = 0; i < size(v); i++) {
				cout << v[i]->getName() << endl;
			}
			cout << endl;
		}
		else if (choice == 4) {
			break;
		}
	}
	cout << "프로그램을 종료합니다..";
}