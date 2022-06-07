#include <locale>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Timer.h"

using namespace std;

bool isDivider(char symbol);

bool isLetter(char symbol);

bool isDigit(char symbol);

string searchNumber(string str, int regionCode);

void findNumber(string text);

void replaceVariables(vector<string>& code);

void main()
{
	std::setlocale(LC_ALL, "ru");
	int task = 1;
	/*vector<string> protocols
	{
		"BMW �132��35",
		"�012��286 MAZDA",
		"�116��55 TOYOTA",
		"RENAULT �797��154",
		"Lorem Ipsum",
		"�707��000 FERRARI",
		"TESLA �278��45",
		"�263��999 LADA"
	};*/
	std::string protocols;

	vector<string> code
	{
		"int x = 5;",
		"int y = 6;",
		"std::cout << (x > y) ? x : y;",
		"for (size_t i = 0; i < size; i++)"
	};

	regex regular("(\\w+) (\\w+)(( = (\\w+))*)");

	while (task != 0)
	{
		system("cls");
		std::cout << "����� �10, ��������� �.�., ������� 22\n";

		std::cout << "1 - ����� � ������� ��������� ������-����\n"
			"2 - ��������� ���������� ����������\n"
			"0 - ����� �� ���������\n"
			"��� �����: ";

		cin >> task;
		cin.ignore();
		switch (task)
		{
		case 1:
			std::cout << "������� ������, � ������� ���������� ����� �����:\n";
			protocols = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. In et nibh sapien. In sollicitudin porttitor justo et maximus. Suspendisse potenti. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Proin pharetra vulputate enim. Nullam sapien tortor, mollis nec magna vitae, euismod eleifend enim. Sed a metus mauris. Morbi et velit rhoncus, hendrerit lacus sit amet, placerat urna.Quisque pellentesque tincidunt vulputate.Etiam rutrum libero ac enim fringilla, in condimentum ex tincidunt.Quisque ut vestibulum ipsum.Nunc sed suscipit purus.Nam sed tempus elit.Vivamus bibendum ac lectus eu pharetra.Duis non pretium ante, id venenatis dolor.Nullam eget magna nec felis porttitor pulvinar.Nunc sollicitudin turpis magna, in dignissim turpis posuere a.Duis rutrum commodo lectus, tristique posuere erat varius vel.Mauris congue tortor arcu.Phasellus pharetra elit vel justo malesuada finibus.In tincidunt vitae dui ut vulputate.Donec ut nisi Lorem ipsum dolor sit amet, consectetur adipiscing elit. In et nibh sapien. In sollicitudin porttitor justo et maximus. Suspendisse potenti. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Proin pharetra vulputate enim. Nullam sapien tortor, mollis nec magna vitae, euismod eleifend enim. Sed a metus mauris. Morbi et velit rhoncus, hendrerit lacus sit amet, placerat urna.Quisque pellentesque tincidunt vulputate.Etiam rutrum libero ac enim fringilla, in condimentum ex tincidunt.Quisque ut vestibulum ipsum.Nunc sed suscipit purus.Nam sed tempus elit.Vivamus bibendum ac lectus eu pharetra.Duis non pretium ante, id venenatis dolor.Nullam eget magna nec felis porttitor pulvinar.Nunc sollicitudin turpis magna, in dignissim turpis posuere a.Duis rutrum commodo lectus, tristique posuere erat varius vel.Mauris congue tortor arcu.Phasellus pharetra elit vel justo malesuada finibus.In tincidunt vitae dui ut vulputate.Donec ut nisi Lorem ipsum dolor sit amet, consectetur adipiscing elit. In et nibh sapien. In sollicitudin porttitor justo et maximus. Suspendisse potenti. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Proin pharetra vulputate enim. Nullam sapien tortor, mollis nec magna vitae, euismod eleifend enim. Sed a metus mauris. Morbi et velit rhoncus, hendrerit lacus sit amet, placerat urna.Quisque pellentesque tincidunt vulputate.Etiam rutrum libero ac enim fringilla, in condimentum ex tincidunt.Quisque ut vestibulum ipsum.Nunc sed suscipit purus.Nam sed tempus elit.Vivamus bibendum ac lectus eu pharetra.Duis non pretium ante, id venenatis dolor.Nullam eget magna nec felis porttitor pulvinar.Nunc sollicitudin turpis magna, in dignissim turpis posuere a.Duis rutrum commodo lectus, tristique posuere erat varius vel.Mauris congue tortor arcu.Phasellus pharetra elit vel justo malesuada finibus.In tincidunt vitae dui ut vulputate.Donec ut nisi Lorem ipsum dolor sit amet, consectetur adipiscing elit. In et nibh sapien. In sollicitudin porttitor justo et maximus. Suspendisse potenti. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Proin pharetra vulputate enim. Nullam sapien tortor, mollis nec magna vitae, euismod eleifend enim. Sed a metus mauris. Morbi et velit rhoncus, hendrerit lacus sit amet, placerat urna.Quisque pellentesque tincidunt vulputate.Etiam rutrum libero ac enim fringilla, in condimentum ex tincidunt.Quisque ut vestibulum ipsum.Nunc sed suscipit purus.Nam sed tempus elit.Vivamus bibendum ac lectus eu pharetra.Duis non pretium ante, id venenatis dolor.Nullam eget magna nec felis porttitor pulvinar.Nunc sollicitudin turpis magna, in dignissim turpis posuere a.Duis rutrum commodo lectus, tristique posuere erat varius vel.Mauris congue tortor arcu.Phasellus pharetra elit vel justo malesuada finibus.In tincidunt vitae dui ut vulputate.Donec ut nisi Lorem ipsum dolor sit amet, consectetur adipiscing elit. In et nibh sapien. In sollicitudin porttitor justo et maximus. Suspendisse potenti. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Proin pharetra vulputate enim. Nullam sapien tortor, mollis nec magna vitae, euismod eleifend enim. Sed a metus mauris. Morbi et velit rhoncus, hendrerit lacus sit amet, placerat urna.Quisque pellentesque tincidunt vulputate.Etiam rutrum libero ac enim fringilla, in condimentum ex tincidunt.Quisque ut vestibulum ipsum.Nunc sed suscipit purus.Nam sed tempus elit.Vivamus bibendum ac lectus eu pharetra.Duis non pretium ante, id venenatis dolor.Nullam eget magna nec felis porttitor pulvinar.Nunc sollicitudin turpis magna, in dignissim turpis posuere a.Duis rutrum commodo lectus, tristique posuere erat varius vel.Mauris congue tortor arcu.Phasellus pharetra elit vel justo malesuada finibus.In tincidunt vitae dui ut vulputate.Donec ut nisi Lorem ipsum dolor sit amet, consectetur adipiscing elit. In et nibh sapien. In sollicitudin porttitor justo et maximus. Suspendisse potenti. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Proin pharetra vulputate enim. Nullam sapien tortor, mollis nec magna vitae, euismod eleifend enim. Sed a metus mauris. Morbi et velit rhoncus, hendrerit lacus sit amet, placerat urna.Quisque pellentesque tincidunt vulputate.Etiam rutrum libero ac enim fringilla, in condimentum ex tincidunt.Quisque ut vestibulum ipsum.Nunc sed suscipit purus.Nam sed tempus elit.Vivamus bibendum ac lectus eu pharetra.Duis non pretium ante, id venenatis dolor.Nullam eget magna nec felis porttitor pulvinar.Nunc sollicitudin turpis magna, in dignissim turpis posuere a.Duis rutrum commodo lectus, tristique posuere erat varius vel.Mauris congue tortor arcu.Phasellus pharetra elit vel justo malesuada finibus.In tincidunt vitae dui ut vulputate.Donec ut nisi Lorem ipsum dolor sit amet, consectetur adipiscing elit. In et nibh sapien. In sollicitudin porttitor justo et maximus. Suspendisse potenti. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Proin pharetra vulputate enim. Nullam sapien tortor, mollis nec magna vitae, euismod eleifend enim. Sed a metus mauris. Morbi et velit rhoncus, hendrerit lacus sit amet, placerat urna.Quisque pellentesque tincidunt vulputate.Etiam rutrum libero ac enim fringilla, in condimentum ex tincidunt.Quisque ut vestibulum ipsum.Nunc sed suscipit purus.Nam sed tempus elit.Vivamus bibendum ac lectus eu pharetra.Duis non pretium ante, id venenatis dolor.Nullam eget magna nec felis porttitor pulvinar.Nunc sollicitudin turpis magna, in dignissim turpis posuere a.Duis rutrum commodo lectus, tristique posuere erat varius vel.Mauris congue tortor arcu.Phasellus pharetra elit vel justo malesuada finibus.In tincidunt vitae dui ut vulputate.Donec ut nisi Lorem ipsum dolor sit amet, consectetur adipiscing elit. In et nibh sapien. In sollicitudin porttitor justo et maximus. Suspendisse potenti. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Proin pharetra vulputate enim. Nullam sapien tortor, mollis nec magna vitae, euismod eleifend enim. Sed a metus mauris. Morbi et velit rhoncus, hendrerit lacus sit amet, placerat urna.Quisque pellentesque tincidunt vulputate.Etiam rutrum libero ac enim fringilla, in condimentum ex tincidunt.Quisque ut vestibulum ipsum.Nunc sed suscipit purus.Nam sed tempus elit.Vivamus bibendum ac lectus eu pharetra.Duis non pretium ante, id venenatis dolor.Nullam eget magna nec felis porttitor pulvinar.Nunc sollicitudin turpis magna, in dignissim turpis posuere a.Duis rutrum commodo lectus, tristique posuere erat varius vel.Mauris congue tortor arcu.Phasellus pharetra elit vel justo malesuada finibus.In tincidunt vitae dui ut vulputate.Donec ut nisi Lorem ipsum dolor sit amet, consectetur adipiscing elit. In et nibh sapien. In sollicitudin porttitor justo et maximus. Suspendisse potenti. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Proin pharetra vulputate enim. Nullam sapien tortor, mollis nec magna vitae, euismod eleifend enim. Sed a metus mauris. Morbi et velit rhoncus, hendrerit lacus sit amet, placerat urna.Quisque pellentesque tincidunt vulputate.Etiam rutrum libero ac enim fringilla, in condimentum ex �116��55 tincidunt.Quisque ut vestibulum ipsum.Nunc sed suscipit purus.Nam sed tempus elit.Vivamus bibendum ac lectus eu pharetra.Duis non pretium ante, id venenatis dolor.Nullam eget magna nec felis porttitor pulvinar.Nunc sollicitudin turpis magna, in dignissim turpis posuere a.Duis rutrum commodo lectus, tristique posuere erat varius vel.Mauris congue tortor arcu.Phasellus pharetra elit vel justo malesuada finibus.In tincidunt vitae dui ut vulputate.Donec ut nisi Lorem ipsum dolor sit amet, consectetur adipiscing elit. In et nibh sapien. In sollicitudin porttitor justo et maximus. Suspendisse potenti. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Proin pharetra vulputate enim. Nullam sapien tortor, mollis nec magna vitae, euismod eleifend enim. Sed a metus mauris. Morbi et velit rhoncus, hendrerit lacus sit amet, placerat urna.Quisque pellentesque tincidunt vulputate.Etiam rutrum libero ac enim fringilla, in condimentum ex tincidunt.Quisque ut vestibulum ipsum.Nunc sed suscipit purus.Nam sed tempus elit.Vivamus bibendum ac lectus eu pharetra.Duis non pretium ante, id venenatis dolor.Nullam eget magna nec felis porttitor pulvinar.Nunc sollicitudin turpis magna, in dignissim turpis posuere a.Duis rutrum commodo lectus, tristique posuere erat varius vel.Mauris congue tortor arcu.Phasellus pharetra elit vel justo malesuada finibus.In tincidunt vitae dui ut vulputate.Donec ut nisi ";
			findNumber(protocols);
			system("pause");
			break;
		case 2:
			std::cout << "������ ���������� � ���� ��������� �� ���������� ���������� ���� �� ���� �� ��������� NULL\n";

			std::cout << "\n����������� ���:\n";
			for (auto& str : code)
			{
				std::cout << str << "\n";
			}

			replaceVariables(code);
			std::cout << "\n��������� ���:\n";
			for (auto& str : code)
			{
				std::cout << str << "\n";
			}

			system("pause");
			break;
		default:
			break;
		}
	}
}

