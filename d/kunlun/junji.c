//Cracked by Roath
// Room: /d/mingjiao/junji.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "军机处");
	set("long", @LONG
此处乃明教首领商讨决策之处。西墙下摆一斑斓虎皮宝座，两侧列有
几张紫红木椅。门口站着数名明教卫士。教中首领们常在这里谈到深夜。
因乃最高机密，故常人不得随便进入。
LONG
	);
	set("objects",([
		__DIR__"npc/pengyingyu" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"shijie77",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
