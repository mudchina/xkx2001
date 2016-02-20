//Cracked by Roath

int accept_fight()
{
        object me, ob;

        me = this_object();
        ob = this_player();

        if( ob->query_temp(me->query("mz/set"))) {
		command("say 阁下武功出众，在下很是佩服。你我不必再动手了。");
		return 0;
	}
	if (!ob->query_temp(me->query("id")+"toy")) {
		command("say 在下野居多年，懒散惯了，不想和人动手。");
		return 0;
	}
	if (!ob->query_temp(me->query("mz/need"))) {
		command("say 请阁下先同"+me->query("mz/needname")+"较量之後"
			"在下再现丑。");	
		return 0;
	}
	command("say 好吧，你我就比划比划，点到为止。");
	me->set_temp("challenger", ob);
	return 1;
}

int chat()
{
	object me = this_object();
	object ob = me->query_temp("challenger");
        int my_max_qi, his_max_qi;

	if( !objectp(ob) ) return ::chat();
	if (me->is_fighting(ob)) return ::chat();

	me->delete_temp("challenger");
        if (me->is_fighting()) return ::chat();

        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

        if ( !present(ob, environment()) ) return ::chat();

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 )
        {
		command("say 阁下果然高明，我认输了。");
		ob->set_temp(me->query("mz/set"),1);
		ob->set_temp(me->query("id")+"toy",0);
		call_out("fightwin",1,ob);
		return ::chat();
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 )
        {
                command("say 看来这"+me->query("mz/toy")+"要归我了。");
		command("jump");
		return ::chat();
	}
}

int accept_object(object me, object obj)
{
	if ((string)obj->query("name")!=this_object()->query("mz/toy")){
		command("say 君子不夺人之美，请阁下收回。");
		return 0;
	}
	command("bow "+me->query("id"));
	command("say 啊，这是真的吗，在下愿为此宝凭微末之技和阁下赌上一赌。");
	me->set_temp(this_object()->query("id")+"toy",1);
	return 1;
}


