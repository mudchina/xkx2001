// /d/lingjiu/npc/tbhao.c 昊天部 余婆婆
// By adx @ CuteRabbit 22:21 99-3-19

#include <ansi.h>
int auto_perform();
inherit NPC;
void create()
{
	set_name("余婆婆", ({ "yu popo", "yu", "popo" }));
	set("long",
	    "她是「灵鹫宫」九天九部中昊天部的首领.\n"+
	    "她跟随童姥多年, 出生入死,饱经风霜.\n");
	set("title", "昊天部首领");
	set("gender", "女性");
	set("age", 60);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("per", 23);
	set("class", "scholar");
	set("str", 20);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 1300);
	set("max_qi", 1300);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 20);

	set("combat_exp", 300000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	set_skill("sword",100);
	set_skill("literate",100);
	set_skill("music",100);

	set_skill("zhemei-shou",100);
	set_skill("liuyang-zhang",100);
	set_skill("tianyu-qijian",100);
	set_skill("yueying-wubu",100);
	set_skill("bahuang-gong", 100);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");
	create_family("灵鹫宫",4,"弟子");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	setup();
 	carry_object("/clone/weapon/changjian")->wield();
 	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        add_money("silver",25);
}
#include "/kungfu/class/lingjiu/tianbu.h"
#include "/kungfu/class/lingjiu/auto_perform.h"