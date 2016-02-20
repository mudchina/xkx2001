//Cracked by Roath
// jiuke.c 酒客
#include <ansi.h>
inherit NPC;
inherit F_SKILL;

void create()
{
        set_name("酒客", ({ "jiu ke", "ke", "jiuke" }));
        set("gender", "男性");
        set("age", 20);
        set("long", "一个喝得醉醺醺的酒客。\n");

        set("chat_chance", 3);
        set("chat_msg", ({ 
                (: command("drinkcup jiuke") :),   
                (: command("careful") :),  
                (: command("joycup jiuke") :),  
        }));

        set("combat_exp", 10000);
        set("shen_type", 1);

        set_skill("sword", 40);
        set_skill("unarmed", 30);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("san-sword", 35);

        map_skill("sword", "san-sword");
        map_skill("parry", "san-sword");


        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 10);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/armor/cloth")->wear();
}
