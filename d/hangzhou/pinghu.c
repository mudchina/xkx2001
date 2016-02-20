//Cracked by Roath
// 平湖秋月
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", HIB"平湖秋月"NOR);
    set("long", @LONG
平湖秋月三面临水，几乎同湖面相平。曾有“万顷湖平长似镜，
四时月好最宜秋”的联句来描写这里秋夜时皓月当空的幽美景色。朝
西北走便是放鹤亭。东北边则是白堤。西边就是孤山。
LONG);
    set("exits", ([ /* sizeof() == 3 */ 
                   "northeast" : __DIR__"baiti", 
                   "northwest" : __DIR__"fanghe", 
                   "west": __DIR__"gushan1",
                ])
       );
	set("cost", 2);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
