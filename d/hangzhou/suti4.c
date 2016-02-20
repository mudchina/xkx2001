//Cracked by Roath
// 苏堤
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "苏堤");
   set("long", @LONG
春晓，漫步林荫道上，烟柳笼纱，雀鸟欢鸣，一片生机。苏堤春
晓被列为西湖十景之首，果然名不虚传。北边是压堤桥，南面是望山
桥。东面一片梅林，林后似乎有座院落，但看不真切。
LONG
        );

   set("exits", ([ /* sizeof() == 3 */ 
                  "south" : __DIR__"suti5", 
                  "north" : __DIR__"suti3", 
                ])
       );
	set("objects" , ([
                "/d/jiaxing/npc/wuya" : 1,
                "/d/city/npc/maque" : 2,
	]));
	set("cost", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
