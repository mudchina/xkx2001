//Cracked by Roath
// referee.c

inherit NPC;
#include <ansi.h>;

int do_bihua();
string ask_me();
int do_halt();

void create()
{
	set_name("公平子", ({ "gongping zi", "zi", "referee" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这是一位仙风道骨的中年道人，早年云游四方，性好任侠，公正无私。\n");
	set("combat_exp",60000);
        set("shen_type", 1);
	set("attitude", "friendly");

	set("apply/attack", 50);
	set("apply/defense", 50);

	set("max_qi", 800);
	set("max_jing", 800);
	set("max_neili", 800);

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("sword",80);
	set_skill("parry",80);
	set_skill("dodge", 80);

	set("inquiry", ([
		"比武大会"       : (: ask_me :),
	]));

	setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/changjian")->wield();
}

void init()
{
        ::init();	
        add_action("do_bihua", "bihua");
        add_action("do_bihua", "bi");
        add_action("do_bihua", "fight");
        add_action("do_halt", "halt");
        add_action("do_halt", "h");
}

string ask_me()
{
	object* ob;
	int i;
	ob = users();

	if ( !wizardp(this_player()) ) return "你无权召开比武大会！\n";

	for ( i=sizeof(ob); i>0; i-- ) {
		ob[i-1]->move("/d/quanzhou/leitai2");
	}

	return "好，现在比武大会正式开始，全体集合！\n";
}

