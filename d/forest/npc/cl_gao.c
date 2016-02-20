//Cracked by Roath
// /d/huanghe/changle/npc/gaosan.c 高三娘子
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("高三娘子", ({ "gao san", "gao" }));
        set("title", "万马庄女庄主");
        set("long", 
                "这女子颇有几分姿色，两幅罗裙外面系着绣花鸾带。\n"
                "腰间整整齐齐插着两排短刀。\n");
        set("gender", "女性");
        set("age", 35);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 23);
        set("int", 30);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 500);
        set("max_jing", 300);
        set("max_neili", 300);
        set("neili", 300);
        set("jiali", 20);
        set("combat_exp", 70000);
        set("score", 3500);

        set_skill("force", 65);
        set_skill("dodge", 65);
        set_skill("parry", 65);
        set_skill("cuff",  65);
        set_skill("blade", 70);

        set_skill("ding-force", 65);
        set_skill("wuxingbu", 65);
        set_skill("wuxing-quan", 65);
        set_skill("luan-blade", 70);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("parry", "luan-blade");
        map_skill("blade", "luan-blade");

        prepare_skill("cuff", "wuxing-quan");

        set("chat_chance", 3);
        set("chat_msg", ({
                "高三娘子怒道：丁不四这老贼，总有一天要找他算帐！\n",
        }) );

        set("inquiry",([
                "丁不四" : "下次再遇到这老贼，定在他身上插几把飞刀。",
                "长乐帮" : "我也正要到长乐帮拜山。",
                "司徒横" : "听说长乐帮的奸贼作乱饭上害死了他。",
        ]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/dali/obj/duandao")->wield();
}
