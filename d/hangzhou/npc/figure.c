//Cracked by Roath
// /d/hangzhou/npc/figure.c
// by aln  2 / 98

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("蒙面人", ({ "mengmian ren", "mengmian", "figure" }) );
        set("gender", "男性");
        set("age", 23);
        set("long",
                "一个黑布蒙面，神秘兮兮的家伙。\n");
        set("combat_exp", 300000 + random(200000));
        set("shen_type", -1);
        set("attitude", "heroism");

        set("str", 25);
        set("con", 25);
        set("int", 20);
        set("dex", 25);

        set("max_qi", 1000);
        set("eff_qi", 1000);
        set("qi", 1000);
        set("max_jing", 600);
        set("jing", 600);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 40);

        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);

        set_skill("sword",   135);
        set_skill("blade",   135);
        set_skill("staff",   135);
        set_skill("club",    135);
        set_skill("whip",    135);
        set_skill("unarmed", 135);
        set_skill("parry",   135);
        set_skill("dodge",   135);

        setup();

        switch( random(5) ) 
        {
                case 0:
                       carry_object("/d/city/obj/gangjian")->wield();
                       break;
                case 1:
                       carry_object("/d/city/obj/gangdao")->wield();
                       break;
                case 2:
                       carry_object("/d/xingxiu/obj/gangzhang")->wield();
                       break;
                case 3:
                       carry_object("/d/shaolin/obj/qimeigun")->wield();
                       break;
                case 4:
                       carry_object("/d/shaolin/obj/changbian")->wield();
                       break;
        }

        carry_object("/d/taishan/obj/yexing")->wear();
        carry_object("/d/taishan/obj/mianzhao");
}

void init()
{
        object ob;

        ::init();

        if( (ob = present("du dajin", environment())) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
        if( is_fighting(me) ) return;

        say("蒙面人对都大锦喝道：都大锦！明年的今天是你的忌日！\n");

        kill_ob(me);
}
