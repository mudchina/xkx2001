//Cracked by Roath
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW"象棋棋苑"NOR);
	set("long", @LONG
这里是侠客行象棋棋苑，是一间摆设整齐的房间，大门面对的墙
壁上挂着一副正楷书写的条幅(tiaofu)。西、南、北边的月洞门通往
可供下棋的庭园。
LONG
	);
	set("exits", ([
		"east" : "/d/city/duchang",
		"north" : "/d/city/qiyuan2",
		"south" : "/d/city/qiyuan3",
		"west" : "/d/city/qiyuan4",
	]));
	set("objects", ([
		"/kungfu/class/misc/hezudao" : 1,
	]));
	set("item_desc", ([
		"tiaofu" : 
			"		※※※※※※※※※※※※※		\n"
			"		※※※观棋不语真君子※※※		\n"
			"		※※※起手无回大丈夫※※※		\n"
			"		※※※※※※※※※※※※※		\n\n",
	]));
	set("cost", 1);
    setup();
}
