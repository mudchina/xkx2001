//Cracked by Roath
// Room: /d/dali/dalicheng15.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"马厩"NOR);
        set("long", @LONG
这是军营边上的马厩，常年供应新鲜草料。据说此地民风淳朴，客人只要带
马来，马夫们就会把马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净。
一直伺候到客人离城上路。马厩中堆放著几堆草料，正中有一口泔槽。
LONG);
	set("objects", ([
		"/clone/obj/car" : 2,
		"/d/shaolin/npc/ma-fu" : 1,
		"/clone/horse/xiaoma" : 2,
		"/clone/horse/huangma" : 1,
		"/clone/horse/qingma" : 1,
		"/d/shaolin/obj/caoliao" : 2,
		]));
	set("exits", ([
		"east" : __DIR__"dalicheng14",
		]));
	set("cost",1);
	set("no_clean_up", 0);
	set("resource/water",1);
	setup();
	replace_program(ROOM);
}
