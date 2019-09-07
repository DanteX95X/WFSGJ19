#ifndef CRIER_H
#define CRIER_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <KinematicBody2D.hpp>
#include <PackedScene.hpp>
#include <Area2D.hpp>

namespace godot
{
	class Crier : public godot::KinematicBody2D
	{
		GODOT_CLASS(Crier, godot::KinematicBody2D)

	public:
		static void _register_methods();

		Crier();
		~Crier();

		void _init();
		void _ready();
		void _process(float delta);

		void OnBallDestroyed();
		void OnBodyEntered(PhysicsBody2D* body);
		void OnBodyExited(PhysicsBody2D* body);

	private:
		void SpawnBall();

		Ref<PackedScene> ballScene;
		Node* ball;
		Area2D* area;
		bool canOwnBallDoHarm;
		int health;

		Vector2 velocity;
		float timeCounter;
		const float xTimer = 8;
		float yTimer;
	};
}

#endif // CRIER_H
