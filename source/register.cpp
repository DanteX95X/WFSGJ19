#include "./test.h"
#include "./paddle.h"
#include "./pit.h"
#include "./ball.h"
#include "./crier.h"
#include "./crier_column.h"
#include "./game_manager.h"
#include "./terminal.h"
#include "./menu_paddle.h"
#include "./intro.h"
//$include$ DO NOT DELETE THIS COMMENT

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o)
{
	godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o)
{
	godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle)
{
	godot::Godot::nativescript_init(handle);

	godot::register_class<godot::test>();
	godot::register_class<godot::Paddle>();
	godot::register_class<godot::Pit>();
	godot::register_class<godot::Ball>();
	godot::register_class<godot::Crier>();
	godot::register_class<godot::CrierColumn>();
	godot::register_class<godot::GameManager>();
	godot::register_class<godot::Terminal>();
	godot::register_class<godot::MenuPaddle>();
	godot::register_class<godot::Intro>();
	//$register$ DO NOT DELETE THIS COMMENT
}
