//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "山门");
        set("long", @LONG
这里是大轮寺的山门，门前是络绎不绝的进香朝圣的信徒，有的甚至来
自乌丝藏西南的波丝。山门(gate)前站了几个手持法器的葛伦布在维持秩序，
东方是一条青石板铺成的山路。
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"dshanlu",
                "north" : __DIR__"guangchang",
        ]));
        set("item_desc", ([
                "gate" : "两扇厚厚的铜色大门，非合数人之力，是难以推动的。\n"
        ]));
	set("objects", ([
                __DIR__"npc/gelun1" : 2,
		__DIR__"npc/xiangke" : 1,
        ]));
        set("outdoors","qilian-shan");
	set("no_clean_up", 1);
	set("cost", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

   if (dir =="north" ) {
	this_player()->delete_temp("mark/comin");

        if (present("ge lunbu", environment(me))) {
            if (!myfam || myfam["family_name"] != "雪山派"
	    && myfam["family_name"] != "血刀门" 
	    && !present("suyou guan", this_player()))
            if (!this_player()->query_temp("marks/酥"))		
                return notify_fail("葛伦布挡住你说：你准备用什麽供奉我们佛爷呀？\n");
	else this_player()->set_temp("marks/酥", 0);
        }
        
        return 1;
   }
   return ::valid_leave(me, dir);
}
