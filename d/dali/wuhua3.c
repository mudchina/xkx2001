//Cracked by Roath
// Room: /d/dali/wuhua3.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一条长长的走廊，通向各个客人的寝室。到了二楼，毛毡已经换成纯白，
两侧木壁上或刻有花鸟鱼虫，或挂了些许时人的字画，每隔七八步，就有一处香
台，缕缕青烟从铜鹤嘴里游出，闻之精神一振。
LONG);
	set("exits", ([
		"west" : __DIR__"wuhua8.c",
		"down" : __DIR__"wuhua2.c",
		"east" : __DIR__"wuhua6.c",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
