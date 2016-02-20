//Cracked by Roath
// Npc: /kungfu/class/shaolin/xuan-ku.c
// Date: YZC 96/01/19
// xQin 8/00

inherit NPC;
inherit F_MASTER;
string ask_for_huansu();
int auto_perform();
string ask_me();

void create()
{
	set_name("玄苦大师", ({
		"xuanku dashi",
		"xuanku",
		"dashi",
	}));
	set("long",
		"他是一位白须白眉的老僧，身穿一袭银丝棕黄袈裟。他身材瘦高，\n"
		"脸上满布皱纹，手臂处青筋绽露，似乎久经风霜。\n"
	);

	set("nickname", "罗汉堂首座");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("force", 150);
	set_skill("hunyuan-yiqi", 150);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 150);
        set_skill("cuff", 120);
        set_skill("luohan-quan", 120);
        set_skill("club", 120);
        set_skill("weituo-gun", 120);
        set_skill("strike", 120);
        set_skill("sanhua-zhang", 120);
        set_skill("hand", 120);
        set_skill("qianye-shou", 120);
        set_skill("blade", 150);
        set_skill("xiuluo-dao", 150);

	set_skill("parry", 150);
	set_skill("buddhism", 150);
	set_skill("literate", 150);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
        map_skill("club", "weituo-gun");
        map_skill("strike", "sanhua-zhang");
        map_skill("hand", "qianye-shou");
	map_skill("parry", "xiuluo-dao");
	map_skill("blade", "xiuluo-dao");

	prepare_skill("cuff", "luohan-quan");

	create_family("少林派", 36, "弟子");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: auto_perform :), }));

	set("inquiry", ([
		"十八罗汉阵"       : (: ask_me :),
		"罗汉大阵"	   : (: ask_me :),
                "zhen" : (: ask_me :),
                "还俗" : (:ask_for_huansu:), 
	]));

	setup();

        carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
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
#include "/kungfu/class/shaolin/xuan-ku.h"
#include "/kungfu/class/shaolin/auto_perform.h"



