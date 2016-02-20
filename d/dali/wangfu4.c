//Cracked by Roath
// Room: /d/dali/wangfu4.c

inherit ROOM;

void create()
{
	set("short", "大殿");
	set("long", @LONG
这是一座三重檐的圆形大殿，兰色琉璃瓦顶，全砖木结构，没有大梁长檩，
全靠二十八根木柱和三十六根枋桷支撑。大殿中央四根“龙井柱”代表一年四季，
中层十二根柱子象征十二个月，外圈十二根柱象征十二个时辰，内外檐柱十二根
代表二十四个节气。设计精巧，寓意奇特。
LONG);
	set("objects", ([
		__DIR__"npc/weishi3" : 2,
		"/kungfu/class/dali/weishitou" : 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"wangfuroad1.c",
		"south" : __DIR__"wangfu3.c",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
