//Cracked by Roath
void init()
{
	object ob,me=this_object();

	if (interactive(ob = this_player())
		&& ((int)ob->query_condition("dlkiller")
		|| ob->query("dali/trust")<-300)) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
	else {
		if (interactive(ob = this_player()) && ob->query("dali/rank")>=5 && me->query("dali/rank")<5)
			call_out("bow1", 1, me, ob);
		else 
			if (ob->query("dali/rank")==4 && me->query("family/family_name")=="大理段家" && me->query("dali/rank")<5)
				call_out("bow2", 1, me, ob);
	}

	if (interactive(ob = this_player())
		&& ob->query("dali/employee")
		&& ob->query("family/family_name")!="大理段家"
		&& ob->query("dali/trust")<0) {
		message_vision("$N严肃地警告$n：“"+RANK_D->query_respect(me)+"投我大理为差，却怎么行为不轨、恶迹累累？皇上就要把你开除了！”\n",me,ob);
	}

	if (interactive(ob = this_player())
		&& ob->query("dali/employee")
		&& ob->query("family/family_name")!="大理段家"
		&& (ob->query("dali/trust")<=-100
		|| ob->query("family/family_name")=="丐帮"
		|| ob->query("family/family_name")=="星宿派"
		|| ob->query("family/family_name")=="雪山派"
		|| ob->query("family/family_name")=="血刀门"
		|| ob->query("family/family_name")=="白驼山"
		|| ob->query("sg/spy")
		|| (ob->query("class") && ob->query("class")!="officer")
		|| (ob->query("PKS")>20	&& ob->query("combat_exp")/ob->query("PKS") < 7500))) {
		command("sneer "+ob->query("id"));
		message_vision("$N对$n冷笑着道：“"+RANK_D->query_rude(me)+"来此为差却心怀不轨，视国法为无物。大理岂是你这种小人逍遥的地方！”\n",me,ob);
		message_vision("$N掏出一卷公文对$n大声宣读：“现秉承皇命，革去"+ob->query("name")+"大理差人之职，永不复录用！”\n",me,ob);
		ob->set("dali/betrayer",1);
		ob->delete("dali/employee");
		ob->delete("dali/rank");
		ob->delete("dali/jobdone");
		ob->delete("dali/arrestmade");
		ob->delete("dali/duty");
		ob->delete("dali/lastjob");
		ob->delete("class");
		if (ob->query_skill("buddhism",1)>40) ob->set_skill("buddhism", 40);
		ob->set("dali/trust",-100);
	}

	if (interactive(ob = this_player())
		&& ob->query("dali/employee")
		&& ob->query("family/family_name")!="大理段家"
		&& (ob->query("shen")>(ob->query("combat_exp")/2)
		|| ob->query("shen")<(-ob->query("combat_exp")/2)
		|| ob->query("family/family_name")=="全真教"
		|| ob->query("family/family_name")=="桃花岛")) {
		command("sigh "+ob->query("id"));
		message_vision("$N轻轻地拍了拍$n肩膀，说道：“"+RANK_D->query_respect(me)+"近来在江湖上名声大长，在大理屈尊为差实在太委屈你了。”\n",me,ob);
		message_vision("$N掏出一卷公文对$n大声宣读：“现秉承皇命，革去"+ob->query("name")+"大理差人之职，永不复录用！”\n",me,ob);
		ob->set("dali/betrayer",1);
		ob->delete("dali/employee");
		ob->delete("dali/rank");
		ob->delete("dali/jobdone");
		ob->delete("dali/arrestmade");
		ob->delete("dali/duty");
		ob->delete("dali/lastjob");
		ob->delete("class");
		if (ob->query_skill("buddhism",1)>40) ob->set_skill("buddhism", 40);
		ob->set("dali/trust",0);
	}
}

int bow1(object me, object ob)
{
	if (present(ob, environment(me)))
		message_vision("$N毕恭毕敬地向$n躬身行礼：“王爷好。”\n",me,ob);
	return 1;
}

int bow2(object me, object ob)
{
	if (present(ob, environment(me)))
		me->command("bow "+ob->query("id"));
	return 1;
}

int accept_fight(object me)
{
	if (me->query("family/family_name") != "大理段家"
		&& !me->query("dali/employee")) {
		command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
        me->apply_condition("dlkiller", 100);
        kill_ob(me);
        return 1;
	}
	else {
		command("say 我正忙着公务呢，你别来捣乱。");
        return notify_fail("看来他不想和你交手。\n");
	}
}

int accept_kill(object me)
{
	if (me->query("dali/employee")) {
		command("say 你我同府共事，何故加害与我？！我跟你拼了！\n");
		me->add("dali/trust",-1);
	}
	else command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	me->apply_condition("dlkiller", 100);
	return 1;
}

void unconcious()
{
	object ob, me=this_object();

	if (objectp(ob = me->query_temp("last_damage_from")))
		ob->add("dali/trust", -1);

	::unconcious();
}

void die()
{
	object ob, me=this_object();

	if (objectp(ob=me->query_temp("last_damage_from")))
		ob->add("dali/trust", -1);

	::die();
}
