//Cracked by Roath
// gaolao.c 高老者
// qfy Sept 8, 1996.

inherit NPC;
inherit F_MASTER;

int auto_perform();

void create()
{
	set_name("高老者", ({ "gao lao", "gao", "lao" }));
	set("long", 
"他身形高大硕状，满面红光。举止滑稽，带点傻气，武功却是极高。\n"
"他因不常在江湖上露面，是以并非太多人知闻其名。\n");
	set("gender", "男性");
	set("age", 73);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 27);
	set("int", 20);
	set("con", 27);
	set("dex", 25);
	
	set("max_qi", 4300);
	set("max_jing", 3000);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 100);
	set("combat_exp", 3200000);
	set("score", 5000);

	set_skill("force", 320);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("blade", 330);
	set_skill("sword", 320);
	set_skill("strike", 300);
	set_skill("liangyi-dao", 330);
	set_skill("huashan-jianfa", 320);
	set_skill("hunyuan-zhang",300);
	set_skill("huashan-shenfa", 300);
	set_skill("zixia-gong", 320);
	set_skill("cuff", 300);
	set_skill("pishi-poyu", 300);
	set_skill("ziyin-yin", 300);
	set_skill("zhengqi-jue", 300);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("blade", "liangyi-dao");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");
	map_skill("dodge", "huashan-shenfa");
	
	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("华山派", 12, "长老");

	set("inquiry", ([
	    "紫霞功" : "那是本门至高的内功心法。据说紫霞有个大秘密，可惜已失传多年了。\n",
	    "紫霞神功" : "那是本门无上的内功心法。据说紫霞有个大秘密，可惜已失传多年了。\n",
	    "思过崖" : "那是本派弟子修行思过之处。\n",
            "紫霞密笈" : "密笈上记载了修习紫霞功的心法。\n",
	    "紫霞密籍" : "密籍上记载了修习紫霞功的心法。\n",
	    "密室" : "你胡说八道些甚麽？\n",
	]));

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

#include "/kungfu/class/huashan/zhanglao.h"
