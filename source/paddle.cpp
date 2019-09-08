#include "paddle.h"
#include <Input.hpp>

namespace godot
{
	void Paddle::_register_methods()
	{
		godot::register_method("_ready", &Paddle::_ready);
		godot::register_method("_process", &Paddle::_process);

		godot::register_method("OnBodyEntered", &Paddle::OnBodyEntered);

		godot::register_signal<Paddle>("point_gained");
	}

	Paddle::Paddle()
	{
	}

	Paddle::~Paddle()
	{
	}

	void Paddle::_init()
	{
	}

	void Paddle::_ready()
	{
		Node* area = get_node("Area2D");
		area->connect("body_entered", this, "OnBodyEntered");

		bounce = static_cast<AudioStreamPlayer*>(get_node("Bounce"));
	}

	void Paddle::_process(float delta)
	{
		Vector2 velocity{0,0};
		bool left_pressed = Input::get_singleton()->is_action_pressed("ui_left");
		bool right_pressed = Input::get_singleton()->is_action_pressed("ui_right");

		if(left_pressed)
			velocity.x -= speed;
		if(right_pressed)
			velocity.x += speed;

		move_and_slide(velocity);
	}

	void Paddle::OnBodyEntered(PhysicsBody2D *body)
	{
		if(body->get_name() == "Ball")
		{
			bounce->play();
			emit_signal("point_gained");
		}
	}
}
