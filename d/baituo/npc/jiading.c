//Cracked by Roath
// Jay 10/7/96

inherit NPC;

void create()
{
        set_name("家丁", ({ "jiading" }));
        set("long", "一个二十来岁的小伙子，膀大腰圆。\n");
        set("gender", "男性");
        set("age", 28);

        set_skill("hand", 30);
	set_skill("shexing-diaoshou", 30);
        set_skill("dodge", 20);
	set_skill("chanchubu", 20);
        set_skill("parry", 30);
        set_skill("force", 20);
	set_skill("hamagong", 20);
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
        set("combat_exp", 8000);

        set("attitude", "peaceful");
        set("shen_type", -1);

        create_family("白驼山", 4 , "弟子");
	setup();
	carry_object("/d/city/obj/cloth")->wear();
}
void attempt_apprentice(object ob)
{
        command("shake");
        command("say 我只是个小家丁，不能收徒。");
        return;
}

