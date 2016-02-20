//Cracked by Roath
// Npc: /kungfu/class/shaolin/cheng-zhi.c
// Date: YZC 96/01/19
// xQin 8/00

inherit NPC;
inherit F_MASTER;
string ask_for_huansu();
int auto_perform();

void create()
{
	set_name("澄知", ({
		"chengzhi luohan",
		"chengzhi",
		"qingjing",
		"luohan",
	}));
	set("long",
		"他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
		"太阳穴高高鼓起，似乎身怀绝世武功。\n"
	);

	set("nickname", "清净罗汉");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	
	set("inquiry",([
		"还俗" : (:ask_for_huansu:),
	]));
	
	set("age", 60);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 400000);
	set("score", 5000);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("cuff", 130);
        set_skill("luohan-quan", 80);
        set_skill("jingang-quan", 130);
        set_skill("hand", 80);
        set_skill("fengyun-shou", 80);
        set_skill("qianye-shou", 100);
        set_skill("strike", 90);
        set_skill("sanhua-zhang", 90);
	set_skill("parry", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
        map_skill("hand", "fengyun-shou");
        map_skill("strike", "sanhua-zhang");
	map_skill("parry", "jingang-quan");

	prepare_skill("cuff", "jingang-quan");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	create_family("少林派", 37, "弟子");

	setup();

        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}

int auto_perform()
{
        object target = select_opponent();

        if( !objectp(target) )  return 0;

        return perform_action("cuff.jingang");
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

#include "/kungfu/class/shaolin/cheng.h"

