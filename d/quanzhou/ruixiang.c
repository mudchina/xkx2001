//Cracked by Roath
// ruixiang.c 瑞象岩
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "瑞象岩");
	set("long", @LONG
这是座落在半山腰的小峡谷中的一块石坪。登上此处，即可见一座漂亮的
仿木石室。石室后高耸的大岩石叫作「天柱峰」。古时一位巧匠将其雕成「释
迦牟尼」瑞象，作立状，神像庄严大方，维妙维肖。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northdown" : __DIR__"shanlu3",
		"southup" : __DIR__"wangzhou",
	]));

        set("objects", ([
                "/clone/beast/smonkey" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 4);
        setup();
	replace_program(ROOM);
}
