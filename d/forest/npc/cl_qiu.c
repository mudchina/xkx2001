//Cracked by Roath
// /d/huanghe/changle/npc/qiu.c
// by aln 2 / 98

#define TUCHAN "/d/forest/obj/cl_tuchan"

inherit NPC;

void create()
{
        set_name("邱山风", ({ "qiu shanfeng", "qiu" }));
        set("title", "长乐帮虎猛堂香主");
        set("long",
"他是一位三十多岁的彪形大汉。\n");
        set("gender", "男性");
        set("age", 32);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 20);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 700);
        set("max_jing", 400);
        set("max_neili", 600);
        set("neili", 600);
        set("jiali", 30);
        set("combat_exp", 150000);
        set("score", 7000);

        set_skill("force", 90);
        set_skill("dodge", 90);
        set_skill("parry", 90);
        set_skill("cuff",  90);
        set_skill("club",  100);

        set_skill("ding-force", 90);
        set_skill("wuxingbu", 90);
        set_skill("wuxing-quan", 90);
        set_skill("wuhu-gun", 100);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("parry", "wuhu-gun");
        map_skill("club", "wuhu-gun");

        prepare_skill("cuff", "wuxing-quan");

        set("inquiry", ([
                "长乐帮" : "这里就是长乐帮总舵所在地。",
                "司徒横" : "我对我们帮主老人家的景仰之情，有如滔滔江水连绵不绝。",
                "虎猛堂" : "虎猛堂自从我当香主后，一日千里，哈！哈！哈！",
                "香主" : "各位香主的任命由帮主老人家说了算。",
                "贝海石" : "贝大夫在弊帮劳苦功高，颇得帮主信任。",
                "帮主" : "我家帮主司徒大爷乃威镇江南的“东霸天”也。",
        ]));

        setup();

        carry_object("/clone/weapon/panguanbi")->wield();
}

int accept_object(object who, object ob)
{
        if( base_name(ob) != TUCHAN )
                return notify_fail(name() + "摆了摆手，说道：你还是自个儿留着用吧。\n");

        command("joythank " + who->query("id"));
        who->set_temp("changle/enter", 1);
        call_out("do_destroy", 1, ob);
        return 1;
}

void do_destroy(object ob)
{
        if( ob ) destruct(ob);
}
