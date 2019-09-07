#ifndef TERMINAL_H
#define TERMINAL_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Label.hpp>

namespace godot
{
	class Terminal : public godot::Label
	{
		GODOT_CLASS(Terminal, godot::Label)

	public:
		static void _register_methods();

		Terminal();
		~Terminal();

		void _init();
		void _ready();
		void _process(float delta);

	private:
		String text;
		String toWrite;
		String copy;

		float timeCounter;
	};
}

#endif // TERMINAL_H
