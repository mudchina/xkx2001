//Cracked by Roath
// Room: /d/dali/senlin.c

inherit ROOM;

void create()
{
	set("short", "大森林");
	set("long", @LONG
此去向北是无量山区和大森林，这里已经林木茂密人迹罕至了，南面是大理
到中原的官道大路。
LONG);
	set("exits", ([
		"southdown" : __DIR__"minov15",
		"north" : __DIR__"senlin1",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
