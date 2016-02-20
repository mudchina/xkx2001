//Cracked by Roath
// 三潭映月
// Dong  11/03/1996.
// xbc 06/21/1997

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   
	set("short", "花岛亭");
	set("long", @LONG
只见四面池中莲荷高下，水面亭楼倒影。一阵轻风吹过，清香使
人陶醉。北边是竹径通幽，南边有一座小亭。
LONG);

    	set("exits", ([ /* sizeof() == 2 */ 
        "south" : __DIR__"santan6", 
        "north" : __DIR__"santan4", 
                 ])
       );

	set("cost", 1);
        set("outdoors", "hangzhou");
        set("he_count", 2);
   	setup();
//   	replace_program(ROOM);
}

void init()
{
        add_action("do_pick", "pick");
        add_action("do_pick", "zhai");
}

int do_pick(string arg)
{
        object me = this_player();
        object ob = new("/d/gaibang/obj/heye");

        if ( !arg || arg == "") return 0;

        if ( arg == "he ye" || arg == "荷叶" ){
                if (query("he_count") < 1) {
                        tell_object(me, "还摘？再摘人家还看不看「曲院风荷」了？\n", me);
                        return 1;
                }
                message_vision("$N从湖中摘下一片荷叶来。\n", me);
                ob->move(me);
                add("he_count", -1);
                return 1;
        }
        return 0;
}

