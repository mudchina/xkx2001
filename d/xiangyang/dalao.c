//Cracked by Roath
// Room: /d/xiangyang/dalao.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "牢狱");
	set("long", @LONG
这里黑沉沉的，即无一丝光亮，也无半分声息。四壁摸上去冰凉，且极硬，
似乎都是用粗糙的片岩垒垛而成，一颗颗水珠沿着墙壁滚下来，溅在地上。只有
北面有一道小门，门上开了个巴掌大的洞，象是送饭用的。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -1, "y" : -3 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"bingying",
]));

	create_door("north", "铁门", "south", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
