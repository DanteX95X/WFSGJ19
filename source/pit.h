#ifndef PIT_H
#define PIT_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <StaticBody2D.hpp>
#include <Area2D.hpp>
#include <AudioStreamPlayer.hpp>

namespace godot
{
	class Pit : public godot::StaticBody2D
	{
		GODOT_CLASS(Pit, godot::StaticBody2D)

	public:
		static void _register_methods();

		Pit();
		~Pit();

		void _init();
		void _ready();
		void _process(float delta);

		void BodyEntered(PhysicsBody2D* body);
		void OnBallDestroyed();

	private:
		Area2D* area;

		AudioStreamPlayer* hit;
	};
}

#endif // PIT_H
