//Cracked by Roath
//Npc: 谢逊
//Date: 17/3/98, kane

#include <ansi.h>
inherit NPC;

int ask_for_dao();
int ask_for_book();

void create()
{
        set_name("谢逊", ({ "xie xun", "xie", "xun" }));
        set("long", 
"他就是明教四大护教法王之一的＂金毛狮王＂。\n"
"他身材魁伟异常，满头黄发，散披肩头，眼睛碧油油的发光，\n"
"威风凛凛，真如天神天将一般。\n");

	set("nickname", HIY"金毛狮王"NOR);
	set("gender", "男性");
	set("attitude", "heroism");

        set("inquiry",([
                "屠龙刀"  : (: ask_for_dao :),
		"七伤拳"  : (: ask_for_book :),
		"qs-jing" : (: ask_for_book :),
		"七伤拳经"  : (: ask_for_book :),
		"七伤拳谱"  : (: ask_for_book :),
		"成昆" :"此人与我有血海深仇，如能得他首级，谢逊死而无憾。",
		"张无忌" : "啊？！你难道知道我那无忌孩儿的下落？！",
		"明教" : "这都是过去的事了，提它作甚？",
        ]));

	set("age", 45);
	set("shen_type", -1);

	set("str", 30);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
        set_temp("apply/armor", 100);
	set_temp("apply/attack", 100);
        set_temp("apply/dodge", 100);
	set_temp("apply/damage", 50);

	set("max_qi", 3000);
	set("max_jing", 2500);
	set("neili", 2500);
	set("max_neili", 3000);
	set("jiali", 200);
	set("combat_exp", 1800000);
	set("score", 8000);
	set("PKS", 100000000);

        set_skill("force", 170);
        set_skill("hunyuan-yiqi", 170);
        set_skill("cuff", 180);
        set_skill("qishang-quan", 180);
        set_skill("blade", 170);
        set_skill("liuhe-dao", 170);
        set_skill("parry", 180);
        set_skill("dodge", 180);
        set_skill("xueshitiao", 180);
        set_skill("literate", 150);

        map_skill("force", "hunyuan-yiqi");
        map_skill("cuff", "qishang-quan");
        map_skill("blade", "liuhe-dao");
        map_skill("parry", "qishang-quan");
        map_skill("dodge", "xueshitiao");

        prepare_skill("cuff", "qishang-quan");

/*
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );
*/

	setup();

	if (clonep()) carry_object("/clone/unique/tulong-dao");
	carry_object("/d/changbai/obj/hupi")->wear();
//	carry_object(__DIR__"obj/qs-jing");
}

int ask_for_dao()
{
	object  me = this_player();
	command("shout");
	command("stare "+me->name());
	command("say "+RANK_D->query_rude(me)+"既然已知道屠龙刀在我手中，乖乖受死吧！\n");

        if (present("tulong dao", this_object())){
        command("wield tulong dao");
        }
        set_leader(me);
        kill_ob(me);
	return 1;
}

int ask_for_book()
{
        object  me, book;

	me = this_player();
	book = new("/clone/unique/qs-jing");
	if( !me->query_temp("xiexun_thank") ) {
        	command("grin "+me->name());
        	command("stare "+me->name());
        	command("say "+RANK_D->query_rude(me)+"既然已知道七伤拳经在我手中，就尝尝七伤拳的厉害吧！");
        	set_leader(me);
        	kill_ob(me);
	} 
	else if (book) {
		book->move(me);
		command("say 谢某大仇已报，此生已再无牵挂，这本七伤拳经对我已无大用，"+RANK_D->query_respect(me)+"若看得起，尽管取去无妨！");
		message_vision("谢逊给$N一本" + book->query("name") +"。\n", me);
		log_file("Xiexun",sprintf("%s(%s)得到七伤拳经 on %s．\n",
                me->name(), getuid(me)), ctime(time()));
	} 
	else { 
	command("say 实在对不住，七伤拳经已经不在我这里了！");
	}
	return 1;
}

int accept_kill(object me)
{
        command("shout");
        if (present("tulong dao", this_object())){
        command("wield tulong dao");
        }
	set_leader(me);
        kill_ob(me);
        return 1;
}

int accept_object(object me, object obj)
{      
	if((string)obj->query("name") == "成昆的头"
	&& me->query_temp("kill_chengkun") ) {
                command("ah");
		command("shout");
		command("say "+RANK_D->query_respect(me)+"武功果然高明，使谢某报此血海深仇，若有所求，谢某肝脑涂地，在所不辞！\n");
        	me->set_temp("xiexun_thank",1);
	        log_file("Xiexun",sprintf("%s(%s)把成昆的头交给谢逊 on %s．\n",
                me->name(), getuid(me)), ctime(time()));
		return 1;
	}
	else if((string)obj->query("name") == "成昆的头"
	&& !me->query_temp("kill_chengkun") ) {	
		command("slapsb "+me->query("id"));
		command("say 老夫眼虽盲了，心却是不盲！");
		if (present("tulong dao", this_object())){
        	command("wield tulong dao");
        	}
        	set_leader(me);
        	kill_ob(me);	
	}

        return 0;
}
