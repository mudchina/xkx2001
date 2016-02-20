//Cracked by Roath
// 北海
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "北海");
    set("long", @LONG
游黄山北海是必来的。这里附近是观日出和日落的好地方。这里
有一客店，让游客可过宿，清晨观日出。北边是清凉台，西边可到排
云亭。
LONG);

    set("exits", ([ /* sizeof() == 5 */
	"west" : __DIR__"paiyun",
	"south" : __DIR__"guangmin",
	"north" : __DIR__"qinglian",
	"southwest" : __DIR__"feilai",
	"southeast" : __DIR__"mengbi",
	"enter" : __DIR__"kedian",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
