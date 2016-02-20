//Cracked by Roath
// Npc: /kungfu/class/shaolin/hui-he.c
// Date: YZC 96/01/19
// xQin 8/00

inherit NPC;
inherit F_MASTER;
string ask_for_huansu();
string ask_me();

void create()
{
	set_name("慧合尊者", ({
		"huihe zunzhe",
		"huihe",
		"zunzhe",
	}));
	set("long",
		"他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，\n"
		"太阳穴微凸，双目炯炯有神。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 650);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("cuff", 78);
	set_skill("luohan-quan", 78);
	set_skill("parry", 70);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");

	prepare_skill("cuff", "luohan-quan");

	create_family("少林派", 38, "弟子");

	set("inquiry", ([
		"买铁" :    (: ask_me :),
		"还俗" : (:ask_for_huansu:),
	]));

	setup();

        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

#include "/kungfu/class/shaolin/hui.h"

string ask_me()
{
	return "买铁？ 他现在又不缺铁！ 前天老乔不是刚送来一堆铁块，铁手掌什么的给他吗？！";
}

string ask_for_huansu()
{
	object ob, me;
	me=this_player();
	ob=this_object();
	
	if (me->query("gender") != "男性" )
	{
	return "阿弥陀佛！"+RANK_D->query_respect(me)+"不可拿老衲开这种玩笑。";
	}
	if (me->query("class") != "bonze" )
	{
	return "阿弥陀佛！"+RANK_D->query_respect(me)+"本非佛门中人，如何有此一问？";
	}
	if (me->query("family/family_name") != "少林派" )
	{
	return "阿弥陀佛！"+RANK_D->query_respect(me)+"非本门中人，还俗一事老衲不能作主。";
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