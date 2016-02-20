//Cracked by Roath
void init()
{
	object ob, me = this_object();

	::init();

	set_heart_beat(1);

	if ( interactive(ob=this_player()) && ob->query("family/master_id")==me->query("id") 
	&& ob->query("shen") < 0 ) {
		command("say " + RANK_D->query_rude(ob) + "胆敢瞒着我在外胡作非为！" );
		command( "expell " + ob->query("id"));
	}

	add_action("do_steal", "steal");
	add_action("do_throw", "throw");
}

void attempt_apprentice(object ob)
{
	if ( ob->query_skill("dugu-jiujian", 1) && !ob->query("family/family_name") ) {
		command("say 好吧，老夫就收下你了。你今后立身处事，必须以大义为先，扬善惩恶。");
		command("recruit " + ob->query("id"));
		return;
	}
	
	if ( (string)ob->query("family/family_name") != "华山派" ) {
		command("say " + RANK_D->query_respect(ob) + "非我华山门人，恕我不能收你。");
		return;
	}

	if ( (string)ob->query("gender") == "无性" ) {
		command("say " + RANK_D->query_respect(ob) + "是东厂中人，恕我不能收你。");
		return;
	}

	if ( (int)ob->query("shen") < 50000 ) {
		command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
		command("say "+RANK_D->query_respect(ob)+"在品德方面，做得还不够，老夫不能收你。");
		return;
	}

	if ( (int)ob->query_skill("strike", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"的基本掌法修为不够，恕我不能收你。");
		return;
	}

	if ( (int)ob->query_skill("cuff", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"的基本拳法修为不够，恕我不能收你。");
		return;
	}

	if ( (int)ob->query_skill("dodge", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"的基本轻功修为不够，恕我不能收你。");
		return;
	}

	if ( (int)ob->query_skill("parry", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"的基本招架修为不够，恕我不能收你。");
		return;
	}

	if ( (int)ob->query_skill("force", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"的基本内功修为不够，恕我不能收你。");
		return;
	}

	if ( (int)ob->query_skill("sword", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"的基本剑法修为不够，恕我不能收你。");
		return;
	}

	if ( (int)ob->query_skill("hunyuan-zhang", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"的混元掌修为不够，恕我不能收你。");
		return;
	}

	if ( (int)ob->query_skill("pishi-poyu", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"的劈石破玉拳修为不够，恕我不能收你。");
		return;
	}

	if ( (int)ob->query_skill("huashan-jianfa", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"的华山剑法修为不够，恕我不能收你。");
		return;
	}

	if ( (int)ob->query_skill("huashan-shenfa", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"的华山身法修为不够，恕我不能收你。");
		return;
	}

	if ( (int)ob->query_skill("zixia-gong", 1) < 50 ) {
		command("say "+RANK_D->query_respect(ob)+"的紫霞功修为不符合我的要求，恕我不能收你。");
		return;
	}

	command("say 好吧，老夫就收下你了。你今后立身处事，必须以大义为先，扬善惩恶。");
	command("recruit " + ob->query("id"));
}

int accept_fight(object ob)
{
	object obj, me = this_object();
	int my_max_qi = me->query("max_qi");

	if ( me->query("qi")*100 / my_max_qi <= 80 ) {
		call_out("checking1", 1, me, ob);
		return 0;
	}

	remove_call_out("checking1");
	call_out("checking1", 1, me, ob);

	return 1;
}

int accept_kill(object ob)
{
	object obj, me = this_object();

	if ( me->query("id")== "ai lao" && obj = present("gao lao", environment(me)) ) {
		command("say 好家伙，竟想谋害老夫！师弟，准备双刀合壁！");
		obj->kill_ob(ob);
	}

	if ( me->query("id")== "gao lao" && obj = present("ai lao", environment(me)) ) {
		command("say 师兄，准备双刀合壁超渡这家伙！");
		obj->kill_ob(ob);
	}

	remove_call_out("checking2");
	call_out("checking2", 1, me, obj, ob);

	return 1;
}

int checking1(object me, object ob)
{
	object obj;

	if ( me->is_fighting() && me->is_killing() && !me->query_temp("hebi") ) {
		if ( me->query("id") == "gao lao" && obj=present("ai lao", environment(me)) ) 
			obj->kill_ob(ob);
		if ( me->query("id") == "ai lao" && obj=present("ai lao", environment(me)) ) 
			obj->kill_ob(ob);
		call_out("checking2", 1, me, obj, ob); 
	}
	else if ( me->is_fighting() ) {
		call_out("checking1", 1, me, ob);
	}

	return 1;
}
	
int checking2(object me, object obj, object ob)
{
	if ( me->is_fighting() ) {
	   if ( objectp(obj) && !obj->is_fighting() ) {
		obj->kill_ob(ob);
	   }

	   if ( !me->query_temp("hebi") ) {
		if ( me->query("id") == "gao lao" ) command("perform hebi ai");
		if ( me->query("id") == "ai lao" ) command("perform hebi gao");
	   }
 
	   call_out("checking2", 1, me, obj, ob);
	}
	
	return 1;
}

