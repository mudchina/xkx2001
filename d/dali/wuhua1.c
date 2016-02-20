//Cracked by Roath
// Room: /d/dali/wuhua1.c

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这里是五华楼的前大厅，异常宽敞明亮，足有一里见方，全是云石铺地，黑
白相间，足足可以容纳二、三千人。时时可见锦衣侍者手托美食来回行走。
LONG);
	set("objects", ([
		__DIR__"npc/waiter" : 3,
		]));
	set("exits", ([
		"north" : __DIR__"wuhua10.c",
		"west" : __DIR__"wuhua2.c",
		"out" : __DIR__"wuhua.c",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
