//Cracked by Roath
// Room: /d/xixia/dongmen.c

inherit ROOM;

void create()
{
	set("short", "灵州东门");
	set("long", @LONG
这是东城门，城门正上方刻着几个西夏文字。城墙
上贴着几张官府告示。一条路往东北通向城外一片松林。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"luorilin",
  "west" : __DIR__"dongdajie",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
