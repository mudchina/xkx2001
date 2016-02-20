//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "佛山西门");
        set("long", @LONG
这里是佛山镇的西门。岭南以西经由广西可至大理。东面一条东
西向的大街是佛山镇的主要街道。
LONG
        );
        set("exits", ([
		"east" : __DIR__"street0",
		"west" : __DIR__"dlroad1",
	]));

	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
