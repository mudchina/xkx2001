// lin.c 林朝英
// 1998.9 by Lgg

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int auto_perform();

void create()
{
        set_name("林朝英", ({"lin chaoying", "lin"}));
        set("gender", "女性");
        set("age", 42);
        set("long",
                "她就是古墓派的开山祖师林朝英，虽然已经是四十许人，望之却\n"
                "还如同三十出头。当年她与全真教主王重阳本是一对痴心爱侣，\n"
                "只可惜有缘无份，只得独自在这古墓上幽居。\n");

        set("attitude", "friendly");
        set("per", 30);
        set("str", 20);
        set("int", 32);
        set("con", 35);
        set("dex", 30);

        set("qi", 3600);
        set("max_qi", 3600);
        set("jing", 7400);
        set("max_jing", 7400);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);

        set("combat_exp", 3600000);
        set("score", 0);

        set_skill("force", 400);
        set_skill("yunu-xinjing", 400);   
        set_skill("sword", 400);
        set_skill("yunu-jianfa", 400);    
        set_skill("quanzhen-jian",400); 
        set_skill("dodge", 400);
        set_skill("gumu-shenfa", 400);   
        set_skill("parry", 400);
        set_skill("cuff",400);
        set_skill("meinu-quan", 400);    
        set_skill("strike",400);
        set_skill("tianluo-diwang", 400);    
        set_skill("literate",400);
        set_skill("yunu-jue",400);
        set_skill("throwing",400);

        map_skill("force", "yunu-xinjing");
        map_skill("dodge", "gumu-shenfa");
        map_skill("cuff", "meinu-quan");
        map_skill("strike", "tianluo-diwang");
        map_skill("sword", "yunu-jianfa");
        map_skill("parry", "yunu-jianfa");

        prepare_skill("cuff", "meinu-quanfa");
        prepare_skill("strike", "tianluo-diwang");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

        create_family("古墓派", 1, "开山祖师");

        set("book_count",1);
        set("inquiry", ([
                "王重阳" :  "大胆后辈小子，也敢直呼重阳祖师之名？\n",
                "重阳祖师" : "重阳是全真教的掌教，自号“活死人”。\n",
                "古墓派" :  "是啊，这里就是我一手创下的古墓派\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/armor/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam = ob->query("family");

	if(ob->query("gender") != "女性") {
                command("say 我们古墓派只收女徒，我不能收你，"+RANK_D->query_respect(ob)+"还是请回吧。");
                return;
                }
	if (!fam || fam["family_name"] != "古墓派"){
                command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
                return;
                }
	if(fam["master_name"] == "李莫愁") {
		command("say 你是"+fam["master_name"]+"的徒弟，我不能收你。");
		return;
		}       
	if((int)ob->query_skill("force", 1) < 200) {
                command("say 我古墓武功内功是基础。"); 
                command("say " + RANK_D->query_respect(ob)+"是否还应该先在内功上多下点功夫？");
                return;
                }  
	if((int)ob->query_skill("dodge", 1) < 200) {
                command("say 你轻功这么差，我教的你不一定学得会。"); 
                command("say "+RANK_D->query_respect(ob)+"是否还应该在轻功上多下点功夫？");
                return;
                }
	if((int)ob->query_skill("sword", 1) < 200) {
                command("say 你剑法这么差，我教的你不一定学得会。"); 
                command("say "+RANK_D->query_respect(ob)+"是否还应该在剑法上多下点功夫？");
                return;
                }
	if((int)ob->query_skill("yunu-jue", 1) < 200) {
                command("say 你的玉女二十四诀修为尚浅，领悟不了我的功夫。"); 
                command("say "+RANK_D->query_respect(ob)+"是否还应该在玉女二十四诀上多下点功夫？");
                return;
                }
	if((int)ob->query_skill("tianluo-diwang", 1) < 200) {
                command("say 你的天罗地网势修为尚浅，领悟不了我的功夫。"); 
                command("say "+RANK_D->query_respect(ob)+"还是多抓几只麻雀再来找我吧。");
                return;
                }
	if(ob->query_int() < 42) {
                command("say 我的武功都要极高的悟性才能学会。");
                command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
                command("say 这位"+RANK_D->query_respect(ob)+"的悟性还大有潜力可挖，还是请回吧。");
                return;
                }
        command("say 好吧，看你也是性情中人，我就收下你这个徒弟了。");
        command("recruit " + ob->query("id"));
}

int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object opp=me->select_opponent();

	if( me->query("qi",1) < 0 || me->query("jing",1) < 0 || me->query("jingli",1) < 0) return 1;

	if ( !me->is_fighting() ) {
					 if ( me->query("eff_qi") < me->query("max_qi") )
								me->exert_function("heal");
					 me->set("jiali", 50);

					 return 1;
		  }

		  if ( objectp(weapon) ) {
					 if ( weapon->query("skill_type") == "sword" )
								return perform_action("sword.suxin");
		  }
		  else return perform_action("cuff.luowang");
}