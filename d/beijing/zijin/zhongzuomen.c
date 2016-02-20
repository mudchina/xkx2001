//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "中左门");
	set("long",  @LONG
从这里向北是后右门，向南是太和殿前的大广场。许多太监和侍
卫从这匆匆而过。
LONG
	);

	set("exits", ([
        "north" : __DIR__"xiaodao2",
        "southwest" : __DIR__"guang1"
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
