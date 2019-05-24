#include <stdio.h>

#ifndef LIME_FILE_H
#define LIME_FILE_H

typedef enum
{
	FILE_WAV = 1,     ///< Microsoft WAVE
	FILE_FLAC,        ///< Free Lossless Audio Codec
	FILE_VORBIS,      ///< Ogg Vorbis
	FILE_OPUS,        ///< Ogg Opus
	FILE_MP3,         ///< Mp3
	FILE_MIDI,        ///< Midi and midilike
	FMT_NETWORK,      ///< Network http stream
} FILE_audioformat;

namespace File {
	int GetFileType(const char* file);
}
#endif
