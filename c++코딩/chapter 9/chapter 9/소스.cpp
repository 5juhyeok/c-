/*#include <iostream>
using namespace std;
class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
		cout << getSourceString() << "을 입력하세요>> ";
		cin >> src;
		cout << "변환 결과: " << convert(src) << getDestString() << endl;
	}
};
class WonToDollar : public Converter {
public:
	WonToDollar(double ratio = 0.0) : Converter(ratio) { }
	double convert(double src) { return src / ratio; }
	string getSourceString() { return "원"; }
	string getDestString() { return "달러"; }
};
int main() {
	WonToDollar wd(1010);
	wd.run();
}*/
/*#include <iostream>
using namespace std;
class LoopAdder {
	string name;
	int x, y, sum;
	void read();
	void write();
protected:
	LoopAdder(string name = "") { this->name = name; }
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run();
};
void LoopAdder::read() {
	cout << name << ":" << endl;
	cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}
void LoopAdder::write() {
	cout << x << "에서 " << y << "까지의 합 = " << sum << "입니다." << endl;
}
void LoopAdder::run() {
	read();
	sum = calculate();
	write();
}
class ForLoopAdder : public LoopAdder {
public:
	ForLoopAdder(string name = "") : LoopAdder(name) { }
	int calculate() {
		int ret = 0;
		for (int i = getX(); i <= getY(); i++) {
			ret += i;
		}
		return ret;
	}
};
int main() {
	ForLoopAdder forLoop("For Loop");
	forLoop.run();
}*/
/*#include <iostream>
using namespace std;
class AbstractGate {
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};
class ANDGate : public AbstractGate {
public:
	bool operation() {
		return x & y;
	}
};
class ORGate : public AbstractGate {
public:
	bool operation() {
		return x | y;
	}
};
class XORGate : public AbstractGate {
public:
	bool operation() {
		return x ^ y;
	}
};
int main() {
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;
	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);
	cout.setf(ios::boolalpha);
	cout << andGate.operation() << endl;
	cout << orGate.operation() << endl;
	cout << xorGate.operation() << endl;
}*/
/*#include <iostream>
using namespace std;
class Shape {
protected:
	string name;
	int width, height;
public:
	Shape(string n = "", int w = 0, int h = 0) { name = n; width = w; height = h; }
	virtual double getArea() { return 0; }
	string getname() { return name; }
};
class Oval :public Shape {
public:
	Oval(string n, int w, int h) : Shape(n, w, h) { }
	double getArea() {
		return width * height * 3.14;
	}
};
class Rect :public Shape {
public:
	Rect(string n, int w, int h) : Shape(n, w, h) { }
	double getArea() {
		return width * height;
	}
};
class Triangular :public Shape {
public:
	Triangular(string n, int w, int h) : Shape(n, w, h) { }
	double getArea() {
		return width * height * 0.5;
	}
};
int main() {
	Shape* p[3];
	p[0] = new Oval("빈대떡", 10, 20);
	p[1] = new Rect("찰떡", 30, 40);
	p[2] = new Triangular("토스트", 30, 40);
		for (int i = 0; i < 3; i++) {
		cout << p[i]->getname() << " 넓이는 " << p[i]->getArea() << endl;
	}
		for (int i = 0; i < 3; i++) delete p[i];
}*/
#include <iostream>
using namespace std;
class Printer {
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
protected:
	Printer(string mo = "", string me = "", int a = 0) {
		this->model = mo;
		this->manufacturer = me;
		this->availableCount = a;
		this->printedCount = 0;
	}
	bool isValidPrint(int pages) {
		if (availableCount > pages) return true;
		else return false;
	}
	string getModel() { return model; }
	string getManufacturer() { return manufacturer; }
	int getPrintedCount() { return printedCount; }
	int getAvailableCount() { return availableCount; }
	void setModel(string model) { this->model = model; }
	void setManufacturer(string manufacturer) { this->manufacturer = manufacturer; }
	void setPrintedCount(int printedCount) { this->printedCount = printedCount; }
	void setAvailableCount(int availableCount) { this->availableCount = availableCount; }
	virtual void print(int pages) = 0;
	virtual void show() = 0;
};
class InkJetPrinter : public Printer {
	int availableInk;
public:
	InkJetPrinter(string mo = "", string me = "", int a = 0, int i = 0) : Printer(mo, me, a) { this->availableInk = i; }
	bool isValidInkJetPrint(int pages) {
		if (availableInk > pages) return true;
		else return false;
	}
	void print(int pages) {
		if (isValidPrint(pages)) {
			if (isValidInkJetPrint(pages)) {
				setPrintedCount(getPrintedCount() + pages);
				setAvailableCount(getAvailableCount() - pages);
				setAvailableInk(getAvailableInk() - pages);
				cout << "프린트하였습니다" << endl;
			}
			else {
				cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
			}
		}
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	void show() {
		cout << getModel() << ", " << getManufacturer() << ", 남은 종이 " << getAvailableCount() << "장, 남은 잉크 " << getAvailableInk() << endl;
	}
	int getAvailableInk() { return availableInk; }
	void setAvailableInk(int availableInk) { this->availableInk = availableInk; }
};
class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string mo = "", string me = "", int a = 0, int t = 0) : Printer(mo, me, a) { this->availableToner = t; }
	bool isValidLaserPrint(int pages) {
		if (availableToner > pages) return true;
		else return false;
	}
	void print(int pages) {
		if (isValidPrint(pages)) {
			if (isValidLaserPrint(pages)) {
				setPrintedCount(getPrintedCount() + pages);
				setAvailableCount(getAvailableCount() - pages);
				setAvailableToner(getAvailableToner() - pages);
				cout << "프린트하였습니다" << endl;
			}
			else {
				cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
			}
		}
		else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	void show() {
		cout << getModel() << ", " << getManufacturer() << ", 남은 종이 " << getAvailableCount() << "장, 남은 토너 " << availableToner << endl;
	}
	int getAvailableToner() { return availableToner; }
	void setAvailableToner(int availableToner) { this->availableToner = availableToner; }
};
int main() {
	InkJetPrinter* ink = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";
	ink->show();
	cout << "레이저 : ";
	laser->show();

	int printer, paper;
	char ch;
	while (true) {
		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> printer >> paper;
		switch (printer) {
		case 1: ink->print(paper); break;
		case 2: laser->print(paper); break;
		default: break;
		}
		ink->show();
		laser->show();
		cout << "게속 프린트 하시겠습니까(y/n)>>";
		cin >> ch;
		if (ch == 'n') break;
		else continue;
	};
}