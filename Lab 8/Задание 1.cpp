#include <iostream>
#include <cstring>
#include <string>
#include <clocale>
#include <Windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
	SetConsoleCP(1251); //русский язык для консоли
    cout << "С клавиатуры вводится строка символов, представляющая собой некоторый отрывок литературного произведения. Для каждого слова в тексте определить, сколько раз оно встречается.";
	const int MAX_WORDS_COUNT = 30;
	//Максимальная длина строки
	const int MAX_LENGTH = 10000;
	string s;
	//Массив строк, представляющих собой отдельные слова строки s
	char words[MAX_WORDS_COUNT][MAX_LENGTH + 1];
	string schet[MAX_WORDS_COUNT];
	int leng; //Длина строки s
	int nwords; //Счетчик количества выделенных слов
	int cur_word_len; //Длина текущего слова

	//Чтение строки s с клавиатуры
	cout << "Введите строку :" << endl;
	cin>>s;
	//Определение длины строки
	leng = size(s);
	nwords = cur_word_len = 0;
	//В цикле пробегаемся по всем символам строки s
	for (int i = 0; i < leng; i++)
	{
		//Если i-й символ строки s пробел, и длина
		//текущего выделяемого слова больше нуля
		//(это означает, что мы встретили пробел, и
		//текущее выделяемое слово закончилось)
		if (s[i] == ' ' && cur_word_len > 0)
		{
			//Добавляем нулевой символ в конец текущего
			//выделяемого слова (слова с индексом nwords
			//в массиве words) и увеличиваем на 1 счетчик количества
			//выделенных слов nwords
			words[nwords++][cur_word_len] = '\0';
			//Т.к. текущее выдяемое слово закончилось, то
			//обнуляем длину текущего выделяемого слова
			cur_word_len = 0;
		}
		//иначе, если i-й символ строки s не пробел, то
		//он является частью очередного слова, поэтому
		else if (s[i] != ' ')
		{
			//В конец очередного (текущего) выделяемого слова words[nwords]
			//добавляем i-й символ строки s
			words[nwords][cur_word_len++] = s[i];
		}
	}
	//Если после того, как был пробежались по всем символам строки s,
	//оказалось, что длина текущего выделяемого слова больше нуля
	//(это возможно только в случае, когда строка s не заканчивается
	// пробелом), то
	if (cur_word_len > 0)
	{
		//Добавляем нулевой символ в конец текущего
		//выделяемого слова (слова с индексом nwords
		//в массиве words) и увеличиваем на 1 счетчик количества
		//выделенных слов nwords
		words[nwords++][cur_word_len] = '\0';
		cur_word_len = 0;
	}

	//Выводим на экран выделенные из строки words слова
	cout << "Words : " << endl;
	int jj = 0;
	string ss=" ";
	string slovo;
	string otvet;
	int f = 0;
	int x = 0;
	for (int i = 0; i < nwords; i++)
	{
		int k = 0;

		ss = words[i];
		if (ss == schet[i - 1])
			continue;
		for (int j = 0; j < nwords; j++) //подсчет одинаковых слов
		{
			if (ss == words[j])
				k += 1;
			f = 1;
		}

		for (int p = 0; x > p; x--)//проверка одинкаовых слов 
			if (schet[x] == ss)
				f = 0;
		x = i;
		if (ss == schet[0])
			continue;
		
		if (f == 1)    
		{
			cout << ss << " = " << k << " ";
			for (int i = 0; i < nwords; i++)
				schet[i] = words[i];
		}
			else
				continue;
	}
	return 0;
}