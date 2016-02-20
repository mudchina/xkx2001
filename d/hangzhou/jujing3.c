//Cracked by Roath
// 聚景园 柳浪桥
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", GRN"柳浪桥"NOR);
    set("long", @LONG
每当春至，站在桥上，沿湖垂柳在风中摇曳如翠浪翻空，黄莺在
枝头迎春嬉戏，鸣声婉转，故得名“浪桥闻莺”。
LONG);

    set("exits", ([ /* sizeof() == 1 */ 
                   "southwest" : __DIR__"jujing2", 
                 ])
       );
	set("objects" , ([
                "/d/jiaxing/npc/wuya" : 1,
                "/d/city/npc/maque" : 2,
	]));
	set("cost", 2);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
