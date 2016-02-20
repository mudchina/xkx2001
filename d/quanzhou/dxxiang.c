//Cracked by Roath
// dxxiang.c 打锡巷
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "打锡巷");
	set("long", @LONG
这是普普通通的一条石板小路。走在上面，也许你根本想不到这是施琅将
军攻克台湾后为显其战功，将其城池的砌石运回铺成此路。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"citong_s1",
		"east" : __DIR__"jiangfu",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
