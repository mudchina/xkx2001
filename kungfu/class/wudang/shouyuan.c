//Cracked by Roath
// chenggao.c 成高

#define HOME "/d/wudang/langmei"

inherit NPC;
int auto_perform();
string ask_me(string);

void create()
{
	set_name("成高道长", ({ "chenggao daozhang", "chenggao", "daozhang", "shouyuan" }));
	set("nickname", "守园道长");
	set("long",
		"他是凌虚的师侄，剑术算不得很精，但年轻之时，曾在西域住过十几年，\n"
		"懂得善制炸药，现今是看守榔梅园的道长。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "taoist");

	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 20);
	set("combat_exp", 250000);
	set("score", 8000);
	set("wudang/liangyi", "yin");

	set_skill("force", 100);
	set_skill("wudang-jiuyang", 100);
	set_skill("dodge", 110);
	set_skill("tiyun-zong", 110);
	set_skill("cuff", 60);
	set_skill("chang-quan", 60);
	set_skill("parry", 90);
	set_skill("sword", 135);
	set_skill("wudang-jian", 135);
	set_skill("literate", 80);
	set_skill("taoism", 90);

	map_skill("force", "wudang-jiuyang");
	map_skill("dodge", "tiyun-zong");
	map_skill("cuff", "chang-quan");
	map_skill("parry", "wudang-jian");
	map_skill("sword", "wudang-jian");

	prepare_skill("cuff", "chang-quan");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	create_family("武当派", 4, "弟子");
	set("inquiry", ([
		"here" : (: ask_me, "here" :),
		"name" : "贫道道号成高，负责看守榔梅园，不知这位"+
				RANK_D->query_respect(this_player()) +"有何见教？",
		"武当" : "贫道便是武当派弟子，不知这位"+ RANK_D->query_respect(this_player())
				+"有何见教？",
		"武当派" : "贫道便是武当派弟子，不知这位"+ RANK_D->query_respect(this_player())
				+"有何见教？",
		"武当山" : (: ask_me, "here" :),
		"剑法" : "本门剑法贫道尚未练到家，不敢妄加评论。",
		"太极剑" : "嗯……这个我不大清楚。",
		"太极剑法" : "嗯……这个我不大清楚。",
		"武当剑" : "武当剑？",
		"武当剑法" : "本门剑法贫道尚未练到家，不敢妄加评论。",
		"两仪剑法" : "两仪剑法的剑招一阴一阳，一刚一柔，必须二人同使。",
		"武当两仪剑" : "两仪剑法的剑招一阴一阳，一刚一柔，必须二人同使。",
		"绕指柔剑" : "这路剑法贫道没能学会。",
		"神门十三剑" : "这路剑法贫道没能学会。",
		"武当长拳" : "拳脚功夫非贫道所长。",
		"绵掌" : "拳脚功夫非贫道所长。",
		"震山掌" : "拳脚功夫非贫道所长。",
		"虎爪绝户手" : "嗯……听说敝派好像是有这一路武功，不过贫道不大清楚。",
		"张三丰" : "敝派创派祖师，近年来常年闭关不出，我也未见过几次。",
		"张真人" : "敝派创派祖师，近年来常年闭关不出，我也未见过几次。",
		"宋远桥" : "那是敝派掌门。",
		"宋大侠" : "那是敝派掌门。",
		"俞莲舟" : "那是敝派的前辈。",
		"俞二侠" : "那是敝派的前辈。",
		"俞岱岩" : "那是敝派的前辈。",
		"俞三侠" : "那是敝派的前辈。",
		"张松溪" : "那是敝派的前辈。",
		"张四侠" : "那是敝派的前辈。",
		"张翠山" : "那是敝派的前辈，可是贫道未得有缘一见。",
		"张五侠" : "那是敝派的前辈，可是贫道未得有缘一见。",
		"殷梨亭" : "那是敝派的前辈。",
		"殷六侠" : "那是敝派的前辈。",
		"莫声谷" : "那是敝派的前辈，就在这附近的南岩。",
		"莫七侠" : "那是敝派的前辈，就在这附近的南岩。",
		"宋青书" : "宋师叔？好久都未曾见过了。",
		"冲虚" : "冲虚道长是贫道的师伯，剑法上的造诣已是出神入化，在众师伯师叔中无人可及。",
		"冲虚道长" : "冲虚道长是贫道的师伯，剑法上的造诣已是出神入化，在众师伯师叔中无人可及。",
		"谷虚" : "谷虚师伯负责在山上主持武当事务。",
		"谷虚道长" : "谷虚师伯负责在山上主持武当事务。",
		"清虚" : "清虚道长是贫道的师叔，曾与贫道一同在西域住过十几年。",
		"清虚道长" : "清虚道长是贫道的师叔，曾与贫道一同在西域住过十几年。",
		"凌虚" : "凌虚师叔在遇真宫。",
		"凌虚道长" : "凌虚师叔在遇真宫。",
		"制香" : "凌虚师叔在遇真宫。",
		"制香道长" : "凌虚师叔在遇真宫。",
		"灵虚" : "灵虚师叔在山门，负责接待香客。",
		"灵虚道长" : "灵虚师叔在山门，负责接待香客。",
		"知客" : "灵虚师叔在山门，负责接待香客。",
		"知客道长" : "灵虚师叔在山门，负责接待香客。",
		"成高" : "贫道便是成高，负责看守榔梅园，不知这位"+
				RANK_D->query_respect(this_player()) +"有何见教？",
		"成高道长" : "贫道便是成高，负责看守榔梅园，不知这位"+
				RANK_D->query_respect(this_player()) +"有何见教？",
		"守园" : "这位"+ RANK_D->query_respect(this_player())
				+"太客气了，看守榔梅园的事还是我一人来做吧。",
		"守园道长" : "贫道道号成高，负责看守榔梅园，不知这位"+
				RANK_D->query_respect(this_player()) +"有何见教？",
		"炸药" : "贫道曾在西域学过制造炸药之术。",
		"火药" : "贫道曾在西域学过制造炸药之术。",
		"制造火药" : "制造火药？"+ RANK_D->query_respect(this_player())
				+"是想制造炸药吧？",
		"制造炸药" : "炸药威力过於巨大，造难用险，不知这位"+
				RANK_D->query_respect(this_player()) +"问来做甚？",
		"机关" : "这你得去问清虚师叔。",
		"机关削器" : "这你得去问清虚师叔。",
	]));

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

string ask_me(string arg)
{
	object home, here = environment();
	
	switch( arg )
	{
		case "here" :
			if( base_name(here) == HOME )
				return "这里是榔梅园，西面上去便是武当著名的南岩。";
			else
			{
				command("say 这里是"+ here->query("short")
					+"………咦？我怎麽会在这。");
				if( !(home = find_object(HOME)) )
				{
					message("vision", this_object()->name() +"急急忙忙地离开了。\n",
						environment(), this_object());
					move("/d/death/death");
					return "……";
				}
				else
				{
					return_home(home);
					message("vision", this_object()->name() +"急急忙忙地走了过来。\n",
						environment(), this_object());
					return "我怎麽跑到"+ here->query("short") +"去了。";
				}
			}
			break;
	}
}

int auto_perform()
{
	object partner;

	if( partner = present("qingxu daozhang", environment(this_object())) )
	{
		command("perform liangyi qingxu");
		partner->auto_perform();
	}
}