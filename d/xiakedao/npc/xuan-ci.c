//Cracked by Roath
// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

inherit NPC;

void create()
{
        set_name("玄慈大师", ({
                "xuanci dashi",
                "xuanci",
                "dashi",
        }));
        set("long",
                "他是一位白须白眉的老僧，身穿一袭金丝绣红袈裟。\n"
                "他身材略显佝偻，但却满面红光，目蕴慈笑，显得神完气足。\n"
        );
        
        
        set("nickname", "少林寺方丈");
        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");
        
        set("age", 70);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("combat_exp", 900000);
        set("score", 500000);
        
        set_skill("force", 200);
        set_skill("hunyuan-yiqi", 200);
        set_skill("dodge", 200);
        set_skill("shaolin-shenfa", 210);
        set_skill("finger", 200);
        set_skill("strike", 200);
        set_skill("hand", 114);
        set_skill("claw", 200);
        set_skill("parry", 200);
        set_skill("nianhua-zhi", 200);
        set_skill("sanhua-zhang", 200);
        set_skill("fengyun-shou", 200);
        set_skill("longzhua-gong", 200);
        set_skill("buddhism", 200);
        set_skill("literate", 200);
        
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("finger", "nianhua-zhi");
        map_skill("strike", "sanhua-zhang");
        map_skill("hand", "fengyun-shou");
        map_skill("claw", "longzhua-gong");
        map_skill("parry", "nianhua-zhi");
        
        prepare_skill("finger", "nianhua-zhi");
        prepare_skill("strike", "sanhua-zhang");
        
        create_family("少林派", 36, "弟子");
        set("chat_chance", 20);
        set("chat_msg", ({
                "玄慈大师道：不然，不然。\n",
                "玄慈大师道：这吴钩之意乃隐含其势，圆转如意。\n",
        }) );

        setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command ("say 这「侠客行」的古诗图解，包藏着古往今来最博大精深
的武学秘奥，老夫竭尽心智，尚自不能参悟其中十之一二，那还能分
心去理会世上俗事。 ");
}


