//=======================================================================
//	������������ �3. ������� �������. ������� �������. ����������� ������� �++.
//				��������� ����������.
//=======================================================================
//����������� ����������� ����� �� ������������ 2
#include "MyVector.h"
#include "MyString.h"
#include "MyStack.h"
#include <vector>
#include <list>
#include <algorithm>
#include <string>

//============= ������ ������� ��� ������ � ������� ���������
template <class T> void pr(T& v, string s)
{
    cout<<"\n\n\t"<<s<<"  # Sequence:\n";

    // �������� ������ ����������
    typename T::iterator p;
    int i;

    for (p = v.begin(), i=0;  p != v.end();  p++, i++)
        cout << endl << i+1 <<". "<< *p;
    cout << '\n';
}

template <typename T> void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

bool pred(Vector v) { return (v.getX() > 4 && v.getY() > 4); }
bool predpt(Vector* v) { return (v->getX() > 4 && v->getY() > 4); }

class PredStr {
    char c;
public:
    PredStr(char k) : c(k) {}
    bool operator() (std::string str) { return str[0] == c; }
};

class PredStr2 {
    std::string c;
public:
    PredStr2(std::string k) { c = k; }
    bool operator() (std::string str) { return str == c; }
};

int Shape::Count = 0;
Shape* Shape::shapes[] = { nullptr };

