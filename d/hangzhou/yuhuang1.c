//Cracked by Roath
// 玉皇山路
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "玉皇山脚");
   set("long", @LONG
只见往上的山路曲折蜿延。山路旁有一座小六角亭，几个游人正
在亭里歇脚。东北边是一条青石大道，往西是上山的路。
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "northeast" : __DIR__"road71", 
                  "westup" : __DIR__"yuhuang2", 
                ])
       );

	set("cost", 3);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}