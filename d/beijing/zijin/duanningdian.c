//Cracked by Roath
// Room: /d/beijing/zijincheng/duanningdian.c

inherit ROOM;

void create()
{
	set("short", "端凝殿");
	set("long", @LONG
这是存放皇帝的冠，袍，带，履的地方。房间里放满了各种大小
、不同颜色的柜子。柜门上写着一个个标签。地上已经积了一层厚厚
的的灰尘，显然很久没人来过了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"rijingmen",
  "north" : __DIR__"yuchafang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
