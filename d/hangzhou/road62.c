//Cracked by Roath
 // 山路
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "山路");
    set("long", @LONG
走在小路上，只见漫山遍野都是绿油油的茶蓬。农家少女们在欢
笑声中采茶。山路延伸向东西两边，北边就是龙井，东北边有一条土
路。
LONG);

    set("exits", ([ /* sizeof() == 4 */ 
                  "east" : __DIR__"road63",
                  "south" : "/d/quanzhou/qzroad5",
                  "westup" : __DIR__"road61", 
                  "north" : __DIR__"longjin0", 
                  "northeast" : __DIR__"road43", 
                ])
       );
	set("objects", ([
                __DIR__"npc/caichanu" : 2,
        ]));
	set("cost", 2);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
