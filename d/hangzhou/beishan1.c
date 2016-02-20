//Cracked by Roath
// 北山山路
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "山路");
    set("long", @LONG
山上林木茂密，就是炎夏这里还是清凉依旧。朝北走便到了黄龙洞。
南边则是下山的路。
LONG);

   set("exits", ([ /* sizeof() == 2 */ 
                  "south" : __DIR__"road13", 
                  "north" : __DIR__"hl1", 			
                ])
       );
	set("cost", 3);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
