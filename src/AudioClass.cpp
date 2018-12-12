#include "AudioClass.h"

AudioClass::AudioClass()
{
}
AudioClass::~AudioClass()
{
}
void my_audio_callback(void *userdata, Uint8 *stream, int len) {
	if (AudioClass::audio_len == 0)
		return;

	len = (len > AudioClass::audio_len ? AudioClass::audio_len : len);
	SDL_memcpy(stream, AudioClass::audio_pos, len);

	AudioClass::audio_pos += len;
	AudioClass::audio_len -= len;
}

void AudioClass::Init() {
	if (SDL_LoadWAV(audioStream.c_str(), &wav_spec, &wav_buffer, &wav_length) == NULL) {
		std::cout << "File Error" << std::endl;
	}
	// set the callback function
	wav_spec.callback = my_audio_callback;
	wav_spec.userdata = NULL;
	// set our global static variables
	audio_pos = wav_buffer; // copy sound buffer
	audio_len = wav_length; // copy file length

							/* Open the audio device */
	if (SDL_OpenAudio(&wav_spec, NULL) < 0) {
		fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
		exit(-1);
	}

	/* Start playing */
	SDL_PauseAudio(0);

	// wait until we're don't playing
	
}

void AudioClass::Update() {
	while (audio_len > 0) {
		SDL_Delay(1000);
	}
	isDone = true;
}

