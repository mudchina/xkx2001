//Cracked by Roath
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("护卫", ({ "hu wei", "wei" }));
        set("long", "一个神情剽悍的蒙古大汉，是军中将官的随从，均是熟习武艺之辈。\n");
        set("gender", "男性");
        set("age", 25);
        set("attitude", "heroism");
        set("str", 25);
        set("con", 25);
        set("int", 15);
        set("dex", 20);
        
        set("max_qi", 1000);
        set("eff_qi", 1000);
        set("qi", 1000);
        set("max_jing", 800);
        set("jing", 800);
        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 50);
        set_skill("blade", 100);
        set_skill("strike", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set("combat_exp", 50000);
        set("shen_type", -1);
        setup();
        carry_object("/d/city/obj/gangjian")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}

int start_check(object ob)
{
        object me = this_object();
        call_out("leave", 1 ,ob);
}

void leave(object ob)
{
        object me = this_object();

	if(!ob){
        message_vision("$N匆匆忙忙地离开了。\n"NOR,me);
        destruct(me);
        }
	else {
        call_out("leave", 1 ,ob,me);
        }
        return;
}
int accept_fight(object me)
{
        command("say 领教个屁，看本大爷宰了你！\n");
        kill_ob(me);
        return 1;
}
