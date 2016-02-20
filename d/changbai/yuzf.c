//Cracked by Roath
// Room: yuzf.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "玉柱峰");
	set("long", @LONG
这里是长白主峰之一，又名青石峰，东北距白云峰仅里许的路程。此峰
高耸，象一根擎天的玉柱，顶天立地，高不可攀，可谓白云峰之辅弼。此峰
山路崎岖，且冰多路滑，向为入山的最后一到屏障。
LONG	);

	set("exits", ([ 
              "northwest" : __DIR__"lumf",
              "eastdown" : __DIR__"tianchi",
              "northeast" : __DIR__"baiyf",
              "southeast" : __DIR__"tiyf",
        ]));

        set("objects",([
                __DIR__"npc/tian" : 1,
        ]));
	
        set("outdoors", "changbai");

        set("count", random(3)+1);

	setup();
}
