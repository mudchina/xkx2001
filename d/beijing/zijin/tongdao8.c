//Cracked by Roath
// Room: /d/beijing/zijincheng/tongdao8.c

inherit ROOM;

void create()
{
	set("short", "通道");
	set("long", @LONG
这是通向出宫的神武门的通道，一侧是数丈高的围
墙，另一侧则是植满花草树木，鸟语花香令人心旷神怡。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yinghuadian",
  "east" : __DIR__"shenwumen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
