#include "crier.h"
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>
#include "ball.h"

namespace godot
{
	void Crier::_register_methods()
	{
		godot::register_method("_ready", &Crier::_ready);
		godot::register_method("_process", &Crier::_process);
		godot::register_method("OnBallDestroyed", &Crier::OnBallDestroyed);
		godot::register_method("OnBodyEntered", &Crier::OnBodyEntered);
		godot::register_method("OnBodyExited", &Crier::OnBodyExited);

		godot::register_property<Crier, int>("Health", &Crier::health, 1);
	}

	Crier::Crier()
	{
	}

	Crier::~Crier()
	{
	}

	void Crier::_init()
	{
		Ref<Resource> resource = ResourceLoader::get_singleton()->load("res://scenes/ball.tscn");
		ballScene = resource;
		ball = nullptr;
	}

	void Crier::_ready()
	{
		area = static_cast<Area2D*>(get_node("Area2D"));
		area->connect("body_exited", this, "OnBodyExited");
		area->connect("body_entered", this, "OnBodyEntered");
	}

	void Crier::_process(float delta)
	{
		if(!ball)
		{
			SpawnBall();
		}


	}

	void Crier::OnBallDestroyed()
	{
		ball = nullptr;
	}

	void Crier::OnBodyEntered(PhysicsBody2D *body)
	{
		if(body->get_name() == "Ball" && (body != ball || canOwnBallDoHarm))
		{
			--health;
			static_cast<Ball*>(body)->Destroy();
			if(health <= 0)
			{
				queue_free();
			}
		}
	}

	void Crier::OnBodyExited(PhysicsBody2D* body)
	{
		if(body == ball)
		{
			remove_collision_exception_with(ball);
			canOwnBallDoHarm = true;
		}
	}

	void Crier::SpawnBall()
	{
		ball = ballScene->instance();
		add_child(ball);
		ball->connect("ball_destroyed", this, "OnBallDestroyed");
		add_collision_exception_with(ball);
		canOwnBallDoHarm = false;
	}
}