//Cracked by Roath
// taizipo.c 武当太子坡
// by Fang 8/19/96

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"太子坡"NOR);
	set("long", @LONG
	此处地处坡陀之隘，形势险要，名叫太子坡，好象一朵出水芙蓉，涌出
绿波，瓣萼历历可数。远处峰回路转，忽明忽灭，尽在云雾之中。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shiliang",
		"northdown" : __DIR__"shanlu",
                "east" : __DIR__"wuceng",
	]));

	set("cost", 3);
	setup();
	replace_program(ROOM);
}

