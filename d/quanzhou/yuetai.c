//Cracked by Roath
// yuetai.c 月台广场
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "月台广场");
	set("long", @LONG
这是平坦光滑的石面广场，中间凸起一台面，面放置一焚吊炉。台座边嵌
着七十二幅狮身人面青石浮雕，有着浓厚的异国风味。东西各有一座恢宏的石
塔。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"ganlu",
		"south" : __DIR__"dxbaodian",
		"east" : __DIR__"dongta",
		"west" : __DIR__"xita",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
