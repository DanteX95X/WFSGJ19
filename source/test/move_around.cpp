#include "move_around.h"

namespace test
{
	void MoveAround::_register_methods()
	{
		godot::register_method("_process", &MoveAround::_process);
		godot::register_property<MoveAround, float>("amplitude", &MoveAround::amplitude, 10.0f);
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
		amplitude = 10;
	}

	void MoveAround::_process(float delta)
	{
		timePassed += delta;
		godot::Vector2 position = godot::Vector2(amplitude + (amplitude * sin(timePassed * 2.0)),
												 amplitude + (amplitude * cos(timePassed * 1.5)));
		set_position(position);
	}
}
