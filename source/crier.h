#ifndef CRIER_H
#define CRIER_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <KinematicBody2D.hpp>
#include <PackedScene.hpp>
#include <Area2D.hpp>
#include <random>

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
		Vector2 velocityHorizontal;
		Vector2 velocityVertical;
		float timeCounter;
		const float xTimer = 8;
		float yTimer = 1;

		std::random_device random;
		std::mt19937 twister;
		std::uniform_real_distribution<float> distribution;

		float spawnTimeCounter;
		float spawnTimer;

		static int id;
	};
}

#endif // CRIER_H
