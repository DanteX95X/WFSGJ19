#ifndef CRIER_H
#define CRIER_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <KinematicBody2D.hpp>
#include <PackedScene.hpp>

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

	private:
		void SpawnBall();

		Ref<PackedScene> ballScene;
		Node* ball;
	};
}

#endif // CRIER_H
