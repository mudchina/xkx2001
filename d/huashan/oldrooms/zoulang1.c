//Cracked by Roath
// Room: zoulang1.c 走廊
// qfy July 7, 1996.

inherit ROOM;

void reset();

void create()
{
    set("short", "走廊");
    set("long", @LONG
走廊东西边连着练功房。南边是华山掌门及男女弟子的休息室，外人
不方便进去。
LONG
    );

    set("exits", ([
	"east" : __DIR__"liangong1",
	"west" : __DIR__"liangong2",
	"south" : __DIR__"zoulang",
	"north" : __DIR__"buwei1",
    ]));

    set("no_clean_up", 0);

	set("cost", 1);
    setup();
    //replace_program(ROOM);
}
