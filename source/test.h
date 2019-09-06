#ifndef TEST_H
#define TEST_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot
{
	class test : public godot::Node2D
	{
		GODOT_CLASS(test, godot::Node2D)

	public:
		static void _register_methods();

		test();
		~test();

		void _init();
		void _ready();
		void _process(float delta);
	};
}

#endif // TEST_H
