//Cracked by Roath
int accept_object(object ob, object obj)
{
		if (obj->query("id")!="xin yin") {
                command("say 对不起，这东西我不要。");
                return 0;
        }
//        if (obj->query("applicant")!=me->query("id")) {
//                command("say 大胆！！连皇上的信印都想冒名顶替！");
//                remove_call_out("destroying");
//                call_out("destroying", 1, obj);
//                return 1;
//        }

        if (ob->query("family/family_name") != "大理段家" && !ob->query("dali/employee")) {
                command("say "+RANK_D->query_respect(ob)+"和本派并无关系，给我此物何意？");
                remove_call_out("destroying");
                call_out("destroying", 1, obj);
                return 1;
        }

        if (ob->query("dali/rank")!=3) {
                command("hmm "+getuid(ob));
                command("say "+RANK_D->query_respect(ob)+"似乎身分不符，不该在我这里申请升级吧。\n");
                remove_call_out("destroying");
                call_out("destroying", 1, obj);
                return 1;
        }

        if (ob->query("family/family_name")=="大理段家" && ob->query("dali/jobdone")<1000) {
                command("say "+RANK_D->query_respect(ob)+"我看你还是先为王府出点力吧，到时候我一定和你比划。");
                remove_call_out("destroying");
                call_out("destroying", 1, obj);
                return 1;
        }

		ob->set_temp("fight_ok5",1);
		command("say 好，既然已得到圣上的许可，我们就来验证一下武功。");
		remove_call_out("destroying");
		call_out("destroying", 1, obj);
		return 1;
}

void destroying(object obj)
{
        destruct(obj);
        return;
}

int accept_fight()
{
	object me, obj;
	mapping skill_status;
	string *sname;
	int i ,num, level = 0, s_level, exp, obj_exp, rate;

	obj = this_object();
	me = this_player();
	exp = me->query("combat_exp");

	if (!me->query_temp("fight_ok5")) {
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


	if (obj->is_fighting())
		return notify_fail(obj->name()+"摇头道："+RANK_D->query_respect(me)+"，请勿倚多为胜！");

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			if ( skill_status[sname[i]] > level ) level = skill_status[sname[i]];
		}
		
		level = (int)level*3/4 + 1;
		s_level = (int)level*11/10;

		rate = random(3)+9;
		obj->set("max_qi", me->query("max_qi")*11/10);
		obj->set("eff_qi", me->query("max_qi")*11/10);
		obj->set("max_jing", me->query("max_jing")*11/10);
		obj->set("eff_jing", me->query("max_jing")*11/10);
		obj->set("qi", obj->query("max_qi"));
		obj->set("jing", obj->query("max_jing"));
		obj->set("jiali", me->query("jiali")*3/4);
		obj->set("max_neili", me->query("max_neili")*11/10);
		obj->set("max_jingli", me->query("max_jingli")*11/10);
		obj->set("neili", obj->query("max_neili"));
		obj->set("jingli", obj->query("max_jingli"));
		obj->set("no_sing", 1);
		obj->set("combat_exp", exp*rate/10 + random(exp/100) );
		obj->set_skill("cuff", level);
		obj->set_skill("jinyu-quan", s_level);
		obj->set_skill("dodge", level);
		obj->set_skill("duanshi-shenfa", s_level);
		obj->set_skill("parry", level);
		obj->set_skill("force", level);
		obj->set_skill("kurong-changong", s_level);
		obj->set_skill("finger", level);
		obj->set_skill("buddhism", 400);
		obj->set_skill("yiyang-zhi", s_level);
		obj->map_skill("cuff","jinyu-quan");
		obj->map_skill("dodge","duanshi-shenfa");
		obj->map_skill("force","kurong-changong");
		obj->map_skill("finger","yiyang-zhi");
		obj->prepare_skill("finger","yiyang-zhi");
		obj->prepare_skill("cuff","jinyu-quan");
		obj->set_temp("apply/attack", 100);
		obj->set_temp("apply/defence", 100);
		obj->set_temp("apply/armor", 100);

	command("unwield di");
    command("enable parry yiyang-zhi");
	obj->set_temp("challenger", me);
    add_action("do_kill", "kill");
    me->delete_temp("fight_ok5");
    return 1;
	}
}
int chat()
{
        object letter, me = this_object();
        object ob = me->query_temp("challenger");
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
		ob->set_temp("dali/upranked",1);
//		command("smile "+ob->query("id"));
		command("smile");
		letter = new("/u/mantian/work-letter2");
		letter->move(me);
		letter->set("applicant",ob->query("id"));
		command("give zou zhe to "+ob->query("id"));
		command("say 请"+RANK_D->query_respect(ob)+"把这份奏折代我呈交圣上。\n");
		remove_call_out("reset");
		call_out("reset", 2, me);
//		destruct(me);
		return ::chat();
		}

    if (((int)ob->query("qi")*100/his_max_qi)<50) {
                command("say 看来"+RANK_D->query_respect(ob)+"功夫火候尚浅，还不能胜任高职呀。\n");
				remove_call_out("reset");
				call_out("reset", 2, me);
                return ::chat();
        }
    return ::chat();  
}

int do_kill()
{
    object me= this_object();
    say(me->name()+"高高举起书信，喝道：大理门下比武，不可杀人!\n");
        return 1;
}
void reset(object me)
{
	me = this_object();
	me->set_skill("cuff", 100);
	me->set_skill("jinyu-quan", 100);
	me->set_skill("dodge", 100);
	me->set_skill("duanshi-shenfa", 110);
	me->set_skill("parry", 90);
	me->set_skill("force", 105);
	me->set_skill("kurong-changong", 90);
	me->delete_skill("finger");
	me->set_skill("buddhism", 110);
	me->delete_skill("yiyang-zhi");
	me->map_skill("cuff","jinyu-quan");
	me->map_skill("dodge","duanshi-shenfa");
	me->map_skill("force","kurong-changong");
	me->map_skill("parry", "duanjia-jian");
	me->prepare_skill("cuff","jinyu-quan");
	me->set("max_qi", 800);
	me->set("eff_qi", 800);
	me->set("max_jing", 800);
	me->set("eff_jing", 800);
	me->set("qi", me->query("max_qi"));
	me->set("jing", me->query("max_jing"));
	me->set("jiali", 40);
	me->set("max_neili", 800);
	me->set("max_jingli", 600);
	me->set("neili", 800);
	me->set("jingli", me->query("max_jingli"));
	me->set("combat_exp", 500000);
	command("wield di");
	me->set_temp("apply/attack", 50);
	me->set_temp("apply/defence", 50);
	me->set_temp("apply/armor", 50);

}