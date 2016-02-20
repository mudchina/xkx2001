//Cracked by Roath
// /d/changbai/npc/jiao2.c

inherit NPC;

void create()
{
        set_name("焦文期", ({ "jiao wenqi", "jiao" }));
        set("nickname", "关东三魔");
        set("long",
"他就是关东六魔中的第三魔。\n"
"又矮又瘦，黑黝黝一张脸，两撇燕尾须，长不盈寸，精干矫健。\n");
        set("gender", "男性");
        set("age", 54);
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);

        set("max_qi", 900);
        set("eff_qi", 100);
        set("qi", 50);
        set("max_jing", 600);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 30);
        set("combat_exp", 300000);
        set("score", 20000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("hand", 100);
        set_skill("parry", 100);
        set_skill("blade", 120);
        set_skill("throwing", 100);
        set_skill("ding-force", 100);
        set_skill("wuxingbu", 100);
        set_skill("liangyi-dao", 120);
        set_skill("lanhua-fuxue", 100);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("parry", "liangyi-dao");
        map_skill("blade", "liangyi-dao");
        map_skill("hand", "lanhua-fuxue");

        prepare_skill("hand", "lanhua-fuxue");

        setup();

        call_out("do_dying", 1, this_object());

        carry_object("/d/changbai/obj/tiepai")->wield();
        carry_object("/d/changbai/obj/piqiu")->wear();
}

void do_dying(object ob)
{
        if(ob)  ob->receive_wound("qi", 10000, "流血过多而死");
}
