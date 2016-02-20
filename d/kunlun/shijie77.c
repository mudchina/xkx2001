//Cracked by Roath
// Room: /d/mingjiao/shijie77.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
此处石阶连接着乾坤坊和大广场。向北望去，可隐约看到几座大殿。
石阶虽不很长，但人来人往甚是热闹。由此往上可到大广场，东西各与军
机处和执法处相连。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"daguangchang",
  "southdown" : __DIR__"qiankun",
  "northeast" : __DIR__"zhifa",
  "northwest" : __DIR__"junji",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
