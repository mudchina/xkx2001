//Cracked by Roath
// Room: /d/dali/wangfu9.c

inherit ROOM;

void create()
{
        set("short", "厅房");
        set("long", @LONG
只见正门五间，上面瓦泥鳅脊；那门栏窗隔俱是细雕新鲜花样，并无朱粉涂
饰，一色水磨群墙；下面白石台阶，凿成西番草花样。左右一望，皆雪白粉墙，
下面虎皮石，随势砌去，果然不落富丽俗套。
LONG);
	set("exits", ([
		"northeast" : __DIR__"wangfu13",
		"southeast" : __DIR__"wangfu8",
		"north" : __DIR__"wangfu12",
		"south" : __DIR__"wangfuroad2",
		"east" : __DIR__"wangfu11.c",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
