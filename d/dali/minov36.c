//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov36.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"玉霞山"NOR);
	set("long","
玉霞山东镇星云湖，山清林秀，许多游人来此欣赏湖光山色，无不为之倾倒。

　　　古人有诗曰：
　　　"HIC"玉霞凄清秋气凉，
　　　星云湖水澄明光，
　　　近屿含烟凝紫翠，
　　　远山峭壁摩青苍，
　　　水光山色相辉映，
　　　万里无云碧天净。\n"NOR
);
	set("objects", ([
		__DIR__"npc/youke1.c" : 1,
		]));
	set("exits", ([
		"westdown" : __DIR__"minov35",
		]));
	set("area", "步雄部");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
