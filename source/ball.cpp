#include "ball.h"
#include <random>

namespace godot
{
	void Ball::_register_methods()
	{
		godot::register_method("_ready", &Ball::_ready);
		godot::register_method("_process", &Ball::_process);

		godot::register_signal<Ball>(/*ballDestroyedSignal*/"ball_destroyed");
	}

	Ball::Ball()
	{
	}

	Ball::~Ball()
	{
	}

	void Ball::_init()
	{
		Vector2 velocity = get_linear_velocity();

		std::random_device random;
		std::mt19937 twister{random()};
		std::uniform_int_distribution<int> distribution{0, 1};
		velocity.x = distribution(twister) == 0 ? -velocity.x : velocity.x;

		set_linear_velocity(velocity);
	}

	void Ball::_ready()
	{
	}

	void Ball::_process(float delta)
	{
	}

	void Ball::Destroy()
	{
		emit_signal(/*ballDestroyedSignal*/"ball_destroyed");
		queue_free();
	}

	//const String Ball::ballDestroyedSignal = "ball_destroyed";
}
