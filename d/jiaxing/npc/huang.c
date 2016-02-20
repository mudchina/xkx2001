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


	set("mz/toy","广陵散");
	set("mz/set","huang");
	set("mz/need","heibai");
	set("mz/needname","二庄主");
        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/yaoqin")->wield();
}

void fightwin(object who)
{
	object where = environment(this_object());

	message_vision("黄钟公掀起床上的被缛，揭起床板，露出一个长方大洞。\n\n",
		who);
        command("say 你若有本事，请和我们梅庄里的这位在地下隐居的高手比比。");

	call_out("create_exit",1,where);
}

void create_exit(object where)
{
	where->set("exits/enter","/d/jiaxing/didao1");
}
#include "mzfight.h"



