#ifndef MENU_PADDLE_H
#define MENU_PADDLE_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot
{
	class MenuPaddle : public godot::Node2D
	{
		GODOT_CLASS(MenuPaddle, godot::Node2D)

	public:
		static void _register_methods();

		MenuPaddle();
		~MenuPaddle();

		void _init();
		void _ready();
		void _process(float delta);

	private:
		Vector2 start;
		Vector2 quit;
	};
}

#endif // MENU_PADDLE_H
