//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov39.c

inherit ROOM;

void create()
{
	set("short", "杆栏");
	set("long", @LONG
一间摆夷族的杆栏民居，此间下层没有牛羊，却用竹席围成一个养桑蚕的小
棚屋，有竹架竹盘。楼上传来阵阵纺纱机的梭飞声。
LONG);
	set("objects", ([
		__DIR__"npc/bycannv" : 1,
		]));
	set("exits", ([
		"east" : __DIR__"minov38",
		"up" : __DIR__"minov40",
		]));
	set("area", "步雄部");
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
