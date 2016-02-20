//Cracked by Roath
// 曲院风荷
// Dong  11/03/1996.
// Xbc 06/21/1997

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   	set("short", "曲院风荷");
   	set("long", @LONG
跨过小拱桥，迎面有一亭院，旁边立着石碑，上题“曲院风荷。”
往东是回苏堤。
LONG );

   	set("exits", ([ /* sizeof() == 2 */ 
                  "east" : __DIR__"suti2", 
  		  "enter" : __DIR__"quyuan2",
                ]));

	set("cost", 1);
        set("outdoors", "hangzhou");

   	setup();
   	replace_program(ROOM);
}
