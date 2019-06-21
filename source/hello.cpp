#include "hello.h"

namespace test
{
	void Hello::_register_methods()
	{
		godot::register_method("_process", &Hello::_process);
	}

	Hello::Hello()
	{
	}

	Hello::~Hello()
	{
	}

	void Hello::_init()
	{
		godot::Godot::print("Hello World!");
	}

	void Hello::_process(float delta)
	{
	}
}
