//Cracked by Roath


#include <ansi.h>

#define DO_SPECIAL_CHECK 0

inherit NPC_TRAINEE;
inherit "/d/wanshou/inherit/animal_inherit.c";

void init() 
{
	::init();
    add_action("do_show", "show");
}

void create()
{
	// setup animal starting 200 is beast, 202 is third from the start
	setup_animal(202);
    setup();
}

int do_show(string arg)
{
	mixed *data1;
	int i;

	if( !arg || sscanf(arg, "%d", i)!=1 ) 
	   return notify_fail("type: show #\n");

	setup_animal(i);
	return 1;
}

