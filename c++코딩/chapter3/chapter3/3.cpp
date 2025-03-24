/*#include <iostream>
using namespace std;
class Tower {
public:
	int height;
	Tower();
	Tower(int height);
	int getHeight();
};
Tower::Tower() {
	height = 1;
}
Tower::Tower(int height) {
	this -> height = height;
}
int Tower::getHeight() {
	return height;
}
int main() {
	Tower myTower;
	Tower seoulTower(100);
	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
}*/
/*#include <iostream>
#include <string>
using namespace std;
class Date {
public:
	int year, month, day;
	Date(int year, int month, int day);
	Date(string date);
	void show();
	int getYear(), getMonth(), getDay();
};
Date::Date(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}
Date::Date(string date) {
	int ind;
	this->year = stoi(date);
	ind = date.find('/');
	this->month = stoi(date.substr(ind + 1));
	ind = date.find('/', ind + 1);
	this->day = stoi(date.substr(ind + 1));
}
void Date::show() {
	cout << year << "년" << month << "월" << day << "일" << endl;
}
int Date::getDay() {
	return day;
}
int Date::getYear() {
	return year;
}
int Date::getMonth() {
	return month;
}
int main() {
	Date birth(2014, 3, 20);
	Date indepndenceDay("1945/8/15");
	indepndenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}*/
