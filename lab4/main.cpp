// Контейнеры STL: 
//deque, stack, queue, priority_queue
//set, multiset, map, multimap
//Итераторы. Стандартные алгоритмы. Предикаты.

#include "misc.h"

int main()
{
    setlocale(LC_ALL, "Rus");
	//Очередь с двумя концами - контейнер deque

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать

    std::deque<Point> Pdq;
    std::vector<Point> Pv {Point(1, 2), Point(3, 4), Point(5, 6)};
    Pdq.assign(Pv.begin(), Pv.end());

    pr(Pdq, "Deque of Points");

	//Создайте deque с элементами типа MyString. Заполните его значениями
	//с помощью push_back(), push_front(), insert()
	//С помощью erase удалите из deque все элементы, в которых строчки
	//начинаются с 'A' или 'a'

    std::deque<MyString> MSdq;

    MSdq.push_back("last");
    MSdq.push_front("first");
    MSdq.insert(MSdq.begin() + 1, "Around");
    pr(MSdq, "Deque before erasing of MyStrings");

    erase_if(MSdq, pred);
    pr(MSdq, "Deque after erasing of MyStrings");

	////////////////////////////////////////////////////////////////////////////////////


	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//Подумайте, как "получать" данное "с верхушки"?
	//Что происходит с контейнерами после вывода значений?

    std::stack<Point> st;
    st.push(Point(1, 2));
    st.push(Point(2, 3));
    st.push(Point(4, 5));
    pr2(st, "Stack of Points");
    std::cout << st.size();

    std::priority_queue<Point> pq;
    pq.push(Point(2, 3));
    pq.push(Point(1, 2));
    pq.push(Point(4, 5));
    pr2(pq, "Priority Queue of Points");

    std::queue<Point> pq3;
    pq3.push(Point(2, 3));
    pq3.push(Point(1, 2));
    pq3.push(Point(4, 5));
    pr2(pq3, "Queue of Points"); //FIXME
	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 
    pr(Pv, "Vector");
    std::reverse(Pv.begin(), Pv.end());
    std::stack<Point, std::vector<Point>> Vst(Pv);
    pr2(Vst, "Stack");

	//Сравнение и копирование стеков
	//а) создайте стек и любым способом задайте значения элементов
	//б) создайте новый стек таким образом, чтобы он стал копией первого
	//в) сравните стеки на равенство
	//г) модифицируйте любой из стеком любым образом (push, pop, top)
	//д) проверьте, какой из стеков больше (подумайте, какой смысл вкладывается в такое сравнение)
	{
	    std::stack<Point, std::vector<Point>> Vst2(Pv);
        std::stack<Point, std::vector<Point>> Vst3 = Vst2;
        std::cout << ((Vst2 == Vst3) ? "equal\n" : "not equal\n"); // равны
        Vst3.push(Point(0, 0));
        std::cout << ((Vst2 < Vst3) ? "Vst3 bigger\n" : "Vst2 bigger\n"); // равны
	}


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
	{
        Point a(1, 2), b(3, 4);
        std::queue<Point*, std::vector<Point*>> Pq(std::vector(2, &a));
        Pq.front() = &a;
        Pq.back() = &b;
	}
	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?


	{
	    const char* cAr[3] {"jkl", "abcde", "fghi"};
        std::priority_queue<const char*, std::vector<const char*>, compareStr> PQ(cAr, cAr + 3);//FIXME
        pr2(PQ, "priority_queue");
	}
	
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)

    std::set<Point> Pset(Pv.begin(), Pv.end());
    pr(Pset, "Set");

    int iar[5]{1, 2, 1, 4, 5};
    int iar2[3]{5, 6, 7};
    std::set<int> iset1(iar, iar + 5);
    std::set<int, std::less<int>> iset2(iar, iar + 5);
    iset1.insert(iar2, iar2 + 3);
    pr(iset1, "iset1");
    pr(iset2, "iset2");

	////////////////////////////////////////////////////////////////////////////////////
	//multiset




	////////////////////////////////////////////////////////////////////////////////////
	//map	
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

    std::map<const char*, int> salary;
    salary.insert(std::pair<const char*, int>("Ivanov", 100));
    salary["Petrov"] = 200;
    salary.insert(std::pair<const char*, int>("Sidorov", 300));

    std::map<const char*, int>::iterator it = salary.begin();
    while(it != salary.end())
    {
        std::cout<<(*it).first<< ":" <<(*it).second<< '\n';
        it++;
    }

	//е) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")
    std::cout << "________________\n";
    int k = salary.find("Petrov")->second;
    salary.erase("Petrov");
    salary["Vodolazov"] = k;

    it = salary.begin();
    while(it != salary.end())
    {
        std::cout<<(*it).first<< ":" <<(*it).second<< '\n';
        it++;
    }

	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()
    std::multimap<std::string, std::string> mm;
    std::pair<std::string, std::string> prr[4]{std::make_pair(std::string("strange"), std::string("чужой")),
                                               std::make_pair(std::string("strange"), std::string("странный")),
                                               std::make_pair(std::string("left"), std::string("левый")),
                                               std::make_pair(std::string("left"), std::string("выйти"))};
    mm.insert(prr, prr + 4);
    std::multimap<std::string, std::string>::iterator it2 = mm.begin();
    while(it2 != mm.end()){
        std::cout << (*it2).first<< ":" << (*it2).second<< '\n';
        it2++;
    }
    std::cout << "________________\n";
    for(auto i = mm.lower_bound(std::string("left")); i != mm.upper_bound(std::string("left")); i++)
        std::cout << (*i).first<< ":" << (*i).second<< '\n';
