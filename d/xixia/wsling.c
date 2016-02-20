//Cracked by Roath
// Room: /d/xixia/wsling.c

inherit ROOM;

void create()
{
	set("short", "乌鞘岭");
	set("long", @LONG
乌鞘岭是武威东南的一个险要地段，黑石山上密林重重，时常有野兽出没。
一条官道从山下蜿蜒而过。
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dacaigou",
  "northwest" : __DIR__"weiwu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
