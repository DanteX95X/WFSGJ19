#include "move_around.h"

namespace test
{
	void MoveAround::_register_methods()
	{
		register_method("_process", &MoveAround::_process);
	}

	MoveAround::MoveAround()
	{
	}

	MoveAround::~MoveAround()
	{
	}

	void MoveAround::_init()
	{
		timePassed = 0;
	}

	void MoveAround::_process(float delta)
	{
		timePassed += delta;
		godot::Vector2 position = godot::Vector2(10.0 + (10.0 * sin(timePassed * 2.0)), 10.0 + (10.0 * cos(timePassed * 1.5)));
		set_position(position);
	}
}
