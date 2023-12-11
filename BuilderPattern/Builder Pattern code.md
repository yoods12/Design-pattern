```
#include <iostream>
using namespace std;

class Monster { // 만들어질 객체
    // 완성품이 가지는 속성들
    int hp;
    int mp;
    int level;
    int dropExp;
    string name;
public:
    //객체 속성에 값을 변경하는 함수들
    void setHp(int h) { hp = h; }
    void setMp(int m) { mp = m; }
    void setLevel(int l) { level = l; }
    void setDropExp(int e) { dropExp = e; }
    void setName(string n) { name = n; }

    void show() { // 만들어진 객체의 값들을 출력하는 함수
        cout << "name : " << name << endl;
        cout << "hp : " << hp << endl;
        cout << "mp : " << mp << endl;
        cout << "level : " << level << endl;
        cout << "dropExp : " << dropExp << endl;
        cout << endl;
    }
};

class MonsterBuilder { // 객체를 생성하는데 사용되는 추상인터페이스
public:
    //순수가상함수만 존재한다
    virtual void setHp() = 0;
    virtual void setMp() = 0;
    virtual void setLevel() = 0;
    virtual void setDropExp() = 0;
    virtual void setName() = 0;
    virtual Monster getMonster() = 0;
};

class Warrior : public MonsterBuilder { // 워리어 객체를 만드는 곳 객체의 값들을 정하고 반환함
    Monster monster;
public:
    void setHp() { monster.setHp(1000); }
    void setMp() { monster.setMp(300); }
    void setLevel() { monster.setLevel(35); }
    void setDropExp() { monster.setDropExp(5800); }
   void setName() { monster.setName("WarriorMonster"); }
   Monster getMonster() { return monster; }
};

class Archer : public MonsterBuilder { // 아처 객체를 만드는 곳 객체의 값들을 정하고 반환함
    Monster monster;
public:
    void setHp() { monster.setHp(750); }
    void setMp() { monster.setMp(350); }
    void setLevel() { monster.setLevel(33); }
    void setDropExp() { monster.setDropExp(5200); }
    void setName() { monster.setName("ArcherMonster"); }
    Monster getMonster() { return monster; }
};

class MonsterDirector { // 객체의 생성 순서를 담당하는 곳
public:
    Monster makeMonster(MonsterBuilder* MB) { // 다형성이 사용됨 MonsterBuilder의 포인터 형이여도 상속받은 Warrior나 Archer을 넣어 받을 수 있음
        MB->setHp();
        MB->setMp();
        MB->setLevel();
        MB->setDropExp();
        MB->setName();
        return MB->getMonster();
    }
};

int main()
{
    MonsterDirector monsterDirector;// 객체 순서를 담당하는 객체 생성
    Warrior warrior; // 워리어 객체의 구현을 담당하는 객체
    Archer archer; // 아처 객체의 구현을 담당하는 객체

    Monster warriorMonster = monsterDirector.makeMonster(&warrior); // Director를 통해 객체가 생성되어 반환됨
    Monster archerMonster = monsterDirector.makeMonster(&archer);

    warriorMonster.show();
    archerMonster.show();
}
```
