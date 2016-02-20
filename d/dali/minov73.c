//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov73.c

inherit ROOM;

void create()
{
	set("short", "河西镇");
	set("long", @LONG
此镇正处妃丽湖南，住的是阿藜蛮的休猎部。阿藜蛮属台夷，村民除了耕种
沿湖的田地外，主要以捕鱼为生。临湖风光格外秀丽，北边不远就是渔船出入的
小码头。南边山中有不少野兽，休猎部的男子经常前去狩猎。
LONG);
	set("objects", ([
		__DIR__"npc/tyshang" : 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov74",
		"north" : __DIR__"minov72",
		"west" : __DIR__"minov76",
		]));
	set("area", "妃丽湖");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
