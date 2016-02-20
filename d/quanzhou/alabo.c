//Cracked by Roath
// alabo.c 阿拉伯宅区
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "阿拉伯宅区");
	set("long", @LONG
由于泉州与世界的商贸往来，许多阿拉伯人来到此地居住和劳作，久而久
之形成了这聚居地。远远望去白色的圆形尖顶突兀而起，显得格外抢眼。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northwest" : __DIR__"citong_s2",
		"south" : __DIR__"qingjing",
	]));

        set("objects", ([ 
		__DIR__"npc/trader" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
