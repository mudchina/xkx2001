//Cracked by Roath
// Ryu, 5/10/97

inherit ROOM;
string look_cliff();
void create()
{
	set("short", "天池");
	set("long", @LONG
灵山上白雪皑皑，冰川纵横，铺银盖玉。大大小小的冰面湖、
冰洞，广为分布。高悬在冰峰峡谷里的天池，恰似一面巨大的银镜，
溢彩流光，闪烁耀眼。迷人的山色湖光，山风习习，空气清凉如水。 
山前的峭壁(cliff)上刻有几行字迹，入石三分。
LONG
	);
	set("exits", ([
                "westup" : __DIR__"shanluan",
                "southdown" : __DIR__"guozi",
        ]));
	set("item_desc",([
                "cliff"         :       (: look_cliff :),
        ]));
	set("cost", 7);
	set("bing_can", 7);
	set("resource/water",1);
	set("outdoors", "tianshan");

	setup();
}
string look_cliff()
{
        return
        "\n"
        "              冰    雪    四    三\n\n"
        "              池    岭    壁    峰\n\n"
        "              耀    界    横    并\n\n"
        "      长      日    天    陈    起\n"
	"      春                          \n"
	"      真      俗    人    绕    插\n"
	"      人                          \n"
	"      丘      难    不    涧    云\n"
	"      处                          \n"
	"      机      观    到    盘    寒\n";
}
void init()
{
        add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}
int do_climb(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return notify_fail("你要跟哪儿爬？\n");

	if (me->query_busy())
                return notify_fail("你正忙着呢。\n");

        if( arg=="cliff")
        {
	message_vision("$N手脚并用顺着峭壁往峰顶上爬去。\n", me);
	me->start_busy(5);

	if (random(me->query_skill("dodge")) < 50){
	remove_call_out("drop_down");
        call_out("drop_down", 5, me);
	return 1;
	}
	
	message("vision", me->name()+"一会儿便消失在云气里了。\n", environment(me), ({me}) );
	remove_call_out("climb_up");
	call_out("climb_up", 5, me);
	return 1;
	}
}
void drop_down(object me)
{
	tell_object(me, "突然你一失手，从峭壁上掉了下来，屁股重重地摔在地上。\n");
        message("vision", me->name() + "突然一失手，从峭壁上掉了小来，屁股重重地摔在地上。\n",
                             environment(me), ({me}) );
	me->receive_damage("qi", 50, "从峭壁上掉了下来摔死了");
        me->receive_wound("qi",  50, "从峭壁上了下来摔死了");
}
void climb_up(object me)
{
	tell_object(me, "你深吸一口气纵身跃起，几个起落间，已窜上了峰顶。\n");
	me->add("jingli", -50);
	me->move(__DIR__"lingshan");
        message("vision", me->name() + "气喘吁吁地从下面爬了上来。\n",
                             environment(me), ({me}) );
}

