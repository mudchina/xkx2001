//Cracked by Roath
// /d/huanghe/npc/tc_hu.c

inherit NPC;

int ask_job();

void create()
{
        set_name("胡大哥", ({ "hu dage", "hu" }));
        set("title", "铁叉帮二把手");
        set("long",
"他是一位四十多岁的彪形大汉。\n");
        set("gender", "男性");
        set("age", 42);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 20);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 800);
        set("max_jing", 500);
        set("max_neili", 500);
        set("neili", 500);
        set("jiali", 20);
        set("combat_exp", 80000);
        set("score", 5000);

        set_temp("apply/armor", 30);

        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("cuff",  80);
        set_skill("pike",  90);

        set_skill("ding-force", 80);
        set_skill("wuxingbu", 80);
        set_skill("wuxing-quan", 80);
        set_skill("liuhe-qiang", 90);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("parry", "liuhe-qiang");
        map_skill("pike", "liuhe-qiang");

        prepare_skill("cuff", "wuxing-quan");

        set("inquiry", ([
                "铁叉帮" : "咱们铁叉帮横行黄河两岸，天不怕，地不怕，连皇帝老儿都不买他的帐。",
                "尤得胜" : "我对我们帮主老人家的景仰之情，有如滔滔江水连绵不绝。",
                "赏善罚恶使者" : "赏善罚恶使者重入江湖，各帮各派都是难逃大劫。唉！",
                "侠客岛" : "赏善罚恶使者重入江湖，各帮各派都是难逃大劫。唉！",
                "胡大哥" : "在铁叉帮里除了帮主，就数我胡老大说了算。",
                "王老六" : "癞头鼋王老六癞头老是自逞英雄好汉，终有一天会坏了帮主的大事。",
                "帮主" : "我家帮主尤大爷乃是山西‘伏虎门’的惟一传人，叉法绝世无双。",
                "帮务" : (: ask_job :),
                "入帮" : "有关入帮方面的事，你还是问帮主吧。",
        ]));

        setup();

        carry_object("/clone/weapon/sangucha")->wield();
}
