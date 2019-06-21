#include "move_around.h"

namespace test
{
	void MoveAround::_register_methods()
	{
		godot::register_method("_process", &MoveAround::_process);
		godot::register_property<MoveAround, float>("amplitude", &MoveAround::amplitude, 10.0f);
		godot::register_property<MoveAround, float>("speed", &MoveAround::setSpeed, &MoveAround::getSpeed, 1.0f);
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
		speed = 1;
	}

	void MoveAround::_process(float delta)
	{
		timePassed += speed * delta;
		godot::Vector2 position = godot::Vector2(amplitude + (amplitude * sin(timePassed * 2.0)),
												 amplitude + (amplitude * cos(timePassed * 1.5)));
		set_position(position);
	}

	float MoveAround::getSpeed() const { return speed; }
	void MoveAround::setSpeed(float speed) { this->speed = speed; }
}
