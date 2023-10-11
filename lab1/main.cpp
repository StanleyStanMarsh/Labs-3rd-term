#include <cmath>			// �������������� �������
#include <locale.h>	// �������, ��������������� ������������ ��������� ��������
#include <iostream>	// ��� - ����� ���������� STL (Standard Template Library)
#include <float.h>			// �������� ���������
#include <conio.h>

using namespace std;		// ������������ ��������� ���� STL

int n;	 // ���������� ����������. �� ��������� ��� ����������.

namespace space	 // � ������������ ���� - space
{
	int n = 1;	 // ��������� ���������� n
}				 // space ���������� ������� ��������� ���� ����������

int  main()
{
	// �������� ��������� �� �����, ������� �� ���������� ����������  � ��������������� ���������, �������� ����
	// ����������� ��������. �������� �������� �� ������ ������������� ����������  signed � unsigned ����� ������.
	char c = 'A'; // 65 'A' 0x41
	// � ����������� ������ ������� ���������� ���������� ���������� � �����������������
	// �������� ���������� ����� ���������� ��������� ������. �� ������ ������ �� � ���� Autos.
	c = 0x42;		// 66 'B' 0x42
	c = -1;		// -1 '�' 0xff
	c = CHAR_BIT;	 // ������ ���������� ���� char

	// � ������������ �������� ���������, ������������ ���������� sizeof ���
	// ���������� ���� wchar_t (�� ������)
	wchar_t cw = L'�';
	size_t ns = sizeof(cw); //ns = 2

	unsigned char uc = 0x41;
	uc = 'B';
	uc = -127; //  0x81 1000 0001

	int i = 1;
	i = -1;

	unsigned int ui = 1;
	ui = -1; // ui = 4294967295 0xffffffff

	unsigned short s = 0xffff;	 // ����� compiler ���������� warning. �������� ���, ����� ������ warning
	s = short(0xffff);
	s = 1;

	//==== �������� ���, ����� ������ warning
	unsigned short us = 0xffff;
	us = 5;

	long long l = 0xffffffff;
	l = -128;

	l = FLT_MAX_EXP;	// 128 // ��� ��� ��������� �� ������ ����� � ����� limits (float.h) � ��������� �� ����� �� ������������
	l = DBL_MAX_EXP;    // 1024

	l = FLT_MANT_DIG; // 24
	l = DBL_DIG; // 15

	l = FLT_MANT_DIG; // 24
	l = DBL_MANT_DIG; // 53

	float f = -12.56;	 // ����� warning. ������� ���.
	f = -1.e-27f;

	f = FLT_MAX;
	f = FLT_MIN;

	double d = 0.1234567890123456789123456789;
	d = -0.123456789012345e+306;
	d = DBL_MAX;
	d = DBL_MIN;
	d = DBL_EPSILON; // ����� ��������� �������� ����� ����� ���-�� ���� double

	uc = ~0;		 // ��������� ���������
	i = ~0;
	// ������ (��� ����������) ��� ������� ���������� ����� ������
	// ��������� �� ��������, ������� �� ���������� � ���� Autos. ���������� ������� ��������� ������������.
	d = f = i = s = c = 1 / 3; // 0, 0, 0, 0, 0
	c = s = i = f = d = 100 / 3; // 33, 33, 33, 33, 33
	c = s = i = f = d = 10 / 3; // 3, 3, 3, 3, 3
	c = s = i = f = d = 1 / 3.; // c = 0, s = 0, f = 0.333333343, d = 0.33333333333333331, i = 0

	// ������ "����������" ������������� �������� ���������� �����.	 ��������� ����������.
	i = 256;
	c = i;

	uc = 255;
	unsigned char u = 2, sum = uc + u;

	// ����� ���������� �����	��������� ������� ����������� � ������� (3) � (4)
	i = 100;
	f = d = i / 3;							// (3)
	f = d = (double)i / 3;		// (4)
	f = d = double(i) / 3;			// (4)
	f = d = static_cast<double>(i) / 3;		// (4)

	// ������� ��������, ������� ��������� � ����� �������������. � ���� ��������� ���������� ������
	//  ���������� � ����� � ��� �� ������ n.  ���� - ����������, ������ ���������� � ����� ������������ ����,
	// ������ - ��������� ������ ������� main(), ��������� - ��������� ������ �����.
	//  �������� ��������, ��� ���������� ���������� � ��, ��� � ������������ ���� space - ��������� ��� ������� main()
	// ����������, � ����� �� ������� ���������� ���� ���������, c������������ ������� �������� � ������� ���������
	// ������ ����������. ��� ���������� ������� ������������� ������������  ��������� "Watches" ��� "Locals" ����
	// "Autos". ���������: � ���� "Watches" ����� ��������� ����� ��� ���������� (n, ::n, � space::n)
	n = 100; // global
	space::n = 200;
	n++;
	int n;	// local	//��� ����� ��� ���������� ?
	n = 10; // local
	::n++; // global

	{				//  ������ �����
		int n;		// ��� ���������� ����� ������ �����
		n = -1; // block local
		n++;
		::n++;
		space::n++;
	}		// ����� �����
	n--;
	::n--;
	space::n--;

	// ������������ ������ ������ - static �������� ������� �� �����, �������� �������� ��  ������ ���������
	// ���������� nLoc � nStat
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
	// ������������ - enum. �������� �������� �� ����� � ������� ������������� ��������
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
		// ����� ������������� ���������� ����� ��������� enum-����������
		int i = r;
		r = RANK(i++);		// �������� �������������� ���� ��������� ����
		i = r;
		r = RANK(++i);
		i = r;
	}
	RANK rr = Ace;
	//	���������� ��� bool.	�������� ������� �� �����, ������� �� ���������� ���������� b
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

	//	����������� const
	const double pi = acos(-1.);
	double space_permiability = 4.e-7 * pi;		//	��������� ������������� �������
	const int dozen = 12;
	int var = dozen;

	//	���������������� ��������� ������� � ��������� ������ ���������� (l-value �������� left value)
	//	dozen = 1;
	//	��������� �������� ����������. ��������� ��������, ������� ��������� ���������� version.
	//	��� ����� ������� ��� ����, ����� ��������� ��� ������?
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

	//� ���� ClassView ��� Solution Explorer ��������� ����� �� ��� ������� ����� ������� Project/Properties.
	//	� ������� Property Pages �������� �� ����� Configuration Properties, ���������, ��� � ������� Code Generation
	//	����������� ��������� ���������� _DEBUG. �������� ��������� ������������� � ��� �++, �������
	//	� ����������� �� ����������� ������������ ������� (_DEBUG ��� NDEBUG) ������� ���������������
	//	���������. �������� ������������ ������� (� ������� Property Pages) � ��������� ��� ���.
	//	����� �������� ������������ ����������� ������� Configuration Manager