string searchNumber(string str, int regionCode) 
{
	int patternLength = 6 + regionCode;
	int textLength = str.length();

	int shift = 0;
	while (shift <= (textLength - patternLength))
	{
		int j = patternLength - 1;

		while (j >= 0)
		{
			if ((j == patternLength - 1) && (shift + j != textLength - 1) && (isDivider(str[shift + j + 1]) == false)) // ������� ����������� ������
			{
				break;
			}

			if ((j == 0) && (shift != 0) && (isDivider(str[shift - 1]) == false)) // ������� ����������� �����
			{
				break;
			}

			if (((j >= 1 && j <= 3) || (j >= 6 && j <= patternLength - 1)) && (isDigit(str[shift + j]) == false)) // �������� ������� ����
			{
				break;
			}

			if ((j == 0 || j == 4 || j == 5) && (isLetter(str[shift + j]) == false)) // �������� ������� ����
			{
				break;
			}
			--j;
		}

		if (j < 0)
		{
			return str.substr(shift, patternLength);
		}
		else
		{
			if (isDigit(str[shift + j]))
			{
				shift += 1;
			}
			else if (isLetter(str[shift + j]))
			{
				switch (regionCode)
				{
				case 2:
					shift += 2;
					break;
				case 3:
					shift += 3;
				default:
					break;
				}
			}
			else
			{
				shift += patternLength;
			}
		}
	}
	return "";
}

