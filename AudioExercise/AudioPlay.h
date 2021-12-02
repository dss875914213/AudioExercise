#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
extern "C"
{
#include <SDL/SDL.h>
}

/*
1. ��ʼ��
	1.1 ��ʼ�� SDL
	1.2 ����Ƶ�豸
2. ѭ����������
	2.1 ������Ƶ����
	2.2 ��ʱ�ȴ��������
*/
#define BUFFER_SIZE 4096
class AudioPlay
{
public:
	AudioPlay(string path);
	~AudioPlay();
	void Initialize();
	void Play();
private:
	string m_path;
	ifstream* m_stream;
	int m_size;
	uint8_t* m_data;
};

