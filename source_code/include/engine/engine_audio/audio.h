#ifndef AUDIO_H
#define AUDIO_H

#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

class Audio
{
    Audio()
    {
        PlaySound(TEXT("./project/assets/audio/stonemans_rave.wav"), NULL, SND_FILENAME | SND_ASYNC);
    };
};

#endif