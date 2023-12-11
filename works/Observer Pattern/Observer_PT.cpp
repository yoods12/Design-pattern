#include <iostream>
#include <list>

using namespace std;

class Observer {
public:
	virtual void update() = 0;
};

class DonateViewer : public Observer {
	string Nickname;
	string comment = "답글";

public:
	DonateViewer(const string& name) : Nickname(name){}
	DonateViewer(string name, string com) : Nickname(name), comment(com){};
	void update() {
		cout << Nickname << " 메세지를 받았습니다 : " << comment << endl;
	}
	void writeComment(string com) { comment = com; } // 메세지 작성기능 포함
};

class Subject {
public:

};

class StreamerSystem {
	// 리스트로 후원 구독자에 대한 정보 객체 생성, 느슨한 결합 상태, 데이터의 삽입/삭제의 용이성을 위해 리스트 사용
	list<DonateViewer*> donateViewer; 
public:	
	void notify() {	for (auto idx : donateViewer) { idx->update(); }}
	void removeViewer(DonateViewer* observer)
	{
		for (auto idx = donateViewer.begin(); idx != donateViewer.end(); ++idx) // 구독자 목록 순환
		{
			if (*idx == observer) // 입력한 구독자와 일치하면 실행
			{
				donateViewer.erase(idx);
				break;
			}
		}
	}
	void addViewer(DonateViewer* observer) { donateViewer.push_back(observer); }
};

int main()
{
	StreamerSystem YourSystem;
	DonateViewer Chul("철수", "실환가?");
	DonateViewer Young("영희", "갑작스레 페이커가 대단하다 느껴지네...");
	DonateViewer OldMan("노인", "요즘에는 게임도 뉴스에 나오는구만...");
	DonateViewer Man("젊은남자");

	YourSystem.addViewer(&Chul);
	YourSystem.addViewer(&Young);
	YourSystem.addViewer(&OldMan);
	YourSystem.addViewer(&Man);

	cout << "젊은 남자 구독자 삭제전" << endl;
	cout << endl;

	YourSystem.notify();
	YourSystem.removeViewer(&Man);

	cout << endl;
	cout << "삭제 후 구독자 목록" << endl;
	cout << endl;
	YourSystem.notify();

	cout << endl;
	cout << " 댓글 수정 후 출력" << endl;
	Chul.writeComment("실화인가요?");

	YourSystem.notify();

	return 0;
}