#include "crier_column.h"
#include <ResourceLoader.hpp>

namespace godot
{
	void CrierColumn::_register_methods()
	{
		godot::register_method("_ready", &CrierColumn::_ready);
		godot::register_method("_process", &CrierColumn::_process);

		godot::register_property<CrierColumn, int>("Count", &CrierColumn::count, 0);
	}

	CrierColumn::CrierColumn()
	{
	}

	CrierColumn::~CrierColumn()
	{
	}

	void CrierColumn::_init()
	{
		Ref<Resource> resource = ResourceLoader::get_singleton()->load("res://scenes/crier.tscn");
		crierScene = resource;
	}

	void CrierColumn::_ready()
	{
		for(int i = 0; i < count; ++i)
		{
			Node* node = crierScene->instance();
			Crier* crier = static_cast<Crier*>(node);
			Vector2 position = crier->get_position();
			position.y += 100 * i;
			crier->set_position(position);
			add_child(crier);
			criers.push_back(crier);
		}
	}

	void CrierColumn::_process(float delta)
	{
	}
}
