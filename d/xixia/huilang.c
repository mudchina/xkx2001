//Cracked by Roath
// Room: /d/xixia/huilang.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
这是连接前殿和后宫的回廊，两旁是朱红的廊柱，廊顶是飞檐琉璃
瓦，地上铺着白玉石板。西面通向西偏殿，北面打了个弯向东折向后宫。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ysdian",
  "west" : __DIR__"xidian",
  "north" : __DIR__"huilang2",
  "east" : __DIR__"yushanfang",
]));
	set("objects", ([
		__DIR__"npc/shiwei" : 4,
	]));
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
