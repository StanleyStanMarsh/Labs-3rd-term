#include <cmath>			// математические функции
#include <locale.h>	// функции, устанавливающие национальные кодировки символов
#include <iostream>	// Эта - часть библиотеки STL (Standard Template Library)
#include <float.h>			// Полезные константы
#include <conio.h>

using namespace std;		// Обеспечивает видимость имен STL

int n;	 // Глобальная переменная. По умолчанию она обнуляется.

namespace space	 // В пространстве имен - space
{
	int n = 1;	 // Объявлена переменная n
}				 // space определяет область видимости этой переменной

int  main()
{
	// Выполняя программу по шагам, следите за значениями переменных  и интерпретируйте результат, объясняя себе
	// наблюдаемые значения. Обратите внимание на разную интерпретацию отладчиком  signed и unsigned типов данных.
	char c = 'A'; // 65 'A' 0x41
	// В комментарии справа полезно проставить десятичное символьное и шестнадцатиричное
	// значения переменной после выполнения указанной строки. Вы должны видеть их в окне Autos.
	c = 0x42;		// 66 'B' 0x42
	c = -1;		// -1 'я' 0xff
	c = CHAR_BIT;	 // Размер переменной типа char

	// В комментариях напишите результат, возвращаемый оператором sizeof для
	// переменной типа wchar_t (ее размер)
	wchar_t cw = L'Ф';
	size_t ns = sizeof(cw); //ns = 2

	unsigned char uc = 0x41;
	uc = 'B';
	uc = -127; //  0x81 1000 0001

	int i = 1;
	i = -1;

	unsigned int ui = 1;
	ui = -1; // ui = 4294967295 0xffffffff

	unsigned short s = 0xffff;	 // Здесь compiler генерирует warning. Измените код, чтобы убрать warning
	s = short(0xffff);
	s = 1;

	//==== Измените код, чтобы убрать warning
	unsigned short us = 0xffff;
	us = 5;

	long long l = 0xffffffff;
	l = -128;

	l = FLT_MAX_EXP;	// 128 // Все эти константы вы должны найти в файле limits (float.h) и объяснить их смысл по комментариям
	l = DBL_MAX_EXP;    // 1024

	l = FLT_MANT_DIG; // 24
	l = DBL_DIG; // 15

	l = FLT_MANT_DIG; // 24
	l = DBL_MANT_DIG; // 53

	float f = -12.56;	 // Здесь warning. Уберите его.
	f = -1.e-27f;

	f = FLT_MAX;
	f = FLT_MIN;

	double d = 0.1234567890123456789123456789;
	d = -0.123456789012345e+306;
	d = DBL_MAX;
	d = DBL_MIN;
	d = DBL_EPSILON; // Самая маленькая разность между двумя пер-ми типа double

	uc = ~0;		 // Побитовое отрицание
	i = ~0;
	// Раннее (при компиляции) или неявное приведение типов данных
	// Объясните те значения, которые вы наблюдаете в окне Autos. Определите порядок выполения присваиваний.
	d = f = i = s = c = 1 / 3; // 0, 0, 0, 0, 0
	c = s = i = f = d = 100 / 3; // 33, 33, 33, 33, 33
	c = s = i = f = d = 10 / 3; // 3, 3, 3, 3, 3
	c = s = i = f = d = 1 / 3.; // c = 0, s = 0, f = 0.333333343, d = 0.33333333333333331, i = 0

	// Пример "небрежного" использования неявного приведения типов.	 Объясните результаты.
	i = 256;
	c = i;

	uc = 255;
	unsigned char u = 2, sum = uc + u;

	// Явное приведение типов	Объясните разницу результатов в строках (3) и (4)
	i = 100;
	f = d = i / 3;							// (3)
	f = d = (double)i / 3;		// (4)
	f = d = double(i) / 3;			// (4)
	f = d = static_cast<double>(i) / 3;		// (4)

	// Область действия, область видимости и время существования. В этом фрагменте фигурируют четыре
	//  переменных с одним и тем же именем n.  Одна - глобальная, вторая определена в своем пространстве имен,
	// третья - локальная внутри функции main(), четвертая - локальная внутри блока.
	//  Обратите внимание, что глобальная переменная и та, что в пространстве имен space - объявлены вне функции main()
	// Определите, к какой из четырех переменных идет обращение, cформулируйте область действия и область видимости
	// каждой переменной. Для выполнения задания рекомендуется пользоваться  закладкой "Watches" или "Locals" окна
	// "Autos". Подсказка: В окно "Watches" можно поместить сразу все переменные (n, ::n, и space::n)
	n = 100; // global
	space::n = 200;
	n++;
	int n;	// local	//Где живет эта переменная ?
	n = 10; // local
	::n++; // global

	{				//  Начало блока
		int n;		// Эта переменная живет внутри блока
		n = -1; // block local
		n++;
		::n++;
		space::n++;
	}		// Конец блока
	n--;
	::n--;
	space::n--;

	// Спецификатор класса памяти - static Выполняя задание по шагам, обратите внимание на  разное поведение
	// переменных nLoc и nStat
	{
	Again:
		int outer;
		for (int i = 0; i < 5; i++)
		{
			static int nStat;
			{
				int nLoc = 0;
				nLoc++;		nStat++;
			}
			outer = nStat;
		}
		if (outer < 10)
			goto Again;
	}
	// Перечисления - enum. Обратите внимание на явную и неявную инициализацию констант
	enum RANK
	{
		One, // 0
		Two,
		Three,
		Four,
		Jack = 6,
		Queen, // 7
		Ace = Queen + 3,
		Joker = 20
	};
	typedef RANK RANG;

	RANG r = Jack;
	if (r == Jack)
		r = Queen;

	if (r == Queen)
	{
		// Любой целочисленной переменной можно присвоить enum-переменную
		int i = r;
		r = RANK(i++);		// Обратное преобразование надо указывать явно
		i = r;
		r = RANK(++i);
		i = r;
	}
	RANK rr = Ace;
	//	Логический тип bool.	Выполняя задание по шагам, следите за значениями переменной b
	{
		int n = 127;
		bool b = n != 0; // true
		b = n == 0; // false
		b = n > 0; // true
		b = n <= 0; // false
		b = n > 1; // true

		int num = static_cast<int>(b); // num = 1
		if (b)
			cout << "\n\t My flag is: true" << "   or: " << b
			<< "\n\t Conversion to int: " << num << endl;
		b = n == num;
		cout << "\n\t Now the flag is: false" << "   or: " << b;
	}

	//	Модификатор const
	const double pi = acos(-1.);
	double space_permiability = 4.e-7 * pi;		//	Магнитная проницаемость пустоты
	const int dozen = 12;
	int var = dozen;

	//	Раскомментируйте следующую строчку и объясните ошибку компиляции (l-value означает left value)
	//	dozen = 1;
	//	Директивы условной трансляции. Объясните значение, которое принимает переменная version.
	//	Что нужно сделать для того, чтобы результат был другим?
// #define _MSVER400
	const char* version;
#if defined _MSVER400
	version = "version 4.00";
#elif defined _MSVER311
	version = "version 3.11";
#else
	version = "version Unknown";
#endif

	cout << endl << version;

	//В окне ClassView или Solution Explorer поставьте фокус на имя проекта дайте команду Project/Properties.
	//	В диалоге Property Pages щелкните на папке Configuration Properties, убедитесь, что в разделе Code Generation
	//	установлена константа компиляции _DEBUG. Создайте директивы препроцессора и код С++, которые
	//	в зависимости от действующей конфигурации проекта (_DEBUG или NDEBUG) выводят соответствующее
	//	сообщение. Измените конфигурацию проекта (в диалоге Property Pages) и проверьте ваш код.
	//	Чтобы изменить конфигурацию пользуйтесь кнопкой Configuration Manager

#if NDEBUG
cout << "\nrelease\n";
#else
cout << "\ndebug\n";
#endif

	//	Простейшие циклы. Объясните суть происходящего.
	{
		// Цикл while надо использовать, когда неизвестно количество итераций (повторений) цикла.
		cout << "\n\nGradually eat out all the units:\n\n";
		unsigned short us = 0xff;
		while (us)
		{
			cout << hex << us << endl;
			us &= us - 1;
		}
		cout << hex << us << "\nDone\n";
		// Цикл for надо использовать, когда известно количество итераций и/или есть код подготовки.
		// Подсказка: odd - нечетое, even - четное.
		cout << "\n\nShow even-odd:\n\n";
		for (int i = 0; i < 10; i++)
		{
			if (3 & 1)
				cout << i << " - odd\n";
			else
				cout << i << " - even\n";
		}
		// Когда нужно использовать цикл do-while?
		char c = ' ';
		do
		{
			if (c == 'a')
				cout << "\nAction is a delegate type in C#";
			else if (c == 'b')
				cout << "\nbreak is one of the 'leave' statements in all C-like languages";
			else if (c == 'c')
				cout << "\ncontinue is a 'go on' statement in all C-like languages";
			else if (c == 'd')
				cout << "\ndo-while is a rarely used loop statement in all C-like languages";
			else
				cout << "\nPlease read the rules of this loop";
			cout << "\n\nEnter chars: a, b, c, d (q - to quit):\n\n";
			cin >> c;
			if (c == 'q')
				cout << "\nI am going to leave the loop\n";
		} while (c != 'q');
	}
	//	Логические условные операторы и циклы. Функция y = f(x) задана графиком
	//	Напишите фрагмент кода, который с шагом 0.1 вычисляет y = f(x)  и выводит в консольное окно значения x и y.
	//	  y
	//	  |
	//	 2|__________
	//	  |         /\
	//	  |        /  \
	//	  |       /    \
	//	  |______/      \__________  x
	//	  0      1   2   3
	//	 Реалируйте 2 варианта этого алгоритма:   1. Используйте операторы if	 2. Используйте тернарные операции    ? :
    float x = 0;
    while (x < 4) {
        if (x <= 1 or x >= 3)
            cout << "x=" << x << "\ty=" << 0 << endl;
        else if (x > 1 and x < 2)
            cout << "x=" << x << "\ty=" << 2 * x - 2 << endl;
        else
            cout << "x=" << x << "\ty=" << - 2 * x + 6 << endl;
        x += 0.1;
    }
    cout << "---------------------" << endl;
    x = 0;
    while (x < 4) {
        float y;
        y = (x <= 1 or x >= 3) ? 0 : ((x > 1 and x < 2) ? (2 * x - 2) : (- 2 * x + 6));
        cout << "x=" << x << "\ty=" << y << endl;
        x += 0.1;
    }
	//	Напишите фрагмент, который с помощью for и switch реализует следующую логику. Если пользователь ввел:
	//	символ 'a',   ваш алгоритм выводит  "Ok" (в кавычках)
	//	символ 'b',   ваш алгоритм выводит  Bell (alert - звуковой сигнал)
	//	символ 'с',   ваш алгоритм выводит  число, которое равно количеству введенных символов
	//	символ 'Esc', ваш алгоритм выводит  "to quit use 'q'"
	//	символ 'q',   ваш алгоритм выводит  "Bye" и выходит из цикла ввода

    int key, count;
    char inp;
    for (;;){
        key = getch();
        count++;
        switch(key) {
            case 'a':
                cout << "Ok" << endl;
                break;
            case 'b':
                cout << "\a" << endl;
                break;
            case 'c':
                cout << "count: " << count << endl;
                break;
            case 27:
                cout << "to quit use 'q'" << endl;
                break;
            case 'q':
                cout << "Bye" << endl;
                goto finish_loop;
            default:
                break;
        }
    }
    finish_loop:
	//	Побитовые операции:  |, &, ~, ^ и сдвиги >>, <<
	//	Поменяйте местами байты переменной flags и выведите результат в консолное окно unsigned short flags = 0xaabb;
	//	Ваш код
	//	Для вывода в шестнадцатеричном виде используйте  cout <<"\n bits = " << hex << flags;
    unsigned short flags = 0xaabb;
    flags = (flags << 8) | (flags >> 8);
    cout << "\n bits = 0x" << hex << flags;
	//	В переменной unsigned char byte = 0x26;
        //      - установите в единицу 3-й бит (счет от нуля). Выведите результат.
    unsigned char byte = 0x26; // 00100110
    byte |= 0x08;
    cout << "\n byte = 0x" << hex << (int)byte; // 0x36 (00110110)
	//	- инвертируйте два младших бита. Выведите результат.
    byte ^= 0x03;
    byte ^= 0x03;
    cout << "\n byte = 0x" << hex << int(byte); // 0x35 (00110101)
        //      - обнулите 4 младших бита. Выведите результат.
    byte &= 0xf0;
    cout << "\n byte = 0x" << hex << int(byte); // 0x30 (00110000)

	cout << "\n\n";
    system("pause");
}	// Конец функции main()
