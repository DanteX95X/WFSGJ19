#ifndef HELLO_H
#define HELLO_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace test
{
	class Hello : public godot::Node2D
	{
		GODOT_CLASS(Hello, godot::Node2D)

	public:
		static void _register_methods();

		Hello();
		~Hello();

		void Signal(godot::Node* node, godot::Vector2 position);

		void _init();
		void _ready();
		void _process(float delta);

	private:
		bool done;
	};
}

#endif // HELLO_H
