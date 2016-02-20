//Cracked by Roath
//xiaojian May25,2000

string ask_tiaoshui()
{
	object me, ob;
	string event;
	string fam;
	int time;
	mapping my_fam;
	me = this_player();
	ob = this_object();
	event = NATURE_D->outdoor_room_event();
	fam = me->query("family/family_name");
	my_fam = me->query("family");
	if (!fam || fam != "少林派")
		return "阿弥陀佛,这位施主不是少林寺的，贫僧可不敢劳动大驾。";
	if (me->query("combat_exp") > 500000)
		return "这位"+RANK_D->query_respect(ob)+"已经是高手了，不用在做这种粗话了! ";
	
	/*if (event == "event_night" || event == "event_midnight")
		return "阿弥陀佛,本寺的山门夜晚不开,"+RANK_D->query_respect(me)+ "还是等天亮在来吧。";*/
	if (me->query("shaolin/job_asked"))
		return RANK_D->query_respect(me)+ "不是问过了吗，怎么还在这里偷懒? ";
	if(me->query_condition("ts_pending"))
		return "目前还找不到什么活儿给你干，你等等再来吧。";
	
	command("nod");
	command("say 你来的正好，这几天厨房里正缺水呢，你去山下挑些水吧! \n");
	command("say 先去找烧饭僧要上挑水的工具吧。\n");
	me->set("shaolin/job_asked",1);
	time = 30 + random(10);
	me->apply_condition( "tiaoshui", time );
	return "早去早回，厨房里还等着用水呢。";

}
string ask_abandon()
{
	object me, ob;
	int busy;
	object *inv;
	int i;
	ob = this_player();
	me = this_object();
	inv = all_inventory(me);
	if (!ob->query("shaolin/job_asked"))
		return "你现在并没有任务在身呀。";
	command("disapp "+ob->query("id"));
	command("say 连这么点小事都办不了，将来怎么为少林寺出力呀? \n");
	ob->delete("shaolin/job_asked");
	ob->delete("shaolin/tool_assigned");
	if(ob->query_condition("tiaoshui"))
          ob->clear_one_condition("tiaoshui");
	for (i = 0; i <sizeof(inv);i++){
		if (inv[i]->query("id") == "shui tong")
			destruct("shui tong");
	}
    busy = 20+random(8);
	ob->apply_condition("ts_pending", busy );
	return "下去好好反思一下吧。";
}

