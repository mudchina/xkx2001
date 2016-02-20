//Cracked by Roath
// Room: /d/beijing/west/lingtang.c

inherit ROOM;

void create()
{
	set("short", "灵堂");
	set("long", @LONG
灵堂正中一张桌子上有一座灵座，上面有一个灵牌。当中挂着灵
幔，后面有个棺材。旁边桌子上点着八根极粗的蓝色蜡烛，旁边挂着
几条挽联，树着一根招魂幡子。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"baihoutang",
  "south" : __DIR__"baiqianyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
