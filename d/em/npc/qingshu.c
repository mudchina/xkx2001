//Cracked by Roath
//Jay 9/30/96
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("宋青书", ({ "song qingshu", "song", "qingshu" }));
	set("long", 
		"他是武当首徒宋远桥的大儿子，武功据说在武当三代弟子中是姣姣者。\n"
		"他身着白色道袍，手持长剑，相貌英俊，举止不俗。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 30);
	set("combat_exp", 100000);

	set_skill("force", 60);
	set_skill("taiji-shengong", 60);
	set_skill("dodge", 60);
	set_skill("tiyunzong", 60);
	set_skill("cuff", 60);
	set_skill("taiji-quan", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji-jian", 60);
	set_skill("taoism", 60);
  	set_skill("literate", 80);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	prepare_skill("cuff", "taiji-quan");

	create_family("武当派", 3, "弟子");
	set("class", "taoist");

	set("inquiry", 
		([
			"周芷若" : (: ask_me :),
			"宋远桥" : "便是家父。\n",
			"张三丰" : "是我师祖。\n",
			"谷虚" : "我的师弟，功夫不行，道德经念得道不少。\n",
		]));
                                

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "武当派" 
	&&  ob->query("combat_exp") >= 10000 )
	{
		command ("say " + RANK_D->query_respect(this_player()) + "是" 
			+ fam["family_name"] + "的武功高手，本山可不敢收留！");
		return;
	}

	if ((int)ob->query("shen") > 0) {
		command("say " + RANK_D->query_respect(ob) +
			"还是去拜我师弟谷虚吧。");
		return;
	}

	command("say 好吧，贫道就收下你了。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
        object me;

        me = this_player();
           message("vision",
   HIY "宋青书大怒：『你也配打周女侠的主意？！』\n"
       "宋青书决心杀死" + me->name() +"\n"
   NOR, environment(), this_object() );
                   kill_ob(this_player());
   return "\n";
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()
		&& (string)environment()->query("short") == "小树林") {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
        if (me->query("shen")<0) {
          command("say "+ RANK_D->query_rude(me) +"也来偷睽峨眉女侠的寝宫？小心"
		"大爷我宰了你！");
	  return ;
	}
	if (me->query_temp("miekou")) return;
	command("hi " + me->query("id"));
	command("say 小弟在此久候了。");
	command("follow "+me->query("id"));
	me->set_temp("miekou",1);
	remove_call_out("miekou");
	call_out("miekou", 3, this_object(), me);
	command("hehe song");
	return ;
}

int miekou(object song, object me)
{
	command("say 如果你日後把我偷睽峨眉女侠寝宫的事宣扬出去，我还怎麽在江湖上走动？");
	tell_object(me,"宋青书想杀你灭口！\n");
        kill_ob(me);
	return 1;
}

