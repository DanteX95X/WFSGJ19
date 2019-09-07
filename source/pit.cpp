#include "pit.h"
#include "ball.h"

namespace godot
{
	void Pit::_register_methods()
	{
		godot::register_method("_ready", &Pit::_ready);
		godot::register_method("_process", &Pit::_process);
		godot::register_method("BodyEntered", &Pit::BodyEntered);

		godot::register_method("OnBallDestroyed", &Pit::OnBallDestroyed);

		godot::register_signal<Pit>("life_lost");
	}

	Pit::Pit()
	{
	}

	Pit::~Pit()
	{
	}

	void Pit::_init()
	{
	}

	void Pit::_ready()
	{
		 area = static_cast<Area2D*>(get_node("Area2D"));
		 area->connect("body_entered", this, "BodyEntered");
	}

	void Pit::_process(float delta)
	{
	}

	void Pit::BodyEntered(PhysicsBody2D* body)
	{
		if(body->get_name() == "Ball")
		{
			Ball* ball = static_cast<Ball*>(body);
			ball->connect("ball_destroyed", this, "OnBallDestroyed");
			ball->Destroy();
			emit_signal("life_lost");
		}
	}

	void Pit::OnBallDestroyed()
	{
		Godot::print("ball_destroyed");
	}
}
