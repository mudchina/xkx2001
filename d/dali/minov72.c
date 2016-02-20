//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov72.c

inherit ROOM;

void create()
{
	set("short", "妃丽湖东");
	set("long", @LONG
你站在妃丽湖的东岸，脚下的土路绕湖东连接南北的村镇。眺望湖中只见轻
舟点点，正是捕鱼的台夷竹筏。路边尽是青青竹林，台夷的竹楼间或出现。正路
向南通往湖西的休猎部，向东南去的岔路直达龙口城。
LONG);
	set("exits", ([
		"northwest" : __DIR__"minov71",
		"southeast" : __DIR__"minov77",
		"south" : __DIR__"minov73",
		]));
	set("area", "妃丽湖");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
