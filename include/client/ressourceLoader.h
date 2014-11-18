#ifndef __RESSOURCELOADER_H
#define __RESSOURCELOADER_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iostream>

#ifdef BUFFER_SIZE
#	define OLD_BUFFER_SIZE BUFFER_SIZE
#	undef BUFFER_SIZE
#endif // BUFFER_SIZE
#define BUFFER_SIZE 1024

namespace lifeAfterEarth3
{
	typedef struct
	{
		std::string name;
		sf::Texture* texture;
	} texture_set;

	typedef struct
	{
		std::string name;
		sf::Sound* sound;
		sf::SoundBuffer* buffer;
	} sound_set;

	typedef struct
	{
		std::string name;
		sf::Music* music;
	} music_set;

	class RessourceLoader
	{
	public:

		/*
			Chargement et lecture des textures par nom ou par id.
		*/
		static void LoadTextures(const char* dataFile);
		static sf::Texture* GetTexture(const std::string& name);
		static sf::Texture* GetTexture(unsigned int index);
		static void ClearTextures(void);

		/*
			Chargement et lecture des sons par nom ou par id.
		*/
		static void LoadSounds(const char* dataFile);
		static sf::Sound* GetSound(const std::string& name);
		static sf::Sound* GetSound(unsigned int index);
		static void ClearSounds(void);

		/*
			Chargement et lecture des musics par nom ou par id.
		*/
		static void LoadMusics(const char* dataFile);
		static sf::Music* GetMusic(const std::string& name);
		static sf::Music* GetMusic(unsigned int index);
		static void ClearMusics(void);

	private:

		RessourceLoader(void);

	protected:

		static std::vector<texture_set*> s_textureArray;
		static std::vector<sound_set*> s_soundArray;
		static std::vector<music_set*> s_musicArray;

		/*
			Recupère l'item suivant dans le fichier et stocke le nom dans name et le chemin dans path
			Si la lecture se fait sans problèmes, true est retourné. Si la lecture ne réussi pas (fin de fichier) false est retourné.
		*/
		static bool NextItem(std::ifstream& file, std::string& name, std::string& path);

	};
}

#ifdef OLD_BUFFER_SIZE
#	ifdef BUFFER_SIZE
#		undef BUFFER_SIZE
#		define BUFFER_SIZE OLD_BUFFER_SIZE
#	endif // BUFFER_SIZE
#	undef OLD_BUFFER_SIZE;
#endif // OLD_BUFFER_SIZE

#endif // __RESSOURCELOADER_H
