//Cracked by Roath
// Room: /d/xixia/yushanfang.c

inherit ROOM;

void create()
{
	set("short", "御膳房");
	set("long", @LONG
这里是膳房，西厢房是两位江南名厨的住处，东厢房是膳房
下手们住的。北面是柴房。院子打扫的很干净，中间有一口水井。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"bingku",
  "north" : __DIR__"chaifang",
  "west" : __DIR__"huilang",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");
	set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

	setup();
	replace_program(ROOM);
}
