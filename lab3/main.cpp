//=======================================================================
//	Лабораторная №3. Шаблоны функций. Шаблоны классов. Стандартные шаблоны С++.
//				Обработка исключений.
//=======================================================================
//Используйте недостающие файлы из лабораторной 2
#include "MyVector.h"
#include "MyString.h"
#include "MyStack.h"
#include <vector>
#include <list>
#include <algorithm>
#include <string>

//============= Шаблон функции для вывода с помощью итератора
template <class T> void pr(T& v, string s)
{
    cout<<"\n\n\t"<<s<<"  # Sequence:\n";

    // Итератор любого контейнера
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
    // Шаблоны функций
    //===========================================================
    // Создайте шаблон функции перестановки двух параметров - Swap().
    // Проверьте работоспособность созданного шаблона с помощью
    // приведенного ниже фрагмента.
    {
        int i = 1, j = -1;
		Swap (i, j);

        double a = 0.5, b = -5.5;
		Swap (a, b);

        Vector u(1,2), w(-3,-4);
		Swap(u, w);

        // Если вы достаточно развили класс MyString в предыдущей работе,
        // то следующий фрагмент тоже должен работать корректно.

        MyString s1 ("Your fault"), s2 ("My forgiveness");
        Swap (s1, s2);
    }
    //===========================================================
    // Шаблоны классов
    //===========================================================
    // Создайте шаблон класса MyStack для хранения элементов любого типа T.
    // В качестве основы для стека может быть выбран массив.
    // Для задания максимального размера стека может быть использован
    // параметр-константа шаблона
    // Обязательными операциями со стеком являются "Push" и "Pop","GetSize" и "Capacity"
    // Необязательной - может быть выбор по индексу (operator[]).
    // Для того, чтобы гарантировать корректное выполнение этих операций
    // следует генерировать исключительные ситуации.

    // С помощью шаблона MyStack создайте стек переменных типа int, затем
    // стек переменных типа double и, наконец, стек из переменных типа Vector
    // Если вы подготовите три класса для обработки исключений,
    // то следующий фрагмент должен работать
    try
    {
        cout << "\tTest MyStack\n";
        MyStack <int, 3> stack;

        cout << "\nInteger Stack capacity: " << stack.Capacity();

        stack.Push(1);
        stack.Push(2);
        stack.Push(3);

        cout << "\nInteger Stack has: " << stack.GetSize() << " elements";

		stack.Push(4);	// Здесь должно быть "выброшено" исключение

        cout << "\nInteger Stack pops: " << stack.Pop();
        cout << "\nInteger Stack pops: " << stack.Pop();

        cout << "\nInteger Stack has: " << stack.GetSize() << " elements";
        stack.Pop();
		stack.Pop();		// Здесь должно быть "выброшено" исключение
        stack.Push(2);

//        int i = stack[3];	// Здесь должно быть "выброшено" исключение

        MyStack<Vector, 5> ptStack;

        cout << "\nVector Stack capacity: " << ptStack.Capacity();

        ptStack.Push(Vector(1,1));
        ptStack.Push(Vector(2,2));

        cout << "\nVector Stack pops: ";
        // Используйте метод класса Vector для вывода элемента
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
    // Контейнеры стандартной библиотеки. Последовательности типа vector
    //=======================================================================

    // Создайте пустой вектор целых чисел. Узнайте его размер с помощью метода size(),
    // С помощью метода push_back() заполните вектор какими-либо значениями.
    // Получите новый размер вектора и выведите значения его элементов.
    // В процессе работы с вектором вы можете кроме количества реально заполненных
    // элементов (size()) узнать максимально возможное количество элементов (max_size()),
    // а также зарезервированную память (capacity()).

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

    // Так как мы часто будем выводить последовательности, то целесообразно
    // создать шаблон функции для вывода любого контейнера.
    // Проанализируйте коды такого шабдлона (pr), который приведен выше
    // Используйте его для вывода вашего вектора

    pr (v, "Vector of ints");

    // Используем другой конструктор для создания вектора вещественных
    // с начальным размером в 2 элемента и заполнением (222.).
    // Проверим параметры вектора. Затем изменим размер вектора и его заполнение
    // (метод - resize()) и вновь проверим параметры.

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

    // Используя метод at(), а также операцию выбора [], измените значения
    // некоторых элементов вектора и проверьте результат.
    vd.at(0) = 111.;
    vd.at(1) = 222.;
    pr (vd, "After at");

    // Создайте вектор вещественных, который является копией существующего.
    std::vector<double> wd = vd;
    pr (wd, "Copy");

    // Создайте вектор, который копирует часть существующей последовательности
    std::vector<double> ud(wd.begin() + 1, wd.begin() + 3);
    pr (ud, "Copy part");

    // Создайте вектор вещественных, который является копией части обычного массива.
    double ar[] = { 0., 1., 2., 3., 4., 5. };

    std::vector<double> va(ar + 1, ar + 4);
    pr (va, "Copy part of array");

    // Создайте вектор символов, который является копией части обычной строки
    char s[] = "Array is a succession of chars";

    std::vector<char> vc(s + 4, s + 16);
    pr (vc, "Copy part of c-style string");

    // Создайте вектор элементов типа Vector и инициализируйте
    // его вектором с координатами (1,1).
    std::vector<Vector> vv{Vector(1, 1)};

    cout << "\n\nvector of Vectors\n";
    for (int i=0;  i < vv.size();  i++)
        vv[i].Out();

    // Создайте вектор указателей на Vector и инициализируйте его адресами
    // объектов класса Vector

    Vector v1(1, 2);
    Vector v2(3, 4);
    Vector v3(5, 6);

    std::vector<Vector*> vp{&v1, &v2, &v3};

    cout << "\n\nvector of pointers to Vector\n";

    for (int i=0;  i < vp.size();  i++)
        vp[i]->Out();

    // Научитесь пользоваться методом assign и операцией
    // присваивания = для контейнеров типа vector.
    vp.assign(2, &v2);

    cout << "\n\nAfter assign\n";
    for (int i=0;  i < vp.size();  i++)
        vp[i]->Out();

    // Декларируйте новый вектор указателей на Vector и инициализируйте его
    // с помощью второй версии assign
    std::vector<Vector*> vpNew;
    vpNew.assign(&vp[0], &vp[1]);

    cout << "\n\nNew vector after assign\n";
    for (int i=0;  i < vpNew.size();  i++)
        vpNew[i]->Out();


    // На базе шаблона vector создание двухмерный массив и
    // заполните его значениями разными способами.
    // Первый вариант - прямоугольная матрица
    // Второй вариант - ступенчатая матрица

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

    //========= Ступенчатая матрица
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
    // Простейшие действия с контейнерами
    //===================================
    //3б. Получение значения первого и последнего элементов последовательности.
    //Получение размера последовательности. Присваивание значений
    //элементов одной последовательности элементам другой - assign().

    //Создайте и проинициализируйте вектор из элементов char. Размер -
    //по желанию.
    std::vector<char> vchar {'a', 'b', 'c', 'd'};

    //Создайте и проинициализируйте массив из элементов char. Размер -
    //по желанию.
    char cMas[] {'1', '2', '3', '4', '5'};

    //Получите значение первого элемента вектора ( front() )
    std::cout << "front element of vector " << vchar.front() << '\n';

    //Получите значение последнего элемента вектора ( back() )
    std::cout << "last element of vector " << vchar.back() << '\n';

    //Получите размер вектора
    std::cout << "size of vector " << vchar.size() << '\n';

    //Присвойте вектору любой диапазон из значений массива cMas.
    vchar.assign(cMas + 1, cMas + 4);

    //Проверьте размер вектора, первый и последний элементы.
    std::cout << "after: front element of vector " << vchar.front() << '\n';
    std::cout << "after: last element of vector " << vchar.back() << '\n';
    std::cout << "after: size of vector " << vchar.size() << '\n';


    //3в. Доступ к произвольным элементам вектора с проверкой - at()
    //и без проверки - []
    //Создайте неинициализированный вектор из 8 элементов char - vChar2.
    //С помощью at() присвойте четным элементам вектора значения
    //элементов vChar1 из предыдущего задания,
    //а с помощью [] присвойте нечетным элементам вектора vChar2 значения
    //массива {'K','U','K','U'}.
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


    //Попробуйте "выйти" за границы вектора с помощью at() и
    //с помощью []. Обратите внимание: что происходит при
    //попытке обращения к несуществующему элементу в обоих случаях
    try {
        std::cout << vChar2.at(vChar2.size());
    }
    catch (std::exception){}
//    std::cout << vChar2[vChar2.size() + 1000];
    

    //3г.Добавьте в конец вектора vChar2  - букву Z (push_back()). Для
    //расширения кругозора можете ее сразу же и выкинуть (pop_back())
    vChar2.push_back('Z');
    vChar2.pop_back();
    

    //3д. Вставка-удаление элемента последовательности insert() - erase()
    //Очистка последовательности - clear()



    //Вставьте перед каждым элементом вектора vChar2 букву 'W'
    for (int i = 0; i < vChar2.size(); i++) {
        vChar2.insert(vChar2.begin() + i, 'W');
        i++;
    }
    for (int i = 0; i < vChar2.size(); i++)
        std::cout << vChar2[i] << ' ';
    std::cout << '\n';
    //Вставьте перед 5-ым элементом вектора vChar2 3 буквы 'X'
    vChar2.insert(vChar2.begin() + 4, 3, 'X');
    for (int i = 0; i < vChar2.size(); i++)
        std::cout << vChar2[i] << ' ';
    std::cout << '\n';

    //Вставьте перед 2-ым элементом вектора vChar2 с третьего по
    //шестой элементы массива "aaabbbccc"
    char carr[] = "aaabbbccc";
    vChar2.insert(vChar2.begin() + 1, carr + 2, carr + 6);
    for (int i = 0; i < vChar2.size(); i++)
        std::cout << vChar2[i] << ' ';
    std::cout << '\n';

    //Сотрите c первого по десятый элементы vChar2
    vChar2.erase(vChar2.begin(), vChar2.begin() + 10);
    for (int i = 0; i < vChar2.size(); i++)
        std::cout << vChar2[i] << ' ';
    std::cout << '\n';
    

    //Уничтожьте все элементы последовательности - clear()
    vChar2.clear();
    

    //Создание двухмерного массива
//10X5 2
    vector<vector<int>> vvv(10, vector<int>(5, 2));

///////////////////////////////////////////////////////////////////
	//Задание 4. Списки. Операции, характерные для списков.
	//Создайте два пустых списка из элементов Vector - ptList1 и
	//ptList2
	std::list<Vector> ptList1, ptList2;

	//Наполните оба списка значениями с помощью методов push_back(),
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

    //Отсортируйте списки - sort().
	//Подсказка: для того, чтобы работала сортировка, в классе Vector
	//должен быть переопределен оператор "<"
    ptList1.sort();
    ptList2.sort();

    pr(ptList1, "sorted ptList1");
    std::cout << '\n';
    pr(ptList2, "sorted ptList2");
    std::cout << '\n';

	//Объедините отсортированные списки - merge(). Посмотрите: что
	//при этом происходит со вторым списком.

    ptList1.merge(ptList2);
    pr(ptList1, "merged ptList1");
    std::cout << '\n';
    pr(ptList2, "merged ptList2");
    std::cout << '\n';

	//Исключение элемента из списка - remove()
	//Исключите из списка элемент с определенным значением.
	//Подсказка: для этого необходимо также переопределить
	//в классе Vector оператор "=="
    ptList1.remove(v1);

	
///////////////////////////////////////////////////////////////////
	//Задание 5. Стандартные алгоритмы.Подключите заголовочный файл
	// <algorithm>
	//5а. Выведите на экран элементы ptList1 из предыдущего
	//задания с помощью алгоритма for_each()
    std::for_each(ptList1.begin(), ptList1.end(), [](Vector v) { std::cout << v << ' '; });
	

	//5б.С помощью алгоритма find() найдите итератор на элемент Vector с
	//определенным значением. С помощью алгоритма find_if() найдите
	//итератор на элемент, удовлетворяющий определенному условию, 
	//например, обе координаты точки должны быть больше 2.
	//Подсказка: напишите функцию-предикат, которая проверяет условие
	//и возвращает boolean-значение (предикат может быть как глобальной
	//функцией, так и методом класса)
    std::cout << *std::find(ptList1.begin(), ptList1.end(), v1) << '\n';
    std::cout << *std::find_if(ptList1.begin(), ptList1.end(), pred) << '\n';

	  

	//Создайте список из указателей на элеметы Vector. С помощью 
	//алгоритма find_if() и предиката (можно использовать предикат - 
	//метод класса Vector, определенный в предыдущем задании) найдите в
	//последовательности элемент, удовлетворяющий условию
    std::list<Vector *> ptList3;
    ptList3.push_back(&v1);
    ptList3.push_back(&v2);
    ptList3.push_back(&v3);
    std::cout << *std::find_if(ptList3.begin(), ptList3.end(), predpt) << '\n';

	//5в. Создайте список элементов Vector. Наполните список
	//значениями. С помощью алгоритма replace() замените элемент
	//с определенным значением новым значением. С помощью алгоритма
	//replace_if() замените элемент, удовлетворяющий какому-либо
	//условию на определенное значение. Подсказка: условие
	//задается предикатом.
    std::replace(ptList3.begin(), ptList3.end(), &v1, &v2);

  //Сформировали значения элементов списка
    std::replace_if(ptList3.begin(), ptList3.end(), predpt, &v2);
  
	


	//5г. Создайте вектор строк (string). С помощью алгоритма count()
	//сосчитайте количество одинаковых строк. С помощью алгоритма
	//count_if() сосчитайте количество строк, начинающихся с заданной
	//буквы
    std::vector<std::string> strVec {"abc", "def", "ghi", "abc", "abc"};
    std::cout << std::count(strVec.begin(), strVec.end(), "abc") << '\n';
    std::cout << std::count_if(strVec.begin(), strVec.end(), PredStr('d')) << '\n';

	//5д. С помощью алгоритма count_if() сосчитайте количество строк,
	//которые совпадают с заданной строкой. Подсказка: смотри тему
	//объекты-функции
    std::cout << std::count_if(strVec.begin(), strVec.end(), PredStr2("abc")) << '\n';



    cout <<"\n\n";
}