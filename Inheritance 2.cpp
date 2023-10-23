#include <iostream>
#include <string>

using namespace std;

class Animal
{
	string name;
public:
	virtual const char* speak()
	{
		return "???";
	}
	virtual void walk() = 0; //상속받는 자식한테 꼭 있어야함
};

class Cat : public Animal
{
public:	
	Cat(string) {};
	const char* speak() 
	{ 
		return "Meow"; 
	}
	virtual void walk() {};
};

class Dog : public Animal
{
public:
	Dog(string) {};
	const char* speak() 
	{ 
		return "Woof"; 
	}
	virtual void walk() {};
};

int main()
{
	Cat c("cat");
	Dog d("dog");

	Animal *a;
	a = &c;
	cout << a->speak() << endl;
	a = &d;
	cout << a->speak() << endl;
}

// 생성자 추가, c를 통해 speak를 호출하는게 아니라  Amimal *a을 통해 고양이 개의 speak를 호출
// name 출력함수 추가, virtual 순수가상함수 에러 뜨면 무슨 에러인지 얘기하기
// 순수가상함수 왜 쓰는지? 
// **다형성에 대해 이해 한 것 더 붙이기**