#ifndef AUDIO_CONTROLLER_HPP
#define AUDIO_CONTROLLER_HPP

#include "audio_component.hpp"
#include "log.h"

#include <map>
#include <iostream>

namespace engine {

	class AudioController : public AudioComponent {
		private:
			std::map <std::string, AudioComponent *> audio_map;
		public:
			AudioController();
			AudioController(GameObject &game_object);
			void AddAudio(std::string audio_name, AudioComponent &animation);
			void PlayAudio(std::string audio_name);
			void PauseAudio(std::string audio_name);
			void StopAudio(std::string audio_name);
			AudioState GetAudioState(std::string audio_name);
			void Init();
			void Shutdown();
			void UpdateCode();

	};

}

#endif