#if NDEBUG
cout << "\nrelease\n";
#else
cout << "\ndebug\n";
#endif

	//	���������� �����. ��������� ���� �������������.
	{
		// ���� while ���� ������������, ����� ���������� ���������� �������� (����������) �����.
		cout << "\n\nGradually eat out all the units:\n\n";
		unsigned short us = 0xff;
		while (us)
		{
			cout << hex << us << endl;
			us &= us - 1;
		}
		cout << hex << us << "\nDone\n";
		// ���� for ���� ������������, ����� �������� ���������� �������� �/��� ���� ��� ����������.
		// ���������: odd - �������, even - ������.
		cout << "\n\nShow even-odd:\n\n";
		for (int i = 0; i < 10; i++)
		{
			if (3 & 1)
				cout << i << " - odd\n";
			else
				cout << i << " - even\n";
		}
		// ����� ����� ������������ ���� do-while?
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
	//	���������� �������� ��������� � �����. ������� y = f(x) ������ ��������
	//	�������� �������� ����, ������� � ����� 0.1 ��������� y = f(x)  � ������� � ���������� ���� �������� x � y.
	//	  y
	//	  |
	//	 2|__________
	//	  |         /\
	//	  |        /  \
	//	  |       /    \
	//	  |______/      \__________  x
	//	  0      1   2   3
	//	 ���������� 2 �������� ����� ���������:   1. ����������� ��������� if	 2. ����������� ��������� ��������    ? :
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
	//	�������� ��������, ������� � ������� for � switch ��������� ��������� ������. ���� ������������ ����:
	//	������ 'a',   ��� �������� �������  "Ok" (� ��������)
	//	������ 'b',   ��� �������� �������  Bell (alert - �������� ������)
	//	������ '�',   ��� �������� �������  �����, ������� ����� ���������� ��������� ��������
	//	������ 'Esc', ��� �������� �������  "to quit use 'q'"
	//	������ 'q',   ��� �������� �������  "Bye" � ������� �� ����� �����

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
	//	��������� ��������:  |, &, ~, ^ � ������ >>, <<
	//	��������� ������� ����� ���������� flags � �������� ��������� � ��������� ���� unsigned short flags = 0xaabb;
	//	��� ���
	//	��� ������ � ����������������� ���� �����������  cout <<"\n bits = " << hex << flags;
    unsigned short flags = 0xaabb;
    flags = (flags << 8) | (flags >> 8);
    cout << "\n bits = 0x" << hex << flags;
	//	� ���������� unsigned char byte = 0x26;
        //      - ���������� � ������� 3-� ��� (���� �� ����). �������� ���������.
    unsigned char byte = 0x26; // 00100110
    byte |= 0x08;
    cout << "\n byte = 0x" << hex << (int)byte; // 0x36 (00110110)
	//	- ������������ ��� ������� ����. �������� ���������.
    byte ^= 0x03;
    byte ^= 0x03;
    cout << "\n byte = 0x" << hex << int(byte); // 0x35 (00110101)
        //      - �������� 4 ������� ����. �������� ���������.
    byte &= 0xf0;
    cout << "\n byte = 0x" << hex << int(byte); // 0x30 (00110000)

	cout << "\n\n";
    system("pause");
}	// ����� ������� main()
