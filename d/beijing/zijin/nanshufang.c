//Cracked by Roath
// Room: /d/beijing/zijincheng/nanshufang.c

inherit ROOM;

void create()
{
	set("short", "南书房");
	set("long", @LONG
文学修养好的词臣在此值班,每天四人,准备皇帝随时咨询,同
时也观察这些人是否可以重用.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nzsfang",
  "east" : __DIR__"jingshifang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
