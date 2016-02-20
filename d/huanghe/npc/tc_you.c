//Cracked by Roath
// you.c

inherit NPC;

int ask_join();

void create()
{
        set_name("尤得胜", ({ "you deshen", "you" }));
        set("title", "铁叉帮帮主");
        set("long",
"他便是臭名远扬的铁叉帮帮主尤得胜。一位四十多岁的彪形大汉，\n"
"手持一把明晃晃的钢叉，似乎又在想什么坏主意。\n");
        set("gender", "男性");
        set("age", 45);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 28);
        set("int", 20);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 800);
        set("max_jing", 500);
        set("max_neili", 700);
        set("neili", 700);
        set("jiali", 30);
        set("combat_exp", 150000);
        set("score", 7000);

        set_temp("apply/armor", 40);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("cuff",  100);
        set_skill("pike",  100);

        set_skill("ding-force", 100);
        set_skill("wuxingbu", 100);
        set_skill("wuxing-quan", 100);
        set_skill("liuhe-qiang", 100);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("parry", "liuhe-qiang");
        map_skill("pike", "liuhe-qiang");

        prepare_skill("cuff", "wuxing-quan");

        set("inquiry", ([
                "铁叉帮" : "咱们铁叉帮横行黄河两岸，天不怕，地不怕，连皇帝老儿都不买他的帐。",
                "尤得胜" : "我乃是山西‘伏虎门’的惟一传人，叉法绝世无双，想见识一下吗。",
                "赏善罚恶使者" : "你可千万不可让赏善罚恶使者得知我们铁叉帮的帮址啊。",
                "侠客岛" : "侠客岛赏善罚恶使者重入江湖，我们铁叉帮还是暂时避一避把。唉！",
                "胡大哥" : "胡老弟在弊帮办事得力，我对他十分倚重。",
                "王老六" : "癞头鼋王老六癞头老是自逞英雄好汉，行事莽撞，不过倒是一向是很忠心的。",
                "帮主" : "我就是铁叉帮帮主，有什麽好问的！",
		"join" : (: ask_join :),
		"入帮" : (: ask_join :),
                "job" : "关於帮务的事，你还是去问胡老弟吧",
		"帮务" : "关於帮务的事，你还是去问胡老弟吧",
        ]));

        setup();

        carry_object("/clone/weapon/sangucha")->wield();
}
