//Cracked by Roath
// Room: /d/xixia/xidian.c

inherit ROOM;

void create()
{
	set("short", "西偏殿");
	set("long", @LONG
这里是西偏殿，是皇上上朝是必经之处，朝上议事的时候内侍们就
在这里候着。地板是白玉铺成，四周是白色的帷幄。东面的走廊通向议
事大殿，西面是一条回廊通向御书房和寝宫，北面的墙上悬着历代先皇
的画像，南面是一排落地长窗。几个内侍肃立，鸦雀无声。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yushufang",
  "east" : __DIR__"huilang",
]));
	set("objects", ([
		__DIR__"npc/neishi" : 2,
	]));
	setup();
	replace_program(ROOM);
}
