#pragma once
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"

using namespace std;

class Computer {
private:
	//��� ����������
	int computerID;
	//�������� ����� ����������
	string computername;
	//��� ����������
	string typeofCPU;
	//������� ����������
	double CPUfrequency;
	//����� ����������� ������
	int capacityRAM;
	//����� �������� �����
	int capacityHDD;
	//����� ������ ����������
	int capacityGPU;
	//��������� ����������
	double cost;
	//���������� �����������
	int count;


	int typesearch;
public:
	//����������� �� ���������
	Computer()
	{
		int computerID = 0;
		string computername = "";
		string typeofCPU = "";
		double CPUfrequency = 0;
		int capacityRAM = 0;
		int capacityHDD = 0;
		int capacityGPU = 0;
		double cost = 0;
		int count = 0;
	}

	//��� ����������
	int ComputerID() {
		return computerID;
	}
	//�������� ����� ����������
	string ComputerName() {
		return computername;
	}
	//��� ����������
	string TypeOfCPU() {
		return typeofCPU;
	}	//������� ����������
	double CPUFrequency() {
		return CPUfrequency;
	}
	//����� ����������� ������
	int CapacityRAM() {
		return capacityRAM;
	}
	//����� �������� �����
	int CapacityHDD() {
		return capacityHDD;
	}
	//����� ������ ����������
	int CapacityGPU() {
		return capacityGPU;
	}
	//��������� ����������
	double Cost() {
		return cost;
	}
	//���������� �����������
	int Count() {
		return count;
	}
	//�������
	//��� ����������
	void ComputerID(int value) {
		computerID = value;
	}
	//�������� ����� ����������
	void ComputerName(string value) {
		computername = value;
	}
	//��� ����������
	void TypeOfCPU(string value) {
		typeofCPU = value;
	}	//������� ����������
	void CPUFrequency(double value) {
		CPUfrequency = value;
	}
	//����� ����������� ������
	void CapacityRAM(int value) {
		capacityRAM = value;
	}
	//����� �������� �����
	void CapacityHDD(int value) {
		capacityHDD = value;
	}
	//����� ������ ����������
	void CapacityGPU(int value) {
		capacityGPU = value;
	}
	//��������� ����������
	void Cost(double value) {
		cost = value;
	}
	//���������� �����������
	void Count(int value) {
		count = value;
	}

	int TypeSearch() {
		return typesearch;
	}
	//�������
	//��� ����������
	void TypeSearch(int value) {
		typesearch = value;
	}


	//��������� ��������� "���������"
	Computer ChangeComputer(Computer &result)
	{
		int num = InputNumber(0, 9, "��� ������ ��������\n1 - ID\n2 - Name\n3 - Type Cpu\n4 - frequency\n5 - Ram\n6 - Hdd\n7 - Gpu\n8 - cost\n9 - count\n0 - exit\n");
		switch (num)
		{
		case 1:
			result.computerID = InputNumber(0, 999999, "������� ����� ��� ���������� (0-999.999): ");
			break;
		case 2:
			result.computername = InputInformation("������� ����� ��� ����������: ");
			break;
		case 3:
			result.typeofCPU = InputInformation("������� ����� ��� ����������: ");
			break;
		case 4:
			result.CPUfrequency = InputDoubleNumber(0, 6, "������� ����� ������� ���������� (0-6 ���): ");
			break;
		case 5:
			result.capacityRAM = InputNumber(0, 256, "������� ����� ����� ����������� ������ (0-256 GB): ");
			break;
		case 6:
			result.capacityHDD = InputNumber(0, 8192, "������� ����� ����� �������� ����� (0-8.192 GB): ");
			break;
		case 7:
			result.capacityGPU = InputNumber(0, 16, "������� ����� ����� ������ ���������� (0-16 GB): ");
			break;
		case 8:
			result.cost = InputDoubleNumber(0, 1000000, "������� ����� ��������� ���������� (0-1.000.000 ���.): ");
			break;
		case 9:
			result.count = InputNumber(0, 100, "������� ����� ���������� ����������� (0-100 ��.): ");
			break;
		case 0:
			break;
		default:
			break;
		}
		return result;
	}

