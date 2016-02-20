//Cracked by Roath
// due.c
// xQin 8/00

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "/kungfu/class/shaolin/auto_perform.h";
int auto_perform();
string ask_me();
string ask_for_huansu();
string ask_damo();
string rumor(object place, object holder);

string* places = ({
	"/d/qilian/mine",
	"/d/qilian/shiku2",
	"/d/forest/mty1",
	"/d/quanzhou/liang", 
	"/d/xingxiu/btgate",
	"/d/xingxiu/icecave2",
	"/d/taishan/baozang",
	"/d/xixia/hut",
});

void create()
{
	object *obs;

	set_name("渡厄", ({ "du e", "e" }) );
	set("title", "少林长老");
	set("gender", "男性");
	set("age", 90);
	set("long",
		"这是一个面颊深陷，瘦骨零丁的老僧，他脸色枯黄，如同一段枯木。\n");

	set("attitude", "peaceful");
	set("combat_exp", 1500000);
	set("score", 200000);

	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("max_qi", 3000);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);

	create_family("少林派", 35, "长老");
	set("class", "bonze");
	assign_apprentice("弟子", 0);

	set_skill("force", 170);
	set_skill("cuff", 180);
	set_skill("whip", 180);
	set_skill("parry", 160);
	set_skill("dodge", 170);

	set_skill("buddhism", 150);
	set_skill("hunyuan-yiqi", 170);
	set_skill("jingang-quan", 180);
	set_skill("riyue-bian", 180);
	set_skill("shaolin-shenfa", 160);

	map_skill("force", "hunyuan-yiqi");
	map_skill("cuff",  "jingang-quan");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	prepare_skill("cuff", "jingang-quan");

	set("chat_chance", 80);
	set("chat_msg", ({
		(: auto_perform :),
	}) );

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	set("inquiry", ([
		"还俗" : (:ask_for_huansu:),
		"伏魔刀"     : (: ask_me :),
		"扫地僧"   : (: ask_damo :),
		"达摩祖师"   : "他是中原禅宗之祖，也是少林寺的创派祖师。\n",
		"圆真" : 
		"圆真师侄孙正在本寺五行洞里静修，外人不要打扰。\n",
		"圆真大师" :
		"圆真师侄孙正在本寺五行洞里静修，外人不要打扰。\n",
		"五行洞" :
		"那是本寺秘阵之一，只要熟悉五行生克变化既可出阵。\n",
	]));

	set("count", 1);

	setup();

	obs = filter_array(children("/d/shaolin/obj/heilong-bian"), 
				(: clonep :));

	if(sizeof(obs) < 3)
		carry_object("/d/shaolin/obj/heilong-bian")->wield();
	else carry_object("/clone/weapon/changbian")->wield();
}

#include "/kungfu/class/shaolin/du.h"

void halt()
{
	command("say 好吧，大家住手！ 看这家伙有什么话要说！");
	command("halt");
}

string ask_me()
{
	mapping fam; 
	int r, i;
	object place, *holder, ob, me = this_player();
	
	if ( !this_player()->query_temp("fighter") 
	||    this_player()->query("combat_exp") < 5000 )
	{
		command("say 大胆鼠辈，乳臭未干，竟敢偷入金刚伏魔圈，且让老衲来超度与你！");
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());
	}

	if ( present("fumo dao", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"宝刀只有一把，而且就在你身上，真是贪得无餍！";

	if ( present("fumo dao", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"宝刀只有一把，而且就在这里任你取走，真是贪得无餍！";

	if ( present("jingang zhao", this_player()) || present("jingang zhao", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"取了金刚罩，就不能再拿伏魔刀，莫要贪得无餍！";

	r = random(6);
	if(!( place = find_object(places[r])) )
	place = load_object(places[r]);

	if(holder = all_inventory(place)) {
		for(i=0; i<sizeof(holder); i++) {
			if( living(holder[i]) && holder[i]->query("race") == "人类" && !userp(holder[i]) ) {
				if(ob = new("/clone/unique/fumo-dao")) {
					ob->move(holder[i]);
					call_out("rumor", 5, place, holder[i]);
					return "我已经把伏魔刀交给了"
						+ place->query("short") + "的" 
						+ holder[i]->query("name") + "，你有本事，自去取吧！";
				}
				else return "伏魔刀乃佛家神物，唯有缘者得之。此时刀在何处，老衲也不知晓。";
			}
			else continue;
		}
	}

	if(ob = new("/clone/unique/fumo-dao")) {
		ob->move(place);
		call_out("rumor", 5, place);
		return "我已经把伏魔刀放在了"	+ place->query("short") + "，你有本事，自去取吧！";
	}
	else return "伏魔刀乃佛家神物，唯有缘者得之。此时刀在何处，老衲也不知晓。";
}

string rumor(object place, object holder)
{
	if(objectp(holder))
	command ("rumor 听说伏魔刀好象落在"
		+ place->query("short") + "的" 
		+ holder->query("name") + "手里了！");
	else
	command ("rumor 听说伏魔刀好象藏在" + place->query("short") + "！");
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