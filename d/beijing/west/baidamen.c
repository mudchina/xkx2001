//Cracked by Roath
// Room: /d/beijing/west/baidamen.c

inherit ROOM;

void create()
{
	set("short", "白府大门");
	set("long", @LONG
这是杨柳胡同里的一所大宅子，听说最近被一帮云南
客商买下了，日常进出的都是操云南口音的人。现在大门
紧闭，外面挂着两盏白色灯笼，里面隐约传来哭声。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"baiqianyuan",
  "south" : __DIR__"yangliu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
