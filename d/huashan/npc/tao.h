//Cracked by Roath
void init()
{
        object ob, me = this_object();
}

int accept_fight(object ob)
{
        object me = this_object();
	object ob1, ob2, ob3, ob4, ob5, ob6;
	string msg1, msg2, msg3, msg4, msg5, msg6;
	int my_max_qi = me->query("max_qi");

	if ( me->query("qi")*100 / my_max_qi <= 80 ) {
                return 0;
        }

	ob1 = present("tao genxian", environment(me));
	ob2 = present("tao ganxian", environment(me));
	ob3 = present("tao zhixian", environment(me));
	ob4 = present("tao yexian", environment(me));
	ob5 = present("tao huaxian", environment(me));
	ob6 = present("tao shixian", environment(me));

	msg1 = "桃根仙突然逼近$N，一把向$N的左手捉去。\n";
	msg2 = "桃干仙突然逼近$N，一把向$N的右手捉去。\n";
	msg3 = "桃枝仙突然逼近$N，一把向$N的左脚捉去。\n";
	msg4 = "桃叶仙突然逼近$N，一把向$N的右脚捉去。\n";
	msg5 = "桃花仙突然逼近$N，一把向$N的左手捉去。\n";
	msg6 = "桃实仙突然逼近$N，一把向$N的右脚捉去。\n";

	command( "say 大夥儿准备。" );

	if ( ob1 != me ) call_out("tear_and_kill", random(5), ob1, ob, msg1);
	if ( ob2 != me ) call_out("tear_and_kill", random(5), ob2, ob, msg2);
	if ( ob3 != me ) call_out("tear_and_kill", random(5), ob3, ob, msg3);
        if ( ob4 != me ) call_out("tear_and_kill", random(5), ob4, ob, msg4);
        if ( ob5 != me ) call_out("tear_and_kill", random(5), ob5, ob, msg5);
        if ( ob6 != me ) call_out("tear_and_kill", random(5), ob6, ob, msg6);

	call_out("observe", 1, me, ob);
        return 1;
}

string ask_me()
{
	return "你打得过咱们六兄弟，我自然会带你去见他。";
}

int accept_kill(object ob)
{
	object me = this_object();
	object ob1, ob2, ob3, ob4, ob5, ob6;

	ob->delete_temp("win");
	command( "say 你想谋材害命不成，是不是妒忌咱们六兄弟名满江湖？\n");

	if ( objectp(ob1 = present("tao genxian", environment(me))) ) ob1->kill_ob(ob);
	if ( objectp(ob2 = present("tao ganxian", environment(me))) ) ob2->kill_ob(ob);
	if ( objectp(ob3 = present("tao zhixian", environment(me))) ) ob3->kill_ob(ob);
	if ( objectp(ob4 = present("tao yexian", environment(me))) ) ob4->kill_ob(ob);
	if ( objectp(ob5 = present("tao huaxian", environment(me))) ) ob5->kill_ob(ob);
	if ( objectp(ob6 = present("tao shixian", environment(me))) ) ob6->kill_ob(ob);

	return 1;
}

int tear_and_kill(object me, object ob, string msg)
{
	if ( !ob->is_fighting() && ob->query("qi")*2 <= ob->query("max_qi")) {
		ob->delete_temp("caught"); 
		return 1;
	}

	message_vision(msg,ob);

	if ( random(me->query("combat_exp")) > (int)ob->query("combat_exp")/2 ) {
		me->delete_temp("catch_pending");
		me->set_temp("catch", 1);
		ob->add_temp("caught", 1);
		message_vision("结果$N被"+me->name()+"捉个正着！\n", ob);
		if ( ob->query_temp("caught") == 4 ) {
		   message_vision("\n桃谷六仙捉着$N四肢猛然一扯，$N只觉得一阵剧痛，便失去知觉了。\n", ob);
		   ob->unconcious();
		   ob->die();
		   CHANNEL_D->do_channel(me,"chat",sprintf("%s被桃谷六仙撕成四块了！",ob->name()));
//		   COMBAT_D->killer_reward(me, ob);
		}
	}
	else {
		message_vision("$N成功地闪开了。\n", ob);
	}

	return 1;
}     

int observe(object me, object ob)
{
        int my_max_qi = me->query("max_qi");
        string msg;

        if (me->is_fighting()) {
	   if ( (me->query("qi")*100 / my_max_qi) <= 80 ) {
                command("exert recover");
           }

	   call_out("observe", 1, me, ob);
           return 1;
        }

	if (me->query("qi")*2 <= me->query("max_qi")) {
 	   me->remove_enemy(ob);
           ob->remove_enemy(me);
           command( "say "+RANK_D->query_respect(ob)+"果然有几手，我还是让你歇会儿吧，可不是我打不过你喔。");
	   if ( me->name() == "桃根仙" ) ob->set_temp("win/tao1", 1);
	   if ( me->name() == "桃干仙" ) ob->set_temp("win/tao2", 1);
	   if ( me->name() == "桃枝仙" ) ob->set_temp("win/tao3", 1);
           if ( me->name() == "桃叶仙" ) ob->set_temp("win/tao4", 1);
           if ( me->name() == "桃花仙" ) ob->set_temp("win/tao5", 1);
           if ( me->name() == "桃实仙" ) ob->set_temp("win/tao6", 1);
	   ob->delete_temp("caught");
	}

	if (ob->query("qi")*2 <= ob->query("max_qi")) {
           me->remove_enemy(ob);
           ob->remove_enemy(me);
	   ob->delete_temp("caught");
        }

	if ( !present(ob, environment()) ) return 1;

	return 1;
}
