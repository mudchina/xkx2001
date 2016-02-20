//Cracked by Roath
// Room: /d/mingjiao/xiaolu37.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "林中小路");
	set("long", @LONG
此处野草丛杂，道路难辨，四周被高大密集的松树林包围着。仔细听
听，似乎有轰隆轰隆的响声从林中传来。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"milin36",
  "northeast" : __DIR__"shenchu",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
