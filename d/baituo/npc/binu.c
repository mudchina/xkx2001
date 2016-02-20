//Cracked by Roath
// Jay 10/7/96

inherit NPC;

void create()
{
        set_name("婢女", ({ "binu" }));
        set("long", "一个二十来岁的男装女子，面貌清秀，但眉间眼角透着一股邪气。\n");
        set("gender", "女性");
        set("age", 22);

        set_skill("hand", 20);
	set_skill("shexing-diaoshou", 20);
        set_skill("dodge", 20);
	set_skill("chanchubu", 20);
        set_skill("parry", 20);
        set_skill("force", 20);
	set_skill("hamagong", 20);
	set_skill("training",30);
	map_skill("hand","shexing-diaoshou");
        map_skill("dodge","chanchubu");
	map_skill("force","hamagong");
	prepare_skill("hand","shexing-diaoshou");

        set("str", 28);
        set("int", 21);
        set("con", 27);
        set("dex", 21);

        set("max_neili", 200);
        set("jiali", 10);
        set("combat_exp", 5000);

        set("attitude", "peaceful");
        set("shen_type", -1);

        create_family("白驼山", 4 , "弟子");
	setup();
	carry_object("/d/xingxiu/obj/wcloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("shake");
        command("say 我只是个小婢女，不能收徒。");
        return;
}

