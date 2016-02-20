//Cracked by Roath
// Room: /d/xiangyang/bingying.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "兵营");
	set("long", @LONG
你正处在兵营中，四周密密麻麻到处都是官兵。为了应付随时而来的蒙古大
军，都在带头武将的指挥下列队加紧操练。南墙下坐着主将，不动声色来回寻视
着四周。南边高墙深院，有一扇铁门(door)在南墙之下。西去即是集兵让主帅简
阅的校士台。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_sleep_room", 1);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -1, "y" : -2 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"bydamen",
  "west" : __DIR__"lianwuc",
  "south" : __DIR__"dalao",
]));

	create_door("south", "铁门", "north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("官兵拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}