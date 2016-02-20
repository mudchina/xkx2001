//Cracked by Roath
// Room: /d/dali/yuxuguan1.c

inherit ROOM;

void create()
{
	set("short", "玉虚观前");
	set("long", @LONG
东面一座庙观，门前匾上写着“玉虚观”三个大字，西边一个碧水荡漾的小
湖，四周绿柳成荫，实乃修心养性的好地方。
LONG);
	set("objects", ([
		__DIR__"npc/daogu" : 2,
		]));
	set("exits", ([
		"south" : __DIR__"minov9",
		"enter" : __DIR__"yuxuguan.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
