#include "game_manager.h"
#include <SceneTree.hpp>

namespace godot
{
	void GameManager::_register_methods()
	{
		godot::register_method("_ready", &GameManager::_ready);
		godot::register_method("_process", &GameManager::_process);

		godot::register_method("OnLifeLost", &GameManager::OnLifeLost);
		godot::register_method("OnPointGained", &GameManager::OnPointGained);

		godot::register_property<GameManager, int>("Lifes", &GameManager::lifes, 0);
	}

	GameManager::GameManager()
	{
	}

	GameManager::~GameManager()
	{
	}

	void GameManager::_init()
	{
		points = 0;
		multiplier = 1;
	}

	void GameManager::_ready()
	{
		pit = get_node("Pit");
		pit->connect("life_lost", this, "OnLifeLost");

		paddle = get_node("Paddle");
		paddle->connect("point_gained", this, "OnPointGained");
	}

	void GameManager::_process(float delta)
	{
	}

	void GameManager::OnLifeLost()
	{
		--lifes;
		multiplier = 1;
		if(lifes <= 0)
		{
			Godot::print("Game Over");
			get_tree()->change_scene("res://scenes/level.tscn");
		}
	}

	void GameManager::OnPointGained()
	{
		points += multiplier;
		Godot::print("points gained");
	}
}
