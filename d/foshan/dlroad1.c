//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "林间道");
        set("long", @LONG
这里是一条林间小道，在树丛中蜿蜒。东面是岭南重镇佛山，
西边通向广西。
LONG
        );
        set("exits", ([
		"east" : __DIR__"wgate",
		"west" : __DIR__"dlroad2",
	]));

	set("objects", ([
		"/d/city/obj/branch" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
