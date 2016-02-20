//Cracked by Roath
// /d/huanghe/changle/npc/zhan.c 展飞
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("展飞", ({ "zhan fei", "zhan" }));
        set("title", "长乐帮豹捷堂香主");
        set("fam", "长乐帮");
        set("long",
"他是一个身披斑衣的汉子。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 25);
        set("con", 24);
        set("dex", 25);

        set("max_qi", 700);
        set("max_jing", 400);
        set("max_neili", 500);
        set("neili", 500);
        set("jiali", 30);
        set("combat_exp", 120000);
        set("score", 6000);

        set_skill("force", 90);
        set_skill("dodge", 90);
        set_skill("parry", 90);
        set_skill("strike",  90);

        set_skill("ding-force", 90);
        set_skill("wuxingbu", 90);
        set_skill("cuixin-zhang", 90);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("strike", "cuixin-zhang");
        map_skill("parry", "cuixin-zhang");

        prepare_skill("strike", "cuixin-zhang");

        set("inquiry", ([
                "长乐帮" : "我为长乐帮赴汤蹈火十几年竟落得这个下场。",
                "司徒横" : "这贼帮主凶淫毒辣，不知要想什么新镣古怪的花样来折磨我？",
                "帮主" : "这贼帮主凶淫毒辣，不知要想什么新镣古怪的花样来折磨我？",
                "豹捷堂" : "没有我的管辖，豹捷堂眼看要垮了。",
                "贝海石" : "贝大夫在弊帮劳苦功高，颇得帮主信任。",
                "香主" : "各位香主的任命由帮主老人家说了算。",
        ]));

        setup();
}