int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object opp=me->select_opponent();

	if ( !me->is_fighting() ) {
                if ( me->query("eff_qi") < me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 80);

                return 1;
        }

        if ( objectp(weapon) ) {
                if ( weapon->query("skill_type") == "blade" )
                        return perform_action("blade.sanshen");
        }
        else if ( !me->query_temp("leidong") ) {
			return perform_action("cuff.leidong");
	}
	else if ( !me->query_temp("wuji") && opp->query_condition("hyz_damage") <= 5 ) {
			return perform_action("strike.wuji");
	}
}

int accept_object(object me, object obj)
{
	object ob = this_player();

	if ( me->is_fighting() ) 
		return notify_fail("浑帐！你没见我正忙着吗？\n");

	if ( obj->query("id") != "zixia paper" ) return 0;
	
	if ( ob->query("huashan/yin-jue") > 1 ) {
		remove_call_out("ask_why");
		call_out("ask_why", 1, obj, ob);
		return 1;
	}

	if ( (string)ob->query("family/family_name") != "华山派" ) {
		remove_call_out("thank_other");
		call_out("thank_other", 1, me, obj, ob);
	}
	else {
		remove_call_out("thank_huashan");
		call_out("thank_huashan", 1, obj, ob);
	}

	return 1;
}

int ask_why(object obj, object ob)
{
	object me = this_object();

	message_vision("$N皱着眉头对$n说道：咦！你不是已闭关静修过了吗？\n", me, ob);
	command("say 紫霞遗页交给我保管也好，你还有甚麽事吗？");

	destruct(obj);
	return 1;
}

int thank_other(object me, object obj, object ob)
{
	message_vision("$N失声叫道：啊！这竟是本派遗失多年的紫霞遗页！这。。。本派真是无以为报。\n", me);
	command("say 请受老朽代表华山一脉向"+RANK_D->query_respect(ob)+"至意。");
	command("bow");
	message_vision("$N说完便飞身离去。\n", me);

	destruct(obj);
	destruct(me);
	return 1;
}

int thank_huashan(object obj, object ob)
{
	object ob1, me=this_object();
	
	message_vision("$N失声叫道：啊！这竟是本派遗失多年的紫霞遗页！\n", me);
	
	if ( me->query("id") == "gao lao" && ob1=present("ai lao", environment(me)) ) { 
		command("say 让我和师哥商量商量，你便在此等着吧。");
		message_vision("$N将矮老者拉到一旁细说了一番，只见矮老者脸色变了几变，两人低头沉思着。\n", me);
		me = ob1;
	}	
	else if ( me->query("id") == "ai lao" && present("gao lao", environment(me)) ) { 
		command("say 让我和师弟商量商量，你便在此等着吧。");
		message_vision("$N将高老者拉到一旁细说了一番。高老者听罢脸色变了几变，两人低头沉思着。\n", me);
	}	
	else {
		command("say 让我仔细研究此笺，你便在此等着吧。");
		message_vision("$N说完後便独自走到一旁坐下，全神贯注地研读起着紫霞遗页来。\n", me);
	}

	remove_call_out("open_room");
	call_out("open_room", 5, me, ob, obj);

	return 1;
}

int open_room(object me, object ob, object obj)
{
	message_vision("$N走了过来，向$n凝视了一阵。\n", me, ob);
	command("say 你既能找回紫霞遗页，实在是为本派立了个大功。华山有幸了！ ");

	if ( file_name(environment(me)) != "/d/huashan/xiaozhu" ) {
		command("say 你快回华山去吧，把喜讯告诉大夥儿！");
		message_vision("$N说完便飞身离去。\n", me);
		destruct(obj);
		if (objectp(me) ) destruct(me);
	}
	else {
		command("say 好！我便为你护法。你安心在密室里闭关修练玄功吧。");
		message_vision("$N将紫霞遗页交还给$n。\n", me, ob);
		message_vision("接着$N转身向墙上一处一按一掀，墙壁正中轰隆隆响了一阵，露出一道门来。\n", me);
		command("say 唉！数十年来我始终钻研不透密室里的用处，原来还有这个秘密。");
		command("say 好好利用密室里的东西，小心别把练功的步骤搞错了！");
		obj->move(ob);
		message_vision("$N走入了门内，石门便缓缓关闭起来。\n", ob);
		ob->move("/d/huashan/stair");
	}

	return 1;
}

int do_steal()
{
	object obj, ob=this_object(), me=this_player();

	if ( ob->query("id")=="ai lao" ) {
		obj = present("gao lao", environment(me));
	}
	else if ( ob->query("id")=="gao lao" ) {
		obj = present("ai lao", environment(me));
	}

	call_out("checking2", 5, ob, obj, me);

	return 0;
}

int do_throw()
{
	object obj, ob=this_object(), me=this_player();

	if ( ob->query("id")=="ai lao" ) {
		obj = present("gao lao", environment(me));
	}
	else if ( ob->query("id")=="gao lao" ) {
		obj = present("ai lao", environment(me));
	}

	call_out("checking2", 5, ob, obj, me);

	return 0;
}
