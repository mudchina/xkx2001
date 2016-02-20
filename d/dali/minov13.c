//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov13.c

inherit ROOM;

void create()
{
	set("short", "沿池堤岸");
	set("long", @LONG
这里沿湖堤岸遍植白色的素馨花，故又称“银棱河”；而它的一条分支，堤
岸栽种黄色的迎春花，故称“金棱河”，或金汁河。两河同为滇池的出水口，又
称海口。
LONG);
	set("exits", ([
		"westdown" : __DIR__"minov4",
		"eastup" : __DIR__"minov14",
		]));
	set("area", "罗伽甸");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
