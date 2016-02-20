//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov76.c

inherit ROOM;

void create()
{
	set("short", "渔家");
	set("long", @LONG
休猎部专事渔猎，很少蓄养牲畜或耕作。这是一座普通的竹楼，下层通常的
牲畜圈是修补竹筏渔网的工棚，一位台夷妇女正在细心地编织渔网。楼边有一排
木架，挂满开过膛的鱼，正在凉晒鱼干。
LONG);
	set("objects", ([
		__DIR__"npc/tywoman" : 1,
		]));
	set("exits", ([
		"east" : __DIR__"minov73",
		]));
	set("area", "河西镇");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
