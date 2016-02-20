//Cracked by Roath
// Room: /d/mingjiao/nanxiu.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "男寝室");
	set("long", @LONG
四周并无什么陈设，只有七八张松木大床，两、三个明教弟子正在休
息。每张松木床边都有一只大木箱，里面装有弟子们更换的衣裤。屋子中
间有一大木头桌，上置一青铜烛台。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zoulang46",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
