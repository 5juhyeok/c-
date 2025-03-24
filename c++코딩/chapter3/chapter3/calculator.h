#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Add {
	int x, y;
public:
	void setValue(int x, int y);
	int calculate();
};

class Sub {
	int x, y;
public:
	void setValue(int x, int y);
	int calculate();
};

class Mul {
	int x, y;
public:
	void setValue(int x, int y);
	int calculate();
};

class Div {
	int x, y;
public:
	void setValue(int x, int y);
	int calculate();
};

#endif