	//������������� �������� ��������� ��� ��������� "���������"
	Computer& operator = (Computer c)
	{
		computerID = c.computerID;
		computername = c.computername;
		typeofCPU = c.typeofCPU;
		CPUfrequency = c.CPUfrequency;
		capacityRAM = c.capacityRAM;
		capacityHDD = c.capacityHDD;
		capacityGPU = c.capacityGPU;
		cost = c.cost;
		count = c.count;

		return (*this);
	}

	//����� ������� �������� �� ���������� ��������
	bool SearchElement(Computer second)
	{
		switch (typesearch)
		{
		case 1:
			return ((*this).typeofCPU == second.typeofCPU);
		case 2:
			return ((*this).capacityRAM == second.capacityRAM);
		case 3:
			return ((*this).capacityGPU == second.capacityGPU);
		case 4:
			return ((*this).capacityHDD == second.capacityHDD);
		default:
			return false;
		}
	}
};
	//������� ����� ��������� "���������" � �������
	Computer InputScreenComputer()
	{
		Computer c;
		c.ComputerID( InputNumber(0, 999999, "������� ��� ���������� (0-999.999): "));
		c.ComputerName ( InputInformation("������� ��� ����������: "));
		c.TypeOfCPU (InputInformation("������� ��� ����������: "));
		c.CPUFrequency ( InputDoubleNumber(0, 6, "������� ������� ���������� (0-6 ���): "));
		c.CapacityRAM ( InputNumber(0, 256, "������� ����� ����������� ������ (0-256 GB): "));
		c.CapacityHDD ( InputNumber(0, 8192, "������� ����� �������� ����� (0-8.192 GB): "));
		c.CapacityGPU ( InputNumber(0, 16, "������� ����� ������ ���������� (0-16 GB): "));
		c.Cost ( InputDoubleNumber(0, 1000000, "������� ��������� ���������� (0-1.000.000 ���.): "));
		c.Count (InputNumber(0, 100, "������� ���������� ����������� (0-100 ��.): "));
		return c;
	}

	//������� ������ ��������� "���������" �� �������
	void OutputScreenComputer(Computer c)
	{
		cout << "��� ����������: " << c.ComputerID() << endl;
		cout << "��� ����� ����������: " << c.ComputerName() << endl;
		cout << "��� ����������: " << c.TypeOfCPU() << endl;
		cout << "������� ����������: " << c.CPUFrequency() << " ���" << endl;
		cout << "����� ����������� ������: " << c.CapacityRAM() << " GB" << endl;
		cout << "����� �������� �����: " << c.CapacityHDD() << " GB" << endl;
		cout << "����� ������ ����������: " << c.CapacityGPU() << " GB" << endl;
		cout << "��������� ����������: " << c.Cost() << " ���." << endl;
		cout << "���������� �����������: " << c.Count() << " ��." << endl;
	}

	//������� ��������� "���������" � ������
	string ToString(Computer c,int i)
	{
		return "������ � " + to_string(i) + "\r\n" + "��� ����������: " + to_string(c.ComputerID()) + "\r\n" + "��� ����������: " + c.ComputerName() + "\r\n" + "��� ����������: "
			+ c.TypeOfCPU() + "\r\n" + "������� ���������� (� ���): " + to_string(c.CPUFrequency()) + "\r\n"
			+ "����� ����������� ������ (� GB): " + to_string(c.CapacityRAM()) + "\r\n" + "����� �������� ����� (B GB): " +
			to_string(c.CapacityHDD()) + "\r\n" + "����� ������ ���������� (B DB): " + to_string(c.CapacityGPU()) + "\r\n" +
			"��������� ���������� (� ���.): " + to_string(c.Cost()) + "\r\n" + "���������� ����������� (� ��.): " + to_string(c.Count()) + "\r\n";
	}

	//���������� ��������� "���������" �� ������
	Computer ReadFromString(ifstream& input)
	{
		Computer c;
		string s;
		try
		{
			if (!input.eof())
			{
				getline(input, s);
			}
			if (!input.eof())
			{
				getline(input, s, '\n');
				string wrd = "��� ����������: ";
				c.ComputerID(atoi(s.substr(wrd.length(), s.length()).c_str()));
			}
			c.ComputerName (GetValueOfStr(input));
			/*if (!input.eof())
			{
				getline(input, s, '\n');
				string wrd = "��� ����������: ";
				result.computername = s.substr(wrd.length(), s.length()).c_str();
			}*/
			if (!input.eof())
			{
				getline(input, s, '\n');
				string wrd = "��� ����������: ";
				c.TypeOfCPU (s.substr(wrd.length(), s.length()).c_str());
			}
			if (!input.eof())
			{
				getline(input, s, '\n');
				string wrd = "������� ���������� (� ���): ";
				c.CPUFrequency ( atoi(s.substr(wrd.length(), s.length()).c_str()));
			}
			if (!input.eof())
			{
				getline(input, s, '\n');
				string wrd = "����� ����������� ������ (B GB): ";
				c.CapacityRAM ( atoi(s.substr(wrd.length(), s.length()).c_str()));
			}
			if (!input.eof())
			{
				getline(input, s, '\n');
				string wrd = "����� �������� ����� (B GB): ";
				c.CapacityHDD ( atoi(s.substr(wrd.length(), s.length()).c_str()));
			}
			if (!input.eof())
			{
				getline(input, s, '\n');
				string wrd = "����� ������ ���������� (B GB): ";
				c.CapacityGPU( atoi(s.substr(wrd.length(), s.length()).c_str()));
			}
			if (!input.eof())
			{
				getline(input, s, '\n');
				string wrd = "��������� ���������� (B ���.): ";
				c.Cost (atoi(s.substr(wrd.length(), s.length()).c_str()));
			}
			if (!input.eof())
			{
				getline(input, s, '\n');
				string wrd = "���������� ����������� (� ��.): ";
				c.Count ( atoi(s.substr(wrd.length(), s.length()).c_str()));
			}
		}
		catch (...)
		{
			cout << "������ ������ � ����!" << endl;
		}
		return c;
	}

	//���� �������� ������ � ����������� �� ���������� ����
	Computer InputChangeTypeSearch(int typesearch)
	{
		Computer c;
		switch (typesearch)
		{
		case 1:
			c.TypeOfCPU(InputInformation("������� ��� ����������: "));
			break;
		case 2:
			c.CapacityRAM(InputNumber(0, 256, "������� ����� ����������� ������ (0-256 GB) :"));
			break;
		case 3:
			c.CapacityGPU ( InputNumber(0, 16, "������� ����� ������ ���������� (0-16 GB): "));
			break;
		case 4:
			c.CapacityHDD ( InputNumber(0, 8192, "������� ����� �������� ����� (0-8.192 GB): "));
			break;
		}
		return c;
	}

//��������� �������� � ����������� �� ���������� ���� ��� ����������
int Sort(Computer first, Computer second, int typesearch)
{
	switch (typesearch)
	{
	case 1:
		if (first.TypeOfCPU() > second.TypeOfCPU()) return 1;
		else if (first.TypeOfCPU() < second.TypeOfCPU()) return -1;
		else return 0;
	case 2:
		if (first.CapacityRAM() > second.CapacityRAM()) return 1;
		else if (first.CapacityRAM() < second.CapacityRAM()) return -1;
		else return 0;
	case 3:
		if (first.CapacityGPU() > second.CapacityGPU()) return 1;
		else if (first.CapacityGPU() < second.CapacityGPU()) return -1;
		else return 0;
	case 4:
		if (first.CapacityHDD() > second.CapacityHDD()) return 1;
		else if (first.CapacityHDD() < second.CapacityHDD()) return -1;
		else return 0;
	default:
		return -2;
	}
};