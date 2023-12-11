#include <iostream>

using namespace std;

class Singleton
{
	Singleton() {};
	//생성자를 private으로 선언하여 외부에서 직접 객체를 생성할 수 없음

	static Singleton* instance;
	//Singleton 의 객체를 가리키는 instance
	//static 으로 하여 instance는 하나만 존재 하도록 함

public:
	static Singleton* getInstance()
	{
		if (instance != nullptr)
		{
			return instance; 
			//instance가 생성되어 있으면 반환
		}
		else
		{
			instance = new Singleton();
			return instance; 
			//instance가 없으면 만들고 반환
		}
	}
};

Singleton* Singleton::instance = nullptr;

int main()
{
	// Singleton a;(x) 생성자의 접근지정자가 private임

	Singleton* a = Singleton::getInstance();
	Singleton* b = Singleton::getInstance();
	Singleton* c = Singleton::getInstance();

	cout << "a addr : " << a << endl;
	cout << "b addr : " << b << endl;
	cout << "b addr : " << c << endl;

	return 0;
}
