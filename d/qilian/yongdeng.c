//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "永登");
        set("long", @LONG
这里就是西北的军事重镇永登。一座孤城耸立在茫茫荒野之上。此城
建于汉光武年间，据闻大将军霍去病曾在此练兵三年，后一举平定大西北。
历代而来，这里都有军队长驻。
LONG
        );
        set("exits", ([
                "west" : __DIR__"kedian",
		"east" : "/d/huanghe/huanghe3",
                "north" : __DIR__"gulang",
		"southup" : "/d/xingxiu/xxroad3",
        ]));

	set("objects", ([
		"/d/xingxiu/npc/wujiang" : 1,
		"/d/xingxiu/npc/bing" : 3,
	]));
	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
