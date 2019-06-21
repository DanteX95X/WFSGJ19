#include "move_around.h"

namespace test
{
	void MoveAround::_register_methods()
	{
		godot::register_method("_process", &MoveAround::_process);
		godot::register_property<MoveAround, float>("amplitude", &MoveAround::amplitude, 10.0f);
		godot::register_property<MoveAround, float>("speed", &MoveAround::setSpeed, &MoveAround::getSpeed, 1.0f);

		godot::Dictionary args;
		args[godot::Variant("node")] = godot::Variant(godot::Variant::OBJECT);
		args[godot::Variant("position")] = godot::Variant(godot::Variant::VECTOR2);
		godot::register_signal<MoveAround>((char*)"done", args);

		godot::register_method("SignalledMethod", &MoveAround::SignalledMethod);
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
		connect("done", this, "SignalledMethod");
	}

	void MoveAround::_process(float delta)
	{
		timePassed += speed * delta;
		godot::Vector2 position = godot::Vector2(amplitude + (amplitude * sin(timePassed * 2.0)),
												 amplitude + (amplitude * cos(timePassed * 1.5)));
		set_position(position);

		if(timePassed > 10)
		{
			emit_signal("done", this, position);
		}
	}

	float MoveAround::getSpeed() const { return speed; }
	void MoveAround::setSpeed(float speed) { this->speed = speed; }

	void MoveAround::SignalledMethod(godot::Node* node, godot::Vector2 position)
	{
		godot::Godot::print("signal");
		queue_free();
	}
}
