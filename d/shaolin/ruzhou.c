//Cracked by Roath
// Room: /d/shaolin/ruzhou.c

inherit ROOM;

void create()
{
	set("short", "汝州城");
	set("long", @LONG
汝州城是本府的大城，立来是兵家必争之地。故州治在此驻
扎重兵，盘查南来北往的行人，并负责翦灭附近山上的草寇。城
内一队队官兵来来去去，一派森严气象。再折向西，就是五岳之
一的嵩山。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  "/d/city/npc/wujiang" : 1,
  "/d/city/npc/bing" : 3,
]));
	set("cost", 1);
	set("outdoors", "shaolin");
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : "/d/beijing/yidao1",
  "west" : __DIR__"shijie1",
  "south" : __DIR__"yidao3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
