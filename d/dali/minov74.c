//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov74.c

inherit ROOM;

void create()
{
	set("short", "妃丽湖南岸");
	set("long", @LONG
这里是休猎部的渔船码头。岸边有台夷村民正在扎制竹筏，一些渔民划着竹
筏下湖捕鱼，新鲜的鱼鳖可以在附近的喜州、龙口等城镇卖出好价钱。
LONG);
	set("objects", ([
		__DIR__"npc/tyfisher" : 1,
		]));
	set("exits", ([
		"southeast" : __DIR__"minov73",
		"southwest" : __DIR__"minov75",
		]));
	set("area", "妃丽湖");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
