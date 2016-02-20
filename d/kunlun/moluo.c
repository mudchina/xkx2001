//Cracked by Roath
// Room: /d/mingjiao/moluo.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "摩罗门");
	set("long", @LONG
一块高大的牌坊耸立于半山的开阔地上，牌坊正中挂一字匾，上书三
个大字“摩罗门”，门旁立一尊五丈来高的摩尼金像。过了此门再向北走
便是响誉武林的明教光明顶。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"shijie51",
  "southwest" : __DIR__"yongdao",
  "southeast" : __DIR__"yongdao2",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
