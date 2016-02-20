//Cracked by Roath
// Ryu, 12/5/96

inherit ITEM;
#include <ansi.h>;

void init();
void wear(int);

int worn;

void create()
{
	set_name(HIR"一堆火焰"NOR,({"huo yan"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIR"火焰高约尺，"+GRN+"色作纯碧，"+BLU+"鬼气森森，"+HIR+"和寻常火焰大异。\n"NOR);
		set("unit", "堆");
		set("value", 10000);
		set("no_get", 1);
		set("no_drop", 1);
    	}
	
	setup();
}

void init()
{
	worn = 0;
	call_out("wear", 100, 1); 
}



void wear(int phase)
{
	worn = phase;
	switch(phase) {
	case 1:
		set("long", HIR"火焰熊熊燃烧着，"+GRN+"色作纯碧，"+BLU+"鬼气森森，"+HIR+"和寻常火焰大异。\n"NOR);
		call_out("wear", 100, phase+1); 
		break;
	case 2:
		set("long", RED"火势越来越弱，几乎快烧完了。\n"NOR);
		call_out("wear", 30, phase+1); 
		break;
	case 3:
		message_vision(RED"火焰渐渐地熄灭了。\n"NOR, this_object());
		destruct(this_object());
		break;
	}	
}

// End of File 
