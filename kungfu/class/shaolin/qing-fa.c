//Cracked by Roath
// Npc: /kungfu/class/shaolin/qing-fa.c
// Date: YZC 96/01/19
// xQin 8/00
// xiaojian Jan 19,2001 for fixing chujia bug

inherit NPC;
inherit F_MASTER;

string ask_for_huansu();
string ask_for_join();

void create()
{
	set_name("清法比丘", ({
		"qingfa biqiu",
		"qingfa",
		"biqiu",
	}));
	set("long",
		"他是一位体格强健的壮年僧人，他生得虎背熊腰，全身似乎蕴含\n"
		"着无穷劲力。他身穿一袭白布黑边袈裟，似乎身怀武艺。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("inquiry",([
		"剃度"	: (: ask_for_join :),
		"出家"	: (: ask_for_join :),
		"还俗" : (:ask_for_huansu:),
	]));

	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 17);
	set("con", 50);
	set("dex", 21);
	set("max_qi", 450);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 40000);
	set("score", 100);

        set_skill("force", 30);
        set_skill("hunyuan-yiqi", 30);
        set_skill("dodge", 50);
        set_skill("shaolin-shenfa", 50);
        set_skill("cuff", 50);
        set_skill("luohan-quan", 50);
        set_skill("jingang-quan", 50);
        set_skill("club", 50);
        set_skill("weituo-gun", 50);
        set_skill("parry", 30);
        set_skill("buddhism", 30);
        set_skill("literate", 30);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff",  "luohan-quan");
        map_skill("club",  "weituo-gun");
        map_skill("parry", "weituo-gun");

        prepare_skill("cuff",  "luohan-quan");

        set_temp("apply/damage", 30);
        set_temp("apply/attack", 20);

        prepare_skill("cuff", "jingang-quan");

        create_family("少林派", 40, "弟子");

	setup();

        carry_object("/clone/weapon/qimeigun")->wield();
        carry_object("/d/shaolin/obj/qing-cloth")->wear();
}

string ask_for_join()
{
	object me;

	me = this_player();

	if (me->query("quit/bonze"))
	{
		return "阿弥陀佛！施主既然已经还俗又因何再提出家之事？";
	}
	if( (string)me->query("class")=="bonze" )
		return "阿弥陀佛！你我同是出家人，何故跟贫僧开这等玩笑？\n";
	if ( (string)me->query("class") =="taoist" )
		return "阿弥陀佛！施主已经是道家人，何故跟贫僧开这等玩笑？\n";

	if( (string)me->query("gender") != "男性" )
		return "阿弥陀佛！善哉！善哉！女施主若真心皈依我佛，可去后山庵里受戒。\n";

	me->set_temp("pending/join_bonze", 1);

	add_action("do_kneel", "kneel");
	return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下(kneel)受戒。\n";
}

int do_kneel()
{
	object me = this_player();

	string *prename =
	 ({ "虚", "空", "明", "净" });
	string name, new_name;

	if( !me->query_temp("pending/join_bonze") )
		return 0;

	message_vision(
		"$N双手合十，恭恭敬敬地跪了下来。\n\n"
		"$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n",
		me, this_object() );
	name = me->query("name");
	new_name = prename[random(sizeof(prename))] + name[0..1];
	command("say 从今以后你的法名叫做" + new_name + "。");
	command("smile");
	me->delete_temp("pending/join_bonze");
	me->set("name", new_name);
	me->set("class", "bonze");
	me->set("K_record", me->query("PKS") + me->query("MKS"));
	me->set("shen_record", me->query("shen"));
        	me->set("shen", 0);

	return 1;
}

void attempt_apprentice(object ob)
{
	mapping fam;

	if( ob->query("family/family_name") == "少林派" 
	&& ob->query("generation") <= this_object()->query("generation") )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	if( ob->query("family/family_name") != "少林派"
	&&  (ob->query("combat_exp") >= 10000 || ob->query("rank") >= 2)        )
	{
		command ("say 阿弥陀佛！ 施主是别派的武功高手，本寺可不敢收留！");
		return;
	}

	if( (string)ob->query("gender") == "女性" )
	{
		command ("say 阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。");
		return;
	}
	
	if( (string)ob->query("class")!="bonze" )
	{
		command ("say 阿弥陀佛！贫僧就收下你做『俗家弟子』了。");
	}
	else    command ("say 阿弥陀佛，善哉！善哉！");

	command("recruit " + ob->query("id"));
}

string ask_for_huansu()
{
	object ob, me;
	me=this_player();
	ob=this_object();
	
	if (me->query("gender") != "男性" )
	{
	return "阿弥陀佛！"+RANK_D->query_respect(me)+"不可拿贫僧开这种玩笑。";
	}
	if (me->query("class") != "bonze" )
	{
	return "阿弥陀佛！"+RANK_D->query_respect(me)+"本非佛门中人，如何有此一问？";
	}
	if (me->query("family/family_name") != "少林派" )
	{
	return "阿弥陀佛！"+RANK_D->query_respect(me)+"非本门中人，还俗一事贫僧不能作主。";
	}
	if (me->query("family/master_id") == ob->query("id"))
	{
	add_action("do_jueding", "想清楚了");
	me->set_temp("pending/quit_bonze", 1);
	command("sigh "+me->query("id"));
	return "既然你与佛无缘，为师也不便强求，但是你将被逐出师们，你可要想清楚了。\n"
	       "(type 想清楚了)";
	} 
	else {
	return "还俗一事还请这为"+RANK_D->query_respect(me)+"和本寺其他长老商议，贫僧作不了主。\n";
	}
}

int do_jueding()
{
	object ob,me;
	me=this_player();
	ob=this_object();
	
	if (!me->query_temp("pending/quit_bonze"))
	return 0;
	
	command("sigh "+me->query("id"));
	message_vision("$N恭恭敬敬的跪下，低声说道：“请恕徒儿不肖。”\n",me);
	message_vision("$n把$N扶了起来，又给了$N一件布衣。\n",ob,me);
	command("say 施主保重，今后好自为之！");
	me->delete_temp("pending/quit_bonze");
	me->set("quit/bonze", 1);
	me->delete("class", "bonze");
	ob=new("/clone/misc/cloth.c");
	ob->move(me);
	command("expell "+me->query("id"));
	return 1;
}

	
