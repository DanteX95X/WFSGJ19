#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Label.hpp>

namespace godot
{
	class GlobalData
	{
	public:
		static GlobalData& Instance()
		{
			static GlobalData instance;
			return instance;
		}

		int score;
		int highScore;
		int level = 0;
		const int maxLevel;

	private:
		GlobalData()
			: score{0}, highScore{0}, level{0}, maxLevel{3}
		{

		}
		GlobalData(const GlobalData&) = delete;
		GlobalData(GlobalData&&) = delete;
	};

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
		void NextLevel();

		int lifes;
		int points;
		int multiplier;

		Node* pit;
		Node* paddle;

		Label* score;
		Label* bonus;
		Label* lifesLeft;
	};
}

#endif // GAME_MANAGER_H
