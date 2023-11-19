#include <iostream>
using namespace std;

class test { // 만들어질 클래스의 형태
    // 각각 int, string, float 자료형의 변수를 하나씩 가지고 있음
    int varI;
    string varS;
    float varF;
public:
    // builder 클래스에서 build함수로 반환될때 test 클래스를 생성해서 반환하기때문에
    // 생성자를 미리 지정해줘야함
    test(int vI, string vS, float vF) { 
        varI = vI;
        varS = vS;
        varF = vF;
    }
    void show() {// 해당 클래스가 가지는 원소들
        cout << "int_var : " << varI << endl;
        cout << "string_var : " << varS << endl;
        cout << "float_var : " << varF << endl;
    }
    class builder { // test클래스 객체를 생성하기 위한 builder클래스
        //생성할 클래스와 같은 자료형의 변수들을 가지고 있어야한다
        //그래야 해당 값을 그대로 넘겨줄 수 있다.
        int varI;
        string varS;
        float varF;
    public:
        builder& int_var(int v) { // int형 자료에 값을 넣는 set함수이다.
            varI = v;
            return *this; // 여기서 자기자신을 호출해서 해당 클래스의 다른 함수로 이어갈 수 있다.
        }
        builder& string_var(string v) {// string형 자료에 값을 넣는 set함수이다.
            varS = v;
            return *this;
        }
        builder& float_var(float v) {// float형 자료에 값을 넣는 set함수이다.
            varF = v;
            return *this;
        }
        test build() { // 위 함수들로 기입한 데이터를 통해 test클래스를 만들고 그를 반환한다
            test t(varI, varS, varF);
            return t;
        }
    };
};

int main()
{
    test::builder build; // 미리 builder 클래스의 build를 만든다 클래스 변수의 선언과 동시에 함수의 호출은 불가능하기 때문
    test t = build// 원래는 test t = build.int_var(10).string_var("abc") .float_var(10.5).build(); 이런 식이나 가독성을 위해 들여쓰기를 했다
        .int_var(10) 
        .string_var("abc") 
        .float_var(10.5)
        .build();

    t.show(); // t에 저장이 되었는지 확인하기 위한 함수 출력
}
