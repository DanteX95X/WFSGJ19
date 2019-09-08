#include "menu_paddle.h"
#include <Input.hpp>
#include <SceneTree.hpp>
#include <game_manager.h>

namespace godot
{
	void MenuPaddle::_register_methods()
	{
		godot::register_method("_ready", &MenuPaddle::_ready);
		godot::register_method("_process", &MenuPaddle::_process);
	}

	MenuPaddle::MenuPaddle()
		: start{548.794, 1025.32}, quit{1026.734, 1025.32}
	{
	}

	MenuPaddle::~MenuPaddle()
	{
	}

	void MenuPaddle::_init()
	{
	}

	void MenuPaddle::_ready()
	{
		set_position(start);

		if(GlobalData::Instance().score > 0)
		{
			static_cast<Node2D*>(get_node("../Scores"))->set_visible(true);
			Label* score = static_cast<Label*>(get_node("../Scores/Score"));
			Label* highScore = static_cast<Label*>(get_node("../Scores/HighScore"));

			if(GlobalData::Instance().score > GlobalData::Instance().highScore)
			{
				GlobalData::Instance().highScore = GlobalData::Instance().score;
			}

			score->set_text(String::num(GlobalData::Instance().score));
			highScore->set_text(String::num(GlobalData::Instance().highScore));
		}
	}

	void MenuPaddle::_process(float delta)
	{
		bool left_pressed = Input::get_singleton()->is_action_pressed("ui_left");
		bool right_pressed = Input::get_singleton()->is_action_pressed("ui_right");
		bool enter = Input::get_singleton()->is_action_just_pressed("ui_accept");

		if(left_pressed)
			set_position(start);
		if(right_pressed)
			set_position(quit);

		if(enter)
		{
			if(get_position() == start)
			{
				get_tree()->change_scene("res://scenes/level0.tscn");
			}
			else if(get_position() == quit)
			{
				get_tree()->quit();
			}
		}
	}
}
