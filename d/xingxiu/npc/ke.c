//Cracked by Roath
// npc: /d/xingxiu/npc/ke.c
// Jay 3/27/96

inherit NPC;

void create()
{
        set_name("欧阳克", ({ "ouyang ke", "ouyang", "ke" }));
        set("long", "他手摇折扇，风流儒雅。\n");
        set("title", "白驼山少庄主");
        set("gender", "男性");
        set("age", 27);

        set_skill("unarmed", 50);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("force", 50);

        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);

        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 20);
        set("combat_exp", 50000);
        set("score", 5000);

        set("attitude", "peaceful");
        set("shen_type", -1);
        setup();
}
