#pragma once
#include <string>
#include <SDL_mixer.h>

using namespace std;
class music
{
public:
	music();
	~music();

	void PlayWav(string directory, int channel, int repeat);
	void StopMusicOverLap(int channelResume, int channelToPauseFor);
	void Pause(int channel);
	void Resume(int channel);
private:
	Mix_Chunk* sound;
	int soundChannel;
};
