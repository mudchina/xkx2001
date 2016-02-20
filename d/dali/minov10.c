//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov10.c

inherit ROOM;

void create()
{
	set("short", "黑龙岭");
	set("long", @LONG
黑龙岭上有红梅二株，干已剥蚀贻尽，仅存枯皮，古质斑斓，横卧于地，离
奇乔异，如骄龙，如横峰，而花朵攒躜，又如锦片，如火球，清芳袭人，不知植
自何代，相传以为唐梅，疑或然也。西南面就是黑龙潭。
LONG);
	set("exits", ([
		"northwest" : __DIR__"minov12",
		"southeast" : __DIR__"minov11",
		"north" : __DIR__"minov8",
		]));
	set("area", "黑龙岭");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
