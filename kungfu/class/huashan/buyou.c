//Cracked by Roath
// buyou.c 成不忧
// qfy Nov 14, 1996

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_SSERVER;
string ask_me();
private int check_env(object me);

void create()
{
	set_name("成不忧", ({ "cheng buyou", "cheng", "buyou" }));
	set("long", 
"成不忧是华山剑宗弟子。剑气之争剑宗一败涂地，他与封不平隐\n"
"居苦练，誓雪此辱。他剑法了得，已获剑宗真传。\n");
	set("gender", "男性");
	set("age", 41);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 25);
	set("int", 22);
	set("con", 25);
	set("dex", 25);
	set("shen", 0);
	
	set("max_qi", 1000);
	set("max_jing", 800);
	set("neili", 1100);
	set("max_neili", 1100);
	set("jiali", 50);
	set("combat_exp", 500000);
	set("score", 5000);
	set("huashan/feilong", 1);

	set_skill("force", 90);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword", 120);
	set_skill("strike", 95);
	set_skill("cuff", 95);
	set_skill("huashan-shenfa", 100);
	set_skill("zixia-gong", 90);
	set_skill("huashan-jianfa", 120);
	set_skill("hunyuan-zhang",95);
	set_skill("pishi-poyu", 95);
	set_skill("ziyin-yin", 80);
	set_skill("zhengqi-jue", 80);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike","hunyuan-zhang");
	map_skill("dodge","huashan-shenfa");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("华山派", 13, "剑宗弟子");
	
	set("inquiry", ([
	    "剑宗" : "剑宗才是华山的正统，以剑为宗，以气为辅，才是武学的精要。\n",
	    "气宗" : "哼！气宗武功庸俗不堪，奉气轻剑，乱七八糟。\n",
	    "岳不群" : "别提那伪君子！可恶！\n",
	    "华山剑法" : "那便是本派绝学，天下一等一的剑法！尤其是「天外飞龙」一招，飞剑杀敌，无人能挡。\n",
	    "紫霞功" : "那是本门内功心法。\n",
	    "思过崖" : "那是本派弟子修行思过之处。\n",
	    "风清扬" : "啊！我已多年不见风师叔，不清楚他的下落。\n",
	    "飞剑" : "「天外飞龙」是本派绝招，飞剑出击，中者立毙！\n",
	    "飞剑杀敌" : "「天外飞龙」是本派绝招，飞剑出击，中者立毙！\n",
	    "天外飞龙" : (: ask_me :),
	]));

	setup();
	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
	object ob, me = this_object();

	if ( interactive(ob=this_player()) ) {
	   if ( !me->is_fighting() ) {
		remove_call_out("rand_move");
		call_out("rand_move", 3+random(4), me);
	   }
	   else if ( ob->query("id") == me->query_temp("target") ) {
		message_vision( "$n对着$N大喝：怨家路窄！咱们又砰头了，纳命来吧！\n", ob, me );
		me->kill_ob(ob);

		remove_call_out("rand_move");
		remove_call_out("checking");
		call_out("checking", 1, me, ob);
	   }
	}
		
	add_action("do_kill", "kill");
	add_action("do_kill", "sha");
}

int rand_move(object me)
{
	object here = environment(me);

	if ( file_name(here) == "/d/village/sexit" ) {
		command( "go north" );
	}
	else if ( file_name(here) == "/d/huashan/qingke" ) {
		command( "go northdown" );
	}
	else if ( file_name(here) == "/d/huashan/hsstreet2" 
	|| file_name(here) == "/d/huashan/hsstreet3" ) {
		if (random(2) == 1) command( "go east" );
		else command("go west");
	}
	else random_move();

	check_env(me);
	remove_call_out("rand_move");
	call_out("rand_move", 3+random(4), me);

	return 1;
}

