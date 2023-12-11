#include<iostream>
using namespace std;


//오디오의 기능을 구현한 클래스
class AudioPlayer {
public:
	void play() { cout << " 재생 중 " << endl; }
	void stop() { cout << " 정지 " << endl; }
	void pause() { cout << " 일시정지 " << endl; }
};

class AudioRecord {
public:
	void record() { cout << " 녹음 시작 " << endl; }
	void pauseRecord() { cout << " 녹음 일시정지 " << endl; }
	void stopRecord() { cout << " 녹음 정지 " << endl; }
	void save() { cout << " 저장 " << endl; }
};


//오디오의 기능을 모아놓은 클래스
class AudioFacade {
	AudioPlayer Player;
	AudioRecord Record;
public:
	void playAudio() { Player.play(); }
	void stopAudio() { Player.stop(); }
	void pauseAudio() { Player.pause(); }
	void stopAndSave() { Record.stopRecord(); Record.save(); }
};


int main() 
{
	AudioFacade audioSystem;

	//기능을 사용하는 모습
	audioSystem.pauseAudio();
	audioSystem.playAudio();
	audioSystem.stopAudio();
	cout << endl;
	audioSystem.stopAndSave();

	return 0;
	
}
