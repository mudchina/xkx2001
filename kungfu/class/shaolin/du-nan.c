//Cracked by Roath
// dunan.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "/kungfu/class/shaolin/auto_perform.h";
int auto_perform();
string ask_me();
string ask_damo();

void create()
{
	object *obs;
	set_name("渡难", ({ "du nan", "nan" }) );
	set("title", "少林长老");
	set("gender", "男性");
	set("age", 90);
	set("long",
		"这是一个面颊深陷，瘦骨零丁的老僧，他脸色漆黑，象是生铁铸成。\n");

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

	set_skill("force", 180);
	set_skill("cuff", 180);
	set_skill("whip", 170);
	set_skill("parry", 170);
	set_skill("dodge", 160);

	set_skill("buddhism", 150);
	set_skill("jingang-quan", 180);
	set_skill("hunyuan-yiqi", 160);
	set_skill("riyue-bian", 170);
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
		"菩提子"     : (: ask_me :),
		"扫地僧"   : (: ask_damo :),
		"达摩祖师"   : "他是中原禅宗之祖，也是少林寺的创派祖师。\n",
                "圆真" :
                "圆真师侄孙正在本寺五行洞里静修，外人不要打扰。\n",
                "圆真大师" :
                "圆真师侄孙正在本寺五行洞里静修，外人不要打扰。\n",
                "五行洞" :
                "那是本寺秘阵之一，只要熟悉五行生克变化既可出阵。\n",
	]));

	set("count", random(10)-8);

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
	object ob;
	
	if ( !this_player()->query_temp("fighter") 
	||    this_player()->query("combat_exp") < 5000 )
	{
		command("say 大胆鼠辈，乳臭未干，竟敢偷入金刚伏魔圈，且让老衲来超度与你！");
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());
	}

	if ( present("puti zi", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"菩提子只有一颗，而且就在你身上，真是贪得无餍！";

	if ( present("puti zi", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"菩提子只有一颗，而且就在这里任你取走，真是贪得无餍！";

	if (query("count") < 1)
		return "菩提子乃天地之灵物，采集艰难无比，我这里现在可没有。";

	ob = new(DRUG_D("puti-zi"));
	ob->move(this_player());

	add("count", -1);

	message_vision("\n渡难惨然一笑，接着长叹一声，从树洞里取出个白玉磁瓶，倒出菩提子递给$N。\n\n", this_player());

	return "我等昔年于佛祖座前发下宏愿，每十年遍访名山大川，历尽艰险，\n" +
	       "方采得数颗菩提子，君乃有缘人，能得此造化奇物，望好自为之！";
}
