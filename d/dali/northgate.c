//Cracked by Roath
// Room: /d/dali/northgate.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"北门"NOR);
	set("long", @LONG
阳苜咩城，或简称苜咩城，是大理国的都城。自南诏于初创，历经陈氏“长
大和国”、赵氏“大天兴国”、杨氏“大义宁国”诸代而至当今的段氏的“大理
国”，均以此城为都。此处乃是北城门，以梅溪为护河，城墙建在溪南，由石块
和土垒成，高二丈五，厚达二丈，门上有重楼，驻有了哨。青石官道从城里直向
北延伸，另有一条黄土大路向西通去。
LONG);
	set("objects", ([
		__DIR__"npc/dalishibing" : 3,
		__DIR__"npc/wujiang" : 1,
		]));
	set("exits", ([
		"northeast" : __DIR__"chhill",
		"westup" : __DIR__"shanlu",
		"north" : __DIR__"gaten1",
		"south" : __DIR__"dalicheng1",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
