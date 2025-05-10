/*#include <iostream>
#include <string>
using namespace std;
class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return radius * radius * 3.14; }
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int radius = 0, string name = "") : Circle(radius) {
		this->name = name;
	}
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << name;
	}
};

int main() {
	NamedCircle waffle(3, "waffle");
	waffle.show();
	return 0;
}*/
/*#include <iostream>
#include <string>
using namespace std;
class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};
class ColorPoint : public Point {
	string color;
public:
	ColorPoint(int x, int y, string color) : Point(x, y) { this->color = color; }
	void setPoint(int x, int y) { move(x, y); }
	void setColor(string color) { this->color = color; }
	void show() { cout << color << "색으로 (" << getX() << ", " << getY() << ")에 위치한 점입니다."; }
};
int main() {
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}*/
/*#include <iostream>
#include <string>
using namespace std;
class BaseArray {
private:
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};
class MyQueue : public BaseArray {
	int start;
	int end;
public:
	MyQueue(int capacity) : BaseArray(capacity) { start = 0; end = 0; }
	int capacity() { return getCapacity(); }
	int length() { return end - start; }
	void enqueue(int n) { put(end, n); end++; }
	int dequeue() { return get(start++); }
};
int main() {
	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' ';
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length();
}*/
/*#include <iostream>
using namespace std;
class BaseMemory {
	char* mem;
protected:
	BaseMemory(int size) { mem = new char[size]; }
	void setData(char x, int length) { mem[length] = x; }
	void setData(char x[], int length) { for (int i = 0; i < length; i++) mem[i] = x[i]; }
	char getData(int index) { return mem[index]; }
};
class ROM : public BaseMemory {
public:
	ROM(int size, char x[], int length) :BaseMemory(size) { setData(x, length); }
	char read(int index) { return getData(index); }
};
class RAM : public BaseMemory {
public:
	RAM(int size) : BaseMemory(size) {}
	void write(int index, char data) { setData(data, index); }
	char read(int index) { return getData(index); }
};
int main() {
	char x[5] = { 'h','e','l','l','o' };
	ROM biosROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);
	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
}*/
#include <iostream>
using namespace std;
class Seat {
	string name;
public:
	Seat(string n = "---") { name = n; }
	void reservation(string n) { name = n; }
	void cancle() { name = "---"; }
	void show() { cout << name; }
};
class Schedule {
	Seat* schedule;
	string time;
public:
	Schedule(string time = "00시") { schedule = new Seat[8]; this->time = time; }
	void reservation(int index, string name) { schedule[index].reservation(name); }
	void cancle(int index) { schedule[index].cancle(); }
	void show() {
		for (int i = 0; i < 8; i++) {
			schedule[i].show();
			cout << "\t";
		}
		cout << endl;
	}
	void setTime(string time) {
		this->time = time;
	}
	string getTime() {
		return time;
	}
};
class AirlineBook {
	Schedule* airlines;
public:
	AirlineBook() {
		airlines = new Schedule[3];
		airlines[0].setTime("07시");
		airlines[1].setTime("12시");
		airlines[2].setTime("17시");
	}
	void show(int index) {
		cout << airlines[index].getTime() << '\t';
		airlines[index].show();
	}
	void reservation(int index, int seat, string name) {
		airlines[index].reservation(seat, name);
	}
	void cancle(int index, int seat, string name) {
		airlines[index].cancle(seat);
	}
};
class Console {
public:
	static int menu;
	static int time;
	static AirlineBook hansung;
	static void start() {
		cout << "***** 한성항공에 오신것을 환영합니다 *****" << endl;
		while (true) {
			showMenu();
			switch (menu) {
			case 1:
				reservation(); break;
			case 2:
				cancle(); break;
			case 3:
				show(); break;
			case 4:
				return;
			}
		}
	}
	static void showMenu() {
		cout << "예약:1, 취소:2, 보기:3, 끝내기:4>>";
		cin >> menu;
	}
	static void reservation() {
		cout << "07시:1, 12시:2, 17시:3>>";
		cin >> time;
		hansung.show(time - 1);
		int seatNum;
		string name;
		cout << "좌석번호>>";
		cin >> seatNum;
		cout << "이름입력>>";
		cin >> name;
		hansung.reservation(time - 1, seatNum - 1, name);
	}
	static void cancle() {
		cout << "07시:1, 12시:2, 17시:3>>";
		cin >> time;
		hansung.show(time - 1);
		int seatNum;
		string name;
		cout << "좌석번호>>";
		cin >> seatNum;
		cout << "이름입력>>";
		cin >> name;
		hansung.cancle(time - 1, seatNum - 1, name);
	}
	static void show() {
		for (int i = 0; i < 3; i++) {
			hansung.show(i);
		}
	}
};
int Console::menu = 0;
int Console::time = 0;
AirlineBook Console::hansung;
int main() {
	Console::start();
}