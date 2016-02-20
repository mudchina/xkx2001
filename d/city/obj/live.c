//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("现场直播", ({ "zhi bo", "broadcaster" }) );
        set("long", "一个精致的小玩意。\n");
        set_weight(100);
	set_max_encumbrance(100000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "steel");
		set("value", "100");
        }

	set("no_get", 1);
	set("no_steal", 1);
	set("env/invisibility", 100);
	enable_commands();

        setup();
}

void receive_message(string msgclass, string msg)
{
	int last = strsrch(msg, '\n', -1);
	mapping exits= environment(this_object())->query("exits");
	string where = environment(this_object())->query("short");

	if(last != -1 ) 
		msg = msg[0..(last-1)];

	if (msg[0..0] != "\n")msg = GRN"【"+where+"】"NOR + msg;
	else msg = replace_string(msg, "\n", "\n"GRN"【"+where+"】"NOR);
	tell_room(exits["down"], msg+"\n", this_object());
}
