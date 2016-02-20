//Cracked by Roath
// /d/hangzhou/npc/zhike.c
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("知客僧", ({"zhike seng", "seng"}));
        set("long",
	    "他是一位老和尚，骨瘦如柴，身上的袈裟打满了补丁。\n");
	 set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 65);
        set("shen_type", 1);
        set("str", 20);
        set("int", 30);
        set("con", 25);
        set("dex", 23);
        set("max_qi", 400);
        set("max_jing", 300);
        set("max_neili", 300);
        set("neili", 300);
        set("combat_exp", 10000);
        set("shen_type", 1);

        set_skill("force", 40);
        set_skill("cuff", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);

        setup();
        carry_object("/d/shaolin/obj/cloth")->wear();

        setup();
}
