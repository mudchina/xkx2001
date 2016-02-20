//Cracked by Roath
// Room: /d/mingjiao/mguangchang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "巨木旗广场");
	set("long", @LONG
这处本是一片密林，后有巨木旗弟子开垦而出。看四周，除了一条小
径通往山前，广场还是被充满生命的草木包围着。广场东西两侧各竖着几
根巨木，仔细一看，上面还装着铁钩。
LONG
);

	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shenchu",
  "north" : __DIR__"milin40",
]));
	set("objects",([
		__DIR__"npc/wencangsong" : 1,
	]));

	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
