//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov3.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "茶花山南");
        set("long", @LONG
这儿是茶花山的南面，虽然仍然有大量的茶花盛开着，但显然不如山上的品
种好了，放眼望去皆属凡品。
LONG);
	set("exits", ([
		"northup" : __DIR__"chhill2",
		"southeast" : __DIR__"minov1",
		]));
	set("area", "大叠水瀑布");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
