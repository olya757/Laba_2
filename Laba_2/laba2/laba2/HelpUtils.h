#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <string.h>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

template <class Type>
Type InputNumber(Type min, Type max, string message)
{
	Type n;
	do
	{
		cout << message;
		while ((!(cin >> n)) || (cin.get() != '\n'))
		{
			cout << "������������ ����! ��������� ����\n";
			cin.clear(); //��������������� �����, ���� �� � ��������� ���������
			cin.sync(); //������� ����� �� ��������� ��������
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message;
		}
	} while ((n < min) || (n > max));
	return n;
}

double InputDoubleNumber(int min, int max, string message)
{
	double n;
	do
	{
		cout << message;
		while ((!(cin >> n)) || (cin.get() != '\n'))
		{
			cout << "������������ ����! ��������� ����\n";
			cin.clear(); //��������������� �����, ���� �� � ��������� ���������
			cin.sync(); //������� ����� �� ��������� ��������
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message;
		}
	} while ((n < min) || (n > max));
	return n;
}

//���� ����������
string InputInformation(string message)
{
	string a, result;
	cout << message;
	do {
		cin >> a;
		result = result + ' ' + a;
	} while (cin.get() != '\n');
	return result;
}

//�������� ������� �� ������������ � ����� �����
bool CorrectSymbol(char c)
{
	switch (c)
	{
	case '.':
	case '*':
	case '?':
	case '<':
	case '>':
	case ':':
	case '|':
	case '/':
	case '\\':
		return false;
	default:
		return true;
	}
}

//�������� ����� ����� �� ������������
bool CorrectName(string name)
{
	int i = 0;
	bool check = true;
	for (int i = 0; (i < name.length() && check); i++)
	{
		check = CorrectSymbol(name[i]);
	}
	return check;
}

string GetValueOfStr(ifstream& input)
{
	string s;
	if (!input.eof())
	{
		getline(input, s, '\n');
		int pos = s.find(':');
		string str = s.substr(pos, s.length()).c_str();
		return str;
	}
}

//���� ����� �����
string InputFileName()
{
	string filename;
	do
	{
		cout << "������� ��� ����� (�� ����� 32 ��������): ";
		cin >> filename;
		if (filename.length() > 32)
		{
			filename.erase(filename.begin(), filename.begin() + 32);
		}
		if (CorrectName(filename))
		{
			break;
		}
		else
			cout << "�������� ��� �����\n";
	} while (true);
	return filename;
}