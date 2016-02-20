//Cracked by Roath
// 岳廊
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "岳廊");
   set("long", @LONG
岳王庙的匾上是“心昭天日”四个大字。步入大殿，正中是岳飞
的塑像，身後的匾上题着“还我河山”。北边的门通向岳坟，往南是
出去的路。
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "north" : __DIR__"yuefen", 
                  "south" : __DIR__"road14", 
                ])
       );

	set("cost", 1);
   setup();
   replace_program(ROOM);
}