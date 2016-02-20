//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov11.c

inherit ROOM;

void create()
{
	set("short", "黑龙潭");
	set("long", @LONG
黑龙潭碧泉如镜，分前后二池，中以一桥相隔，一泉水清，广约半亩，水深
四十余丈，呈黝黑色；一泉水浊，广约一亩，水色微黄。两泉仅隔数步，而水色
徊异，一黑一黄，对比鲜明。似如道家的太极图，游人多感神秘。两池皆围以烟
柳石栏，清水池中游鱼出没，游人围栏管赏，悠然自得。
LONG);
	set("objects", ([
		__DIR__"npc/youke1.c" : 2,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov10",
		"south" : __DIR__"maze1",
		]));
	set("area", "黑龙岭");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
