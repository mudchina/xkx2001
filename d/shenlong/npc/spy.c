//Cracked by Roath
// /d/shenlong/npc/spy.c

inherit NPC;
inherit F_MASTER;
inherit F_CLEAN_UP;

void auto_enable();

int is_sg_spy() { return 1;}

void create()
{
        set_name("魏无双", ({ "wulin mengzhu", "mengzhu", "zhu" }) );
        set("title", "武林盟主" );
        set("gender", "男性" );
        set("age", 40);
        set("long","他就是雄踞武林，号召天下，威风赫赫的当今武林盟主。\n");
        set("attitude", "heroism");

        set("str", 25);
        set("con", 25);
        set("int", 25);
        set("dex", 25);

        set("max_qi", 500);
        set("eff_qi", 500);
        set("qi", 500);
        set("max_jing", 300);
        set("jing", 300);
        set("neili", 500);

        set("max_neili", 500);
        set("jiali", 40);

        set("shen_type", -1);

        set_skill("force",  100); 
        set_skill("unarmed",100);
        set_skill("sword",  100);
        set_skill("dodge",  100);
        set_skill("parry",  100);

        set("weapon", "/d/shaolin/obj/changjian");
        set("armor", "/d/city/obj/cloth");

        setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/city/obj/cloth")->wear(); 
}

void init()
{
        ::init();

        auto_enable();

        if( !this_player()->query("yijin_wan") && interactive(this_player())
        &&  !is_killing() )
                 call_out("do_kill", 1, this_player());
}

void do_kill(object ob)
{
        kill_ob(ob);
        ob->fight_ob(this_object());
}

#include "/clone/npc/auto_enable.h";
