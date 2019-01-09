#include <mpg123.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mp3.hpp"

static size_t				buffSize;
static mpg123_handle*			mh;
static uint32_t			rate;
static uint8_t			channels;

static int LibInit = false;

Mp3Decoder::Mp3Decoder(const char* filename) {
	int err = 0;
	int encoding = 0;

	if((err = mpg123_init()) != MPG123_OK)
		return;

	if((mh = mpg123_new(NULL, &err)) == NULL)
	{
		printf("Error: %s\n", mpg123_plain_strerror(err));
		return;
	}

	if(mpg123_open(mh, filename) != MPG123_OK ||
			mpg123_getformat(mh, (long *) &rate, (int *) &channels, &encoding) != MPG123_OK)
	{
		printf("Trouble with mpg123: %s\n", mpg123_strerror(mh));
		return;
	}

	/*
	 * Ensure that this output format will not change (it might, when we allow
	 * it).
	 */
	mpg123_format_none(mh);
	mpg123_format(mh, rate, channels, encoding);

	/*
	 * Buffer could be almost any size here, mpg123_outblock() is just some
	 * recommendation. The size should be a multiple of the PCM frame size.
	 */
	buffSize = mpg123_outblock(mh) * 16;

	
	LibInit = true;
}

Mp3Decoder::~Mp3Decoder(void) {
	mpg123_close(mh);
	mpg123_delete(mh);
	mpg123_exit();
	LibInit = false;
}

bool Mp3Decoder::IsInit(void) {
	return LibInit;
}

void Mp3Decoder::Info(std::string& copyright) {
	mpg123_id3v1* v1;
	mpg123_id3v2* v2;
	mpg123_id3(mh, &v1, &v2);
	
	/*Not going to deal with this bs. For now ofc.*/
	//if (v1->artist) {
	//infoOut->fileMeta->authorCpright = strdup(v1->artist);
	//}
	if (mpg123_strlen(v2->artist, true)) {
	copyright.assign(v2->artist->p, strlen(v2->artist->p));
	}
	else {
	copyright.assign("(No Author-Mp3)", strlen("(No Author-Mp3)"));
	}
}

uint32_t Mp3Decoder::Position(void) {
	return mpg123_tell(mh);
}

uint32_t Mp3Decoder::Length(void) {
	return mpg123_length(mh);
}

void Mp3Decoder::Seek(uint32_t location)
{
	if(location > mpg123_length(mh)) {
		return;
	}
	mpg123_seek(mh, location, SEEK_SET);
}

uint32_t Mp3Decoder::Decode(int16_t* buffer)
{
	size_t done = 0;
	mpg123_read(mh, reinterpret_cast<unsigned char*>(buffer), buffSize, &done);
	return done / (sizeof(int16_t));
}

uint32_t Mp3Decoder::Samplerate(void)
{
	return rate;
}


uint32_t Mp3Decoder::Buffsize(void)
{
	return buffSize;
}

int Mp3Decoder::Channels(void)
{
	return channels;
}
