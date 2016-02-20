//Cracked by Roath
// 云舫
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "云舫");
    set("long", @LONG
沿着石头大仙所指的草径，不一会二你来到这别具天地的云舫。
这里林木葱茏，环境幽雅，终年碧水长流，四季花开不断。四周奇峰
环列，披云挂霞，如拥蜃楼。传闻古时一些方外僧侣来到这里，他们
用树皮和茅草搭起庵棚，因此得名“皮蓬”。後来有个和尚曾在这住
了三十年，因为住的庵棚长年与白云为伍，恰似一夜方舟泛槎云上，
所以皮蓬又叫“云舫”。
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"xianrenz",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
