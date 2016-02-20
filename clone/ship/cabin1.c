//Cracked by Roath
// cabin1.c

#include <ansi.h>
inherit ROOM;

void create()
{
        string argg;
        int num;

	set("short", "船舱");
	set("long", @LONG
这是一个窄小的舱房，灯火混暗，空气中充塞着一股异味，似乎
是鱼腥味，汗臭味和霉味的大杂烩。舱房一角放着几个大木桶(tong)
和几挂咸鱼干，腊肉干，中间放着几张床。
LONG
	);

	set("item_desc", ([
	    "tong" : "几只装满清水的的木桶。\n",
	]));

	set("resource/water", 1);
	set("objects",([
		"/clone/food/yugan" : 2,
                "/clone/food/larou" : 2,
	]));

        set("sleep_room", 1);
	set("no_fight", 1);

	set("cost", 0);

	setup();

        if( sscanf(__FILE__, "%s%d", argg, num) == 2 )
        set("exits", ([
                "up" : __DIR__"seaboat" + num,
        ]));

        replace_program(ROOM);
}