private int check_env(object me)
{
	object *inv;
	object victim, target;
	int i;

	inv = all_inventory(environment(me));

	for( i=0; i<sizeof(inv); i++ ) {
	     if ((string)inv[i]->query("race") == "人类" && inv[i] != me ) {
		if ( (!inv[i]->query("family") || inv[i]->query("family/family_name")!="华山派" )
		&& inv[i]->is_killing() ) {
			victim = offensive_target(inv[i]);

		    	if ( objectp(victim) && victim != me && victim->query("family/family_name")=="华山派" ) {
				remove_call_out("rand_move");
				target = inv[i];
				remove_call_out("rescue_huashan");
				call_out("rescue_huashan", 1, target, victim);
				
				return;
			}
		}
	     }
  	}

	return 1;
} 

int rescue_huashan(object target, object victim)
{
	object me = this_object();

	me->set_temp("target", target->query("id"));
	me->set_leader(target);
	
	message_vision("$N对$n大吼道：岂有此理！竟敢在华山的地方残杀华山弟子。让我送你归西！\n", me, target);
	command("say "+victim->name()+"你快走，这里一切有我！");
	message_vision("$N说着长剑一旋，冲上前将$n的攻击尽数接了过去。\n\n", me, target);
	target->remove_enemy(victim);
	victim->remove_enemy(target);
	me->kill_ob(target);
	target->kill_ob(me);
	remove_call_out("checking");
	call_out("checking", 1, me, target);

	return 1;
}

int do_kill()
{
	object me = this_object();

	remove_call_out("env_check");
	call_out("env_check", 1, me);

	return 0;
}

int env_check(object me)
{
	check_env(me);

	return 1;
}

int accept_fight(object ob)
{
	object me = this_object();
	int my_max_qi = me->query("max_qi");

	if ( me->query("qi")*100 / my_max_qi <= 80 ) {
		remove_call_out("checking");
		call_out("checking", 1, me, ob);
		return 0;
	}       

	remove_call_out("rand_move");
	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	return 1;
}

int accept_kill(object ob)
{
	object me = this_object();

	command("say 好家伙，让你尝尝华山剑法的历害，让你死得瞑目！");
	
	remove_call_out("rand_move");
	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	return 1;
}

int checking(object me, object ob)
{
	int b, my_max_qi = me->query("max_qi");
	object weapon, env = environment(me);

	if ( me->is_fighting() ) {
/*	   if ( random(10) == 8 && me->query("neili") > 300 
	   && me->query_temp("weapon")->query("skill_type") == "sword") {
		message_vision(HIR"\n$N大喝一声：看我的天外飞龙！\n"NOR, me);
		command("perform feilong");
	   }
*/
	   if ( !me->query_temp("weapon") && (present("changjian", env) 
	   || present("duanjian", env) || present("zhujian", env)) ) {
		command("get jian");
		command("wield jian");
	   }

	   if ( (me->query("qi")*100 / my_max_qi) <= 80 ) {
		command("exert recover");
	   }

	   call_out("checking", 1, me, ob);
	   return 1;
	}

	if ( me->query_temp("target") ) {
	   if ( !ob=find_player(me->query_temp("target")) ) {
		message_vision("$N悻悻说道：算这家伙跑得快！\n", me);

		remove_call_out("rand_move");
		call_out("rand_move", 1, me);
	   }
	   else if ( ob->is_ghost() ) {
	   	if ( !me->query_temp("weapon") ) {
			command("get jian from corpse");
			command("wield jian");  
	   	}
	   	message_vision("$N在尸体的衣服上将剑上的血拭抹干净，得意地「嘿嘿嘿」奸笑了几声。\n", me);
	   
	   	remove_call_out("rand_move");
	   	call_out("rand_move", 1, me);
	   }
	   else if ( present(ob, env) && !me->is_fighting() ) {
	   	message_vision( "$n对着$N大喝：还想逃？给我纳命来吧！\n", ob, me );
		me->kill_ob(ob);

	   	remove_call_out("checking");
	   	call_out("checking", 1, me, ob);
	   }
	   else if ( !me->is_fighting() ) {
		message_vision("$N悻悻说道：算这家伙跑得快！\n", me);

		remove_call_out("rand_move");
		call_out("rand_move", 1, me);
	   }
	
	   return 1;
	}

	if ( !me->is_fighting() ) {
	   message_vision("$N拱手说道：在下尚有要事在身，恕不奉陪！\n", me);

	   remove_call_out("rand_move");
	   call_out("rand_move", 1, me);
	   return 1;
	}
}

