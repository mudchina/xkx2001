//Cracked by Roath
// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW "鬼门关" NOR);
	set("long", 
		"这里就是著名的阴间入口「鬼门关」，在你面前矗立著一座高大的\n"
		"黑色城楼，许\多亡魂正哭哭啼啼地列队前进，因为一进鬼门关就无法再\n"
		"回阳间了。\n");
	set("exits", ([
		"north" : "/d/death/gateway",
	]) );
	set("objects", ([
		__DIR__"npc/wgargoyle":1
	]) );
	set("no_fight", 1);
	set("cost", 0);
	setup();
}

void init()
{

	object *inv, me=this_player();
        int i;

        inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]->is_character())continue;
                destruct(inv[i]);
                }

	me->clear_condition();

	if ( me->query_temp("sanxiao") )
	{
        me->delete_temp("sanxiao");
	me->delete_temp("smile");
	}

	add_action("do_suicide","suicide");

}

int do_suicide(string arg)
{
        object me = this_player();
        tell_object(me, "你还死着呢。\n");
        return 1;
}


