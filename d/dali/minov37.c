//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov37.c

inherit ROOM;

void create()
{
	set("short", "养蚕房");
	set("long", @LONG
这是一间摆夷族的杆栏民居，此间下层却没有牛羊，三面用竹席围住，似一
个棚屋，中置数座竹架竹盘，饲养着一些桑蚕。一位摆夷姑娘正在用新鲜的桑叶
喂养桑蚕。
LONG);
	set("objects", ([
		__DIR__"npc/bycannv" : 1,
		]));
	set("exits", ([
		"west" : __DIR__"minov34",
		]));
	set("area", "步雄部");
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
