//Cracked by Roath
// Room: banlp.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "半拉瓢");
	set("long", @LONG
穿过茂密的森林，眼前出现一座高耸的山峰，看来要继续向前，必须翻
过这座山才行。这座山形似半个瓢，下面宽大，愈向上愈窄，山峰处更是细
窄高耸，好似瓢把一样。
LONG	);
	set("exits", ([ 
              "northwest" : __DIR__"erld",
              "northeast" : __DIR__"pubu",
        ]));

        set("objects",([
		__DIR__"npc/cb_fox" : 1,
	]));
	
        set("outdoors", "changbai");
        set("cost", 3);

        set("count", random(3)+1);

	setup();
}
