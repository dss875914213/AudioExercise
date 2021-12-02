#include "AudioPlay.h"
#include <iostream>

uint8_t* myData;
int mySize;

void SDLCALL MyCallback(void* userdata, Uint8* stream, int len)
{
	SDL_memset(stream, 0, len);
	if (mySize == 0)
		return;
	len = len > mySize ? mySize : len;
	SDL_MixAudio(stream, myData, len, SDL_MIX_MAXVOLUME);
	myData += len;
	mySize -= len;
}


AudioPlay::AudioPlay(string path) :
	m_path(path),
	m_stream(NULL),
	m_data(NULL),
	m_size(0)
{
	m_stream = new ifstream();
	m_data = new uint8_t[BUFFER_SIZE];
}

AudioPlay::~AudioPlay()
{
	m_stream->close();
	delete m_stream;
	delete[] m_data;
}

void AudioPlay::Initialize()
{
	SDL_Init(SDL_INIT_AUDIO|SDL_INIT_TIMER);
	SDL_AudioSpec wanted_spec;
	wanted_spec.freq = 44100;
	wanted_spec.format = AUDIO_S16SYS;
	wanted_spec.channels = 2;
	wanted_spec.silence = 0;
	wanted_spec.samples = 1024;
	wanted_spec.callback = MyCallback;
	if (SDL_OpenAudio(&wanted_spec, NULL) < 0)
	{
		cout << "Failed to OpenAudio" << endl;
	}
	m_stream->open(m_path.c_str(), ios::in|ios::binary);

}

void AudioPlay::Play()
{
	int data_count = 0;
	SDL_PauseAudio(0);
	while (1)
	{
		m_stream->read((char*)m_data, BUFFER_SIZE);
		std::streamsize size = m_stream->gcount();
		if(size <BUFFER_SIZE)
		{
			m_stream->clear();
			m_stream->seekg(0);
			m_stream->read((char*)m_data, BUFFER_SIZE);
			std::streamsize size = m_stream->gcount();
			data_count = 0;
		}
		cout << "data_size: " << data_count<<endl;
		data_count += BUFFER_SIZE;
		myData = m_data;
		mySize = BUFFER_SIZE;
		while (mySize > 0)
			SDL_Delay(1);
	}
	SDL_Quit();
}

