//Cracked by Roath
// qingxu.c 清虚

#define HOME "/d/wudang/chaotian"

inherit NPC;
int auto_perform();
string ask_me(string);

void create()
{
	set_name("清虚道长", ({ "qingxu daozhang", "qingxu", "daozhang" }));
	set("long", 
		"他是谷虚的师弟，剑术算不得很精，但年轻之时，曾在西域住过十几年，\n"
		"学得一项特别本事，精擅机关削器之术。\n");
	set("gender", "男性");
	set("age", 58);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "taoist");

	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 70);
	set("combat_exp", 300000);
	set("score", 8000);
	set("wudang/liangyi", "yang");

	set_skill("force", 120);
	set_skill("wudang-jiuyang", 120);
	set_skill("dodge", 120);
	set_skill("tiyun-zong", 120);
	set_skill("cuff", 80);
	set_skill("chang-quan", 80);
	set_skill("parry", 110);
	set_skill("sword", 140);
	set_skill("wudang-jian", 140);
	set_skill("literate", 80);
	set_skill("taoism", 100);

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

	create_family("武当派", 3, "弟子");
	set("inquiry", ([
		"here" : (: ask_me, "here" :),
		"name" : "贫道便是清虚，不知这位"+ RANK_D->query_respect(this_player())
				+"有何见教？",
		"武当" : "贫道便是武当派弟子，不知这位"+ RANK_D->query_respect(this_player())
				+"有何见教？",
		"武当派" : "贫道便是武当派弟子，不知这位"+ RANK_D->query_respect(this_player())
				+"有何见教？",
		"武当山" : (: ask_me, "here" :),
		"萧琴" : "啊，你是说掌门？ 她最近好像很忙似的。一方面要应付武当的重任，令一方面要考好HSC。您有事找她吗？请去三清殿留言。",
		"太极剑" : "嗯……这我不大清楚，你得去问冲虚师兄。",
		"太极剑法" : "嗯……这我不大清楚，你得去问冲虚师兄。",
		"武当剑" : "嗯……武当剑的质地柔韧不足，坚硬易脆，对方如果使用重器械，则不宜与其硬碰硬撞。",
		"武当剑法" : "武当剑法使起来又狠又稳，一招之间能生出许多变化。",
		"两仪剑法" : "两仪剑法中有阴有阳，亦刚亦柔，神妙精微无比。",
		"武当两仪剑" : "两仪剑法中有阴有阳，亦刚亦柔，神妙精微无比。",
		"绕指柔剑" : "这路剑法我可不会使。",
		"神门十三剑" : "这路剑法我可不会使。",
		"武当长拳" : "拳脚功夫非贫道所长。",
		"绵掌" : "拳脚功夫非贫道所长。",
		"震山掌" : "拳脚功夫非贫道所长。",
		"虎爪绝户手" : "嗯……曾听说敝派有这一路武功，但从未见师伯师叔使过。",
		"张三丰" : "敝派创派祖师，近年来常年闭关不出。",
		"张真人" : "敝派创派祖师，近年来常年闭关不出。",
		"宋远桥" : "那是敝派掌门大师伯。",
		"宋大侠" : "那是敝派掌门大师伯。",
		"俞莲舟" : "那是二师伯。",
		"俞二侠" : "那是二师伯。",
		"俞岱岩" : "那是三师伯。",
		"俞三侠" : "那是三师伯。",
		"张松溪" : "贫道的授业恩师",
		"张四侠" : "贫道的授业恩师",
		"张翠山" : "………那是贫道的五师叔。",
		"张五侠" : "………那是贫道的五师叔。",
		"殷梨亭" : "那是六师叔。",
		"殷六侠" : "那是六师叔。",
		"莫声谷" : "那是七师叔。",
		"莫七侠" : "那是七师叔。",
		"宋青书" : "好久没见到宋师哥了，听说他和莫七叔吵过架，就此再没回武当过。",
		"冲虚" : "他是贫道的师兄，三代弟子中也就他会使太极剑法。",
		"冲虚道长" : "他是贫道的师兄，三代弟子中也就他会使太极剑法。",
		"谷虚" : "谷虚师兄是三代弟子中的佼佼者，近年来负责在山上主持武当事务。",
		"谷虚道长" : "谷虚师兄是三代弟子中的佼佼者，近年来负责在山上主持武当事务。",
		"HSC" : "唉，我们掌门最近正在为这事心烦呢，忙的不可开交。",
		"清虚道长" : "贫道便是清虚，不知这位"+ RANK_D->query_respect(this_player())
				+"有何见教？",
		"凌虚" : "凌虚师弟在遇真宫，负责制造香火。",
		"凌虚道长" : "凌虚师弟在遇真宫，负责制造香火。",
		"制香" : "凌虚师弟在遇真宫，负责制造香火。",
		"制香道长" : "凌虚师弟在遇真宫，负责制造香火。",
		"灵虚" : "灵虚师弟在山门，负责接待来客。",
		"灵虚道长" : "灵虚师弟在山门，负责接待来客。",
		"知客" : "灵虚师弟在山门，负责接待来客。",
		"知客道长" : "灵虚师弟在山门，负责接待来客。",
		"成高" : "他是贫道的师侄，以前曾与贫道在西域住过十几年，现在负责看守榔梅园。",
		"成高道长" : "他是贫道的师侄，以前曾与贫道在西域住过十几年，现在负责看守榔梅园。",
		"守园" : "他是贫道的师侄，以前曾与贫道在西域住过十几年，现在负责看守榔梅园。",
		"守园道长" : "他是贫道的师侄，以前曾与贫道在西域住过十几年，现在负责看守榔梅园。",
		"炸药" : "嗯……这我不大清楚，你得去问成高师侄。",
		"火药" : "嗯……这我不大清楚，你得去问成高师侄。",
		"制造炸药" : "嗯……这我不大清楚，你得去问成高师侄。",
		"制造火药" : "嗯……这我不大清楚，你得去问成高师侄。",
		"机关" : "贫道曾在西域向当地工匠学过机关削器之术。",
		"机关削器" : "贫道曾在西域向当地工匠学过此术。",
		"清虚" : "贫道便是清虚，不知这位"+ RANK_D->query_respect(this_player())
				+"有何见教？",
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
				return "这里是朝天宫，再上去便是武当金顶。";
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

	if( partner = present("chenggao daozhang", environment(this_object())) )
	{
		command("perform liangyi chenggao");
		partner->auto_perform();
	}
}
