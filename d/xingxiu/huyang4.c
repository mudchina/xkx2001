//Cracked by Roath
// huyang road
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "胡杨林");
	set("long", @LONG
道路两边疏疏落落地生长着一片胡杨木，往东越渐茂盛，西去
路上渐渐荒凉，远远可见两座白沙堆积成的山丘。
LONG
	);

	set("exits", ([
		"east" : __DIR__"huyang3",
		"west" : __DIR__"btshan",
	]));
	set("outdoors","xingxiu");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

