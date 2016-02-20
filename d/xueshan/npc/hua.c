//Cracked by Roath
// hua.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("花铁干", ({ "hua tiegan","hua" }) );
	set("nickname","中平无敌");
	set("gender", "男性");
	set("age", 45);
	set("str", 28);
	set("con", 28);
	set("dex", 26);
	set("max_neili", 1000);
	set("neili", 2000);
	set("long",
		"这是江西鹰爪铁枪门的掌门。\n");
	set("combat_exp", 500000);
        set("shen_type", 1);
	set("attitude", "heroism");
	set("jiali", 70);
	set("chat_chance", 3);
	set("chat_msg", ({
	
//	"花铁干恨恨地说道：血刀老祖这个老贼，不知藏在什麽地方。找到他非把他碎尸万段！\n",
	"花铁干长声叫道：落花──流水兮，花──落水流！\n",
        }) );


	set_skill("sword", 120);
	set_skill("claw", 160);
	set_skill("parry", 120);
	set_skill("force", 120);
	set_skill("liuhe-qiang", 160);
	set_skill("ding-force", 120);
	set_skill("shaolin-shenfa", 120);
	set_skill("dodge", 120);
	set_skill("yingzhua-gong", 170);

	map_skill("pike", "liuhe-qiang");
	map_skill("parry", "liuhe-qiang");
	map_skill("force", "ding-force");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("claw", "yingzhua-gong");
	prepare_skill("claw", "yingzhua-gong");

	setup();

        carry_object("/clone/weapon/qiang")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}
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
                killer->add("shen", -3000);

	tell_object(killer,HIR"你只觉得刹那间心中一股杀气上涌，似是与血刀融为一体！\n",NOR);

                }
        }
	::die();
}

