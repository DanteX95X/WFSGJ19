#include "intro.h"

namespace godot
{
	void Intro::_register_methods()
	{
		godot::register_method("_ready", &Intro::_ready);
		godot::register_method("_process", &Intro::_process);
	}

	Intro::Intro()
	{
	}

	Intro::~Intro()
	{
	}

	void Intro::_init()
	{
		toWrite = R"ufo(Once upon a time,
in a distant land,
where nobody heard about game engines,
programmers had a really hard time making games.
The only way to ease their suffering was to cry...
)ufo";

		done = false;
	}

	void Intro::_ready()
	{
		set_text(
R"ufo(














)ufo");

		text = get_text();
		timeCounter = 0;

		player = static_cast<AnimationPlayer*>(get_node("../Blinking"));
	}

	void Intro::_process(float delta)
	{
		timeCounter += delta;
		if(timeCounter > 0.1f && !done)
		{
			timeCounter = 0;

			String substring = toWrite.substr(0, 1);
			text+= substring;
			if(substring == "\n")
			{
				int position = text.find("\n");
				text.erase(0, position + 1);
			}
			toWrite.erase(0, 1);
			set_text(text);

			if(toWrite.empty())
			{
				done = true;
				player->play("Intro");
			}
		}
	}
}
