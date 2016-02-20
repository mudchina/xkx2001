//Cracked by Roath
// liu.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("刘承风", ({ "liu chengfeng","liu" }) );
	set("nickname","柔云剑");
	set("gender", "男性");
	set("age", 45);
	set("con", 30);
	set("str", 24);
	set("dex", 25);
	set("long",

"这是位太极门的高手，肩背长剑，长长的剑穗随风飘扬，看来似乎身怀绝艺。\n");
//	set("title","落花流水老四");
	set("combat_exp", 550000);
        set("shen_type", 1);
	set("attitude", "heroism");
	set("jiali", 70);
	set("max_neili",1500);
	set("neili", 3000);
	set("chat_chance", 3);
	set("chat_msg", ({
//		"刘承风恨恨地说道：血刀老祖这个老贼，不知藏在什麽地方。找到他非把他碎尸万段！\n",
	"刘承风长声叫道：落花流──水兮，流──水落花！\n",
        }) );
	/*
	set("chat_combat_chance", 100);
	set("chat_combat_msg", ({
	(:perform_action, "chan":)
	}));
	*/

	set_skill("sword", 145);
	set_skill("cuff", 140);
	set_skill("parry", 140);
	set_skill("force", 120);
	set_skill("taiji-jian", 140);
	set_skill("taiji-shengong", 120);
	set_skill("taiji-quan", 60);
	set_skill("ding-dodge", 120);
	set_skill("dodge", 170);

	map_skill("sword", "taiji-jian");
	map_skill("parry", "taiji-jian");
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "ding-dodge");
	map_skill("cuff", "taiji-quan");
	prepare_skill("cuff", "taiji-quan");
	setup();

        carry_object("/d/city/obj/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}
//#include "/d/qilian/npc/auto_perform.h"
void die()
{
        object corpse, killer;
        int i;

        if( !living(this_object()) ) revive(1);
        this_object()->clear_condition();
        if( objectp(killer = query_temp("last_damage_from")) ) 
        {
                set_temp("my_killer", killer->query("id"));
                COMBAT_D->killer_reward(killer, this_object());
         if (killer->query_temp("jidao",1)>0)
                {
                killer->add_temp("jidao", -1);
                killer->improve_skill("blade",
(int)(killer->query_skill("blade", 1)+1) * 40);
                killer->add("shen", -30000);

tell_object(killer,HIR"你只觉得刹那间心中一股杀气上涌，似是与血刀融为一体！\n",NOR);

                }
        }
	::die();
}

