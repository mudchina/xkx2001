//Cracked by Roath
// dujie.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "/kungfu/class/shaolin/auto_perform.h";
int auto_perform();
string ask_me();
string ask_damo();
string rumor(object place, object holder);

string* places = ({
	"/d/qilian/mine",
	"/d/quanzhou/liang",
	"/d/forest/mty1",
	"/d/xingxiu/btgate",
	"/d/qilian/shiku2",
	"/d/xingxiu/icecave2",
	"/d/taishan/baozang",
	"/d/xixia/hut",
});

void create()
{
	object *obs;
	set_name("渡劫", ({ "du jie", "jie" }) );
	set("title", "少林长老");
	set("gender", "男性");
	set("age", 90);
	set("long",
		"这是一个面颊深陷，瘦骨零丁的老僧，他脸色惨白，象一张纸一样。\n");

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

	set_skill("force", 150);
	set_skill("cuff", 180);
	set_skill("whip", 180);
	set_skill("parry", 160);
	set_skill("dodge", 170);

	set_skill("buddhism", 150);
	set_skill("hunyuan-yiqi", 180);
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
		"金刚罩"     : (: ask_me :),
		"扫地僧"   : (: ask_damo :),
		"达摩祖师"   : "他是中原禅宗之祖，也是少林寺的创派祖师。\n",
                "圆真" :
                "圆真师侄孙正在本寺五行洞里静修，外人不要打扰。\n",
                "圆真大师" :
                "圆真师侄孙正在本寺五行洞里静修，外人不要打扰。\n",
                "五行洞" :
                "那是本寺秘阵之一，只要熟悉五行生克变化既可出阵。\n",
	]));

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

	if ( present("jingang zhao", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"宝罩只有一件，而且就在你身上，真是贪得无餍！";

	if ( present("jingang zhao", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"宝罩只有一件，而且就在这里任你取走，真是贪得无餍！";

	if ( present("fumo dao", this_player()) || present("fumo dao", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"取了伏魔刀，就不能再拿金刚罩，莫要贪得无餍！";

	r = random(6);
	if(!( place = find_object(places[r])) )
	place = load_object(places[r]);

	if(holder = all_inventory(place)) {
		for(i=0; i<sizeof(holder); i++) {
			if( living(holder[i]) && holder[i]->query("race") == "人类" && !userp(holder[i]) ) {
				if(ob = new("/d/shaolin/obj/jingang-zhao")) {
					ob->move(holder[i]);
					call_out("rumor", 5, place, holder[i]);
					return "我已经把金刚罩交给了"
						+ place->query("short") + "的" 
						+ holder[i]->query("name") + "，你有本事，自去取吧！";
				}
				else return "金刚罩乃佛家神物，唯有缘者得之。此时在何处，老衲也不知晓。";
			}
			else continue;
		}
	}

	if(ob = new("/d/shaolin/obj/jingang-zhao")) {
		ob->move(place);
		call_out("rumor", 5, place);
		return "我已经把金刚罩放在了"	+ place->query("short") + "，你有本事，自去取吧！";
	}
	else return "金刚罩乃佛家神物，唯有缘者得之。此时在何处，老衲也不知晓。";
}

string rumor(object place, object holder)
{
	if(objectp(holder))
	command ("rumor 听说金刚罩好象落在"
		+ place->query("short") + "的" 
		+ holder->query("name") + "手里了！");
	else
	command ("rumor 听说金刚罩好象藏在" + place->query("short") + "！");
}
