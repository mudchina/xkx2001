//Cracked by Roath
// buqun.c 岳不群
// qfy July 4, 1996.

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int auto_perform();
string ask_me();
string ask_feng();
string ask_job();

void create() 
{
	set_name("岳不群", ({ "yue buqun", "yue", "buqun" }));
	set("nickname", "君子剑");
	set("long", 
"这便是华山当代掌门「君子剑」岳不群。他在江湖中侠名远播，\n"
"疾恶如仇，甚得人心。他看起来文绉绉地似个书生，武功却是深\n"
"不可测。\n");
	set("gender", "无性");
	set("age", 46);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 29);
	set("int", 35);
	set("con", 26);
	set("dex", 29);
	
	set("max_qi", 1500);
	set("max_jing", 900);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 50);
	set("combat_exp", 950000);
	set("score", 5000);

	set_skill("force", 150);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("sword", 145);
	set_skill("strike", 140);
	set_skill("huashan-jianfa", 145);
	set_skill("hunyuan-zhang",140);
	set_skill("zixia-gong", 150);
	set_skill("huashan-shenfa", 140);
	set_skill("cuff", 140);
	set_skill("pishi-poyu", 140);
	set_skill("ziyin-yin", 110);
	set_skill("zhengqi-jue", 110);
	set_skill("literate", 150);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike","hunyuan-zhang");
	map_skill("dodge","huashan-shenfa");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("华山派", 13, "掌门");

	set("inquiry", ([
	    "剑宗" : (: ask_me :),
	    "气宗" : (: ask_me :),
	    "宁中则" : "她是我夫人。\n",
	    "岳灵姗" : "她是我女儿。\n",
	    "紫霞功" : "那是本门至高无上的内功心法。\n",
	    "紫霞神功" : "那是本门至高无上的内功心法。\n",          
	    "思过崖" : "那是本派弟子修行思过之处。\n", 
	    "风清扬" : (: ask_feng :),
	    "任务" : (: ask_job :),
	    "job" : (: ask_job :),
	]));

	set_temp("job_pos", 10);
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
	object ob;

	::init();

	set_heart_beat(1);

	if ( interactive( ob = this_player() ) ) {
	   if ( ob->query("family/family_name") == "华山派" ) {
//		remove_call_out("check_student");
		call_out("check_student", 1, ob);
	   }

	   if (present("pixie jianpu",ob)) {
	        message_vision(
	               HIY "$N突然伸手一摸$n的口袋，笑道：功夫不负有心人，东西原来在你这儿！\n"
	               NOR, this_object(), ob );
         	kill_ob(ob);
	   }
        }
}

int check_student(object ob)
{
	mapping job_stat;
	object me = this_object();

	if ( ob->query("shen") < -100 && ob->query("family/master_id") == "yue buqun" ) {
		command("say " + RANK_D->query_rude(ob) + "胆敢瞒着我在外胡作非为！");
		command("expell " + ob->query("id"));
		
		return 1;
	}

	if ( ob->query("huashan/job_pending") && !ob->query_condition("hz_job") ) {
		job_stat = ob->query_temp("hz_job");

		if ( sizeof(job_stat) < 12 ) {
			ob->apply_condition("hz_job", 30);
			message_vision("$N皱着眉头对$n说道：我叫你到华山各处好好巡视，但你似乎还没到各处去过吧。\n", me, ob);
			command("say 你马上给我回去好好巡逻！");
		}
		else {
			ob->delete("huashan/job_pending");
			ob->delete_temp("hz_job");
			ob->add("huashan/job_comp", 1);
			ob->add("combat_exp", 100+random(50));
			ob->add("potential", 50+random(50));
			if ( ob->query("potential") > ob->query("max_potential") )
				ob->set("potential", ob->query("max_potential"));
			
			if ( me->query_temp("job_pos") < 10 ) {
				me->add_temp("job_pos", 1);
			}

			me->set_temp("job_man", ob->query("id") );
			remove_call_out("clear_job_man");
			call_out("clear_job_man", 1000, me);

			command("nod");
			command("say 很好，"+ob->name()+"你累了一天，先到偏厅给祖师爷磕头，再下去休息吧。");
		}
	}

	return 1;
}

