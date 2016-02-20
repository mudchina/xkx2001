//Cracked by Roath
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "荣宝斋");
    set("long", @LONG
这里是京城里最有名的字画店。店主人刘老板见多识广，收藏的字画也颇不
少，除了当世的名家手笔，还时常有些古字画的珍品。这里也兼卖一些笔墨纸砚
之类的。
LONG
	);

    set("exits", ([
	"out" : __DIR__"changanjie_e",
    ]));

    set("objects", ([
	__DIR__"npc/liulaoban":1,
    ]));

    setup();
}
