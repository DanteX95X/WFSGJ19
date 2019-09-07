#ifndef CRIER_COLUMN_H
#define CRIER_COLUMN_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <PackedScene.hpp>
#include <vector>
#include "crier.h"

namespace godot
{
	class CrierColumn : public godot::Node2D
	{
		GODOT_CLASS(CrierColumn, godot::Node2D)

	public:
		static void _register_methods();

		CrierColumn();
		~CrierColumn();

		void _init();
		void _ready();
		void _process(float delta);

	private:
		int count;
		Ref<PackedScene> crierScene;
		std::vector<Crier*> criers;
	};
}

#endif // CRIER_COLUMN_H
