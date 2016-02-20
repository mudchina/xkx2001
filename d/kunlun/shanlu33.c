//Cracked by Roath
// Room: /d/mingjiao/shanlu33.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
两旁松树并不浓密，然而每棵都各有姿态。有的古态隆重，有的气势
豪迈，有的叶茂干粗，有的位险根奇，各有回味，情趣不同。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ldating",
  "east" : __DIR__"szchang",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
