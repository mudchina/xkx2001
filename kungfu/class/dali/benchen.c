//Cracked by Kafei
inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("本尘", ({
                "benchen dashi",
                "dashi",
                "benchen",
                "ben chen",
        }));
        set("long",
"他看起来宝相庄严，虽是全身素衣，却也难掩帝王之色。\n");
                


        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 60);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 150);
        set("combat_exp", 1300000);
        set("score", 5000);

        set_skill("force", 145);
        set_skill("kurong-changong", 155);
        set_skill("dodge", 85);
        set_skill("duanshi-shenfa", 155);
        set_skill("strike", 160);
	set_skill("cuff", 150);
	set_skill("finger", 170);
	set_skill("yiyang-zhi", 180);
	set_skill("liumai-shenjian",170);
        set_skill("qingyan-zhang", 160);
        set_skill("parry", 165);
        set_skill("buddhism", 185);
        set_skill("literate", 185);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "duanshi-shenfa");
        map_skill("strike", "qingyan-zhang");
        map_skill("parry", "liumai-shenjian");
	map_skill("finger", "liumai-shenjian");
	map_skill("cuff", "jinyu-quan");

        prepare_skill("finger", "liumai-shenjian");

        create_family("大理段家", 14, "弟子");

        setup();

        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/kungfu/class/dali/ben.h"

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

