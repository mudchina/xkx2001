//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov59.c

inherit ROOM;

void create()
{
	set("short", "山林");
	set("long", @LONG
你走在一片茂密的山林中，时而有飞禽走兽横过，百鸟在林间飞鸣，南边乌
夷部落里的村民经常来此狩猎。山林北面不远传来隆隆水声，看来有大河流过，
南边是一片低洼的河谷盆地，颇有人烟。
LONG);
	set("objects", ([
		__DIR__"npc/wylieren" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"minov60",
		"southdown" : __DIR__"minov58",
		]));
	set("area", "葛鲁城");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
