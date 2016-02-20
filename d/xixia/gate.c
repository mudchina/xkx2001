//Cracked by Roath
// Room: /d/xixia/gate.c

inherit ROOM;

void create()
{
	set("short", "皇宫大门");
	set("long", @LONG
这里就是西夏皇宫正门，四扇宽阔的朱红大门，上面包着拳头大的
铜钉。门的两边站着两排衣甲鲜明的武士，戒备深严。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"beidajie",
]));
	set("objects", ([
		__DIR__"npc/hgshi" : 4,
	]));
	set("outdoors", "xixia");
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
