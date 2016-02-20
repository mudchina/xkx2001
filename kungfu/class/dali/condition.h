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
		command("say 你我本是同门，切搓一二到也无仿。\n");
        return 1;
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
