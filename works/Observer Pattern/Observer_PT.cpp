#include <iostream>
#include <list>

using namespace std;

class Observer {
public:
	virtual void update() = 0;
};

class DonateViewer : public Observer {
	string Nickname;
	string comment = "���";

public:
	DonateViewer(const string& name) : Nickname(name){}
	DonateViewer(string name, string com) : Nickname(name), comment(com){};
	void update() {
		cout << Nickname << " �޼����� �޾ҽ��ϴ� : " << comment << endl;
	}
	void writeComment(string com) { comment = com; } // �޼��� �ۼ���� ����
};

class Subject {
public:

};

class StreamerSystem {
	// ����Ʈ�� �Ŀ� �����ڿ� ���� ���� ��ü ����, ������ ���� ����, �������� ����/������ ���̼��� ���� ����Ʈ ���
	list<DonateViewer*> donateViewer; 
public:	
	void notify() {	for (auto idx : donateViewer) { idx->update(); }}
	void removeViewer(DonateViewer* observer)
	{
		for (auto idx = donateViewer.begin(); idx != donateViewer.end(); ++idx) // ������ ��� ��ȯ
		{
			if (*idx == observer) // �Է��� �����ڿ� ��ġ�ϸ� ����
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
	DonateViewer Chul("ö��", "��ȯ��?");
	DonateViewer Young("����", "���۽��� ����Ŀ�� ����ϴ� ��������...");
	DonateViewer OldMan("����", "���򿡴� ���ӵ� ������ �����±���...");
	DonateViewer Man("��������");

	YourSystem.addViewer(&Chul);
	YourSystem.addViewer(&Young);
	YourSystem.addViewer(&OldMan);
	YourSystem.addViewer(&Man);

	cout << "���� ���� ������ ������" << endl;
	cout << endl;

	YourSystem.notify();
	YourSystem.removeViewer(&Man);

	cout << endl;
	cout << "���� �� ������ ���" << endl;
	cout << endl;
	YourSystem.notify();

	cout << endl;
	cout << " ��� ���� �� ���" << endl;
	Chul.writeComment("��ȭ�ΰ���?");

	YourSystem.notify();

	return 0;
}