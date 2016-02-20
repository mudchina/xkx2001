//Cracked by Roath
// /kungfu/class/murong/baichuan.c
// Sure  5.13.2001

#include <ansi.h>
inherit NPC;
//inherit F_SSERVER;
inherit F_MASTER;

int auto_perform();
string ask_me();
void create()
{
	set_name("邓百川",({"deng baichuan","deng","baichuan"}) );
	set("gender","男性");
	set("long","他的脸上有深深的皱纹，似乎经历了不少的风雨。\n");
	set("title","百花府主人");
	set("age",53);

	set("con",23);
	set("dex",20);
	set("int",21);
	set("str",22);
	set("jing",3000);
	set("max_jing",3000);
	set("qi",3000);
	set("max_qi",3000);
	set("jingli",4000);
	set("max_jingli",4000);
	set("neili",4000);
	set("max_neili",4000);
	set("combat_exp",3000000);

	set_skill("force",300);
	set_skill("dodge",300);
	set_skill("parry",300);
	set_skill("finger",300);
	set_skill("literate",300);
	set_skill("canhe-zhi",300);
	set_skill("douzhuan-xingyi",300);
	set_skill("murong-shenfa",300);

	map_skill("finger","canhe-zhi");
	map_skill("force","douzhuan-xingyi");
	map_skill("parry","canhe-zhi");
	map_skill("dodge","murong-shenfa");

	prepare_skill("finger","canhe-zhi");

	create_family("姑苏慕容", 19, "传人");

	set("inquiry", ([
		"包不同": "那是我的兄弟。",
		"慕容复" : "我们家公子忙于大事，没时间接待你，你还是请回吧！",
		"姑苏慕容" : "嘿嘿，你是不是觊觎我家公子的“以彼之道，还施彼身”的 \n"
					"功夫了？ \n",
		"慕容博" : "老爷他突然撒手人寰，真是英年早逝呀。唉……",
					]) );
	
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
			
		setup();

	carry_object("/d/murong/obj/qingyi")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}

#include "/kungfu/class/murong/master.h"
}