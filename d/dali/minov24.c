//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov24.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
行进在南诏崎岖的山林中。高山耸立，雨林茂密繁盛，树木大都枝杈横生，
给行路带来额外困难。附近山民经常行走才开出这样的道路来，尽管如此，行旅
仍然需要挟带砍刀，随时准备砍除路边树木横出的障碍。
LONG);
	set("exits", ([
		"southwest" : __DIR__"minov23",
		"eastup" : __DIR__"minov25",
		]));
	set("area", "阳宗镇");
	set("cost", 5);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
