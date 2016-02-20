//Cracked by Roath
// Npc: /d/shaolin/npc/jue-xin.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("觉心", ({
		"juexin dashi",
		"juexin",
		"saodi seng",
	}));

	set("long",
		"这是一位白须白眉的老僧。他身材高大，却骨瘦如柴，\n"
		"他是一位专职负责塔楼清埽工作的寺内杂役僧人。\n"
	);

	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("title", "扫地僧");
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 100);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 6000);
	set("max_jing", 5000);
	set("neili", 6500);
	set("max_neili", 6500);
	set("jiali", 300);
	set("combat_exp", 4000000);
	set("score", 500000);

	set_living_name("damo");

	set_skill("force", 400);
	set_skill("hunyuan-yiqi", 400);
	set_skill("dodge", 400);
	set_skill("shaolin-shenfa", 380);
	set_skill("parry", 380);

	set_skill("cuff", 400);
	set_skill("strike", 390);
	set_skill("hand", 380);
	set_skill("claw", 390);
	set_skill("finger", 380);
	set_skill("blade", 400);
	set_skill("sword", 380);
	set_skill("whip", 400);
	set_skill("club", 400);
	set_skill("staff", 390);

	set_skill("jingang-quan", 380);
	set_skill("luohan-quan", 380);
	set_skill("banruo-zhang", 390);
	set_skill("sanhua-zhang", 380);
	set_skill("qianye-shou", 380);
	set_skill("fengyun-shou", 400);
	set_skill("longzhua-gong", 380);
	set_skill("yingzhua-gong", 380);
	set_skill("yizhi-chan", 400);
	set_skill("nianhua-zhi", 380);
	set_skill("cibei-dao", 400);
	set_skill("xiuluo-dao", 380);
	set_skill("fumo-jian", 400);
	set_skill("damo-jian", 390);
	set_skill("zui-gun", 400);
	set_skill("weituo-gun", 390);
	set_skill("pudu-zhang", 380);
	set_skill("wuchang-zhang", 400);
	set_skill("riyue-bian", 400);

	set_skill("buddhism", 400);
	set_skill("literate", 400);
//	set_skill("yiwei-dujiang", 400);
	
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "qianye-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("finger", "yizhi-chan");
	map_skill("blade", "cibei-dao");
	map_skill("sword", "damo-jian");
	map_skill("whip", "riyue-bian");
	map_skill("club", "weituo-gun");
	map_skill("staff", "pudu-chang");
	map_skill("parry", "cibei-dao");

	prepare_skill("hand", "qianye-shou");
	prepare_skill("claw", "longzhua-gong");

	create_family("少林派", 34, "弟子");

	set("inquiry", ([
		"觉心"     : (: ask_me :),
		"觉心大师"     : (: ask_me :),
		"扫地僧"   : "是啊，我就是管鼓楼里扫地的，以前在藏经阁里干。\n",
		"达摩祖师"   : "他是中原禅宗之祖，也是少林寺的创派祖师。\n",
	]));

	setup();

	carry_object("/clone/armor/seng-cloth")->wear();
	carry_object("/clone/armor/sengxie")->wear();
	carry_object("/clone/weapon/saoba")->wield();
}
void init()
{
	object me;

	::init();
	if( interactive(me = this_player()) ) 
	{
		if( (me->query("family/family_name") != "少林派"
		||  me->query("family/generation") > 36
		||  me->query_temp("win_times") < 3)
		&& me->query( "family/master_name") != "觉心" )
		destruct(this_object());
	}
}
string ask_me()
{
	object me = this_player();	

	if( (me->query("family/family_name") != "少林派"
	||  me->query("family/generation") > 36
	||  me->query_temp("win_times") < 3)
	&& me->query( "family/master_name") != "觉心" )
	command("dunno");

	command("haha");
	return "我就是觉心。看来你就是三长老调教出来的那位弟子吧！\n" +
	           "你既然已经通过了他们的考验，我就收下你这个徒弟了！";
}
	
void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	if ( ob_fam["generation"] < my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) && name[0..1] == "玄" )
	{
		if ( ob->query_temp("win_times") >= 3 )
		{	
			command("say 老衲忝为少林遗老，今于百岁之龄，得此衣钵传人，可谓武林之福也！");

			name = ob->query("name");
			new_name = "渡" + name[2..3];
			ob->set("name", new_name);
	
			command("say 今后你的法名叫做" + new_name + "，恭喜你成为少林派渡字辈长老！");
			command("say 现在老衲就传你一苇渡江之法，从此任你飞渡天堑，遨游四海，渡化众生！");
			message_vision(HIY "\n\n" + me->name() + 
				"将手掌平放于$N顶心，只见一片祥云降下，内里白光旋转，把$N笼罩其中。\n" + 
				"过了半饷，祥云才渐渐消散。\n\n" NOR, ob);
			
		//	ob->set_skill("yiwei-dujiang", 100);
			ob->delete_temp("win_times");

			command("recruit " + ob->query("id"));

			command("say 你去罢！我救济世人，行踪无定，你我若有缘，可在此相会。");
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + 
				"，老衲收徒甚严，你还没有资格做我的徒弟。");
			return;
		}
	}

	return;
}
