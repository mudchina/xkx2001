//Cracked by Roath
inherit NPC;
#include <ansi.h>
#include "/kungfu/class/dali/auto_perform.h"

string ask_me(object);
int do_answer(string);

void create()
{
	set_name("一灯大师", ({ "yideng dashi", "yideng", "dashi" }));
	set("nickname", "南帝");
	set("long", "此人身形高大，两道长长的白眉从眼角垂了下来，面目慈祥，眉\n间虽隐含愁苦，但一番雍容高华的神色，却是一望而知。\n");
	set("gender", "男性");
	set("age", 55);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 30);
	set("int", 50);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 4000);
	set("max_jing",4000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 200);
	set("combat_exp", 3600000);

	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("finger", 400);
	set_skill("kurong-changong", 400);
	set_skill("yiyang-zhi", 400);
	set_skill("cuff", 400);
	set_skill("strike", 400);
	set_skill("buddhism", 400);
	set_skill("sword", 400);
	set_skill("duanshi-shenfa", 400);
	set_skill("duanjia-jian", 400);
	set_skill("qingyan-zhang", 400);
	set_skill("jinyu-quan", 400);
	set_skill("medicine", 300);
	
	map_skill("dodge","duanshi-shenfa");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike","qingyan-zhang");
	map_skill("force", "kurong-changong");
	map_skill("sword","duanjia-jian");
	map_skill("parry", "yiyang-zhi");
	map_skill("finger", "yiyang-zhi");
	prepare_skill("finger", "yiyang-zhi");
	prepare_skill("strike", "qingyan-zhang");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
	        (: auto_perform :),
	}) );

	set("inquiry", ([
	        "name" : "贫僧法号一灯。\n",
	        "here" : "这里是贫僧隐居的地方，阁下请看这山清水秀，好个修行之所啊。\n",
	        "疗伤" : (: ask_me :),
	        "治疗" : (: ask_me :),
	]) );

	create_family("大理段家", 14, "弟子");
	setup();
	carry_object("/d/shaolin/npc/obj/cloth")->wear();
//	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	object ob,who=this_player(),me=this_object();
	if (interactive(ob=this_player())
		&& ob->query("family/master_id") == "yideng dashi"
		&& ob->query("shen") < 0 )
	{
		command("look "+getuid(ob));
		command("sigh");
		command("say "+RANK_D->query_respect(ob)+"你即入了我门却还心存恶念，不能善心修佛，你...你...去吧！");
		command("expell "+ob->query("id"));
	}
	if(interactive(ob=this_player())
		&& ob->query("gender") == "无性" 
		&& ob->query("family/master_id") == "yideng dashi")
	{
		command("look "+getuid(ob));
		command("sigh");
		command("say "+RANK_D->query_respect(ob)+"即入了我门却又投入东厂门下，为师无法再留你，你...你...去吧！");
		command("expell " + ob->query("id"));
	}
	/* 
	if (!userp(who)
		&& ob->query("family/family_name") != "大理段家"
		&& environment()==find_object("/d/dali/yideng12.c"))
	{
		message_vision("$N对$n喝到：“你是谁？！怎么闯到这里来的？！\n",me,who);
		message_vision("$N双掌合十，道：“善哉，善哉，我佛慈悲，也有狮子吼。让老衲我送你一程吧。”\n",me);
		kill_ob(who);
	}
	*/

	  add_action("do_answer","answer");
}

void attempt_apprentice(object ob)
{
	if (ob->query("family/family_name")!="大理段家")
	{
		command("say "+RANK_D->query_respect(this_player())+"是别派的高手，大理荒僻之乡不敢多留。");
		return;
	}

	if (ob->query("shen")<0)
	{
		command("say 善哉！善哉！这位施主面带乖张之色，老衲佛法低浅，怕是化解不了。");
		return;
	}

	if (ob->query_skill("kurong-changong", 1)<80)
	{
		command("say "+RANK_D->query_respect(this_player())+"你的内功尚未登堂入室，还是再修练修练去吧。");
		return;
	}

	if (ob->query_skill("finger", 1)<80)
	{
		command("say "+RANK_D->query_respect(this_player())+"指力尚弱，怕是体会不了我的一阳指，还是再修练修练去吧。");
		return;
	}

	if (ob->query_skill("yiyang-zhi", 1)<50)
	{
		command("say "+RANK_D->query_respect(this_player())+"指力尚弱，怕是体会不了我的一阳指，还是再修练修练去吧。");
		return;
	}

	if (ob->query_str()<25)
	{
		command("say "+RANK_D->query_respect(this_player())+"两臂乏力，怕是难以体会上乘武功。");
		return;
	}

	if (ob->query_int()<32)
	{
		command("say "+RANK_D->query_respect(this_player())+"天资愚鲁，怕是难以体会上乘武功。");
		return;
	}

	if (ob->query_con()<26) {
		command("say "+RANK_D->query_respect(this_player())+"体质太弱，怕是难以体会上乘武功。");
		return;
	}

	if (ob->query_dex()<26) {
		command ("say "+RANK_D->query_respect(this_player())+"身为习武之人却如此呆胖，老衲怎能收你。");
		return;
	}

    command("say 好吧，我就收下你了。但愿你心存善念，向佛终身。");
	ob->set_temp("title", ob->query("title"));
	command("recruit " + ob->query("id"));
	ob->set("title", ob->query_temp("title"));
	ob->delete_temp("title");
	return;
}

