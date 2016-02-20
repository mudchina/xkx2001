//Cracked by Roath
// /d/changbai/npc/sai.c

inherit NPC;

void create()
{
        set_name("赛总管", ({ "sai zongguan", "sai", "zongguan" }));
        set("nickname", "总管");
        set("long",
"他是当今乾隆皇帝手下第一亲信卫士。\n"
"他是满州第一高手，内功外功俱臻化境，为人凶奸狡诈，不知害死过多少忠臣义士。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 30);
        set("int", 25);
        set("con", 30);
        set("dex", 25);

        set("max_qi", 1500);
        set("max_jing",1500);
        set("neili", 1500);
        set("max_neili", 1500);

        set("jiali", 70);

        set("combat_exp", 900000);

        set_temp("apply/armor", 60);

        set_skill("cuff", 170);
        set_skill("force", 170);
        set_skill("dodge", 170);
        set_skill("parry", 170);
        set_skill("wuxingbu", 160);
        set_skill("ding-force", 170);
        set_skill("yanqing-quan", 170);
        set_skill("stick", 170);
        set_skill("wuhu-gun", 170);

        map_skill("dodge", "wuxingbu");
        map_skill("force", "ding-force");
        map_skill("stick", "wuhu-gun");
        map_skill("parry", "wuhu-gun");
        map_skill("cuff", "yanqing-quan");

        prepare_skill("cuff", "yanqing-quan");

        setup();

        carry_object("/clone/weapon/langya-bang")->wield();
        carry_object("/clone/armor/tie-beixin")->wear();
        carry_object("/clone/armor/huwan")->wear();
}
