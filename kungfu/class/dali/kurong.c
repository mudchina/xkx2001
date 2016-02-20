//Cracked by Kafei
inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("枯荣大师", ({
                "kurong dashi",
                "dashi",
                "kurong",
                "ku rong",
        }));
        set("long",
"他身材甚是高大，但四肢却失分枯瘦，面容更是奇特之极，左边一半脸色红润\n"
"右边一半却如枯骨，除了一张焦黄的面皮之外全无肌肉，骨头凸了出来，宛然\n"  
"便是半个骷髅骨头。\n"     
        );


        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 80);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 2000);
        set("combat_exp", 1800000);
        set("score", 5000);

        set_skill("force", 180);
        set_skill("kurong-changong", 200);
        set_skill("dodge", 185);
        set_skill("duanshi-shenfa", 200);
        set_skill("strike", 180);
	set_skill("cuff", 180);
	set_skill("finger", 200);
	set_skill("yiyang-zhi", 200);
	set_skill("liumai-shenjian",200);
        set_skill("qingyan-zhang", 180);
        set_skill("parry", 180);
        set_skill("buddhism", 200);
        set_skill("literate", 185);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "duanshi-shenfa");
        map_skill("strike", "qingyan-zhang");
        map_skill("parry", "liumai-shenjian");
	map_skill("finger", "liumai-shenjian");
	map_skill("cuff", "jinyu-quan");

        prepare_skill("finger", "liumai-shenjian");

        create_family("大理段家", 13, "弟子");

        setup();

        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


void init()
{
        ::init();

        if (interactive(this_player()) && 
this_player()->query_temp("fighting"))
        {
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon") );
                this_player()->add_temp("tianlong_count", 1);
        }       
}