string ask_me()
{
	object ob = this_player(), me = this_object();
	mapping obfam;
	obfam = (mapping)ob->query("family");

	if ( !obfam || obfam["family_name"] != "华山派" ) {
	   if ( ob->query_temp("feilong") < 3 ) {
		command( "sneer" );
		ob->add_temp("feilong", 1);
		return "咱们豪无渊源，你问这做什么？还是别太好奇的好。\n";
	   }
	   else {
		message_vision("$N脸色微变，目中阴鹭一闪，发出一阵冷笑。\n", me);
		ob->delete_temp("feilong");
		me->kill_ob(ob);
		remove_call_out("checking");
		call_out("checking", 1, me, ob);
		return "你三番四次想探听华山剑法的奥密，居心叵测！是否想对本派不利？你即然对华山剑法如此憧景，只好用华山剑法送你上路了。\n";
	   }
	}
	
	command( "look "+ob->query("id") );

	if ( ob->query_skill("huashan-jianfa", 1) < 100 )
		return "你的华山剑法修为不够，学不了「天外飞龙」。";

	if ( ob->query_skill("zixia-gong", 1) < 70 )
		return "剑宗以剑为宗，以气为辅，并非弃气不用，你的紫霞功可得再下一番苦功。";

	if ( ob->query_skill("zixia-gong", 1) > ob->query_skill("huashan-jianfa", 1) ) {
		command( "sneer" );
		return "你是气宗的人，却来向我请教，教我如何担当得起？";
	}

	if ( ob->query("huashan/feilong") )
		return "咦，我封师哥不是传了你「天外飞龙」吗？多下功夫好好练习，别堕了华山剑宗的威名！";

	return "好！你去找我封师哥学「天外飞龙」吧。他便隐居在华山深山里。";
}

void unconcious()
{
	object me = this_object();

	if ( !me->query_temp("performed") ) {
		me->set("neili", 500);
		me->set("jingli", 500);
		me->set("qi", 50);
		me->set_temp("performed", 1);
		command("perform feilong");

		return;
	}

//	message_vision("$N趁机连忙遁走。\n", me);
//	destruct(me);
	
	remove_call_out("checking");
	remove_call_out("rand_move");

        me->disable_player(" <昏迷不醒>");
        me->set("jing", 0);
        me->set("qi", 0);
        COMBAT_D->announce(me, "unconcious");

        call_out("revive", random(100 - query("con")) + 30);
}

varargs void revive(int quiet)
{
        remove_call_out("revive");
        while( environment()->is_character() )
		this_object()->move(environment(environment()));
        this_object()->enable_player();
        COMBAT_D->announce(this_object(), "revive");
	remove_call_out("rand_move");
	call_out("rand_move", 1, this_object());
}

void die()
{
        object corpse, ling;
	mixed killer;

	remove_call_out("checking");
	remove_call_out("rand_move");

	if( !living(this_object()) ) revive(1);
	COMBAT_D->announce(this_object(), "dead");

	if( objectp(killer = query_temp("last_damage_from"))){
                set_temp("my_killer", killer->query("id"));
                COMBAT_D->killer_reward(killer, this_object());
	}

	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());

        this_object()->remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());
	
	destruct(this_object());

//	message_vision("\n$N死了！\n", this_object());
//	destruct(this_object());
}
