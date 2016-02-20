//Cracked by Roath
// 上天竺
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "法喜寺");
   set("long", @LONG
法喜寺是天竺三寺中最敞朗深幽的一座。进香的游客不时的进进
出出。往东可达龙井，朝北是下山的路。
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "eastdown" : __DIR__"road61", 
                  "northdown" : __DIR__"tianzhu4", 
                ])
       );
	set("objects", ([
                "/d/wudang/npc/guest" : 1,
		"/d/hangzhou/npc/heshang" : 1,
        ]));

	set("cost", 1);
   setup();
   replace_program(ROOM);
}
