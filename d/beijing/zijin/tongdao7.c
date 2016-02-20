//Cracked by Roath
// Room: /d/beijing/zijincheng/tongdao7.c

inherit ROOM;

void create()
{
	set("short", "通道");
	set("long", @LONG
这是通向出宫的神武门的通道，一侧是数丈高的围墙，另一侧则
是植满花草树木，鸟语花香令人心旷神怡。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shenwumen",
  "south" : __DIR__"hougongmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
