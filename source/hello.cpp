#include "hello.h"
#include "test/move_around.h"

namespace test
{
	void Hello::_register_methods()
	{
		godot::register_method("_ready", &Hello::_ready);
		godot::register_method("_process", &Hello::_process);
		godot::register_method("Signal", &Hello::Signal);
	}

	Hello::Hello()
	{
	}

	Hello::~Hello()
	{
	}

	void Hello::Signal(godot::Node* node, godot::Vector2 position)
	{
		godot::Godot::print("processing signal");
		queue_free();
	}

	void Hello::_init()
	{
		godot::Godot::print("Hello World!");
		done = false;
		godot::Godot::print("testing");
	}

	void Hello::_ready()
	{
		godot::Node* node = get_node("Sprite");
		node->connect("done", this, "Signal");
	}

	void Hello::_process(float delta)
	{
	}


}
