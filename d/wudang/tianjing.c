//Cracked by Roath
// tianjing.c 天井
// xQin 11/00

inherit ROOM;

void create()
{
	set("short","天井");
	set("long", @LONG
这里是紫霄宫后院旁的天井，四周十分幽静。只见墙边的一棵大榕树枝
叶十分茂盛，树上不时传来蝉鸟之声。白石小径通向西边的后院。
LONG
	);
	set("outdoors", "wudang");
	set("exits", ([
		"west" : __DIR__"houyuan",
		]));
	
	setup();
	replace_program(ROOM);
	
}