int main()
{

    //===========================================================
    // ������� �������
    //===========================================================
    // �������� ������ ������� ������������ ���� ���������� - Swap().
    // ��������� ����������������� ���������� ������� � �������
    // ������������ ���� ���������.
    {
        int i = 1, j = -1;
		Swap (i, j);

        double a = 0.5, b = -5.5;
		Swap (a, b);

        Vector u(1,2), w(-3,-4);
		Swap(u, w);

        // ���� �� ���������� ������� ����� MyString � ���������� ������,
        // �� ��������� �������� ���� ������ �������� ���������.

        MyString s1 ("Your fault"), s2 ("My forgiveness");
        Swap (s1, s2);
    }
    //===========================================================
    // ������� �������
    //===========================================================
    // �������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
    // � �������� ������ ��� ����� ����� ���� ������ ������.
    // ��� ������� ������������� ������� ����� ����� ���� �����������
    // ��������-��������� �������
    // ������������� ���������� �� ������ �������� "Push" � "Pop","GetSize" � "Capacity"
    // �������������� - ����� ���� ����� �� ������� (operator[]).
    // ��� ����, ����� ������������� ���������� ���������� ���� ��������
    // ������� ������������ �������������� ��������.

    // � ������� ������� MyStack �������� ���� ���������� ���� int, �����
    // ���� ���������� ���� double �, �������, ���� �� ���������� ���� Vector
    // ���� �� ����������� ��� ������ ��� ��������� ����������,
    // �� ��������� �������� ������ ��������
    try
    {
        cout << "\tTest MyStack\n";
        MyStack <int, 3> stack;

        cout << "\nInteger Stack capacity: " << stack.Capacity();

        stack.Push(1);
        stack.Push(2);
        stack.Push(3);

        cout << "\nInteger Stack has: " << stack.GetSize() << " elements";

		stack.Push(4);	// ����� ������ ���� "���������" ����������

        cout << "\nInteger Stack pops: " << stack.Pop();
        cout << "\nInteger Stack pops: " << stack.Pop();

        cout << "\nInteger Stack has: " << stack.GetSize() << " elements";
        stack.Pop();
		stack.Pop();		// ����� ������ ���� "���������" ����������
        stack.Push(2);

//        int i = stack[3];	// ����� ������ ���� "���������" ����������

        MyStack<Vector, 5> ptStack;

        cout << "\nVector Stack capacity: " << ptStack.Capacity();

        ptStack.Push(Vector(1,1));
        ptStack.Push(Vector(2,2));

        cout << "\nVector Stack pops: ";
        // ����������� ����� ������ Vector ��� ������ ��������
        ptStack.Pop().Out();

        cout << "\nVector Stack has: " << ptStack.GetSize() << " elements";
    }
    catch (StackOverflow)
    {
        cout << "\nStack overflow";
    }
    catch (StackUnderflow)
    {
        cout << "\nStack underflow";
    }
    catch (StackOutOfRange o)
    {
        o.Out();
    }

    

    //=======================================================================
    // ���������� ����������� ����������. ������������������ ���� vector
    //=======================================================================

    // �������� ������ ������ ����� �����. ������� ��� ������ � ������� ������ size(),
    // � ������� ������ push_back() ��������� ������ ������-���� ����������.
    // �������� ����� ������ ������� � �������� �������� ��� ���������.
    // � �������� ������ � �������� �� ������ ����� ���������� ������� �����������
    // ��������� (size()) ������ ����������� ��������� ���������� ��������� (max_size()),
    // � ����� ����������������� ������ (capacity()).

    std::cout << "\n\t\tstd::vector\n";
    std::vector<int> v;

    int n = v.size();
    std::cout << "Size: " << n << '\n';

    v.push_back(-1);
    v.push_back(-2);

    std::cout << "Now in v: " << n << '\n';
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << ' ';
    std::cout << '\n';

    v.clear();
    n = v.size();
    std::cout << "Size: " << n << '\n';

    n = v.capacity();
    std::cout << "Capacity: " << n << '\n';
    long long k = v.max_size();
    std::cout << "max size: " << k << '\n';

    // ��� ��� �� ����� ����� �������� ������������������, �� �������������
    // ������� ������ ������� ��� ������ ������ ����������.
    // ��������������� ���� ������ �������� (pr), ������� �������� ����
    // ����������� ��� ��� ������ ������ �������

    pr (v, "Vector of ints");

    // ���������� ������ ����������� ��� �������� ������� ������������
    // � ��������� �������� � 2 �������� � ����������� (222.).
    // �������� ��������� �������. ����� ������� ������ ������� � ��� ����������
    // (����� - resize()) � ����� �������� ���������.

    std::vector<double> vd(2, 222.);
    pr (vd, "Vector of doubles");
    n = vd.size();
    n = vd.capacity();
    long long t = vd.max_size();

    vd.resize(3, 333.);
    pr (vd, "After resize");
    n = vd.size();
    n = vd.capacity();
    t = vd.max_size();

    // ��������� ����� at(), � ����� �������� ������ [], �������� ��������
    // ��������� ��������� ������� � ��������� ���������.
    vd.at(0) = 111.;
    vd.at(1) = 222.;
    pr (vd, "After at");

    // �������� ������ ������������, ������� �������� ������ �������������.
    std::vector<double> wd = vd;
    pr (wd, "Copy");

    // �������� ������, ������� �������� ����� ������������ ������������������
    std::vector<double> ud(wd.begin() + 1, wd.begin() + 3);
    pr (ud, "Copy part");

    // �������� ������ ������������, ������� �������� ������ ����� �������� �������.
    double ar[] = { 0., 1., 2., 3., 4., 5. };

    std::vector<double> va(ar + 1, ar + 4);
    pr (va, "Copy part of array");

    // �������� ������ ��������, ������� �������� ������ ����� ������� ������
    char s[] = "Array is a succession of chars";

    std::vector<char> vc(s + 4, s + 16);
    pr (vc, "Copy part of c-style string");

    // �������� ������ ��������� ���� Vector � ���������������
    // ��� �������� � ������������ (1,1).
    std::vector<Vector> vv{Vector(1, 1)};

    cout << "\n\nvector of Vectors\n";
    for (int i=0;  i < vv.size();  i++)
        vv[i].Out();

    // �������� ������ ���������� �� Vector � ��������������� ��� ��������
    // �������� ������ Vector

    Vector v1(1, 2);
    Vector v2(3, 4);
    Vector v3(5, 6);

    std::vector<Vector*> vp{&v1, &v2, &v3};

    cout << "\n\nvector of pointers to Vector\n";

    for (int i=0;  i < vp.size();  i++)
        vp[i]->Out();

    // ��������� ������������ ������� assign � ���������
    // ������������ = ��� ����������� ���� vector.
    vp.assign(2, &v2);

    cout << "\n\nAfter assign\n";
    for (int i=0;  i < vp.size();  i++)
        vp[i]->Out();

    // ������������ ����� ������ ���������� �� Vector � ��������������� ���
    // � ������� ������ ������ assign
    std::vector<Vector*> vpNew;
    vpNew.assign(&vp[0], &vp[1]);

    cout << "\n\nNew vector after assign\n";
    for (int i=0;  i < vpNew.size();  i++)
        vpNew[i]->Out();


    // �� ���� ������� vector �������� ���������� ������ �
    // ��������� ��� ���������� ������� ���������.
    // ������ ������� - ������������� �������
    // ������ ������� - ����������� �������

    vector <vector<double>> vd1;
    vd1.resize(5);
    for (int i=0;  i < vd1.size();  i++)
        vd1[i] = vector<double>(vd1.size(), double(i));

    cout << "\n\n\tTest vector of vector<double>\n";
    for (int i=0;  i < vd1.size();  i++)
    {
        cout << endl;
        for (int j=0;  j < vd1[i].size();  j++)
            cout << vd1[i][j] << "  ";
    }

    //========= ����������� �������
    vector <vector<double>> vdd;
    vdd.resize(5);
    for (int i=0;  i < vdd.size();  i++)
        vdd[i] = vector<double>(i+1, double(i));

    cout << "\n\n\tTest vector of vector<double>\n";
    for (int i=0;  i < vdd.size();  i++)
    {
        cout << endl;
        for (int j=0;  j < vdd[i].size();  j++)
            cout << vdd[i][j] << "  ";
    }
    std::cout << '\n';

    //===================================
    // ���������� �������� � ������������
    //===================================
    //3�. ��������� �������� ������� � ���������� ��������� ������������������.
    //��������� ������� ������������������. ������������ ��������
    //��������� ����� ������������������ ��������� ������ - assign().

    //�������� � ������������������ ������ �� ��������� char. ������ -
    //�� �������.
    std::vector<char> vchar {'a', 'b', 'c', 'd'};

    //�������� � ������������������ ������ �� ��������� char. ������ -
    //�� �������.
    char cMas[] {'1', '2', '3', '4', '5'};

    //�������� �������� ������� �������� ������� ( front() )
    std::cout << "front element of vector " << vchar.front() << '\n';

    //�������� �������� ���������� �������� ������� ( back() )
    std::cout << "last element of vector " << vchar.back() << '\n';

    //�������� ������ �������
    std::cout << "size of vector " << vchar.size() << '\n';

    //��������� ������� ����� �������� �� �������� ������� cMas.
    vchar.assign(cMas + 1, cMas + 4);

    //��������� ������ �������, ������ � ��������� ��������.
    std::cout << "after: front element of vector " << vchar.front() << '\n';
    std::cout << "after: last element of vector " << vchar.back() << '\n';
    std::cout << "after: size of vector " << vchar.size() << '\n';


    //3�. ������ � ������������ ��������� ������� � ��������� - at()
    //� ��� �������� - []
    //�������� �������������������� ������ �� 8 ��������� char - vChar2.
    //� ������� at() ��������� ������ ��������� ������� ��������
    //��������� vChar1 �� ����������� �������,
    //� � ������� [] ��������� �������� ��������� ������� vChar2 ��������
    //������� {'K','U','K','U'}.
    char charray[] {'K','U','K','U'};
    std::vector<char> vChar2(8);

    for (int i = 0; i < vChar2.size(); i++) {
        if (i % 2 == 0)
            vChar2.at(i) = vchar.at(i / 3);
        else
            vChar2[i] = charray[i / 2];
    }

    for (int i = 0; i < vChar2.size(); i++)
        std::cout << vChar2[i] << ' ';
    std::cout << '\n';


    //���������� "�����" �� ������� ������� � ������� at() �
    //� ������� []. �������� ��������: ��� ���������� ���
    //������� ��������� � ��������������� �������� � ����� �������
    try {
        std::cout << vChar2.at(vChar2.size());
    }
    catch (std::exception){}
//    std::cout << vChar2[vChar2.size() + 1000];
    

    //3�.�������� � ����� ������� vChar2  - ����� Z (push_back()). ���
    //���������� ��������� ������ �� ����� �� � �������� (pop_back())
    vChar2.push_back('Z');
    vChar2.pop_back();
    

    //3�. �������-�������� �������� ������������������ insert() - erase()
    //������� ������������������ - clear()



    //�������� ����� ������ ��������� ������� vChar2 ����� 'W'
    for (int i = 0; i < vChar2.size(); i++) {
        vChar2.insert(vChar2.begin() + i, 'W');
        i++;
    }
    for (int i = 0; i < vChar2.size(); i++)
        std::cout << vChar2[i] << ' ';
    std::cout << '\n';
    //�������� ����� 5-�� ��������� ������� vChar2 3 ����� 'X'
    vChar2.insert(vChar2.begin() + 4, 3, 'X');
    for (int i = 0; i < vChar2.size(); i++)
        std::cout << vChar2[i] << ' ';
    std::cout << '\n';

    //�������� ����� 2-�� ��������� ������� vChar2 � �������� ��
    //������ �������� ������� "aaabbbccc"
    char carr[] = "aaabbbccc";
    vChar2.insert(vChar2.begin() + 1, carr + 2, carr + 6);
    for (int i = 0; i < vChar2.size(); i++)
        std::cout << vChar2[i] << ' ';
    std::cout << '\n';

    //������� c ������� �� ������� �������� vChar2
    vChar2.erase(vChar2.begin(), vChar2.begin() + 10);
    for (int i = 0; i < vChar2.size(); i++)
        std::cout << vChar2[i] << ' ';
    std::cout << '\n';
    

    //���������� ��� �������� ������������������ - clear()
    vChar2.clear();
    

    //�������� ����������� �������
//10X5 2
    vector<vector<int>> vvv(10, vector<int>(5, 2));

///////////////////////////////////////////////////////////////////
	//������� 4. ������. ��������, ����������� ��� �������.
	//�������� ��� ������ ������ �� ��������� Vector - ptList1 �
	//ptList2
	std::list<Vector> ptList1, ptList2;

	//��������� ��� ������ ���������� � ������� ������� push_back(),
	//push_front, insrert()
    ptList1.push_back(v1);
    ptList1.push_front(v2);
    ptList1.push_front(Vector(10, 22));

    ptList2.push_back(v3);
    ptList2.push_front(Vector(123, 345));
    ptList2.push_front(Vector(12, 34));

    pr(ptList1, "ptList1");
    std::cout << '\n';
    pr(ptList2, "ptList2");
    std::cout << '\n';

    //������������ ������ - sort().
	//���������: ��� ����, ����� �������� ����������, � ������ Vector
	//������ ���� ������������� �������� "<"
    ptList1.sort();
    ptList2.sort();

    pr(ptList1, "sorted ptList1");
    std::cout << '\n';
    pr(ptList2, "sorted ptList2");
    std::cout << '\n';

	//���������� ��������������� ������ - merge(). ����������: ���
	//��� ���� ���������� �� ������ �������.

    ptList1.merge(ptList2);
    pr(ptList1, "merged ptList1");
    std::cout << '\n';
    pr(ptList2, "merged ptList2");
    std::cout << '\n';

	//���������� �������� �� ������ - remove()
	//��������� �� ������ ������� � ������������ ���������.
	//���������: ��� ����� ���������� ����� ��������������
	//� ������ Vector �������� "=="
    ptList1.remove(v1);

	
///////////////////////////////////////////////////////////////////
	//������� 5. ����������� ���������.���������� ������������ ����
	// <algorithm>
	//5�. �������� �� ����� �������� ptList1 �� �����������
	//������� � ������� ��������� for_each()
    std::for_each(ptList1.begin(), ptList1.end(), [](Vector v) { std::cout << v << ' '; });
	

	//5�.� ������� ��������� find() ������� �������� �� ������� Vector �
	//������������ ���������. � ������� ��������� find_if() �������
	//�������� �� �������, ��������������� ������������� �������, 
	//��������, ��� ���������� ����� ������ ���� ������ 2.
	//���������: �������� �������-��������, ������� ��������� �������
	//� ���������� boolean-�������� (�������� ����� ���� ��� ����������
	//��������, ��� � ������� ������)
    std::cout << *std::find(ptList1.begin(), ptList1.end(), v1) << '\n';
    std::cout << *std::find_if(ptList1.begin(), ptList1.end(), pred) << '\n';

	  

	//�������� ������ �� ���������� �� ������� Vector. � ������� 
	//��������� find_if() � ��������� (����� ������������ �������� - 
	//����� ������ Vector, ������������ � ���������� �������) ������� �
	//������������������ �������, ��������������� �������
    std::list<Vector *> ptList3;
    ptList3.push_back(&v1);
    ptList3.push_back(&v2);
    ptList3.push_back(&v3);
    std::cout << *std::find_if(ptList3.begin(), ptList3.end(), predpt) << '\n';

	//5�. �������� ������ ��������� Vector. ��������� ������
	//����������. � ������� ��������� replace() �������� �������
	//� ������������ ��������� ����� ���������. � ������� ���������
	//replace_if() �������� �������, ��������������� ������-����
	//������� �� ������������ ��������. ���������: �������
	//�������� ����������.
    std::replace(ptList3.begin(), ptList3.end(), &v1, &v2);

  //������������ �������� ��������� ������
    std::replace_if(ptList3.begin(), ptList3.end(), predpt, &v2);
  
	


	//5�. �������� ������ ����� (string). � ������� ��������� count()
	//���������� ���������� ���������� �����. � ������� ���������
	//count_if() ���������� ���������� �����, ������������ � ��������
	//�����
    std::vector<std::string> strVec {"abc", "def", "ghi", "abc", "abc"};
    std::cout << std::count(strVec.begin(), strVec.end(), "abc") << '\n';
    std::cout << std::count_if(strVec.begin(), strVec.end(), PredStr('d')) << '\n';

	//5�. � ������� ��������� count_if() ���������� ���������� �����,
	//������� ��������� � �������� �������. ���������: ������ ����
	//�������-�������
    std::cout << std::count_if(strVec.begin(), strVec.end(), PredStr2("abc")) << '\n';



    cout <<"\n\n";
}