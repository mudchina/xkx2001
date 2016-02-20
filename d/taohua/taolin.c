//Cracked by Roath
//
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "桃林");
	set("long", @LONG
这是一片灿若云霞的桃林，繁花似锦，五色缤纷，比起岛上其它地方的
桃林要茂盛许多，地下的泥土也十分新鲜，像有人刚刚整理过。
LONG
	);
        
	set("exits", ([
                "west" : __DIR__"xiangzhong",
		"east" : __DIR__"jingshe",
           ]));
        
        set("objects", ([
                __DIR__"obj/taoshu" : 1,
        ]));
	
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}

/*
void init()
{
	object ob = this_player();
	if (ob->query_temp("th_tomb_thief")) {
		tell_object(ob,CYN"你似乎觉得桃林中有点异样，但又说不上来。\n"NOR);
		delete("exits/east");
		set("exits/east", __DIR__"hyjuchu");
    		remove_call_out("close_door");
    		call_out("close_door",random(20),ob);

	}
}


void close_door()
{
	delete("exits/east");
	set("exits/east", __DIR__"jingshe");
}


int valid_leave(object me, string dir)
{
	if (me->query_temp("th_tomb_thief") && dir == "east") { 
		me->move("/d/taohua/hyjuchu");
         	return 1;
	}

    	return ::valid_leave(me, dir);
}
*/
