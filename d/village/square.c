//Cracked by Roath
// Room: /d/village/square.c

inherit ROOM;

void create()
{
        set("short", "打谷场");
        set("long", @LONG
这里是村子的中心，一个平坦的广场，每年秋收打谷就在这。广场东角有棵枝
繁叶茂大槐树，平日茶余饭后，村里的男女老少都爱聚在这里谈天说地。角上有几
个大谷堆(gudui)。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                "northwest" : __DIR__"nwroad2",
                "northeast" : __DIR__"majiu",
                "south" : __DIR__"sroad4",
                "east"  : __DIR__"eroad3",
        ]));

        set("objects", ([
                __DIR__"npc/kid": 2,
                "/d/shaolin/obj/caoliao": 2,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "village");

        set("cost", 1);
        setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
        object me;
        mapping fam;

        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="gudui" )
        {
                if(me->query("rided"))
                return notify_fail("你骑着马，不能这么干！\n");
                if( (fam = me->query("family")) && fam["family_name"] == "丐帮" ) 
                {
                        message("vision",
                                me->name() + "运起丐帮缩骨功，一弯腰往谷堆里钻了进去。\n",
                                environment(me), ({me}) );
                        me->move("/d/gaibang/underxc");
                        message("vision",
                                me->name() + "从谷堆里走了进来。\n",
                                environment(me), ({me}) );
                        return 1;
                }
                else 
                        return notify_fail("这么小的洞，你钻得进去吗？\n");
        }
}       
