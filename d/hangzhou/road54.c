//Cracked by Roath
// 沿湖大道
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "沿湖大道");
   set("long", @LONG
一条宽敞的大道上却游人稀少。原来这里沿路住着的都是达官贵
人。本来风景秀丽之处，却显的一片萧瑟。路的西边是一座庄园，大
道向南北延伸。
LONG
      );

   set("exits", ([ /* sizeof() == 3 */ 
                  "north" : __DIR__"road53", 
                  "south" : __DIR__"road74", 
                  "west" : __DIR__"liuz1", 
                ])
       );

	set("cost", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}