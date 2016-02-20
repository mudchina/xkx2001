//Cracked by Roath
// dujie.c

#include <ansi.h>

inherit NPC;
#include "/kungfu/class/shaolin/auto_perform.h";
void create()
{
        set_name("渡劫", ({ "du jie", "jie" }) );
        set("title", "少林长老");
        set("gender", "男性");
        set("age", 90);
        set("long",
                "这是一个面颊深陷，瘦骨零丁的老僧，他脸色惨白，象一张纸一样。\n");

        set("attitude", "peaceful");
        set("combat_exp", 1500000);
        set("score", 200000);

        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);

        set("max_qi", 3000);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);

        create_family("少林派", 35, "长老");
        set("class", "bonze");
        assign_apprentice("弟子", 0);

        set_skill("force", 150);
        set_skill("cuff", 180);
        set_skill("whip", 180);
        set_skill("parry", 160);
        set_skill("dodge", 170);

        set_skill("buddhism", 150);
        set_skill("hunyuan-yiqi", 180);
        set_skill("jingang-quan", 180);
        set_skill("riyue-bian", 180);
        set_skill("shaolin-shenfa", 160);

        map_skill("force", "hunyuan-yiqi");
        map_skill("cuff",  "jingang-quan");
        map_skill("whip",  "riyue-bian");
        map_skill("parry", "riyue-bian");
        map_skill("dodge", "shaolin-shenfa");

        prepare_skill("cuff", "jingang-quan");

        set("chat_chance", 80);
        set("chat_msg", ({
                (: auto_perform :),
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );


        setup();

	carry_object("/clone/weapon/bian")->wield();
}

#include "/d/xiakedao/npc/du.h"

