//Cracked by Roath
// 白驼改版
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
一条白砖砌墙的长廊，一直往西边延伸过去。这里隐隐可以听到东
边传来阵阵歌舞声，西边却是一片寂静。
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"dating",
	    "west" : __DIR__"changlang2",
	]));
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
