#ifndef ASSETS_MANAGER_HPP
#define ASSETS_MANAGER_HPP

#include <iostream>
#include <unordered_map>

#include "sdl2include.h"
#include "log.h"

namespace engine {

	// Struct used to map width and height from a image or a sprite.
	// We also map the texture, which whom we will draw in canvas.
	struct Image {
		SDL_Texture * texture;
		unsigned int width;
		unsigned int height;
	};

	class AssetsManager {
		private:
			std::unordered_map<std::string, Image *> image_map;     // Map of all images already loaded.
			std::unordered_map<std::string, Mix_Music *> music_map; // Map of all musics already loaded.
			std::unordered_map<std::string, Mix_Chunk *> sound_map; // Map of all sounds already loaded.
		public:
			AssetsManager();

			Image* LoadImage(std::string image_path);

			Mix_Music* LoadMusic(std::string audio_path);

			Mix_Chunk * LoadSound(std::string audio_path);

			//TODO(Roger) Create method to shutdown all imagens in map, and put that method in the
			//scene shutdown.
		private:
			void InsertIntoImageMap(std::string image_path, SDL_Surface* image, SDL_Texture *image_texture);
			void InsertIntoMusicMap(std::string audio_path, Mix_Music * music);
			void InsertIntoSoundMap(std::string audio_path, Mix_Chunk * sound);
	};
}

#endif
