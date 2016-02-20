//Cracked by Roath
// Npc: /kungfu/class/shaolin/cheng-ji.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
int auto_perform();

void create()
{
	set_name("澄寂", ({
		"chengji luohan",
		"chengji",
		"zhihui",
		"luohan",
	}));
	set("long",
		"他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
		"太阳穴高高鼓起，似乎身怀绝世武功。\n"
	);

	set("nickname", "智慧罗汉");
	set("gender", "男性");
	set("attitude", "heroism");
	set("class", "bonze");

	set("age", 60);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 550000);
	set("score", 5000);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
        set_skill("cuff", 80);
        set_skill("luohan-quan", 80);
        set_skill("strike", 90);
        set_skill("sanhua-zhang", 90);
        set_skill("hand", 100);
        set_skill("qianye-shou", 100);
	set_skill("club", 120);
	set_skill("weituo-gun", 120);
	set_skill("parry", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
        map_skill("strike", "sanhua-zhang");
        map_skill("hand", "qianye-shou");
	map_skill("club", "weituo-gun");
	map_skill("parry", "weituo-gun");

        prepare_skill("strike", "sanhua-zhang");

	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	create_family("少林派", 37, "弟子");

	setup();

        carry_object("/d/shaolin/obj/qimeigun")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}
int auto_perform()
{
        object me = this_object();
        object weapon;

        if (!present("qimei gun", me)){
        weapon = new("/d/shaolin/obj/qimeigun");
        weapon->move(me);
        message_vision("$N突然转身从身后拿出一根齐眉棍。\n", me);
        command("wield qimei gun");
        return 1;
        }
}

#include "/kungfu/class/shaolin/cheng.h"

