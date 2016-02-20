//Cracked by Roath
// dizi.c 侠客岛弟子
// Long, 6/13/97

#include <ansi.h>

inherit NPC;

int ask_leave();
int ask_food();
int ask_daozhu();
void greeting(object);

void create()
{
	set_name("黄衫弟子", ({ "dizi"}));
	set("long", "他是侠客岛岛主众多弟子之一。\n");
	set("gender", "男性");
	set("age", random(50) + 30);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("race", "人类");	
	set("max_qi", 1500);
	set("eff_qi", 1500);
	set("qi", 1500);
	set("max_jing", 1500);
	set("eff_jing", 1500);
	set("jing", 1500);
	set("max_neili", 1500);
	set("eff_neili", 1500);
	set("neili", 1500);
	set("max_jingli", 1500);
	set("eff_jingli", 1500);
	set("jingli", 1500);
	set("combat_exp", 300000 + random(5) * 100000);
	set("score", 1000);
	
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);
	set_skill("taixuan-gong", 150);
	set_skill("liuxing-bu", 150);
	set_skill("wugou-jianfa", 150);
	set_skill("wuyu-zhangfa", 150);

      map_skill("force", "taixuan-gong");
	map_skill("sword", "wugou-jianfa");
	map_skill("parry", "wugou-jianfa");
	map_skill("dodge", "liuxing-bu");
	map_skill("strike", "wuyu-zhangfa");
      prepare_skill("strike", "wuyu-zhangfa");

	set("inquiry", ([
			"杀人"   :  "杀人者，人杀之",
		]));
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/xiakedao/npc/obj/yellowrobe")->wear();

}
void init()
{	object victim;
	object me = this_object();

	::init();
	victim = find_player((string)me->query("xkd/killer"));
//	victim = find_player("long");	
	if (objectp(victim))	
	{	remove_call_out("do_chase");
		call_out("do_chase", 0, this_object());
	}
	else
	{	remove_call_out("waiting");
		call_out("waiting", 5, this_object());
	}
	return;
}

int do_chase(object killer)
{	object target;
	string callname;
	target = find_player(query("xkd/killer"));
	if( !objectp(target) || !environment(target) )	
	{
		call_out("waiting", 0, killer);
		return 1;
	}
	
	message_vision("$N走了过来。\n" NOR, killer);
	callname = RANK_D->query_rude(target);
	message_vision(HIR "\n$N对著$n喝道：「" 
                + callname + "！胆敢在侠客岛杀人，拿命来！」\n\n" NOR, killer, target);
	killer->set_leader(target);
	killer->kill_ob(target);
	call_out("checking", 1, killer);
	return 1;

}
int checking(object killer)
{
	object ob;

	if (killer->is_fighting()) 
	{	call_out("checking", 1, killer);
		return 1;
	}

	if( objectp(ob = present("corpse", environment(killer)))
		 && ob->query("victim_name") == killer->query("xkd/killer") )
	{	
		killer->delete("xkd/killer");
		command("kick corpse");
		destruct(killer);
        	return 1;
	}
	
	call_out("waiting", 1, killer);
	return 1;
}
int waiting(object killer)
{
	object target;
	target = find_player(killer->query("xkd/killer"));

	if ( objectp(target) )
	{	
		if (target->is_ghost())
		{	message_vision("$N掉头走了。\n" NOR, killer);
			killer->delete("target_name");
			//command("kick corpse", killer);
			destruct(killer);
			return 1;
		}
		else if (killer->is_fighting() && present(target, environment(killer)))
		{	call_out("checking", 0, killer);
			return 1;
		}
		else if (living(killer) && !environment(target)->query("no_fight"))
		{	call_out("do_chase", 0, killer);
			return 1;
		}
	}		
	else
	{	message_vision("$N掉头走了。\n" NOR, killer);
		destruct(killer);
		return 1;
	}
	
	remove_call_out("waiting");
	call_out("waiting", 60, killer);
    	return 1;
}
