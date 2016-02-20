//Cracked by Roath
// Jay 8/9/96
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("任我行",({ "ren woxing","ren" }) );
        set("gender", "男性");
        set("age", 55);
	set("long",
		"他花白长须垂在胸前，胡子满脸，看不清他的本来面容。\n");
      //  set("nickname","");
        set("title","日月神教前教主");
        set("combat_exp", 1800000);
        set("shen_type", 0);
        set("attitude", "peaceful");
        set_skill("unarmed", 180);

	set_skill("force",180);
        set_skill("parry", 180);
        set_skill("dodge", 180);
	set_skill("huagong-dafa",180);
	set_skill("sword",150);
	map_skill("force","huagong-dafa");

	set("max_neili",5000);
	set("neili",5000);
	set("jiali",100);
       setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}


void greeting(object me)
{
  object book, kao;

	if (kao=present("liaokao",me)) {
		destruct(kao);
		me->unconcious();
		me->move("/d/jiaxing/changdi");
		return;
	}
	command("thank "+me->query("id"));
	command("say 多谢你的相助，我才得以逃脱。");
	if (!present("kuihua baodian",me)) {
	 command("say 赠你一本敝教的传教之宝书，你若有心可以研读。");
	 book = new(__DIR__"obj/baodian");
	 book->move(me);
	 command("chat 天下英雄，唯"+me->query("name")+"与我耳！");
	}
	return;
}

	