int clear_job_man(object me)
{
	if ( objectp(me) ) {
		me->delete_temp("job_man");
	}
	
	return 1;
}

void attempt_apprentice(object ob)
{
	if( ob->query("family/family_name") != "华山派" && ob->query("combat_exp") >= 10000 ) {
		command ("say " + RANK_D->query_respect(this_player()) + "是"
			+ob->query("family/family_name")+"高手，本派可不敢收留！");
		return;
	}

	if (ob->query("class")=="bonze") {
		command ("say 华山派一向不收出家人为徒，你请回吧。");
		return;
	}

	if ((string)ob->query("gender") == "女性") {
		command("say 我不收女徒，" + RANK_D->query_respect(ob) + "还是到后堂拜入我夫人门下吧。");
		if ( ob->query("family/family_name") != "华山派" ) {
			ob->set_temp("marks/bai_ning", 1);
		}
		return;
	}

	if ((string)ob->query("gender") == "无性" && (int)ob->query_skill("pixie-jian",1) > 50 ) {
		command("say " + RANK_D->query_respect(ob) + "是东厂中人，恕我不能收你。");
		return;
	}

	if ((string)ob->query("family/family_name") == "丐帮" && ob->query("rank") > 1 ) {
		command("say " + RANK_D->query_respect(ob) + "是丐帮高手，恕我不能收你。");
		return;
	}

	if ((int)ob->query("huashan/yue") == 1 && (int)ob->query("betrayer") > 10) {
		command("say " + RANK_D->query_respect(ob) + "是个出名的反覆之人，叫我如何信得过你？");
		return;
	}

	if ((int)ob->query("shen") < 0) {
		command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
		command("say "+RANK_D->query_respect(ob)+"非我辈中人，恕我不能收你。");
		return;
	}
       
	command("say 好吧，我就收下你了。希望你能将华山发扬光大，造福武林。");
	ob->set("huashan/yue", 1);
	ob->set("betrayer", 0);
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	object me = this_player();
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ( !myfam || myfam["family_name"] != "华山派" )
		return "咱们豪无渊源，你问这事干嘛？\n";

	say("岳不群指着身后的匾额，语重心长地说道：“华山不幸曾分为气剑二宗。咱\n");
	say("们气宗奉气为主，以剑为辅，以气运剑，无坚不摧。而气宗则倒行逆施重剑\n");
	say("轻气。二宗各持己见，终于水火不容，同门操戈！华山因此式微。你即入我\n");
	say("门，盼你能洁身自爱，重振华山！记得当年匾额上写的是「剑气冲霄」，结\n");
	say("果剑宗虽剑路纵横，变化无方，可仍然败在我宗「紫霞神功」之下，数十年\n");
	say("来不复再现，实异不胜正也。”\n");
	return "切记！切记！\n";
}

string ask_feng()
{
	say("岳不群的脸色突然便得很难看，皱着眉头。\n");
	return "他是本门的一个前辈，一向不过问本门事务，我也不清楚他的下落。\n";
}

void unconcious()
{
	object obj, me = this_object();
	object ob = this_player();

	message_vision("\n$N突然丢下长剑，拿出一根绣花针，身形飘忽有如鬼魅，出手之奇之快，直是匪夷所思！\n", me);
	obj = new(__DIR__"buqun2");
	obj->move(environment(me));
	destruct(me);
}

