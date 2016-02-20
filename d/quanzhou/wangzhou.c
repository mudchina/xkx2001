//Cracked by Roath
// wangzhou.c 望州亭
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "望州亭");
	set("long", @LONG
这里的地势豁然开朗，有三块巨石如三条大蟒伸头出洞，故称「蟒石」。
蟒首向前探望，似乎也在鉴赏下界的美景。石上一亭突兀，如飞来神笔，又称
「飞来亭」。凭栏远望，泉州全景，尽收眼底。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northdown" : __DIR__"ruixiang",
		"southdown" : __DIR__"shanlu4",
	]));

        set("objects", ([ 
                __DIR__"npc/jiarenda" : 1,
        ]));


	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
