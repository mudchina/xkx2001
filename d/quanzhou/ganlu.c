//Cracked by Roath
// ganlu.c 甘露戒坛
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "甘露戒坛");
	set("long", @LONG
从大殿后门出来，便是重檐八角攒尖式的戒坛，是佛教徒受戒剃度之处。
坛分五级，最高层中奉木雕的卢舍那坐佛，所祀佛像还有释加牟尼佛、阿弥陀
佛、千手千眼观音佛等。坛座环列「护三皈」和「护五戒」诸神神主牌位六十
四座，气氛庄严。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northup" : __DIR__"cangjing",
		"south" : __DIR__"yuetai",
	]));

        set("objects", ([ 
		__DIR__"npc/huijin" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
