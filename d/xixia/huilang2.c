//Cracked by Roath
// Room: /d/xixia/huilang2.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
这是御花园外的回廊，两旁是朱红的廊柱，廊顶是飞檐琉璃瓦，
地上铺着白玉石板。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huilang",
  "north" : __DIR__"garden",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
