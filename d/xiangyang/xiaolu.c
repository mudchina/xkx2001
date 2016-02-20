//Cracked by Roath
// Room: /d/xiangyang/xiaolu.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "小路");
	set("long", @LONG
你走在假山石旁的小路上，绕过假山，一边是後花园，东南边
通往芍药亭。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 2, "y" : -7 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"huayuan",
  "southeast" : __DIR__"ting",
  "west" : __DIR__"chenhou",
]));
	create_door("west", "小门", "east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
