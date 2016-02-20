//Cracked by Roath
// Room: /d/mingjiao/daguangchang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "大广场");
	set("long", @LONG
此处乃明教大广场，二里方圆的空旷平地，下铺青砖，上盖蓝天，山
风吹过，顿生满腔豪气。广场中央，青石砌成一方大平台，二十来丈的旗
杆高耸入云，焰一样的圣火大旗(daqi)在烈日下闪闪耀目，随风呼呼做响。
龙、狮、鹰、蝠四王殿环绕其周，更显明光明顶雄雄气势。
LONG
);
	set("item_desc",([	
		"daqi" : "旗上绣一血色火焰，随风闪耀，仿佛有了生命一般。\n",
	]));
	set("exits", ([ /* sizeof() == 6 */
  "northup" : __DIR__"shmen",
  "northwest" : __DIR__"longw",
  "southdown" : __DIR__"shijie77",
  "southeast" : __DIR__"fuw",
  "southwest" : __DIR__"yingw",
  "northeast" : __DIR__"shiw",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
