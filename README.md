[![Build Status](https://travis-ci.com/Oreo639/LimePlayer3DS.svg?branch=master)](https://travis-ci.com/Oreo639/LimePlayer3DS)
# Limeplayer 3DS
Limeplayer 3ds is a graphical music player for the 3ds that supports midi, mp3, flac, wav and vorbis (in no particular order) and has metadata parsing.

It checks for music in the `music` folder. If it doesn't exist then it just goes to `sdmc:/`, just like ctrmus. 

The default path for midi patchsets is `/3ds/limeplayer3ds/dgguspat`. The config file can be found in `/3ds/limeplayer3ds/confg.json` This should be automaticly be created (it specifies which patchset to use by default). You can change it with the X button. (or the second option of the "settings menu")

(Improved GUI, TBD. Loading cover pictures. All of the menus (although every one except setting's and copyright's use is TBD).)

Keep in mind that this repo will be updated with the source and liscenses when they are ready, which may be in a few days or longer.


## Note
Limeplayer3ds is currently undergoing a c++ rewrite (instead of just being in c). Alot of its functionality is not going to be avliable right now.

## Officaly Supported Formats
Mp3, Wav, Flac, Midi, Xmi, Mus, Hmi, Hmp, Ogg, and Opus.

## Issues
Make sure that your issue is descriptive and consise. Also please include the crash dump if applicable.

## Building
### Prerequsites:
dkp-pacman, 3ds-dev, 3ds-mpg123, 3ds-libvorbisidec, 3ds-opusfile, 3ds-jansson, and 3ds-wildmidi (if wildmidi isn't avliable just run buildlibs.sh). You will also need [makerom](https://github.com/profi200/Project_CTR) and [bannertool](https://github.com/Steveice10/bannertool/) for cia building (optional).

### Compiling:
You should be able to build it by just runing make. (after installing all the prerequsites)

### Targets: 
+ 3dsx (3dsx only build).
+ cia (generate cia, 3dsx must be built)
+ clean (clean compiled files)

If you want to build with compiler optimazitions, just add RELEASE=1 to the end (EX: `make 3dsx RELEASE=1`)

## Developers
These are the contrubuters and maintainers, both big and small (will be updated every once and a while)
+ Maintainers: Oreo639, TBD
+ Contributers: liquidfenrir (fixed the makefile)
+ Check the credits for those who made a big impact on development.

## Credits
+ Limeplayer started as a fork of ctrmus, meaning that the majority of its code came from, is based off, or was built on top of ctrmus.

+ Deltabeard: For his work on ctrmus which was the foundation for this application.

+ Astronautlevel & Liquidfernir (and the anemone team): For their work on anemone which helped quite a bit when it came to starting with citro2d graphics, and they were very helpful in general.

+ Liquidferinir: Their config parser from multiupdater was revamped and built on top of.

+ Smealum, WinterMute, Fincs, and the Devkitpro team: For making/maintaining documentation and libraries for libctru and citro2d/3d which were very helpfull when making this project.

+ The Easyrpg Team: For inspiring this application with their work porting wildmidi to the 3ds and the switch (the reason I started working on this was because I wondered if there was a midi player for the 3ds).

+ Others: If I forgot to mention someone important (as in their code is used without credit), please let me know.

+ Most of the icons under gfx are from the site [icons8.com](https://icons8.com) and are licensed under the [CC-BY-NC-SA](https://creativecommons.org/licenses/by-nc-sa/3.0/)

## Copyright
The exact license varies between MIT and GPLv2-or-later depending on what file it is. Please look at the top of the file to see which.
The application is licensed under GPLv2-or-later.

## Special Thanks
Nintendo Homebrew: A nice discord that is always giving help with homebrew and development.

Family: For providing somewhat helpfull feedback, and testing pre-release versions.
