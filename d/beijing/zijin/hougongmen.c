//Cracked by Roath
inherit ROOM;

void create()
{
    set("short", "后宫门");
	set("long",  @LONG
这里是宁寿全宫的后宫门，由此向北就可以离开宁寿宫。
LONG
	);

	set("exits", ([
        "north" : __DIR__"tongdao7",
        "south" : __DIR__"yihexuan",
	]));
	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