string ask_me(object who)
{
	object me;
	me=this_player();

	if (environment(me)!=find_object("/d/dali/yideng12.c"))
		return "施主问的是什么？贫僧不知道啊。\n";
	if (me->query_temp("yideng_asked"))
		return "你需要治疗吗？\n";
	else {
		if (me->query("family/master_id")=="yideng dashi")
		{
			me->set_temp("yideng_asked",1);
			return "我徒虔心向佛，为师的自然有义务为你治疗，但不知徒儿你是否需要？\n";
		}
		else {
			me->set_temp("yideng_asked",1);
			return "施主既然有缘到来舍下，贫僧自有义务尽地主之宜为阁下治疗，不知阁下是否需要？\n";
		}
	}
}

void do_answer(string arg)
{
	object me;
	me=this_player();

	if (arg=="需要治疗" && me->query_temp("yideng_asked"))
	{
		tell_object(me, "你请求一灯大师为你运功治疗。\n");
		me->delete_temp("yideng_asked");
		if (me->query("dali/yideng_rewarded"))
		{
			command("look "+getuid(me));
			command("say 由老衲治疗一次，你已经得尽天缘了，唉。。。");
			command("say 为人岂可贪得无厌，唉，请你离开这里吧。");
			message_vision("$N羞愧难当，面色通红，灰溜溜地离开了。\n", me);
			me->move("/d/dali/maze1");
			return;
		}
		if (me->query("family/master_id")=="yideng dashi")
		{
			command("pat "+getuid(me));
			command("smile");
			command("say 好的，为师这就给你治疗。你随我到禅房来。");
			me->set_temp("yideng_waitreward",1);
			me->delete_temp("yideng_asked");
			this_object()->move("/d/dali/yideng10.c");
			me->move("/d/dali/yideng10.c");
			command("say 你准备好了就告诉我。");
			return;
		}
		if (me->query("kar")>random(30))
		{
			command("look "+getuid(me));
			command("smile");
			command("say 好的，老衲这就给你治疗。你随我到禅房来。");
			me->set_temp("yideng_waitreward",1);
			me->delete_temp("yideng_asked");
			this_object()->move("/d/dali/yideng10.c");
			me->move("/d/dali/yideng10.c");
			command("say 你准备好了就告诉我。");
			return;
		}
		else {
			command("look "+getuid(me));
			command("sigh");
			command("say 实在抱歉，施主您缘分不够，老衲不能为你治疗。");
			command(":(");
			me->delete_temp("yideng_asked");
			me->set("dali/yideng_rewarded",1);
			return;
		}
	}
	if (arg=="我准备好了"
		&& me->query_temp("yideng_waitreward")
		&& environment(me)==find_object("/d/dali/yideng10.c"))
	{
		command("nod");
		command("say 你坐正，我这就开始为你治疗了。");
		write("一灯当即闭目垂眉，入定运功，忽的跃起，左掌捂胸，右手伸出 \n");
		write("食指，缓缓的向你头顶百会穴点去。你身不由几的微微一跳，\n");
		write("只觉的一股热气从顶门直透下来。\n");
		write("一灯一指点过，立即缩回，第二指已向点向你的百会穴后一寸五\n");
		write("分处的后顶穴，接着强间，脑户，风府，大锥，陶道，身柱，\n");
		write("神道，灵台一路点将下来。一支香燃了一半，已将你督脉的三十 \n");
		write("大穴顺次点到。\n");
		message_vision(HIR "$N突然觉得一股暖流自顶而入，眼前一黑就什么也看不见了！\n" NOR, me );
		me->unconcious();
		
	if (me->query("family/master_id")=="yideng dashi")
	{
		me->set("con", me->query("con")+2);
		me->set("dex", me->query("dex")+1);
		me->set("str", me->query("str")+1);
	}
		me->add("max_neili",150);
		me->add("combat_exp",15000);
		me->set("dali/yideng_rewarded",1);
		me->delete_temp("yideng_waitreward");
		this_object()->move("/d/dali/yideng12.c");
		me->move("/d/dali/yideng12.c");
		return;
	}
	return;
}
