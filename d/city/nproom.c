//Cracked by Roath
// North teampig room.c 
// Written by Xiang Tu <tu@uwalpha.uwinnipeg.ca>
// Ssy




inherit F_CLEAN_UP;
//inherit ROOM;

#include "teampig.h"

void create()
{
	set("short", "集体拱猪房");
	set("long", @LONG
	这是一间专门为集体拱猪而设计的拱猪房。房间里面灯火通明，仿佛永
远准备着为拱猪狂们服务似的。房间的中心放着一张用百年老松树木材特制的拱
猪桌(table)，周围放着四把楠木靠背椅。桌子上摆着一本记分簿(scoreboard)，
北边的墙上贴着一张纸(paper)。
        请注意，集体拱猪将对家的成绩加起来计算总分，因此配合很重要。
LONG
	);
	set("pigging", 1);

	set("item_desc", ([
		"table" : (: look_table :),
		"scoreboard" : (: look_scoreboard :),
		"paper" : "请务必读 help pig_cmds 和 help pig_rules。\n",
	]));

	set("exits", ([
		"south": "/d/city/duchang2",
	]));

	set("no_fight", "1");

	setup();
}

