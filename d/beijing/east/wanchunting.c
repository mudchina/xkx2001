//Cracked by Roath
// Room: /d/beijing/east/wanchunting.c

inherit ROOM;

void create()
{
	set("short", "万春亭");
	set("long", @LONG
这里是全北京的最高点。向南可以俯瞰整个紫禁城，向北可
以看到钟楼和鼓楼。亭子里有一张石桌，几张石凳，供游人休息。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"shandao4",
  "southdown" : __DIR__"shandao3",
  "northdown" : __DIR__"shandao1",
  "southwest" : __DIR__"shandao2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
