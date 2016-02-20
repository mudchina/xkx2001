//Cracked by Roath
// 鸣弘泉
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "鸣弘泉");
    set("long", @LONG
泉水由高山石涧骤然而下，冲击着一块长三丈，高五尺，形如古
琴的大石。大石在泉水的敲击下发出多种悦耳的声音。闭目静听，仿
若仙音缥缈。泉旁有醉石一块，相传李白游黄山时，在此饮酒听泉，
敞杯尽饮，不知不觉醉到在此石之上。
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"renzipu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
