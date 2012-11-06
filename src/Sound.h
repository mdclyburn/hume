#ifndef SOUND_H
#define SOUND_H

#include <SDL/SDL_mixer.h>
#include <string>

class Sound
{
public:
	Sound();
	Sound(std::string filename);
	~Sound();

	openFile(std::string filename); // Opens a specified audio file.
	closeFile(); // Closes an opened audio file.
protected:
}

#endif