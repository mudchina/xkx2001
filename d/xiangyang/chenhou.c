//Cracked by Roath
// Room: /d/xiangyang/chenhou.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "陈侯巷");
	set("long", @LONG
这条小巷静悄悄的，没什麽人来往。西边传来一阵阵兵士集练的呐喊声，
直往西去就可至兵营。东面路的尽头似乎有扇木门虚掩着。
LONG
	);
        set("coordinates", ([ "x" : 1, "y" : -7 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"nanjie2",
  "east" : __DIR__"xiaolu",
]));
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	create_door("east", "小门", "west", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