void findNumber(string text)
{
	std::cout << "����� ������ � ����� ������� � ���� �������: ";
	Timer* firstTimer = new Timer();
	string number2digits = searchNumber(text, 2);
	delete firstTimer;
	std::cout << "����� ������ � ����� ������� � ���� �������: ";
	Timer* secondTimer = new Timer();
	string number3digits = searchNumber(text, 3);
	delete secondTimer;
	string maxLenNumber = (number2digits >= number3digits) ? number2digits : number3digits;
	if (maxLenNumber.size() == 0)
	{
		maxLenNumber = "����� �� ������";
	}
	std::cout << maxLenNumber << endl;
}

void replaceVariables(vector<string>& code)
{
	regex regular("(\\w+) (\\w+)(( = (\\w+))*)");
	for (auto& str : code)
	{
		str = std::regex_replace(str, regular, "$1* $2 = NULL");
	}
}

bool isDivider(char symbol)
{
	vector<char> dividers
	{
		' ', ',', '.', ':', ';', '-', '!', '?', '\0'
	};

	for (auto& element : dividers)
	{
		if (element == symbol)
		{
			return true;
		}
	}

	return false;
}

bool isLetter(char symbol)
{
	vector<char> letters
	{
		'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'
	};

	for (auto& element : letters)
	{
		if (element == symbol)
		{
			return true;
		}
	}

	return false;
}

bool isDigit(char symbol)
{
	vector<char> digits
	{
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
	};

	for (auto& element : digits)
	{
		if (element == symbol)
		{
			return true;
		}
	}

	return false;
}
