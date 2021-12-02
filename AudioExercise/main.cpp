#include <iostream>
#include "AudioPlay.h"
extern "C"
{
#include <SDL/SDL.h>
}
using namespace std;


// main 函数必须写成这个样子，不然会报错
int main(int argc, char* argv[])
{
	AudioPlay* audio = new AudioPlay("../Resource/Audio44.1k_s16le.pcm");
	audio->Initialize();
	audio->Play();
	return 0;
}





