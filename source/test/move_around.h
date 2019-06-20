#ifndef MOVE_AROUND_H
#define MOVE_AROUND_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace test
{
	class MoveAround : public godot::Node2D
	{
		GODOT_CLASS(MoveAround, godot::Node2D)

	private:
		float timePassed;

	public:
		static void _register_methods();

		MoveAround();
		~MoveAround();

		void _init();
		void _process(float delta);
	};
}

#endif // MOVE_AROUND_H
