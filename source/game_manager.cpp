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
		points = GlobalData::Instance().score;
		multiplier = 1;
	}

	void GameManager::_ready()
	{
		pit = get_node("Pit");
		pit->connect("life_lost", this, "OnLifeLost");

		paddle = get_node("Paddle");
		paddle->connect("point_gained", this, "OnPointGained");

		score = static_cast<Label*>(get_node("Score"));
		bonus = static_cast<Label*>(get_node("Bonus"));
		lifesLeft = static_cast<Label*>(get_node("Lifes"));
	}

	void GameManager::_process(float delta)
	{
		score->set_text(String::num(points));
		bonus->set_text(String::num(multiplier));
		lifesLeft->set_text(String::num(lifes - 1));

		bool found = false;
		for(int i = 0; i < get_child_count(); ++i)
		{
			if(get_child(i)->get_name() == "Crier")
			{
				found = true;
				break;
			}
		}
		if(!found)
		{
			GlobalData::Instance().score = points;
			Godot::print("Level completed");
			++GlobalData::Instance().level;
			if(GlobalData::Instance().level >= GlobalData::Instance().maxLevel)
				get_tree()->change_scene("res://scenes/menu.tscn");
			get_tree()->change_scene("res://scenes/level" + String::num(GlobalData::Instance().level) + ".tscn");
			//Maybe another level
		}
	}

	void GameManager::OnLifeLost()
	{
		--lifes;
		multiplier = 1;
		if(lifes <= 0)
		{
			GlobalData::Instance().score = points;
			Godot::print("Game Over");
			get_tree()->change_scene("res://scenes/menu.tscn");
		}
	}

	void GameManager::OnPointGained()
	{
		points += multiplier;
		++multiplier;
		Godot::print("points gained");
	}
}
