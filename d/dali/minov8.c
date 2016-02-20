//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov8.c

inherit ROOM;

void create()
{
	set("short", "林荫小道");
	set("long", @LONG
沿林荫小道曲折前行约四十公尺，只见古树林立，浓荫蔽天，一方清泉嵌于
其间，底铺青石，泉水明澈，常有人掷钱币于池中，观其缓缓旋落，阳光从树顶
筛下，池底银光闪烁，倍感泉水清冽。池边距地面约二三尺的地方有一粗可合抱
的树干，伸过泉上，池旁建有小亭，小坐生凉，十分清幽。
LONG);
	set("objects", ([
		"/d/city/npc/maque" : 2,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov9",
		"northup" : __DIR__"minov6",
		"south" : __DIR__"minov10",
		]));
	set("area", "黑龙岭");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
