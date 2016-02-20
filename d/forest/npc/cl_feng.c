//Cracked by Roath
// /d/huanghe/changle/npc/fengliang.c 风良
// by aln 2 / 98

#define TUCHAN "/d/forest/obj/cl_tuchan"

inherit NPC;

void create()
{
        set_name("风良", ({ "feng liang", "feng" }));
        set("title", "青龙门掌门人");
        set("long", 
                "他是个高大的中年汉子，腰里缠九节鞭。\n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 30);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 600);
        set("max_jing", 300);
        set("max_neili", 400);
        set("neili", 400);
        set("jiali", 20);
        set("combat_exp", 90000);
        set("score", 4500);

        set_skill("force", 75);
        set_skill("dodge", 75);
        set_skill("parry", 75);
        set_skill("cuff",  75);
        set_skill("whip",  80);

        set_skill("ding-force", 75);
        set_skill("wuxingbu", 75);
        set_skill("wuxing-quan", 75);
        set_skill("canglang-bian", 80);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("parry", "canglang-bian");
        map_skill("whip", "canglang-bian");

        prepare_skill("cuff", "wuxing-quan");

        set("chat_chance", 10);
        set("chat_msg", ({
                "风良说道：丁不四这老贼不许别人使九节鞭，便是和老子过不去！\n",
                "风良说道：长乐帮的司徒大哥与俺们有过命的交情，真想去拜访他老人家。\n",
        }) );

        set("inquiry",([
                "丁不四" : "这老贼竟然把我的九节鞭夺走了。",
		"长乐帮" : "我也正要到长乐帮拜山。",
                "司徒大哥" : "司徒大哥的事就是兄弟我的事。",
                "司徒横" : "听说长乐帮的奸贼作乱饭上害死了他。",
                "九节鞭" : "九节鞭是找不回来了，得另外弄根鞭子当武器用。",
        ]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
 //     carry_object("/clone/weapon/changbian")->wield();
}

int accept_object(object who, object ob)
{
        object obj;

        if( (string)ob->query("skill_type") != "whip"
        ||  (int)ob->query("value") < 100
        ||  query_temp("weapon") )
                return notify_fail(name() + "摆了摆手，说道：你还是自个儿留着用吧。\n");

        command("joythank " + who->query("id"));
        call_out("do_wield", 1, ob);
        obj = new(TUCHAN);
        obj->move(who);
        message_vision("$N将一" + obj->query("unit") + obj->name() + "送给$n。\n", this_object(), who);
        command("say 这是一点小小心意，务必请收下。");
        return 1;
}

void do_wield(object ob)
{
        "/cmds/std/wield"->do_wield(this_object(), ob);
}
