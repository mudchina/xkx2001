//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("黄钟公",({ "huangzhong gong","gong" }) );
        set("gender", "男性");
        set("age", 65);
	set("long",
		"他骨瘦如柴，脸上的肌肉都凹了进去，直如一具骷髅，"
		"双目却炯炯有神。\n");
       // set("nickname","");
        set("title","梅庄大庄主");
        set("combat_exp", 90000);
        set("shen_type", 0);
        set("attitude", "friendly");
        set_skill("unarmed", 90);
	set_skill("force",90);
        set_skill("parry", 90);
        set_skill("dodge", 90);
	set_skill("staff",90);

	set("max_neili",500);
	set("neili",500);
	set("jiali",45);


        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/yaoqin")->wield();
}

#include "mzkill.h"


