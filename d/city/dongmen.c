//Cracked by Roath
// Room: /city/dongmen.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", "东门");
        set("long",
"这是东城门，城门正上方刻着“"+YEL"东门"NOR+"”两个楷书大字。城墙上贴着几张官府
"+HIW"告示"NOR+"(gaoshi)。官兵们警惕地注视着过往行人，好不威严。这里车水马龙，到处
都是行人。虽然这里是城门口，但是小贩们也来到这里，不远处，有卖水的、卖
苹果的、橘子香瓜、零食小点，真是要什么有什么。一条笔直的青石板大道向东
西两边延伸。东边是郊外，北面有一片茂盛的青竹林。\n"
        );
        set("outdoors", "city");

        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));
        set("exits", ([
                "east" : "/d/taishan/yidao",
                "north" : "/d/gaibang/ml1",
                "west" : __DIR__"dongdajie3",
                "south" : __DIR__"dongjiao3",
        ]));

        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
                "/clone/npc/zuo" : 1,
        ]));

        set("cost", 1);
        setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n浙江提督\n李克秀\n";
}
int valid_leave(object me, string dir)
{
        if (dir =="west" )
        if(present("guan bing", (environment(me)))
        && me->query_condition("killer") > 0)
                return notify_fail("官兵手中的刀挡住了你的去路。\n");
        return ::valid_leave(me, dir);
}
