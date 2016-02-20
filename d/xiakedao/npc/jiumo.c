//Cracked by Roath
// Summer 9/26/1996.

inherit NPC;
int auto_perform();

void create()
{
        set_name("鸠摩智", ({ "jiumozhi", "jiu" }));
        set("nickname", "大轮明王");
        set("long", 
"这是一个中年僧人，看起来一脸庄严宝象，面戴微笑，身披浅黄袈裟。\n"
"他就是吐蕃国护国法王、大雪山大轮寺的主持。 \n");
        set("gender", "男性");
        set("age", 45);
        set("attitude", "peaceful");
        set("class","lama");
        set("shen_type", -1);
        set("str", 37);
        set("int", 37);
        set("con", 30);
        set("dex", 35);
        set_temp("apply/armor", 100);
        set("max_qi", 1800);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set("combat_exp", 1800000);
        set("score", 5000);

        set_skill("force", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("staff", 180);
        set_skill("lamaism", 200);
        set_skill("strike", 180);
        set_skill("cuff",180);
        set_skill("jingang-chu", 180);
        set_skill("longxiang-banruo", 180);
        set_skill("huoyan-dao",200);
        set_skill("sword", 180);
        set_skill("mingwang-jian", 180);
        set_skill("necromancy", 200);
        set_skill("shenkongxing", 200);
        set_skill("xiaowuxiang", 180);
        set_skill("yujiamu-quan", 180);

        map_skill("force", "xiaowuxiang");
        map_skill("parry", "huoyan-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("staff", "jingang-chu");
        map_skill("strike", "huoyan-dao");
        map_skill("dodge", "shenkongxing");
        map_skill("cuff", "yujiamu-quan");
        
        prepare_skill("strike", "huoyan-dao");

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
        create_family("雪山派", 6, "掌门人");

        setup();
        carry_object("/d/qilian/obj/lamajiasha")->wear();
}
void attempt_apprentice(object ob)
{
        command ("say 快滚老子没空别来烦我");
        return;
}

#include "/kungfu/class/xueshan/auto_perform.h"

void init()
{
        object me = this_player();

        if( interactive(me) )
        {	remove_call_out("greeting");
            call_out("greeting", 1, me);
        }
}

void greeting(object me)
{     object obj = this_object();
      object opp;
	int maxqi, maxjingli;
	int qi, jingli;
	qi = obj->query("max_qi");
	jingli = obj->query("max_jingli");

      if (opp = present("xuedao laozu", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("say 赵客缦胡缨，胡缨的样子应该是这样的，这是否暗指行掌之势？");
				command("consider ");
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
				opp->set("jingli", maxjingli);
				opp->set("eff_qi", maxqi);
				opp->set("qi", maxqi);
                }
        }
}
