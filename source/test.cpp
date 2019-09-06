#include "test.h"

namespace godot
{
	void test::_register_methods()
	{
		godot::register_method("_ready", &test::_ready);
		godot::register_method("_process", &test::_process);
	}

	test::test()
	{
	}

	test::~test()
	{
	}

	void test::_init()
	{
	}

	void test::_ready()
	{
		Godot::print("ready");
	}

	void test::_process(float delta)
	{
	}
}
