#ifndef INTRO_H
#define INTRO_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Label.hpp>
#include <AnimationPlayer.hpp>

namespace godot
{
	class Intro : public godot::Label
	{
		GODOT_CLASS(Intro, godot::Node2D)

	public:
		static void _register_methods();

		Intro();
		~Intro();

		void _init();
		void _ready();
		void _process(float delta);

	private:
		String text;
		String toWrite;

		float timeCounter;
	};
}

#endif // INTRO_H
