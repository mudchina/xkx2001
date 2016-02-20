//Cracked by Roath
//shanzei 山贼

inherit NPC;

void create()
{
	set_name("山贼", ({ "shan zei","zei","robber" }) );
	set("gender", "男性");
	set("age", 35+random(10));
	set("long",
		"这家伙身裁硕壮高大，一付凶神恶煞的模样，常在此作案洗劫游客。\n");
	set("combat_exp", 5000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set("chat_chance", 5);
	set("chat_msg", ({
	}) );

	set_skill("sword", 20);
	set_skill("blade", 20);
	set_skill("halberd", 20);
	set_skill("axe", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);

	setup();
        switch( random(8) )
        {
                case 0:
                        carry_object("/clone/weapon/gangjian")->wield();
                        break;
                case 1:
                        carry_object("/clone/weapon/gangdao")->wield();
                        break;
                case 2:
                        carry_object("/clone/weapon/banfu")->wield();
                        break;
                case 3:
                        carry_object("/clone/weapon/qiang")->wield();
                        break;
		case 4:
                        carry_object("/clone/weapon/changbian")->wield();
                        break;
                case 5:
                        carry_object("/clone/weapon/gangzhang")->wield();
			break;
                case 6:
                        carry_object("/clone/weapon/qimeigun")->wield();
                        break;
                case 7:
                        carry_object("/clone/weapon/zhubang")->wield();
                        break;
        }

        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 1);
}

#include "/d/quanzhou/npc/biao_robber.h"
