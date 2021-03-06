#ifndef MUSIC_H
#define MUSIC_H

//http://smealum.github.io/ctrulib/audio_2mic_2source_2main_8c-example.html

#include <3ds.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <libxmp-lite/xmp.h>
#include "myfs.h"

#define MUSIC_CHANNEL 0x8
#define MUSIC_SAMPLE_RATE 44100
#define MUSIC_BYTES_PER_SAMPLE 4 //16 bit samples * stereo
#define MUSIC_BUF_LENGTH_SAMPLES (MUSIC_SAMPLE_RATE / 20) //sampling "runs" at 20fps. one channel
#define MUSIC_BUF_LENGTH_BYTES (MUSIC_BUF_LENGTH_SAMPLES * MUSIC_BYTES_PER_SAMPLE) //one channel

char* moduleBuffer; //mod file buffer
xmp_context musicCtx; //handle to module player
u32* audioBuffer; //raw 32bit audio buffer
ndspWaveBuf waveBuf[2]; //dsp audio buffer for stereo channels

Result musicinit();

void loadNewSamplesIntoSoundBuf(u32* audioBuffer);

void musicTick();

void musicFree();

#endif /*MUSIC_H*/