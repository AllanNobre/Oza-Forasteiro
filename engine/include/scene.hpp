#ifndef SCENE_ENGINE_HPP
#define SCENE_ENGINE_HPP

#include <iostream>
#include "sdl2include.h"
#include "game_object.hpp"
#include <unordered_map>

namespace engine {
	class Scene {
		public:
			Scene();
			Scene(std::string scene_name);

			virtual void Init();
			virtual void Shutdown();
			virtual void Draw();
			virtual void UpdateCode();

			inline std::string GetSceneName() {
				return scene_name;
			}

			void AddGameObject(engine::GameObject &game_object);
			engine::GameObject & GetGameObject(std::string & game_object_name);
			void RemoveGameObject(std::string &game_object_name);
			void ResolveCollision();

		protected:
			std::unordered_map<std::string, engine::GameObject *> game_object_map;
			std::string scene_name;
	};
}

#endif