#ifndef PADDLE_H
#define PADDLE_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <KinematicBody2D.hpp>

namespace godot
{
	class Paddle : public godot::KinematicBody2D
	{
		GODOT_CLASS(Paddle, godot::KinematicBody2D)

	public:
		static void _register_methods();

		Paddle();
		~Paddle();

		void _init();
		void _ready();
		void _process(float delta);

		void OnBodyEntered(PhysicsBody2D* body);

	private:
		const float speed = 1000;
	};
}

#endif // PADDLE_H
