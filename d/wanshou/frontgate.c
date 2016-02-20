//Cracked by Roath
// /d/wanshou/frontgate.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "万兽山庄");
        set("long", @LONG
前面便是万兽山庄了，山庄大门上雕刻着虎豹狮象猴的图腾，
门上悬着一面和黑底金字的匾额，上书“万兽山庄”四个苍劲有
力的大字。门前一左一右各伏一只猛虎，正目不转睛地盯着你的
一举一动。
LONG
        );
        set("exits", ([
				"north" : __DIR__"qianting",
				"south" : __DIR__"shijie",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();
        replace_program(ROOM);

}
