//Cracked by Roath
// Npc: /kungfu/class/shaolin/dao-jue.c
// Date: YZC 96/01/19
// xQin 8/00

inherit NPC;
inherit F_MASTER;
string ask_for_huansu();

void create()
{
	set_name("道觉禅师", ({
		"daojue chanshi",
		"daojue",
		"chanshi",
	}));
	set("long",
		"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
		"刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("inquiry",([
	"还俗" : (:ask_for_huansu:),
	
	]));
	
	set("age", 40);
	set("shen_type", 1);
	set("str", 22);
	set("int", 20);
	set("con", 21);
	set("dex", 22);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp", 80000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
        set_skill("cuff", 52);
        set_skill("luohan-quan", 52);
	set_skill("hand", 53);
	set_skill("fengyun-shou", 53);
	set_skill("parry", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "fengyun-shou");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "fengyun-shou");

	prepare_skill("cuff", "luohan-quan");
        prepare_skill("hand", "fengyun-shou");

	create_family("少林派", 39, "弟子");

	setup();

        carry_object("/d/shaolin/obj/dao-cloth")->wear();
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
#include "/kungfu/class/shaolin/dao.h"

