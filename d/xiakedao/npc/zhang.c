//Cracked by Roath
// zhang.c 张三丰

inherit NPC;
int auto_perform();

void create()
{
        set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
        set("nickname", "邋遢真人");
        set("long",
                "他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
                "身穿一件污秽的灰色道袍，不修边幅。\n"
                "身材高大，年满百岁，满脸红光，须眉皆白。\n");
        set("gender", "男性");
        set("age", 100);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("combat_exp", 1800000);
        set("score", 500000);

        set_skill("force", 200);
        set_skill("taiji-shengong", 200);
        set_skill("dodge", 200);
        set_skill("tiyunzong", 200);
        set_skill("cuff", 200);
        set_skill("taiji-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 200);
        set_skill("literate", 200);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 1, "开山祖师");
        set("class", "taoist");

        set("chat_chance_combat", 50);
        set("chat_msg", ({
                "张三丰喃喃道：白居易诗云，「勿轻直折剑，犹胜曲全钩」。\n",
                "张三丰自言自语道：李贺诗云，「男儿何不带吴钩」。\n",
        }) );
        setup();
        carry_object("/clone/weapon/zhujian")->wield();
}

void attempt_apprentice(object ob)
{
        command ("say 这「侠客行」的古诗图解，包藏着古往今来最博大精深
的武学秘奥，老夫竭尽心智，尚自不能参悟其中十之一二，哪还能分
心去理会世上俗事。 ");
}
#include "/kungfu/class/wudang/auto_perform.h"

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

      if (opp = present("feng qingyang", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("say 这招好象应该这样，直中有曲，曲中有直");
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
				opp->set("jingli", maxjingli);
				opp->set("eff_qi", maxqi);
				opp->set("qi", maxqi);
                }
                //else if (random(2) == 0)
                //{       command("say 白居易诗云，「勿轻直折剑，犹胜曲全钩」。");
                //}
        }

}
