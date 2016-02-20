//Cracked by Roath
// 仙人洞
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "仙人洞");
    set("long", @LONG
石路旁边有一洞。相传“阴暗之夜，洞口若有灯，朗朗如星月”，
故得名仙人洞。前边路旁有一座亭，入胜亭。游客们纷纷在那小歇
及观赏四周境色。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"southdown" : __DIR__"yungu",
	"northup" : __DIR__"xianrenz",	
		 ])
	 );
    setup();
    replace_program(ROOM);
}