/*#include <iostream>
#include <string>
using namespace std;
class Account {
public:
	string name;
	int id, balance;
	Account(string name, int id, int balance);
	void deposit(int money);
	int withdraw(int money), inquiry();
	string getOwner();
};
Account::Account(string name, int id, int balance) {
	this->name = name;
	this->id = id;
	this->balance = balance;
}
void Account::deposit(int money) {
	balance += money;
}
int Account::withdraw(int money) {
	balance -= money;
	return balance;
}
int Account::inquiry() {
	return balance;
}
string Account::getOwner() {
	return name;
}
int main() {
	Account a("kitae", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
}*/
/*#include <iostream>
#include <string>
using namespace std;
class CoffeeMachine
{
public:
	int coffee, water, sugar;
	CoffeeMachine(int coffee, int water, int sugar) { this->coffee = coffee; this->water = water; this->sugar = sugar; }
	void show();
	int drinkEspresso();
	int drinkAmericano();
	int drinkSugarCoffee();
	void fill() { coffee = 10; water = 10; sugar = 10; }
};
void CoffeeMachine::show() {
	cout << "커피머신 상태, " << "커피: " << coffee << " 물: " << water <<  " 설탕: " << sugar << endl;
}
int CoffeeMachine::drinkAmericano() {
	coffee = coffee - 1;
	water = water - 2;
	return coffee, water;
}
int CoffeeMachine::drinkEspresso() {
	coffee = coffee - 1;
	water = water - 1;
	return coffee, water;
}
int CoffeeMachine::drinkSugarCoffee() {
	coffee = coffee - 1;
	water = water - 2;
	sugar = sugar - 1;
	return coffee, water, sugar;
}
int main() {
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();
}*/
/*#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Random {
public:
	int randomInt;
	int next();
	int nextInRange(int a, int b);
};
int Random::next() {
	int n = rand();
	return n;
}
int Random::nextInRange(int a, int b) {
	int n = rand() % (b - a + 1) + a;
	return n;
}
int main() {
	Random r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "4까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
}*/
/*#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Random {
public:
	int next();
	int nextInRange(int a, int b);
};
int Random::next() {
	while (true) {
		int n = rand();
		if (n % 2 == 0) {
			return n;
		}
	}
}
int Random::nextInRange(int a, int b) {
	while (true) {
		int n = rand() % (b - 1) + a;
		if (n % 2 == 0)	{
			return n;
		}
	}
}
int main() {
	Random r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "4까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 10);
		cout << n << ' ';
	}
}*/
/*#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Random {
	string first, second;
public:
	int next();
	int nextInRange(int a, int b);
	void inputKind(string first, string second) { this->first = first; this->second = second; }
};
int Random::next() {
	while (true) {
		int n = rand();
		if (first == "짝수") {
			if (n % 2 == 0) {
				return n;
			}
		}
		else if (first == "홀수") {
			if (n % 2 == 1)	{
				return n;
			}
		}
	}
}
int Random::nextInRange(int a, int b) {
	while (true) {
		int n = rand() % (b - 1) + a;
		if (second == "짝수") {
			if (n % 2 == 0) {
				return n;
			}
		}
		else if (second == "홀수") {
			if (n % 2 == 1) {
				return n;
			}
		}
	}
}
int main() {
	string first, second;
	Random r;
	cout << "1번과 2번의 종류를 각각 정해주세요 >> ";
	cin >> first >> second;
	r.inputKind(first, second);
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 " << first << " 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "4까지의 랜덤 " << second << " 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 10);
		cout << n << ' ';
	}
}*/
/*#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Integer {
public:
	int num;
	Integer(int num) { this->num = num; }
	Integer(string nums) { num = stoi(nums); }
	int get() { return num; }
	void set(int num) { this->num = num; }
	bool isEven() { return true; }
};
int main() {
	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';
	Integer m("300");
	cout << m.get() << ' ';
	cout << m.isEven();
}*/
/*#include <iostream>
#include <string>
using namespace std;
class Oval {
private:
	int width;
	int height;
public:
	Oval() {
		width = height = 1;
	}
	Oval(int width, int height) {
		this->width = width;
		this->height = height;
	}
	~Oval() {
		cout << "Oval 소멸 : width = " << width << ", height = " << height << endl;
	}
	void show() {
		cout << "width = " << width << ", height = " << height << endl;
	}
	void set(int width, int height) {
		this->width = width;
		this->height = height;
	}
	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
};
int main() {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << "," << b.getHeight()<< endl;
}*/
/*#include <iostream>
#include <string>
using namespace std;
class Add {
	int a, b;
public:
	void setValue(int x, int y) {
		a = x; b = y;
	}
	int calculate() {
		return a + b;
	}
};
class Sub {
	int a, b;
public:
	void setValue(int x, int y) {
		a = x; b = y;
	}
	int calculate() {
		return a - b;
	}
};
class Mul {
	int a, b;
public:
	void setValue(int x, int y) {
		a = x; b = y;
	}
	int calculate() {
		return a * b;
	}
};
class Div {
	int a, b;
public:
	void setValue(int x, int y) {
		a = x; b = y;
	}
	int calculate() {
		return a / b;
	}
};
int main() {
	Add a;
	Sub s;
	Mul m;
	Div d;
	while (true) {
		cout << "두 정수와 연산자를 입력하세요>>";
		int x, y;
		char op;
		cin >> x >> y >> op;

		switch (op) {
		case '+':
			a.setValue(x, y);
			cout << a.calculate() << endl;
			break;
		case '-':
			s.setValue(x, y);
			cout << s.calculate() << endl;
			break;
		case '*':
			m.setValue(x, y);
			cout << m.calculate() << endl;
			break;
		case '/':
			d.setValue(x, y);
			cout << d.calculate() << endl;
			break;
		default:
			break;
		}
	}
}*/
/*#include <iostream>
#include <string>
#include "calculator.h"
using namespace std;
void Add::setValue(int x, int y) {
	this->x = x;
	this->y = y;
}
int Add::calculate() {
	return x + y;
}
void Sub::setValue(int x, int y) {
	this->x = x;
	this->y = y;
}
int Sub::calculate() {
	return x - y;
}
void Mul::setValue(int x, int y) {
	this->x = x;
	this->y = y;
}
int Mul::calculate() {
	return x * y;
}
void Div::setValue(int x, int y) {
	this->x = x;
	this->y = y;
}
int Div::calculate() {
	return x / y;
}
int main() {
	Add a;
	Sub s;
	Mul m;
	Div d;
	while (true) {
		cout << "두 정수와 연산자를 입력하세요>>";
		int x, y;
		char op;
		cin >> x >> y >> op;

		switch (op) {
		case '+':
			a.setValue(x, y);
			cout << a.calculate() << endl;
			break;
		case '-':
			s.setValue(x, y);
			cout << s.calculate() << endl;
			break;
		case '*':
			m.setValue(x, y);
			cout << m.calculate() << endl;
			break;
		case '/':
			d.setValue(x, y);
			cout << d.calculate() << endl;
			break;
		default:
			break;
		}
	}
}*/
/*#include "Box.h"
#include <iostream>
int main() {
	Box b(10, 2);
	b.draw();
	printf("\n");
	b.setSize(7, 4);
	b.setFill('^');
	b.draw();
}*/
#include <iostream>
#include "Ram.h"
using namespace std;
int main() {	
	Ram ram;
	ram.write(100, 20);
	ram.write(101, 30);
	char res = ram.read(100) + ram.read(101);
	ram.write(102, res);
	cout << "102 번지 값 = " << (int)ram.read(102);
}