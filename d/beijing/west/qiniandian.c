//Cracked by Roath
// Room: /d/beijing/west/qiniandian.c

inherit ROOM;

void create()
{
	set("short", "祈年殿");
	set("long", @LONG
这是一座三重檐的圆形大殿，兰色琉璃瓦顶，全砖木结
构，没有大梁长檩，全靠二十八根木柱和三十六根枋桷支撑。
值。大殿中央四根“龙井柱”代表一年四季，中层十二根柱子
象征十二个月，外圈十二根柱象征十二个时辰，内外檐柱十二
根代表二十四个节气。设计精巧，寓意奇特。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"zaichufang1",
  "south" : __DIR__"danbiqiao",
  "northdown" : __DIR__"shibanlu4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
