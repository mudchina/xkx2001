//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov6.c

inherit ROOM;

void create()
{
	set("short", "清溪三潭");
	set("long", @LONG
清溪三潭，又名翠盆水，隐藏在苍山马龙峰与圣应峰之间幽深的峡谷中。山
泉岩根涌出，喷珠泻玉，岩溪汇池，壮若大盆，分三叠，水清石丽，翠碧交加，
故俗称清碧溪。
LONG);
	set("exits", ([
		"northup" : __DIR__"minov1",
		"southdown" : __DIR__"minov8",
		"eastup" : __DIR__"minov7",
		]));
	set("area", "大叠水瀑布");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
