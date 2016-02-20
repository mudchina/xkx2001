//Cracked by Roath
// Room: /d/beijing/west/huichuntang.c

inherit ROOM;

void create()
{
	set("short", "回春堂");
	set("long", @LONG
这是京城一家老字号的药店，几只比人还高的药柜靠墙而立。几个伙计
站在梯子上取放药材，一名伙计正在一旁切割碾细药材，打包放好。据说这
里的跌打伤药非常灵验。一名小伙计站在柜台后招呼着顾客。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"baozhu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
