//Cracked by Roath
// Shan: 96/07/09

inherit ROOM;

void create()
{
        set("short", "草棚");
        set("long", @LONG
这是峨嵋山脚下一个简单的草棚，地上堆著些上货。很多上山的游客都在
这里买些上山用品。草棚后有个口井，西面是一间马厩。
LONG
        );
        set("exits", ([
	  "east" : __DIR__"shijie1",
	  "west" : __DIR__"majiu1",
        ]));

        set("objects", ([
                __DIR__"npc/seller": 1 ]) );

        set("no_clean_up", 0);
	set("outdoors", "emei");

        setup();
}

void init()
{
        add_action("do_move", "move");
}

int do_move(string arg)
{
        object me;
        mapping fam;

        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="mugai" || arg=="lid" )
        {
		if(me->query("rided"))
                return notify_fail("你骑着马，不能这麽干！\n");
                if( (fam = me->query("family")) && fam["family_name"] == "丐帮" )
                {
                        message_vision("$N移开井上的木盖，只见这口井已经乾涸，下面有个小梯子。\n", me);
                        message("vision",
                                me->name() + "运起丐帮缩骨功，一弯腰往井里钻了下去。\n",
                                environment(me), ({me}) );
                        me->move("/d/gaibang/underem");
                        message("vision",
                                me->name() + "从井里钻了进来。\n",
                                environment(me), ({me}) );
                        return 1;
                }
                else
                        return notify_fail("这么小的井，你钻得进去吗？\n");
        }
}
