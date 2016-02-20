//Cracked by Roath
// /d/forest/npc/cl_lu.c
// by aln  2 / 98

inherit NPC;

void create()
{
        set_name("吕正平", ({ "lu zhengping", "lu" }));
        set("title", "快刀门掌门人");
        set("long", 
"只见他一张国字方脸，腮上一部虬髯，将大半张脸都遮没了。\n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 28);
        set("int", 30);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 500);
        set("max_jing", 300);
        set("max_neili", 300);
        set("neili", 300);
        set("jiali", 20);
        set("combat_exp", 80000);
        set("score", 4000);

        set_skill("force", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        set_skill("cuff", 70);
        set_skill("blade", 80);

        set_skill("ding-force", 70);
        set_skill("wuxingbu", 70);
        set_skill("wuxing-quan", 70);
        set_skill("taiji-dao", 80);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("parry", "taiji-dao");
        map_skill("blade", "taiji-dao");

        prepare_skill("cuff", "wuxing-quan");

        set("chat_chance", 8);
        set("chat_msg", ({
        "吕正平说道：长乐帮的司徒大哥与俺们有过命的交情，真想去拜访他老人家。\n",
        }) );

        set("inquiry",([
                "丁不四" : "下次再遇到这老贼，定在他全身剁上十几刀。",
                "长乐帮" : "我也正要到长乐帮拜山。",
                "司徒大哥" : "司徒大哥的事就是兄弟我的事。",
                "司徒横" : "听说长乐帮的奸贼作乱饭上害死了他。",
        ]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
}

