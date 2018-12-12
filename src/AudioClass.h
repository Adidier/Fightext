#pragma once

#include <iostream>
#include <SDL.h>
#include <string>

using std::string;

class AudioClass
{
public:
	AudioClass();
	~AudioClass();

	void Init();
	void Update();

	bool isDone = false;
	static Uint8 *audio_pos; // global pointer to the audio buffer to be played
	static Uint32 audio_len; // remaining length of the sample we have to play

private:

	string audioStream = "./Assets/audio.wav";

	Uint32 wav_length; // length of our sample
	Uint8 *wav_buffer; // buffer containing our audio file
	SDL_AudioSpec wav_spec; // the specs of our piece of music
};

#ifdef AUDIO_DEF
	Uint8 *AudioClass::audio_pos;
	Uint32 AudioClass::audio_len;
#endif
