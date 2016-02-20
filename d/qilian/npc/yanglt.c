//Cracked by Roath
// yanglt.c 杨莲亭

#include <ansi.h>
inherit NPC;

string ask_job();
int ask_dongfang();
private int is_suitable(object target, object me);

void create() 
{
	set_name("杨莲亭", ({ "yang lianting", "yang", "lianting" }));
	set("title", "日月神教总管");
	set("long", "这便是当今日月神教的权高位重的大总管，长得十分威武神气。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 21);
	set("int", 20);
	set("con", 26);
	set("dex", 21);
	
	set("max_qi", 1500);
	set("max_jing", 1200);
	set("neili", 1600);
	set("max_neili", 1600);
	set("jiali", 50);
	set("combat_exp", 100000);
	set("score", 500);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("strike", 100);
	set_skill("cuff", 100);

	set("inquiry", ([
	    "任务" : (: ask_job :),
	    "job" : (: ask_job :),
		"东方不败" : (: ask_dongfang :),
	]));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

string ask_job()
{
	object ob = this_player();
	object me = this_object();
	object *ppls, *targets, list;
	int i, j = 0, l, *k, m = 0, num, chosen;
	string names = "";

	if ( strsrch(file_name(environment(me)), "/d/qilian/zhengtang") == -1 )
		return "本总管现有要事在身，要差事的话到日月神教祁连分舵来见我。";

	if ( ob->query("combat_exp") < 400000 && ob->query("combat_exp") > 50000 ) {
		message_vision("$N冷冷地看了$n一眼，一副爱睬不睬的神气。\n", me, ob);
		return "就凭你这点本事，也能为本教办事？好好的多练几年再来吧！";
	}

	if ( ob->query_temp("rysj/job") ) {
		return "你不是已经领了差事了吗？多下点心机去办事吧！";
	}

	message_vision("$N脸上顿时浮起笑容道：难得"+ob->name()
	+RANK_D->query_respect(ob)+"愿意为本教出力，实在是太好了！\n", me);
	message_vision("$N非常痛快的说道：只要你好好为本教办事，本总管一定不吝重赏！\n", me);
	message_vision("$N转身走向身后的书台拿起一本册子，说道：让本总管查查目前本教的死敌．．．\n", me);
	
	ppls = users();
	targets = allocate(sizeof(ppls));
	k = allocate(5);

	for ( i=0; i<sizeof(ppls); i++ ) {
		if ( is_suitable(ppls[i], ob) ) {
			targets[j] = ppls[i];
			j++;
		}
	}
	
	if ( !j ) {
		message_vision("过了一会儿，$N皱眉说道：看来目前没有适合你的任务。\n", me);
		return "你还是下次再来吧。\n";
	}
	else {
		list = new("/d/qilian/npc/obj/list");
		list->move(me);

		ob->delete_temp("rysj");

		if ( j > 5 ) {
			num = 5;

			for ( i=0; i<num; i++ ) {
				l = random(j);
				chosen = 0;

				for ( m=0; m<i; m++ ) {
					if ( k[m] == l ) {
						chosen = 1;
						i = i - 1;
					}
				}
	
				if ( !chosen ) {
					k[m] = l;
					ob->set_temp("rysj/target"+m, targets[l]->query("id"));
					list->set("name"+m, targets[l]->short(1));
				}
			}
		}
		else {
			num = j;

			for ( i=0; i<j; i++ ) {
				ob->set_temp("rysj/target"+i, targets[i]->query("id"));
				list->set("name"+i, targets[i]->short(1));
			}
		}

		ob->set_temp("rysj/job", 1);

		for ( i = 0; i<num; i++ ) {
			names += list->query("name"+i)+"\n";
		}

		list->set("long", names);
	}

	command("give "+ob->query("id")+" rysj list");
	return "这是你目标的名单，把名单上任何一人生擒交给本总管便算完成任务了！\n";
}

private int is_suitable(object target, object me)
{
	int value1, value2;

	value1 = target->query("combat_exp") * 10;
	value2 = me->query("combat_exp");

	if ( value2 < 50000 && value1 > value2*10 && !wizardp(target) 
	&& target->query("id") != me->query("rysj/last") ) {
		// let dummies have some fun catching people
		return 1;
	}

	if ( value1 < value2*8 || value1 > value2*12 || target->query_temp("rysj/job")
        || target->is_ghost() || target == me || wizardp(target) 
	|| target->query("id") == me->query("rysj/last") ) {
                return 0;
        }

        return 1;
}

int accept_object(object me, object obj)
{
	object ob = this_player();
	int i, success = 0;

	if ( strsrch(file_name(environment(me)), "/d/qilian/zhengtang") == -1 )
		return 0;

	if ( ob->query_temp("rysj/job") && userp(obj) ) {
		for ( i=0; i<5; i++ ) {
			if ( ob->query_temp("rysj/target"+i) == obj->query("id") ) success++;
		}
	
		if ( success ) {
			remove_call_out("reward_dest");
	   		call_out("reward_dest", 1, obj, ob);
		}
		else {
			remove_call_out("scold_failure");
			call_out("scold_failure", 1, obj, ob);
		}

	   	return 1;
	}
	else if ( userp(obj) ) {
		command( "?" );
		command( "say 你这是什么意思？带此人上本教做什么？" );
	}
	else {
		command( "?" );
		command( "say 你给我这东西做什麽？" );
	}

	return 0;
}

int scold_failure(object obj, object ob)
{
	object me=this_object();

	message_vision("$N对$n破口大骂：混蛋！你怎么随便捉个人回来充数？你当本总管可欺么？\n", me, ob);
	message_vision("$N接着指着$n，高声叫道：来人！将这个窝囊废撵出去！\n", me, obj);

	message_vision("门口进来两个日月神教侍卫，对$N一行礼，马上将$n拖了出去。\n", me, obj);
	obj->move("/d/qilian/qitian");

	if ( ob->query_temp("rysj/fail") ) {
		message_vision("$N气得满脸通红，大声咆哮道：饭桶！一点儿小事也办不好！好好地在牢里待着吧！\n", me);
		message_vision("$N伸手往墙上某处一按，$n站立之处登时裂开一洞！\n", me, ob);
		message_vision("$N一声惊呼，人已身不由己的往洞里跌了下去！\n", ob);
		ob->move("/d/qilian/dilao");
		ob->delete_temp("rysj");
	}
	else {
		message_vision("$N转过身来指着$n的鼻子说道：你立刻给本总管将名单上的要犯捉来，不然要你好看！\n", me, ob);
		ob->set_temp("rysj/fail", 1);
	}

	return 1;
}
	
int reward_dest(object obj, object ob)
{
	object me=this_object();
  	int exp, amount;

	if ( ( exp = obj->query("combat_exp") ) >= 320000 ) amount = exp/1000;
	

	if ( amount < 1000 ) {
		amount = 1000;
	}
	else if ( amount > 3000 ) {
		amount = 3000;
	}

	ob->delete_temp("rysj");
	ob->add("rysj/success", 1);
	ob->set("rysj/last", obj->query("id"));

	if ( ob->query("combat_exp") < 50000 ) {
		ob->add("combat_exp", amount/100);
	}
	else {
		ob->add("combat_exp", amount);
	}

	if ( obj->query_temp("sangong_once") ) {
		obj->add("mz_neili", -(amount/10));
	}
	
	obj->add("max_neili", -(amount/10));
	obj->add("eff_jingli", -(amount/10));

	log_file("RYSJ_JOB", sprintf("%s caught %s and gained %d exp.\n", geteuid(ob), geteuid(obj), amount));

	command("thumb "+ob->query("id"));
	command("say "+ob->name()+RANK_D->query_respect(ob)+"为本教不辞劳苦，立下汗马功劳，本总管自当重重有赏！");
	tell_object(ob, "你的经验增加了！\n");
	//add by wzfeng .about pixie quest
	ob->add("rysj_reward",1);

	message_vision("$N接着指着$n，高声叫道：来人！将这个重犯关进地牢里去！\n", me, obj);
	message_vision("门口进来两个日月神教侍卫，对$N一行礼，马上将$n拖了出去。\n", me, obj);
        obj->move("/d/qilian/dilao");

	message_vision("$N回过头来笑咪咪地对$n说道：你辛苦了，快退下去休息吧。\n", me, ob);

	return 1;
}

int accept_fight(object victim)
{
	object me=this_object();

	if ( me->query("combat_exp") > victim->query("combat_exp") )
		return 1;
	else
		return 0;
}

int accept_kill(object victim)
{
	object me=this_object();
	int i;

        if ( strsrch(file_name(environment(me)), "/d/qilian/zhengtang") == 0 ) {
		command("hehe");
		message_vision("$N不屑地说道：胆敢在日月神教里撒野，简直是找死！\n", me);
		message_vision("$N伸手往墙上某处一按，$n站立之处登时裂开一洞！\n", me, victim);
		message_vision("$N一声惊呼，人已身不由己的往洞里跌了下去！\n", victim);
		victim->move("/d/qilian/dilao");
		message("vision", victim->name() + "突然由墙上开启的洞口滚了出来。\n", environment(victim), ({victim}) );
	}

	return 1;
}


//add by wzfeng
int ask_dongfang()
{
	object obj;
	object me = this_player();
	object ob = this_object();
	
	if(me->query("rysj_reward")<3)
	{
		message_vision("$N不屑地对$p说道：你为本教办事太少，不忠于本教，东方教主那有功夫接见汝等小辈。\n", ob,me);
		return 1;
	}
	if(obj = find_object("/d/qilian/droom"))
	{
		message_vision("$N对$p说道：东方教主教务繁忙，等他清闲的时候再带你去吧。\n", ob,me);
		return 1;
	}
	else
        {
        message_vision("$N对$p说道：看在你为本教尽心办事的份上，就让你见见我们东方教主。\n", ob,me);
        message_vision("$N在墙边隐秘出一按，厅堂边上开除一道侧门。\n", ob,me);
        tell_object(me,"你向侧门走了进去。\n");
        me->add("rysj_reward",-3);
        me->move("/d/qilian/droom");
		me->set("can_dfbb",1);
        }
        
        return 1;
}
