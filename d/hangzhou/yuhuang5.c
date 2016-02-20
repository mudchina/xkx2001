//Cracked by Roath
// 玉皇山脚
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "玉皇山");
   set("long", @LONG
山脚有一座小亭，德意亭。不少游客登山前或下山後都在此小歇。
山路蜿延往东向上。西边有一条大路。
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "west" : __DIR__"road77", 
                  "eastup" : __DIR__"yuhuang4", 
                ])
       );

	set("cost", 3);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}