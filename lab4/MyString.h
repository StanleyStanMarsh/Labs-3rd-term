class MyString
{
private:
	char* m_pStr;		// Элемент данных класса (адрес строки)
public:
    MyString ();
	MyString (char* s);	// Объявление конструктора
    ~MyString();		// Объявление деструктора
    MyString(const MyString&);

	void Copy (char* s);
	char* GetString();	// Объявление метода (accessor)
	int GetLength();	// Объявление метода (длина строки)

    MyString& operator = (const MyString &other);
    friend std::ostream& operator<<(std::ostream &out, const MyString &s);
};
