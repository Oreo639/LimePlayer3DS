#ifndef __LIME_SETTINGS_H__
#define __LIME_SETTINGS_H__
#include <vector>

typedef struct
{
	std::string		 name;
	std::vector<std::string> filepath;
} playlist_t;

typedef std::vector<playlist_t> playvec;

typedef struct
{
	std::string		wildMidiConfig;
	uint32_t		theme;
	int			language;
	playvec			playlist;
} settings_t;

#endif
