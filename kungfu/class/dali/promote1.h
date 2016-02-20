//Cracked by Roath
int accept_object(object ob, object obj)
{
	mapping ob_fam;
	ob_fam=ob->query("family");

	if (obj->query("id")!= "shou yu") {
		command("say 对不起，这东西我不要。");
		return 0;
	}

	if (!(ob_fam = ob->query("family"))
		|| ob_fam["family_name"] != "大理段家") {
		command("say "+RANK_D->query_respect(ob)+"和本派并无关系，给我此物何意？");
		remove_call_out("destroying");
		call_out("destroying", 1, ob, obj);
		return 1;
	}

	if (ob->query("dali/rank")) {
		command("hmm "+getuid(ob));
		command("say "+RANK_D->query_respect(ob)+"似乎身分不符，不该在我这里申请升级吧。\n");
		remove_call_out("destroying");
		call_out("destroying", 1, ob, obj);
		return 1;
	}

	if (ob->query("dali/jobdone")<150) {
		command("say "+RANK_D->query_respect(ob)+"我看你还是先为王府出点力吧，到时候我一定和你比划。");
		remove_call_out("destroying");
		call_out("destroying", 1, ob, obj);
		return 1;
	}

	ob->set_temp("fight_ok1",1);
	command("say 好，既然已得到傅大人许可，我们就来验证一下武功。");
	remove_call_out("destroying");
	call_out("destroying", 1, ob, obj);
	return 1;
}

void destroying(object ob, object obj)
{
	destruct(obj);
	return;
}

int accept_fight(object ob)
{
	object me;
	me=this_object();

	if (!ob->query_temp("fight_ok1")) return 0;

	if (me->is_fighting())
		return notify_fail(me->name()+"摇头道："+RANK_D->query_respect(ob)+"，请勿倚多为胜！");

	me->set("qi", me->query("max_qi"));     
    me->set("eff_qi", me->query("max_qi")); 
    me->set("jing", me->query("max_jing")); 
    me->set("eff_jing", me->query("max_jing"));     
    me->set("jingli", me->query("max_jingli"));     
	me->set_temp("challenger", ob);
    add_action("do_kill", "kill");
    ob->delete_temp("fight_ok1");
    return 1;
}

int chat()
{
	object me = this_object();
	object ob = me->query_temp("challenger");
	object obj;

	int my_max_qi, his_max_qi;
	if (!objectp(ob)) return ::chat();

	my_max_qi  = me->query("max_qi");
    his_max_qi = ob->query("max_qi");
	if (me->is_fighting(ob)) return ::chat();

	me->delete_temp("challenger");
    remove_action("do_kill", "kill");

    if (me->is_fighting()) return ::chat();
    if (!present(ob, environment())) return ::chat(); 
    if (((int)me->query("qi")*100/my_max_qi)<=50) {
		command("say 好，果然不负大人们的栽陪 恭喜你了 !\n");
		command("say 好，我就代大人们收你作个护院啦 !\n");
		ob->set("title","大理国平南王府护院");
		ob->set("dali/rank",1);
        return ::chat();
	}

    if (((int)ob->query("qi")*100/his_max_qi)<50) {
		command("say 看来"+RANK_D->query_respect(ob)+"还得多加努力，方能在大理诸多弟子中出人头地。\n");
		return ::chat();
	}
    return ::chat();  
}

int do_kill()
{
	object me= this_object();
    say(me->name()+"高高举起手谕，喝道：大理门下比武，不可杀人!\n");
	return 1;
}
