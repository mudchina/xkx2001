//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov22.c

inherit ROOM;

void create()
{
	set("short", "杆栏中层");
	set("long", @LONG
这里是杆栏的中层，从楼梯一上来就是祭所。南诏蛮夷大多信奉自己部族特
有的神明，家家户户都居中室设案供奉。中层的其余房间则为寝所。
LONG);
	set("objects", ([
		__DIR__"npc/bykid.c" : 1,
		]));
	set("exits", ([
		"down" : __DIR__"minov21",
		]));
	set("area", "罗伽甸");
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
