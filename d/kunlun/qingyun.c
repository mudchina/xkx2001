//Cracked by Roath
// Room: /d/mingjiao/qingyun.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "青云峰");
	set("long", @LONG
这里就是光明东山麓的一座高峰，因此处地势甚高，终年云雾缭绕，
故名青云峰。北侧一趟石阶通往一个山亭，此处寒意甚重，不宜旧留。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"hst",
  "southeast" : __DIR__"qingshilu1",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
