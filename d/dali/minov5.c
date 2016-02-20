//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov5.c

inherit ROOM;

void create()
{
	set("short", "石刻经幢");
	set("long", @LONG
此幢为方锥状，七层石雕。高约丈五尺，基座为八角形的磐石，边上刻有莲
花；层与层之间有界石。即是本层之盖檐，又是上层之基石。幢基为圆鼓形，周
雕八龙，两龙为一组，盘柱嘻戏，成“二龙抢宝”之态。
LONG);
	set("objects", ([
		__DIR__"npc/sengren" : 2,
		]));
	set("exits", ([
		"south" : __DIR__"minov4",
		"enter" : __DIR__"tower1",
		]));
	set("area", "大叠水瀑布");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
