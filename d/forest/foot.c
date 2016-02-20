//Cracked by Roath
// Jay 7/11/96

#include "tree.h"

void create()
{
    int i;
        set("short", "山脚");
        set("long", @LONG
这里是摩天崖的山脚。摩天崖高耸如云，石壁上光秃秃的，没有
道路。一条铁链(lian)悬在空中。
LONG
        );

        set("exits", ([
                "east" : __DIR__"gate",
		"up" : __DIR__"middle",
        ]));

        set("item_desc", ([
		"lian" : "可惜，有人已经把它砍断，不能用了。\n",
	]));

	set("cost", 1);
	set("outdoors", "city");
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "up" && !wizardp(me))
                return notify_fail("摩天崖非比寻常，即使你轻功再好，也难以登上。\n");
        return 1;
}

