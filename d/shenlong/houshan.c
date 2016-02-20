//Cracked by Roath
// 后山 /d/shenlong/houshan
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "后山");
        set("long", @LONG
这里是后山，人迹罕至，杂草丛生，前面的路越来越小，路上还有什么动
物爬过的痕迹，你越走越害怕，不时回头。突然，你看见草堆中似乎有一个洞，
但是又看不太清楚。
LONG
        );
	set("cost", 5);
        set("outdoors", "shenlong");
        set("exits", ([
		"southup" : __DIR__"fengding",
                "northdown" : __DIR__"luanshi",
        ]));
        set("snaketype", ({"mangshe"}));
        setup();
}

#include "/d/shenlong/snakeroom.h";