string ask_job()
{
	mapping job_stat;
	object ob = this_player();
	object me = this_object();
	object *doer;

	job_stat = ob->query_temp("hz_job");

	if ( ob->query_condition("hz_job") > 0 && sizeof(job_stat) == 12 )
		return "你没仔细巡山吧？这麽快便巡遍了华山？给我老老实实地回去巡山吧！\n";
	else if ( ob->query_condition("hz_job") > 0 )
		return "你还没完成我交待的工作，怎麽又来问我？\n";

	if ( ob->query("family/family_name") != "华山派" )
		return "咦！"+RANK_D->query_respect(ob)+"非我华山弟子，岂敢劳烦。\n";

	if ( me->query_temp("job_pos") == 0 ) {
		doer = filter_array(livings(), "is_doing_job", me, ob);
		me->set_temp("job_pos", 10 - sizeof(doer) );
		if ( me->query_temp("job_pos") == 0 ) {
			command("shake");
			return "现在已有十人正在巡山，你还是先到练功房里打坐练功吧。\n";
		}
	}

	if ( me->query_temp("job_man") == ob->query("id") ) {
		command("shake");
		return "你刚巡山回来，应该好好休息了。不累的话，练功打坐也成。\n";
	}
	
	me->add_temp("job_pos", -1);
	ob->set("huashan/job_pending", 1);
	ob->apply_condition("hz_job", 30+random(10));

	command("nod");
	command("say 近来江湖上纠乱纷争，你到华山村庄四处好好巡逻，别让邪派人仕混了进来。");
	return "如果遇上不平之事，你一定要仗义出手相助，不坠我华山名声！一切小心！\n";
}

private int is_doing_job(object doer)
{
	if ( doer->query("family/family_name") == "华山派" && doer->query_condition("hz_job") > 0 )
		return 1;
	else
		return 0;
}

int accept_object(object me, object obj)
{
	object ob = this_player();

	if ( obj->name() == "青铜令牌" && obj->query("id") == "ling pai" ) {
	   if ( ob->query("family/family_name") == "华山派" ) {
		remove_call_out("reward_dest");
	   	call_out("reward_dest", 1, obj, ob);
	   }
	   else {
		remove_call_out("dest_lingpai");
		call_out("dest_lingpai", 1, obj, ob);
	   }
	   return 1;
	}

	command( "hmm" );
	command( "say 你给我这东西做什麽？" );
	   
	return 0;
}

int reward_dest(object obj, object ob)
{
	object me=this_object();
  	int rate, exp;

	// Modified by Chu:
	// Huashan grows faster when they are young, and slower when they are old
        rate = 100;
        exp = ob->query("combat_exp");
	if (exp > 4000000) rate -= 10;
	if (exp > 3000000) rate -= 10;
	if (exp > 2000000) rate -= 10;
	if (exp > 1000000) rate -= 10;
	if (exp < 300000) rate += 10;
	if (exp < 150000) rate += 10;
	if (exp < 50000) rate += 10;

	message_vision("$N皱眉头对自己低声说道：这是邪派的青铜令，他们到底有何所图？\n", me);
	if ( obj->query_temp("owner") == ob->query("id") ) {
		command("say "+ob->name()+"你做得非常好！快下去休息吧。");
		ob->add("combat_exp", rate*(50+random(50))*obj->query_amount()/100);
		ob->add("potential", rate*(30+random(20))*obj->query_amount()/100);
		if ( ob->query("potential") > ob->query("max_potential") )
		ob->set("potential", ob->query("max_potential"));
	}
	else {
		message_vision("$N向$n置问道：这令牌似乎不是你的。你是怎麽得来的？\n", me, ob);
	}

	destruct(obj);

	return 1;
}

int dest_lingpai(object obj, object ob)
{
	object me=this_object();

	message_vision("$N皱眉头对自己低声说道：这是邪派的青铜令，他们到底有何所图？\n", me);
	message_vision("$N对$n拱手说道：有劳"+RANK_D->query_respect(ob)+"拔刀相助，华山上下深表感激！\n", me, ob);
	command("say "+RANK_D->query_respect(ob)+"此举造福武林，真乃江湖豪侠也！");
	
	destruct(obj);

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
                me->set("jiali", 50);

                return 1;
        }

        if ( objectp(weapon) ) {
                if ( weapon->query("skill_type") == "sword" )
                        return perform_action("sword.jianzhang");
        }
        else if ( !me->query_temp("leidong") ) {
			return perform_action("cuff.leidong");
	}
	else if ( !me->query_temp("wuji") && opp->query_condition("hyz_damage") <= 5 ) {
			return perform_action("strike.wuji");
	}
}
