//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov40.c

inherit ROOM;

void create()
{
	set("short", "杆栏中层");
	set("long", @LONG
这里是杆栏的中层，从楼梯一上来就是祭所。南诏蛮夷大多信奉自己部族特
有的神明，家家户户都居中室设案供奉。中层的其余房间则为寝所。此屋靠窗摆
了一部纺纱机。
LONG);
	set("objects", ([
		__DIR__"npc/byfangsha.c" : 1,
		__DIR__"obj/fangshaji.c" : 1,
		]));
	set("exits", ([
		"down" : __DIR__"minov39",
		]));
	set("area", "步雄部");
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
