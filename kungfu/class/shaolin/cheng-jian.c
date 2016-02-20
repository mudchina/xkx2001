//Cracked by Roath
// Npc: /kungfu/class/shaolin/cheng-jian.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
int auto_perform();

void create()
{
	set_name("澄坚", ({
		"chengjian luohan",
		"chengjian",
		"zhantan",
		"luohan",
	}));
	set("long",
		"他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
		"太阳穴高高鼓起，似乎身怀绝世武功。\n"
	);

	set("nickname", "旃檀罗汉");
	set("gender", "男性");
	set("attitude", "peaceful");
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
	set("combat_exp", 450000);
	set("score", 5000);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);

        set_skill("cuff", 80);
        set_skill("luohan-quan", 80);
        set_skill("jingang-quan", 120);

        set_skill("hand", 80);
        set_skill("fengyun-shou", 80);
        set_skill("qianye-shou", 100);

        set_skill("strike", 90);
        set_skill("sanhua-zhang", 90);

	set_skill("finger", 130);
	set_skill("nianhua-zhi", 130);
	set_skill("parry", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
        map_skill("strike", "sanhua-zhang");
        map_skill("hand", "qianye-shou");
	map_skill("finger", "nianhua-zhi");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	create_family("少林派", 37, "弟子");

	setup();

        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}

int auto_perform()
{
        object target = select_opponent();

        if( !objectp(target) )  return 0;

        return perform_action("finger.fuxue");
}

#include "/kungfu/class/shaolin/cheng.h"

