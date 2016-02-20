//Cracked by Roath
// zixiao.c 紫霄宫
// by Fang
// xQin 11/00

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"紫霄宫大门"NOR);
	set("long", @LONG
你已走到了展旗峰下，眼前展现出一座碧绿琉璃瓦大殿，这便是武当山
最为宏大的宫宇紫霄宫。殿宇依山而筑，高低错落有致。周围古木森森，翠
竹成林，景色清幽。这里是武当师徒的主要活动场所。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"shijie3",
		"southup" : __DIR__"guangchang",
	]));


	set("cost", 1);
	setup();
	replace_program(ROOM);
}

