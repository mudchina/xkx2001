//Cracked by Roath
// room: bshantan.c 碧水寒潭

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "碧水寒潭");
        set("long", @LONG
此处只见一个深潭，潭水呈碧绿色。因地处山阴，常年北风刮过，只
到潭边一站，已然寒气逼人。表面潭水早已结成厚冰，只有几个人工凿去
的缺口，望下去碧沉沉地，深不见底。
LONG );

        set("exits", ([
		"east" : __DIR__"shanquan",
        ]));
        set("outdoors", "mingjiao" );
	set("cost", 3);

        setup();
        replace_program(ROOM);
}