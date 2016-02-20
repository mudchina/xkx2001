//Cracked by Roath
// Room: /d/beijing/west/caishikou.c

inherit ROOM;

void create()
{
	set("short", "菜市口");
	set("long", @LONG
这是一个相当热闹的十字路口，路口正中有一根高高的十字型
木杆，上面还有斑斑血迹，大凡朝廷处斩犯人，弃尸于市，斩首示
众，都在这里进行。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"guangandajie",
  "north" : __DIR__"xuanwumen",
  "east" : __DIR__"tianqiao1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
