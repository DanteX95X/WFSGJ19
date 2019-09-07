#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot
{
	class GameManager : public godot::Node2D
	{
		GODOT_CLASS(GameManager, godot::Node2D)

	public:
		static void _register_methods();

		GameManager();
		~GameManager();

		void _init();
		void _ready();
		void _process(float delta);

		void OnLifeLost();
		void OnPointGained();

	private:
		int lifes;
		int points;
		int multiplier;

		Node* pit;
		Node* paddle;
	};
}

#endif // GAME_MANAGER_H
