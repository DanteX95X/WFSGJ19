#include "crier.h"
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>

namespace godot
{
	void Crier::_register_methods()
	{
		godot::register_method("_ready", &Crier::_ready);
		godot::register_method("_process", &Crier::_process);
		godot::register_method("OnBallDestroyed", &Crier::OnBallDestroyed);
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

	void Crier::SpawnBall()
	{
		ball = ballScene->instance();
		add_child(ball);
		ball->connect("ball_destroyed", this, "OnBallDestroyed");
		add_collision_exception_with(ball);
	}
}
