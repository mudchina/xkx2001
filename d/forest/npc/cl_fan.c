//Cracked by Roath
// /d/forest/npc/cl-fan.c  范一飞
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("范一飞", ({ "fan yifei", "fan" }));
        set("title", "鹤笔门掌门人");
        set("long",
"他是一个矮瘦的老者，一张黑脸。\n"
"腰里插着判官笔，人称‘辽东鹤’。\n");
        set("age", 50);
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
        set("combat_exp", 100000);
        set("score", 5000);

        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
	set_skill("cuff", 80);
        set_skill("club", 90);

        set_skill("ding-force", 80);
        set_skill("wuxingbu", 80);
        set_skill("wuxing-quan", 80);
        set_skill("wuhu-gun", 90);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("parry", "wuhu-gun");
        map_skill("club", "wuhu-gun");

        prepare_skill("cuff", "wuxing-quan");

        set("chat_chance", 3);
        set("chat_msg", ({
        "范一飞说道：长乐帮的司徒大哥与俺们有过命的交情，真想去拜访他老人家。\n",
        }) );

        set("inquiry",([
                "丁不四" : "下次再遇到这老贼，定在他各处要穴点上一点。",
                "长乐帮" : "我也正要到长乐帮拜山。",
                "司徒大哥" : "司徒大哥的事就是兄弟我的事。",
                "司徒横" : "听说长乐帮的奸贼作乱饭上害死了他。",
        ]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/panguanbi")->wield();
}
        

