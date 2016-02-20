//Cracked by Roath
// Room: /d/xiangyang/liangc2.c

inherit ROOM;

void create()
{
	set("short", "粮仓");
	set("long", @LONG
襄阳本是长江上游的重镇，城中市民繁庶。但近来年年抗敌，原本所积的
财栗已所剩无己。不少兵士正严谨的在这来回巡逻。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -1, "y" : 1 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jicang",
]));

	setup();
	replace_program(ROOM);
}
