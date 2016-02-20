//Cracked by Roath
// Room: /d/dali/tower4.c

inherit ROOM;

void create()
{
	set("short", "第四层");
	set("long", @LONG
雕有八坐佛，四隅略大，其中东、南两佛面目驳落，容不可辨。坐佛莲花座
皆有梵文佛经。经文尾处刻有“慈济和尚--大理人”字样。
LONG);
	set("exits", ([
		"up" : __DIR__"tower5",
		"down" : __DIR__"tower3",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
