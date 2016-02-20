//Cracked by Roath
// 金蛇通道
// qfy 16/10/1996

#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_strike();

void create()
{
        set("short", "甬道");
	set("long", @LONG
这是甬道后方。两三丈远处，地势豁然空阔，出现一个洞穴，便如是
座石室。
LONG
        );

	set("exits", ([ /* sizeof() == 1 */
		"enter" :  __DIR__"jinshedong",
		"left" : __DIR__"yongdao3",
	]));
	   
	set("cost", 1);
                setup();
}
