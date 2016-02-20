//Cracked by Roath
// Room: /d/xiangyang/gulou.c

inherit ROOM;

string look_drum();

void create()
{
	set("short", "鼓楼");
	set("long", @LONG
这里就是襄阳城用来击鼓集兵及示警的鼓楼。直入眼帘的便是一只红色的大
鼓(drum)。鼓旁站着几个士兵守卫，你还是不要乱来。鼓楼四面无壁，阵阵凉风
吹来。向北俯视，可以看到襄阳粮仓的内部。南瞰则可见到兵营内士兵在操练与
巡逻。东望是一座比鼓楼低一点的更楼。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"guloud",
]));
	set("outdoors", "xiangyang");
	set("item_desc",([
		"drum"		:	(: look_drum :),
	]));
	setup();
}

void init()
{
	add_action("do_hit", "hit");
	add_action("do_out", "out");
}

int do_hit(string arg)
{
	object me, killer;

	me = this_player();
	if ( !arg || ( arg != "drum" ) ) return notify_fail("你要敲什麽？\n");

	if((int)me->query("qi") < 30)
	{
		killer = new(CLASS_D("shaolin") + "/qing-xiao");
		COMBAT_D->killer_reward(killer, me);
                me->die();
		destruct(killer);
		return 1;
	}
	else
		me->add("qi", -30);

	if ( random((int)me->query("str")) < 10 )
	{
		message_vision("$N一不小心敲到自己头上了。\n", me);
		//me->add("qi", -10 - me->query("qi"));
		me->unconcious();
	}
	else
	{
		mapping mine;

		mine = me->query_entire_dbase();
		message_vision("$N敲了一下大鼓，『咚……』声音传遍整个寺庙。\n", me);
		write("鼓声如迅雷般在你耳边炸响，你头脑中一片糊涂，\n"
			"全身摇摇欲坠，勉力支撑着不倒在地上。心中一个\n"
			"声音告诉你，得赶快离开这里，不然就没命了。\n");
		if ( mine["potential"] - mine["learned_points"] < 100 )
			mine["potential"] += 1;
	}
	return 1;
}

int do_out(string arg)
{
        object me, killer;

	int i, ging_cost, qi_cost;

        me = this_player();
        i = (int)me->query_skill("dodge", 0) + random(200);
        ging_cost = 600 / (int)me->query("int");
        qi_cost = 500 / (int)me->query("int");
        if(((int)me->query("jing") < ging_cost) || ((int)me->query("qi") < qi_cost))
                i = 0;

        message_vision("$N爬上窗台，一个纵身，跳了下去。\n", me);
        me->move(__DIR__"gulou");
        message_vision("只听『砰』地一声$N从塔顶跳了下来。\n", me);
        if ( i < 50)
	{
		killer = new(CLASS_D("shaolin") + "/qing-wen");
		COMBAT_D->killer_reward(killer, me);
                me->die();
		destruct(killer);
	}
        else if( i < 125)
                me->unconcious();
        else {
                message_vision("$N已稳稳地站在地上。\n", me);
                if( i > 175)
                        me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
                me->receive_damage("jing", ging_cost );
                me->receive_damage("qi", qi_cost );
        }

        return 1;
}






string look_drum()
{
	return
"　　大鼓鼓身通红，似由白杨木箍成。两头包以水牛皮，用一匝大铜钉钉在鼓身\n"
"边缘。鼓心有一圈白渍，看来是因为多次击打形成的。整个大鼓放在一个一人高\n"
"的架子上，架子底层搁着两根大鼓槌。你禁不住想击一下鼓(hit)试试。\n";
}

string look_out()
{
	return  "这里是鼓楼顶层的窗台，从这里可以遥望整个少室山脉，\n"
"以及高耸入云的嵩山。浮世烟尘，尽在眼底。据说在此地\n"
"可以与天界诸佛直接交流，对禅修大有益处。\n";
}

