//Cracked by Roath
inherit NPC;

int do_push(string);

void create()
{
        set_name("卫士长", ({ "weishi zhang", "guard", "wei" }));
        set("long", 
"一个中年卫士\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 30);
        set("con", 25);
        set("dex", 30);
        set("shen", 0);
        
        set("max_qi", 400);   
       set("max_jing", 500);
        set("neili", 100);
        set("max_neili", 1000);
        set("jiali", 20);
        set("combat_exp", 5000);
        set("score", 5000);

        set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("axe", 60);
        set_skill("finger", 30);

        setup();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object("/d/dali/obj/gangfu")->wield();
}
#include "/kungfu/class/dali/promote1.h"

