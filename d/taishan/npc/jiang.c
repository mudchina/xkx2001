//Cracked by Roath
// jiang 江百胜

#include <ansi.h>

inherit NPC;
string check_qualification();

void create()
{
	seteuid(getuid());

	set_name("江百胜", ({ "jiang baisheng", "jiang", "baisheng" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "当今武林盟主魏无双之手下之亲兵队长。\n");
	set("attitude", "heroism");
	set("generation",0);
	set("winner","none");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);

	set("max_qi", 400);
	set("eff_qi", 400);
	set("qi", 400);
	set("max_jing", 200);
	set("jing", 200);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 30);
	set("shen_type", 0);

	set("no_clean_up",1);
	set("combat_exp", 50000);

	set_skill("force", 80); 
	set_skill("unarmed", 100);
	set_skill("dodge", 80);
	set_skill("parry", 80);

	set("fight_times", 0);	

	set("inquiry", ([
		"上山" : (: check_qualification :),
	]));

	setup();
        
}

int accept_fight(object ob)
{
	int times;
	object me  = this_object();
		
	if ( me->is_fighting()) return 0;

	if ( !present(ob, environment()) ) return 0;

	times = me->query("fight_times");
	if ( times >= 10 )
		return notify_fail("江百胜已经全身脱力，趴在地上大口地喘着粗气！\n");	

	me->set("eff_qi", me->query("max_qi"));
	me->set("qi",     me->query("max_qi"));
	me->set("jing",   me->query("max_jing"));
	me->set("neili",  me->query("max_neili")*(10-times)/10);
	me->add("fight_times", 1);

	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	
	return 1;
}

int checking(object me, object ob)
{
	object obj;
	int my_max_qi, his_max_qi;

	if ( !present(ob, environment()) ) return 1; 

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if( me->is_fighting() ) 
	{
		if (( (int)me->query("qi")*100 / my_max_qi) <= 80 ) 
		{
			say(GRN "\n江百胜说道： 魏盟主泽被天下，福济苍生， 他老人家算无遗策，功无不克，克无不胜！\n" NOR);
			say(GRN "\n江百胜说道： 魏盟主一句话，属下办事戳力，勇往直前！ 冰天雪地往里闯，刀山火海就敢去！\n" NOR);
			message_vision(HIY "\n江百胜说完，全身不知打哪里冒出来的一股力气，不但功力尽复，拳力也威猛好多倍！\n" NOR, ob);

			me->set("eff_qi", me->query("max_qi"));
			me->set("qi",     me->query("max_qi"));
			me->set("jing",   me->query("max_jing"));
			me->set("jingli", me->query("max_jingli"));
//			me->set("neili",  me->query("max_neili"));
		}
		else if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
		{
			say(GRN "\n江百胜说道： 看来你小子跟我还差着一大截呢，回去练上十年再来吧！\n");
			return 1;
		}

		if ( present(ob, environment()) ) call_out("checking", 1, me, ob);
	}

	return 1;  
}

string check_qualification()
{
	object ob = this_player();
	mapping skill_status;
	string *sname;
        int i, qualified_skills_no = 0;

	if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			if ( ob->query_skill(sname[i],1) >= 90 ) qualified_skills_no++;
		}
	}

	if ( qualified_skills_no > 5 ) {
		ob->set_temp("qualified", 1);
		command( "bow" );
		return "这位"+RANK_D->query_respect(ob)+"请自便。";
	}
	else {
		message_vision("江百胜冷冷地看了$N一眼。\n", ob);
		return "盟主及两位使者没功夫见你。";
	}
}

int accept_object(object who, object ob)
{
        object wage;

        if (who->query_temp("biao/jiang") && ob->name()=="红镖") {
                who->delete_temp("biao/jiang");
		who->delete_temp("apply/short");
                command( "say 有劳这位"+RANK_D->query_respect(who)+"了，你可以走了。");
                wage = new("/clone/money/silver");
                wage->set_amount(5);
                wage->move(who);
                message_vision("江百胜给$N五两白银作为走镖的酬劳。\n", who);
                remove_call_out("destroy_it");
                call_out("destroy_it", 1, ob);
                return 1;
        }

	return 0;
}

void destroy_it(object obj)
{
        destruct(obj);
}
