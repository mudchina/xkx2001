//Cracked by Kafei
// Room: /dali/houshan.c
// AceP

inherit ROOM;

void create()
{
	set("short", "后山");
	set("long", @LONG
你走到了剑湖宫的后面，这里是无量山的后山。一条幽静的小路通往北面山上，
两边是杂草灌木丛。
LONG
	);

	set("exits", ([
		"south"  : __DIR__"jhg",
		"northup"  : __DIR__"yubi",
	]));

	set("cost", 3);
        set("outdoors", "dali");
	setup();
}
