//Cracked by Roath
// Room: /d/beijing/east/yumadamen.c

inherit ROOM;

void create()
{
	set("short", "御马圈大门");
	set("long", @LONG
这是紫禁城外御马圈的大门，平常是不开的，只有皇帝驾
临才会大开。平常采办马匹，草料的人都是从偏门进出，寻常
百姓是不能靠近的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"qianyuan",
  "southwest" : "/d/beijing/zijincheng/donghuamen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
