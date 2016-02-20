//Cracked by Roath
// guangchang.c 广场
// by Xiang
// xQin 04/01

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"武当广场"NOR);
	set("long", @LONG
这是一个由大石板铺成的广场，是武当弟子学习武功和互相切磋的地点
。周围种满了梧桐树，一到秋天就是满地的落叶。一个年纪轻轻的道童正在
打扫。东面传来阵阵桃香，往南是滴水檐。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"zixiao",
		"south" : __DIR__"dishuiyan",
                "east": __DIR__"shanlu1",
                "eastdown" : __DIR__"tyroad1",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/daotong" : 2]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

