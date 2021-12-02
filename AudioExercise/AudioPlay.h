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
1. 初始化
	1.1 初始化 SDL
	1.2 打开音频设备
2. 循环播放数据
	2.1 播放音频数据
	2.2 延时等待播放完成
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

