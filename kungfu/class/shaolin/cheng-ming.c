//Cracked by Roath
// Npc: /kungfu/class/shaolin/cheng-ming.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("澄明", ({
		"chengming luohan",
		"chengming",
		"guizhen",
		"luohan",
	}));
	set("long",
		"他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
		"太阳穴高高鼓起，似乎身怀绝世武功。\n"
	);

	set("nickname", "归真罗汉");
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
	set("combat_exp", 400000);
	set("score", 5000);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
        set_skill("cuff", 80);
        set_skill("luohan-quan", 80);
        set_skill("club", 80);
        set_skill("weituo-gun", 80);
        set_skill("hand", 100);
        set_skill("qianye-shou", 100);
	set_skill("strike", 130);
        set_skill("sanhua-zhang", 90);
	set_skill("banruo-zhang", 130);
	set_skill("parry", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
        map_skill("club", "weituo-gun");
        map_skill("hand", "qianye-shou");
	map_skill("strike", "banruo-zhang");
	map_skill("parry", "banruo-zhang");

	prepare_skill("strike", "banruo-zhang");

	create_family("少林派", 37, "弟子");

	setup();

        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/kungfu/class/shaolin/cheng.h"

