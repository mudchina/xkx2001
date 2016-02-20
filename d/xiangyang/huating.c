//Cracked by Roath
// Room: /d/xiangyang/huating.c

inherit ROOM;

void create()
{
	set("short", "花厅");
	set("long", @LONG
一到战事小胜、侥退敌军时，此处便大摆庆功宴，相互邀功，以图一时之
快。这时并无席宴，有一些小厮们正在打理清扫，以备下回所需。南边有一
座照壁，自古流传下来，为一时之奇景。远与花厅一映，更增特色。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ysting",
  "south" : __DIR__"lvying",
]));

	setup();
	replace_program(ROOM);
}
