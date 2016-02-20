//Cracked by Roath
// /d/hangzhou/npc/shi.c 史

inherit NPC;

void create()
{
        set_name("史镖头", ({ "shi biaotou", "shi", "biaotou" }));
        set("gender", "男性");
        set("age", 35);

        set("combat_exp", 100000);
        set("shen_type", 1);

        set_skill("unarmed", 100);
        set_skill("blade", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 20);

        setup();
//      carry_object(__DIR__"obj/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

