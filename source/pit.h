#ifndef PIT_H
#define PIT_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <StaticBody2D.hpp>
#include <Area2D.hpp>

namespace godot
{
	class Pit : public godot::StaticBody2D
	{
		GODOT_CLASS(Pit, godot::Node2D)

	public:
		static void _register_methods();

		Pit();
		~Pit();

		void _init();
		void _ready();
		void _process(float delta);

		void BodyEntered(PhysicsBody2D* body);

	private:
		Area2D* area;
	};
}

#endif // PIT_H
