//Cracked by Roath
// Room: /d/beijing/zijincheng/nzsfang.c

inherit ROOM;

void create()
{
	set("short", "内奏事房");
	set("long", @LONG
这里就是内奏事房，是紫禁城中的重地．每天内外臣工所进的
奏章由外奏事处接收交到这里，再从这里进呈给皇上，批复后再交
出．这里看似简朴，实则外松内紧，守备森严．
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yuehuamen",
  "south" : __DIR__"nanshufang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
