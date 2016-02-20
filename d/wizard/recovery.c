inherit ROOM;

void create()
{
        set("short", "急诊室");
        set("long", @LONG
这是游戏的急诊室，专为治疗因游戏出毛病而无辜受害的玩家
。急诊室里有许许多多的仪器，外行的人根本看不懂有何用处。正中
央摆着一张大床(bed)，手术便在床上实施。玩家一躺(lay)上床手术
便立刻开始。
LONG
        );

        set("no_fight", 1);

	set("exits", ([
		"out" : "/d/city/wumiao",
		"enter" : "/u/qfy/workroom",
	]));

	set("cost", 0);
        setup();
        //replace_program(ROOM);
}
/* disabled by ryu. For cyz have access to here.
void init()
{
        add_action("do_lay", "lay");
}
*/
int do_lay(string arg)
{
        object me = this_player();
	mapping skill_status;
	string *sname;
	int i, count, new_shen, new_exp, new_pot;

	seteuid( geteuid(me) );

	if ( !arg || arg != "bed" ) return notify_fail("你想躺在那儿呀？\n");
	
	if ( me->query_temp("rec") == 1 ) return notify_fail("你怎么老出毛病啊？不能再治了！\n");

	message_vision("$N往床上一躺，在手术灯的照射下，一会儿便迷迷糊糊的失去知觉了。\n", me);

	me->disable_player("<手术中>");
	me->set_temp("block_msg/all",1);

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname = keys(skill_status);
		count = sizeof(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]+1);
		}
	}

	new_shen = (int)me->query("shen") / 0.9;
	new_exp = 50*(int)me->query("combat_exp") / 49;
	new_pot = (int)me->query("potential") - (int)me->query("learned_points");

	me->set("shen", new_shen);
	me->set("combat_exp", new_exp);
	me->add("potential", new_pot);
	if ( me->query("death_count") > 0 ) {
		me->add("death_count", -1);
		if ((int)me->query("death_times") > (int)me->query("death_count"))
			me->set("death_times", (int)me->query("death_count"));
	}
	me->set_temp("rec", 1);

	call_out("wakeup", 20, me); 

	return 1;
}

void wakeup(object me)
{
	me->enable_player();
	me->set_temp("block_msg/all", 0);
	message_vision("良久$N醒了过来，发现自己已完全康复了！\n", me);
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && dir == "enter")
                return notify_fail("您未受邀请，不能到那儿去。\n");
	return ::valid_leave(me, dir);
}
