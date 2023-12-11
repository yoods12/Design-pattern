#include <iostream>
#include <list>
using namespace std;

class Observer {
public:
    virtual void update() = 0;
};

class Subscriber : Observer {
    string name;
    string comment = "댓글";
public:
    void update() { cout << name << " : " << comment << endl; }
    Subscriber(string n) : name(n) {}
    Subscriber(string n, string c) : name(n), comment(c) {}
    void setComment(string c) { comment = c; }
};

class Youtuber {
    list<Subscriber*> subscribers;
public:
    void addSubscriber(Subscriber* s) { subscribers.push_back(s); }
    void removeSubscriber(Subscriber* s)
    {
        for (auto i = subscribers.begin(); i != subscribers.end(); ++i)
        {
            if (*i == s) {
                subscribers.erase(i);
                break;
            }
        }
    }
    void notify() { for (auto i : subscribers) { i->update(); } }
};

int main()
{
    Youtuber OliverSam;
    Subscriber song("송보현", "와~");
    Subscriber yu("유동수", "?");
    Subscriber kim("김영한", "ㅋㅋ");

    OliverSam.addSubscriber(&song);
    OliverSam.addSubscriber(&yu);
    OliverSam.addSubscriber(&kim);

    OliverSam.notify();

    OliverSam.removeSubscriber(&yu);
    OliverSam.removeSubscriber(&kim);
    song.setComment("보소");

    OliverSam.notify();
}
