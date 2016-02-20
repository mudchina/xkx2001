//Cracked by Roath
// Room: /d/xixia/nanmen.c

inherit ROOM;

void create()
{
        set("short", "灵州南门");
        set("long", @LONG
这是灵州的南城门，城门正上方刻得有几个西夏文字。城墙上贴着几张官府
告示。一条大路往南通向黄羊滩。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nandajie",
  "south" : __DIR__"hytan",
]));
        set("objects", ([
                __DIR__"npc/xiaowei": 1,
                __DIR__"npc/xxbing": 2,
]));

        set("no_clean_up", 0);
        set("outdoors", "xixia");

        setup();
}
int valid_leave(object me, string dir)
{
        if (dir =="north" )
        if(present("guan bing", (environment(me)))
        && me->query_condition("xakiller") > 0)
                return notify_fail("西夏兵手中的长枪挡住了你的去路。\n");
        return ::valid_leave(me, dir);
}
