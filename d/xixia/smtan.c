//Cracked by Roath
// Room: /d/xixia/smtan.c

inherit ROOM;

void create()
{
	set("short", "王铁口算命摊");
	set("long", @LONG
这是城市里常见的那种算命的摊子，屋里的陈设很简单, 正中间
一张八仙桌上面放着一茶壶和几本算卦用的书, 旁边放着几把供客人
休息的椅子, 王铁口名气很大, 算的卦都很灵验但这会儿不知跑到哪
里去了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dongdajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
