//Cracked by Roath
// 云台
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "云台");
    set("long", @LONG
出了文殊院往右过象石，便来到云台。站在云台上眺望云海，巍巍
壮观，美不胜收。时而云卷浪激，惊涛拍岸；时而云消雾散，群峰比美。
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"left" : __DIR__"wenshu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
