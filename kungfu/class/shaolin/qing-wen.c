//Cracked by Roath
// Npc: /kungfu/class/shaolin/qing-wen.c
// Date: YZC 96/01/19

inherit NPC;


void create()
{
	set_name("清闻比丘", ({
		"qingwen biqiu",
		"qingwen",
		"biqiu",
	}));
	set("long",
		"他是一位体格强健的壮年僧人，他身得虎背熊腰，全身似乎蕴含\n"
		"着无穷劲力。他身穿一袭白布黑边袈裟，似乎身怀武艺。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 19);
	set("int", 20);
	set("con", 22);
	set("dex", 21);
	set("max_qi", 350);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 30000);
	set("score", 100);

	set_skill("force", 35);
	set_skill("hunyuan-yiqi", 40);
	set_skill("dodge", 40);
	set_skill("shaolin-shenfa", 40);
	set_skill("hand", 40);
	set_skill("fengyun-shou", 40);
	set_skill("cuff", 40);
	set_skill("luohan-quan", 40);
	set_skill("parry", 40);
	set_skill("buddhism", 50);
	set_skill("literate", 20);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "fengyun-shou");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "fengyun-shou");

	prepare_skill("hand", "fengyun-shou");
        prepare_skill("cuff", "luohan-quan");

	create_family("少林派", 40, "弟子");

	setup();

        carry_object("/d/shaolin/obj/qing-cloth")->wear();
}


#include "/kungfu/class/shaolin/qing.h"

