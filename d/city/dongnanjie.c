//Cracked by Roath
// Room: /city/dongnanjie.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
        set("short", "东南街");
        set("long", @LONG
这条街是用碎石子铺成的，好像没有什么富贵人家。巡捕、衙役也很少到这
来，只有几个卖花的小女孩叫嚷着走来走去。这里没有南北集市那样热闹，不远
的东面好像人头攒动，拿斗的、拿布袋的，正围着一家铺子大声吆喝。南边是一
些卖水果的摊子，北边是新开的小宝斋。
LONG
        );
        set("outdoors", "city");

        set("exits", ([
                "east" : __DIR__"xiangnanjie",
                "west" : __DIR__"nandajie2",
                "north" : __DIR__"xiaobaozhai",
                "south" : __DIR__"guopintan",
        ]));

        set("objects", ([
                __DIR__"npc/girl" : 2,
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
