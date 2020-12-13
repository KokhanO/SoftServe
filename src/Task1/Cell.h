#pragma once
#include <string>
#include <iostream>
using namespace std;

class Cell
{
public:
	Cell() = delete;
	Cell(char texture, string piece);

	void display();

	~Cell() = default;
private:

	string piece_;
	char texture_;
};


class WhiteCell :public Cell
{
public:
	WhiteCell() = delete;
	WhiteCell(char texture, string piece = "0");

private:
};


class BlackCell :public Cell
{
public:
	BlackCell() = delete;
	BlackCell(char texture, string piece = "0");
	
private:
};