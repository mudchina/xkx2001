//Cracked by Roath
// yuanhe.c 源和堂
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "源和堂");
	set("long", @LONG
这是远近闻名的蜜饯制作铺，各色水果经过他们的加工后风味独特，甜而
不腻，咸而不过，酸而不涩，又可以长期保存，远销海内外。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northeast" : __DIR__"minzai2",
		"east" : __DIR__"minzai3",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
