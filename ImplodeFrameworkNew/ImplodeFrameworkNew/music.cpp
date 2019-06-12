#include "music.h"
using namespace std;

music::music()
{
}


music::~music()
{
	Mix_Pause(soundChannel);
	Mix_FreeChunk(sound);

	delete sound;
	sound = nullptr;
	soundChannel = NULL;
}

void music::PlayWav(string directory, int channel, int repeat)
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	Mix_Init(0);

	sound = Mix_LoadWAV(directory.c_str());
	Mix_PlayChannel(channel, sound, repeat);

	soundChannel = channel;

	Mix_Quit();
}

void music::StopMusicOverLap(int channelResume, int channelToPauseFor)
{
	if (Mix_Playing(channelResume) == 1)
	{
		Mix_Pause(channelResume);
	}

	if (Mix_Playing(channelToPauseFor) == 0)
	{
		Mix_Resume(channelResume);
	}
}

void music::Pause(int channel)
{
	Mix_Pause(channel);
}

void music::Resume(int channel)
{
	Mix_Resume(channel);
}