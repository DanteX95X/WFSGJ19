#ifndef BALL_H
#define BALL_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <RigidBody2D.hpp>

namespace godot
{
	class Ball : public godot::RigidBody2D
	{
		GODOT_CLASS(Ball, godot::RigidBody2D)

	public:
		static void _register_methods();

		Ball();
		~Ball();

		void _init();
		void _ready();
		void _process(float delta);

		void Destroy();

	private:
		//static const String ballDestroyedSignal;
	};
}

#endif // BALL_H
