#include "crier.h"
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>

namespace godot
{
	void Crier::_register_methods()
	{
		godot::register_method("_ready", &Crier::_ready);
		godot::register_method("_process", &Crier::_process);
	}

	Crier::Crier()
	{
	}

	Crier::~Crier()
	{
	}

	void Crier::_init()
	{
	}

	void Crier::_ready()
	{
		Ref<Resource> resource = ResourceLoader::get_singleton()->load("res://scenes/ball.tscn");
		Ref<PackedScene> scene = resource;
		add_child(scene->instance());
	}

	void Crier::_process(float delta)
	{
	}
}
