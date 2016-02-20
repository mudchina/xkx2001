//Cracked by Roath
// 立马亭
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "立马亭");
    set("long", @LONG
在朱砂峰畔的树叶中有一座亭。亭对岸的立马峰上有“立马空东
海，登高望太平”十个石刻大字，每个字有二丈八尺，刻在这上无攀
缘，下临深谷的峭壁之上实为不易。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"southdown" : __DIR__"ciguang",
	"northup" : __DIR__"banshan",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
