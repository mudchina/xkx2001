//Cracked by Roath
// 西冷桥
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "西冷桥");
   set("long", @LONG
西冷桥衔结孤山，跨过里西湖。桥的东南边是孤山。北边则是一
条青石大道。
LONG
        );


   set("exits", ([ /* sizeof() == 2 */ 
                  "southeast" : __DIR__"gushan1", 
 		  "north" : __DIR__"road13",
                ])
       );

	set("cost", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}