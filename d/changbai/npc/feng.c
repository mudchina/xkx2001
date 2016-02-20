//Cracked by Roath
// /d/changbai/npc/feng.c

inherit NPC;

void create()
{
        set_name("冯锡范", ({ "feng xifan", "feng" }));
        set("nickname", "一剑无血");
        set("long",
"他容貌瘦削，黄中发黑，留着两撇燕尾须。\n"
"一副没精打采的模样，倒似个痨病鬼模样。\n"
"但偶然一双眼睛睁大了，却是神光炯炯。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 1500);
        set("max_neili", 1500);

        set("jiali", 60);

        set("combat_exp", 800000);

        set_temp("apply/armor", 40);

        set_skill("force", 160);
        set_skill("dodge", 160);
        set_skill("parry", 160);
        set_skill("sword", 160);
        set_skill("strike", 160);
        set_skill("ding-force", 160);
        set_skill("wugou-jianfa", 160);
        set_skill("wuyu-zhangfa", 160);
        set_skill("tiyunzong", 160);

        map_skill("strike", "wuyu-zhangfa");
        map_skill("force", "ding-force");
        map_skill("parry", "wugou-jianfa");
        map_skill("sword", "wugou-jianfa");
        map_skill("dodge", "tiyunzong");

        prepare_skill("strike", "wuyu-zhangfa");

        setup();

        carry_object("/clone/weapon/qinggang-jian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}


