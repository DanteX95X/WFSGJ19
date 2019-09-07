#include "ball.h"

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
