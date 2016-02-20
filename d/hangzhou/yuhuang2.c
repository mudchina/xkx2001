//Cracked by Roath
// 玉皇山路
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "山路");
   set("long", @LONG
山路崎岖，曲折蜿延。四周林木苍翠，修竹茂密。山路旁是涵碧
亭，在这里极目远眺，群山环湖尽收眼底。西边是上山的路，往东便
是下山的路。
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "eastdown" : __DIR__"yuhuang1", 
                  "westup" : __DIR__"yuhuang3", 
                ])
       );

	set("cost", 2);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}