//Cracked by Roath
// 山洪瀑布
// qfy 7/7/1996

inherit ROOM;

void create()
{
        set("short", "山洪瀑布");
        set("long", @LONG
转过一个山峡，水声震耳欲聋，只见山峰间一条大白龙似的瀑布奔泻
而下，冲入一条溪流，奔胜雷鸣，湍急异常，水中挟著树枝石块，转眼便
流得不知去向。溪流(river)的中心有一块巨石(stone)。水花飞溅，四顾
水气蒙蒙，蔚为奇观。那山洪势道猛烈，令人颇有惧意，还是别乱来的好。
LONG
        );
        
        set("exits", ([ /* sizeof() == 1 */
                "southwest":__DIR__"shaluo",
        ]));

        set("item_desc",([
            "stone" : "一块巨大的岩石，正慢慢地被山洪淹盖吞噬。\n",
            "river" : "山水由瀑布冲入溪流，所以异常湍急。\n",
        ]));
        
        set("no_clean_up", 0);
        set("outdoors", "huashan" );

        set("cost", 4);
        setup();
}

void init()
{
        object me = this_player();

        if ( interactive(me) && me->query("huashan/job_pending") ) {
                me->set_temp("hz_job/shanhong", 1);
        }

        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me = this_player();

        if ( !arg || arg != "stone" )
             return notify_fail( "什么？\n");

	if (me->is_busy())
	     return notify_fail("你正忙着呢！\n");	

        message_vision("$N纵身往大石上跳去。\n", me);

        if ( me->query_skill("dodge",1) <= 20 ) {
             message_vision("$N双足一入水，山洪便冲得他左摇右幌，难以站稳。一会儿便发出\n", me);
             message_vision("一声惨嚎，被山洪冲得无影无踪了。\n", me);
             me->receive_wound("qi", me->query("max_qi")+100, "被山洪淹死了");
        }

        if ( me->query_skill("dodge",1) > 20 && me->query_skill("dodge",1) <= 30 ) {
             message_vision("$N双足一入水，山洪便冲得他左摇右幌，难以站稳。只好勉力提气\n", me);
             message_vision("，回身跳向岸边。\n", me);
             me->unconcious();
        }

        if ( me->query_skill("dodge",1) > 30 && me->query_skill("dodge",1) <= 40 ) {
             message_vision("$N双足一入水，便被山洪冲得左摇右幌，难以站稳。只好勉力提气\n", me);
             message_vision("，回身跳向岸边。$N看起来十分疲倦，该好好休息了。\n", me);
             me->receive_damage("qi", 100, "体力透支过度死了");
        }
        
        if ( me->query_skill("dodge",1) > 40 && me->query_skill("dodge",1) <= 50 ) {
             message_vision("$N双足一入水，便打桩站稳。但不一会儿便感到面红心跳，气喘嘘\n", me);
             message_vision("嘘。只好提气跃回岸上。\n", me);
        }

        if ( me->query_skill("dodge",1) > 50 ) {
             me->move(__DIR__"dashi");
             message("vision", me->name() + "纵身由岸上跳了过来。\n",environment(me), ({me}) );
        }

        return 1;
} 