///////////////////////////////////////////////////////////////////

	//Итераторы

	//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
	//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
	//являются копиями элементов set, но упорядочены по убыванию
    std::set<Point> pset;
    for(int i = 0; i < 4; i++)
        pset.insert(Point(i, i + 1));
    std::vector<Point> vset(pset.rbegin(), pset.rend());
//    pr(vset, "Vector from set");
	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.
    std::cout << "________________\n";

    std::ostream_iterator<Point> oi(std::cout, " ");
    for (auto a : pset)
        oi = a;
    std::cout << "\n________________\n";
    for (auto a : vset)
        oi = a;
    std::cout << "\n________________\n";

    //Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()
	//front_inserter()
	//inserter()
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.

    std::vector<int> vvv{1, 2, 3, 4};
    std::list<int> lst{12, 34, 56};

    std::back_insert_iterator<std::list<int>> back_iter = std::back_inserter(lst);
    std::front_insert_iterator<std::list<int>> front_iter = std::front_inserter(lst);
    std::insert_iterator<std::vector<int>> iter = std::inserter(vvv, std::find(vvv.begin(),vvv.end(),2));

    *back_iter = 100;
    *iter = 123;

    *front_iter = 78;
//    MSdq.push_front("abc");

///////////////////////////////////////////////////////////////////

	//Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон
    std::for_each(vvv.begin(), vvv.end(), pr3<int>);
	

	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката
    std::for_each(Pv.begin(), Pv.end(), ChangeCoord<Point>(2,10));



	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.
    auto find_it = std::find(Pv.begin(), Pv.end(), Point(2, 10));
    while (find_it != Pv.end()) {
        std::cout << "Found point at (" << *find_it << ")" << std::endl;
        find_it = std::find(find_it + 1, Pv.end(), Point(2, 10));
    }

    Pv.push_back(Point(1, 2));
    Pv.push_back(Point(3, 4));
    Pv.push_back(Point(1000, 200000));

    //С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!
	
    std::sort(Pv.begin(), Pv.end());


	//Создайте глобальную функцию вида: bool Pred1_1(const Point& ), которая будет вызываться
	//алгоритмом find_if(), передавая в качестве параметра очередной элемент последовательности.
	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
	//[-n, +m].
    std::cout << *std::find_if(Pv.begin(), Pv.end(), Pred1_1(100, 100));


	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.
	
    std::vector<Rect> rects {Rect(12, 23, 31, 432), Rect(1213, 3214, 145, 165),
                             Rect(6665, 66, 7, 68), Rect(19, 1210, 101, 12)};

    std::sort(rects.begin(), rects.end(), comp1);
    pr(rects, "sorrted rects");


	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()
        std::string s1 = "AbCdEfGHijkl";
        std::transform(s1.cbegin(), s1.cend(), s1.begin(), ::tolower );
        std::cout << s1 << '\n';
		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр
	    std::list<std::string> lstr{"aBc", "BcD", "CDE", "abc"};
        std::set<std::string> sstr;
        std::transform(lstr.cbegin(), lstr.cend(), std::inserter(sstr, sstr.begin()),
                       toLowerCase);
        std::cout << "\n___________\n";
		std::for_each(sstr.begin(), sstr.end(), pr3<std::string>);
	}
	{// map
		
		//Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
	
        std::vector<std::string> vstr {"abC", "bCD", "cde", "CDe", "bCD", "abC"};
        std::map<std::string, int> mstr;

        std::sort(vstr.begin(), vstr.end());
        std::for_each(vstr.begin(), vstr.end(),
                      [&mstr](const std::string& elem) { mstr[elem]++; });

        std::cout << "\n___________\n";
        for (const auto& elem : mstr) {
            std::cout << elem.first << ": " << elem.second << std::endl;
        }


	}

	


	return 0;
}

