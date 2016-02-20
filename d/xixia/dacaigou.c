//Cracked by Roath
// Room: /d/xixia/dacaigou.c

inherit ROOM;

void create()
{
	set("short", "打柴沟");
	set("long", @LONG
打柴沟地势不如乌鞘岭那样险要，比较平坦，官道两边全是密林，
时常有樵夫砍柴的声音从林中传出。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qiaofu" : 1,
]));
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wsling",
  "southwest" : "/d/qilian/gulang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
