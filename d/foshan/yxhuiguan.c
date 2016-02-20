//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "英雄会馆");
        set("long", @LONG
赌场里围着黑压压的一群人，正在掷骰子押大小。
LONG
        );
        set("exits", ([
		"north" : __DIR__"street1",
	]));

	set("objects", ([
		__DIR__"npc/yiming" : 1,
	]));
	set("cost",1);
	setup();
        replace_program(ROOM);
}
