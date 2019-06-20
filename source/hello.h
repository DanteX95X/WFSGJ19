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

		void _init();
		void _process(float delta);
	};
}

#endif // HELLO_H
