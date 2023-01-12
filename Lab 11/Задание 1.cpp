#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <Windows.h>

using namespace std;
//Входной текстовый файл содержит отрывок литературного произведения. Необходимо сформировать выходной файл, удалив все строки, содержащие заданное слово (с учетом регистра).
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	ifstream fin("liter.txt");//входной файл
	ofstream fout("output.txt");// выходной файл
		string text;
		string slovo;
		string present_word;
		cout << "Введите слово, которое необходимо удалить = ";
		cin >> slovo;
		getline(fin, text);
		for (int i = 0; i < size(text); i++)
		{
			present_word += text[i];
			if (present_word == slovo)
			{
				while ( (i == 0 || i == (size(text)-1)) || (text[i + 1] == ' ' && i<size(text)) )
				{
					
						text.erase(i, 1);//очистка пробела
						for (int j = 0; j < size(slovo); j++)
						{
							text.erase(i - j, 1);
						}
						present_word.clear();
						i = -1;
					}
				}
				if (i > 0 && text[i] == ' ' )
					present_word.clear();
		}
		fout << text;
		fin.close();
		fout.close();
}

