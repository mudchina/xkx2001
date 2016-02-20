//Cracked by Roath
// 聚景园
// Dong  11/03/1996.
// nta:  Need to as some npc here.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", HIM"聚景园"NOR);
    set("long", @LONG
漫步园中，只见湖傍遍置垂柳。柳树丛中，种了不少碧桃。东风
送暖之时，这里“杨柳千条拂面丝，绿烟金穗不胜吹”。诗人刘禹锡
的“桃红李白皆夸好，须得垂杨相发挥”形容的恰到好处。东面是清
波门，往东北便是柳浪桥。
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
                   "northeast" : __DIR__"jujing3", 
                   "east" : __DIR__"jujing1", 
                 ])
       );
	set("objects",([
                "/d/taishan/npc/jian-ke" : 1,
        ]));
	set("cost", 1);
    setup();
    replace_program(ROOM);
}
