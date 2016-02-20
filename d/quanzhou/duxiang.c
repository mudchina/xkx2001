//Cracked by Roath
// duxiang.c 都督巷
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "都督巷");
	set("long", @LONG
这是泉州的一条小巷，清净整洁。远远可见巷底红墙高砌，把守森严，显
然不是普通的住家。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"citong_n1",
		"east" : __DIR__"dufu",
	]));

	set("objects", ([
		__DIR__"npc/bing" : 2,
	 ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
