//Cracked by Roath
// Npc: /kungfu/class/shaolin/hui-ming.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("慧名尊者", ({
		"huiming zunzhe",
		"huiming",
		"zunzhe",
	}));
	set("long",
		"他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，\n"
		"太阳穴微凸，双目炯炯有神。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 30);
	set("int", 20);
	set("con", 27);
	set("dex", 22);
	set("max_qi", 650);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 250000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("cuff", 74);
	set_skill("luohan-quan", 74);
	set_skill("hand", 70);
	set_skill("fengyun-shou", 70);
	set_skill("parry", 70);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "fengyun-shou");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "fengyun-shou");

	prepare_skill("hand", "fengyun-shou");
        prepare_skill("cuff", "luohan-quan");

	create_family("少林派", 38, "弟子");

	setup();

        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}


#include "/kungfu/class/shaolin/hui.h"

