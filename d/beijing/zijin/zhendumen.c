//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "贞度门");
	set("long",  @LONG
从这里向北是太和殿，向南是九孔白玉桥。
LONG
	);

	set("exits", ([
        "north" : __DIR__"youyimen",
        "southeast" : __DIR__"guang2",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
