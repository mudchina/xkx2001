//Cracked by Kafei
// Xuanyuan 7/14/2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int do_look(string);
int ask_me();
int ask_sanwu();
int auto_perform();
int auto_throw();
void create()
{
        set_name("李莫愁", ({ "li mochou", "li", "mochou" }));
        set("long", "她生得极为美貌，但冰冷的目光让人不寒而立。\n");
	set("nickname", "赤练仙子");
        set("gender", "女性");
        set("rank_info/respect", "道姑");
        set("age", 27);
        set("attitude","heroism");
        set("str", 30);
        set("dex", 35);
        set("con", 17);
        set("int", 25);
        set("shen_type", -1);

        set_skill("strike", 300);
        set_skill("cuff", 300);
	set_skill("gumu-shenfa", 300);
	set_skill("chilian-shenzhang", 300);
	set_skill("meinu-quan", 300);
        set_skill("force", 300);
        set_skill("dodge", 300);
	set_skill("whip",300);
	set_skill("throwing",300);
	set_skill("jueqing-bian",300);
        set_skill("wudu-xinfa",300);

	map_skill("dodge", "gumu-shenfa");
	map_skill("strike", "chilian-shenzhang");
	map_skill("cuff", "meinu-quan");
        map_skill("force", "wudu-xinfa");
	map_skill("whip","jueqing-bian");

	prepare_skill("strike", "chilian-shenzhang");

        set("jiali",50);
        set("combat_exp", 2000000);

        set("max_qi", 2800);
        set("max_jing", 4200);
        set("neili", 4000);
        set("max_neili", 4000);

        create_family("古墓派",3,"弟子");

	set("canuse_sanwu",1);

        set("inquiry", ([
            "name" : "站远点！",
            "here" : "我不是本地人，不知道。",
            "情" : "你如何能理解其中相思之苦、惆怅之意？",
            "陆展元" : "你问那个薄情的小畜生做什么？",
	    "何沅君" : (: ask_me :),
            "小龙女" : "那是我的师妹。你问她想干什么？",
            "林朝英" : "那是我的师祖，不该你问的你别问，小心我宰了你。",
		"三无三不手" : (: ask_sanwu :),
       ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
            "李莫愁纵声而歌，音调凄婉，歌道：「问世间，情是何物，直教生死相许？」\n",
            "李莫愁歌道：「天南地北双飞客，老翅几回寒暑？」\n",
            "李莫愁唱道：「欢乐趣，离别苦，就中更有痴儿女。」\n",
            "李莫愁唱道：「君应有语，渺万里层云，千山暮雪，只影向谁去？」\n",
            "李莫愁词意悲切，声调更是哀怨，唱道：「横汾路，寂寞当年箫鼓。荒烟依旧平楚。」\n",
            "李莫愁歌道：「招魂些何嗟及，山鬼自啼风雨。」\n",
            "李莫愁唱道：「天也妒，未信兴，莺儿燕子俱黄土。」\n",
            "李莫愁唱道：「千秋万古，为留待骚人，狂歌痛饮，来访雁丘处。」\n",
        }) );
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
                (: auto_throw :),
	}) );
        carry_object("/clone/weapon/fuchen")->wield();
        carry_object("/d/wudang/obj/greenrobe")->wear();
        carry_object("/d/zhongnan/obj/bpzhen")->set_amount(7);
}

void init()
{
        ::init();
        add_action("do_look","look");
        add_action("do_look","hug");
        add_action("do_look","mo");
        add_action("do_look","18mo");
        add_action("do_look","kiss");

}

int ask_me()
{
        object me;
 
        me = this_player();
	   message("vision",
   HIY "李莫愁冷笑一声：『我这就送你去见她』\n"
       "李莫愁决心杀死" + me->name() +"\n"
   NOR, environment(), this_object() );
                   kill_ob(this_player());
   return 1;
}
  
int ask_sanwu()
{
        object ob = this_player();
        
        if (ob->query("family/family_name") != "古墓派") {
                command("say 好！就让你看看什么是「三无三不手」！");
		kill_ob(this_player());
                command("perform sanwu");
                return 1;
        }
	if (ob->query("family/master_name") != "李莫愁") {
                command("say 好！就让你看看什么是「三无三不手」！");
		kill_ob(this_player());
                command("perform sanwu");
		return 1;
		}     
        if (ob->query("canuse_sanwu") > 0 ) {
                command("say 你不是已经学会了吗？");
                return 1;
        }
        if (ob->query_skill("whip",1) < 100) {
                command("say 要使用这样的绝招需要高深的鞭法，你还是多练习练习再说吧。");
                return 1;
        }
        if (ob->query_skill("jueqing-bian",1) < 100) {
                command("say 要使用这样的绝招需要高深的鞭法，你还是多练习练习“绝情鞭法”再说吧。");
                return 1;
        }
        	command("say 好，我就教你这招“三无三不手”！\n");

        ob->set("canuse_sanwu", 1);
        return 1;
}
int do_look(string target)
{
        object me;
 
        me = this_player();
        if (target=="li" || target=="li mochou" || target=="mochou" ) 
           if ((string)me->query("gender") == "男性") {
		   message("vision",
   HIY "李莫愁大怒，喝道：我最恨你们这些薄情的臭男人！去死吧！\n"
       "李莫愁决心杀死" + me->name() +"！！\n"
   NOR, environment(), this_object() );
                   kill_ob(this_player());
           }
}       
void attempt_apprentice(object ob)
{
	mapping fam = ob->query("family");
/*
	if (!fam || fam["family_name"] != "古墓派"){
                command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
                return;
                }
*/
	if (ob->query("gender") != "女性") {
		command("say 我只收女弟子，"+RANK_D->query_respect(ob)+"请回吧。");
		return; 
		}

	if (fam["family_name"] == "丐帮" && ob->query("rank") > 1 )  {
		command("say " + RANK_D->query_respect(ob) + "是丐帮高手，恕我不能收你。");
		return;
        	}

	if (ob->query("combat_exp") >= 10000 && ob->query("family") ) {
		command ("say " + RANK_D->query_respect(this_player())
                                + "是" + fam["family_name"]  + "的武功高手，我可不敢收留。");
		return;
                }
	if (ob->query_kar() > 20) {
                command("say 看你肥头大耳一脸富贵样子，原何还来找我这苦命之人。");
                return;
                }
        command("say 嗯，看你还是个学武的料，我就收下你吧！");
        command("recruit " + ob->query("id"));
}

#include "/kungfu/class/gumu/auto_perform.h";
#include "/clone/npc/auto_throw.h";