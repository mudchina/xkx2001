//Cracked by Roath
// Room: erld.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "二龙斗");
	set("long", @LONG
这里已是深山之中，四处都是厚厚的积雪和高大的树木。雪地上偶尔能
看到一些动物留下的脚印，深浅不一，远处山林里传出一阵阵猛兽的吼声，
看来此处经常有猛兽出没，还是快点离开的好。
LONG	);
	set("exits", ([ 
              "northdown" : __DIR__"jiaxz",
              "southeast" : __DIR__"banlp",
        ]));
	
        set("outdoors", "changbai");
        set("cost", 3);

        set("count", random(3)+1);

	setup();
}
