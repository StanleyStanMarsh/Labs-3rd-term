// ���������� STL: 
//deque, stack, queue, priority_queue
//set, multiset, map, multimap
//���������. ����������� ���������. ���������.

#include "misc.h"

int main()
{
    setlocale(LC_ALL, "Rus");
	//������� � ����� ������� - ��������� deque

	//�������� ������ deque � ���������� ���� Point. � �������
	//assign ��������� deque ������� ��������� �������. � �������
	//�������������� ���� � ���������� ������� �������������� �������
	//�������� �������� ��������� �� ������

    std::deque<Point> Pdq;
    std::vector<Point> Pv {Point(1, 2), Point(3, 4), Point(5, 6)};
    Pdq.assign(Pv.begin(), Pv.end());

    pr(Pdq, "Deque of Points");

	//�������� deque � ���������� ���� MyString. ��������� ��� ����������
	//� ������� push_back(), push_front(), insert()
	//� ������� erase ������� �� deque ��� ��������, � ������� �������
	//���������� � 'A' ��� 'a'

    std::deque<MyString> MSdq;

    MSdq.push_back("last");
    MSdq.push_front("first");
    MSdq.insert(MSdq.begin() + 1, "Around");
    pr(MSdq, "Deque before erasing of MyStrings");

    erase_if(MSdq, pred);
    pr(MSdq, "Deque after erasing of MyStrings");

	////////////////////////////////////////////////////////////////////////////////////


	//�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
	//���������, ��� "��������" ������ "� ��������"?
	//��� ���������� � ������������ ����� ������ ��������?

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

	//�������� ���� ����� �������, �����
	//�) �������� ����� ����� ������� ��������� �������
	//�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 
    pr(Pv, "Vector");
    std::reverse(Pv.begin(), Pv.end());
    std::stack<Point, std::vector<Point>> Vst(Pv);
    pr2(Vst, "Stack");

	//��������� � ����������� ������
	//�) �������� ���� � ����� �������� ������� �������� ���������
	//�) �������� ����� ���� ����� �������, ����� �� ���� ������ �������
	//�) �������� ����� �� ���������
	//�) ������������� ����� �� ������ ����� ������� (push, pop, top)
	//�) ���������, ����� �� ������ ������ (���������, ����� ����� ������������ � ����� ���������)
	{
	    std::stack<Point, std::vector<Point>> Vst2(Pv);
        std::stack<Point, std::vector<Point>> Vst3 = Vst2;
        std::cout << ((Vst2 == Vst3) ? "equal\n" : "not equal\n"); // �����
        Vst3.push(Point(0, 0));
        std::cout << ((Vst2 < Vst3) ? "Vst3 bigger\n" : "Vst2 bigger\n"); // �����
	}


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//�������� �������, ������� �������� ��������� �� ������� ���� Point,
	//��� ���� ���� ������� ������� ���������.
	//�������� �������� ������� � ���������� ��������� ����������� front() � back()
	//���������, ��� ��������� ������� ��� ����������� ����� �������?
	{
        Point a(1, 2), b(3, 4);
        std::queue<Point*, std::vector<Point*>> Pq(std::vector(2, &a));
        Pq.front() = &a;
        Pq.back() = &b;
	}
	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
	//�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
	//�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
	//		��� ������������ ��� �������?


	{
	    const char* cAr[3] {"jkl", "abcde", "fghi"};
        std::priority_queue<const char*, std::vector<const char*>, compareStr> PQ(cAr, cAr + 3);//FIXME
        pr2(PQ, "priority_queue");
	}
	
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
	//		� ������ Point (� ����� �������)
	//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������
	//�) ���������� �������� ����� ��������...
	//�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
	//		���� int, �� ���������� � ������ �������
	//�) �������� � ����� ��������� �������� ��������� �� ������ �������
	//	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?)

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
	//�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
	//	��� ���� ������ �������� ���������� ����������
	//�) ��������� ��������� ���������� ����������� operator[] � insert()
	//�) ������������ ����������

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

	//�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")
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
	//�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
	//		��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
	//�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
	//		���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
	//�) �������� ��� ���������� ������� �� �����
	//�) �������� �� ����� ������ �������� "���������" ��� ��������� �����. ���������: ��� ���������� ���������
	//		���������� ����� ������������ ������ lower_bound() � upper_bound()
    std::multimap<std::string, std::string> mm;
    std::pair<std::string, std::string> prr[4]{std::make_pair(std::string("strange"), std::string("�����")),
                                               std::make_pair(std::string("strange"), std::string("��������")),
                                               std::make_pair(std::string("left"), std::string("�����")),
                                               std::make_pair(std::string("left"), std::string("�����"))};
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

	//���������

	//����������� ���������. ����������� set<Point>. ���������, ���
	//����� ����������� � ������ Point. �������� ������, �������� �������� 
	//�������� ������� ��������� set, �� ����������� �� ��������
    std::set<Point> pset;
    for(int i = 0; i < 4; i++)
        pset.insert(Point(i, i + 1));
    std::vector<Point> vset(pset.rbegin(), pset.rend());
//    pr(vset, "Vector from set");
	//��������� ���������. � ������� ostream_iterator �������� ����������
	//vector � set �� ����������� ������� �� �����.
    std::cout << "________________\n";

    std::ostream_iterator<Point> oi(std::cout, " ");
    for (auto a : pset)
        oi = a;
    std::cout << "\n________________\n";
    for (auto a : vset)
        oi = a;
    std::cout << "\n________________\n";

    //��������� �������. � ������� ������������ ���������:
	//back_inserter()
	//front_inserter()
	//inserter()
	//���������� ������� �������� �������� � ����� �� ��������� �����������. ���������:
	//����� �� ���������� ������� ����� ������������ � ������ �����������.

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

	//���������� ��������� (������������ ���� <algorithm>). ���������.

	// �������� for_each() - ����� �������� ������� ��� ������� �������� ����� ������������������
	//(������, vector, list...)
	//� ������� ��������� for_each � ����� ������������������ � ���������� ������ ����
	//������������ �������� ���������
	//��������� : ������� ���������� ������� ���������� ��� ������
    std::for_each(vvv.begin(), vvv.end(), pr3<int>);
	

	//� ������� ��������� for_each � ����� ������������������ � ���������� ���� Point
	//�������� "����������" �� ��������� �������� (����� �������� ���� ����� ����������� 
	//��� ������) � �������� ��������� � ������� ����������� ���������
    std::for_each(Pv.begin(), Pv.end(), ChangeCoord<Point>(2,10));



	//� ������� ��������� find() ������� � ����� ������������������ ��������� Point
	//��� ��������� �� ������� Point � ��������� ���������.
    auto find_it = std::find(Pv.begin(), Pv.end(), Point(2, 10));
    while (find_it != Pv.end()) {
        std::cout << "Found point at (" << *find_it << ")" << std::endl;
        find_it = std::find(find_it + 1, Pv.end(), Point(2, 10));
    }

    Pv.push_back(Point(1, 2));
    Pv.push_back(Point(3, 4));
    Pv.push_back(Point(1000, 200000));

    //� ������� ��������� sort() ������������ ����� ������������������ ��������� Point. 
	////�� ��������� �������� ��������� ������������������ �� �����������.
	//��� ������ ���� ���������� � ������ Point?
	// ���������: ���������� �������� sort �� �������� �� �������, ��� ���
	//��� ���� �� �� ���������� => ��� ������ ���������� ����������� ������� ������!!!
	
    std::sort(Pv.begin(), Pv.end());


	//�������� ���������� ������� ����: bool Pred1_1(const Point& ), ������� ����� ����������
	//���������� find_if(), ��������� � �������� ��������� ��������� ������� ������������������.
	//� ������� ��������� find_if() ������� � ����� ������������������ ��������� Point
	//�������� �� ������� Point, ��������������� �������: ���������� x � y ����� � ����������
	//[-n, +m].
    std::cout << *std::find_if(Pv.begin(), Pv.end(), Pred1_1(100, 100));


	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Rect,
	//���������� �������������� �� �������� ������ �� ������ ���������.
	
    std::vector<Rect> rects {Rect(12, 23, 31, 432), Rect(1213, 3214, 145, 165),
                             Rect(6665, 66, 7, 68), Rect(19, 1210, 101, 12)};

    std::sort(rects.begin(), rects.end(), comp1);
    pr(rects, "sorrted rects");


	{//transform
		//�������� �������, ������� � ������� ��������� transform ��������� 
		//���������� ������� string � ������ �������.
		//���������: ����� string - ��� "�����" ���������, ������� ��� ����
		// ���������� ������ begin() � end()
        std::string s1 = "AbCdEfGHijkl";
        std::transform(s1.cbegin(), s1.cend(), s1.begin(), ::tolower );
        std::cout << s1 << '\n';
		//��������� list ��������� string. � ������� ��������� transform ����������
		//�������� "�������" set, ����������� ������ � ������ �������
	    std::list<std::string> lstr{"aBc", "BcD", "CDE", "abc"};
        std::set<std::string> sstr;
        std::transform(lstr.cbegin(), lstr.cend(), std::inserter(sstr, sstr.begin()),
                       toLowerCase);
        std::cout << "\n___________\n";
		std::for_each(sstr.begin(), sstr.end(), pr3<std::string>);
	}
	{// map
		
		//����������� ����� �������� ������ � ���������� ���� string.
		//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
		//��������� ������������� �� �������� ������ �
		//���������� ���������� ������ ������ � �������
	
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

