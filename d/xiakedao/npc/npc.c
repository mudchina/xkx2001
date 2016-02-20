//Cracked by Roath
// puren.c 侠客岛仆人
// Long, 6/13/97

#include <ansi.h>

inherit NPC;

int ask_leave();
int ask_weapon();
int ask_armor();
void greeting(object);

void create()
{
	set_name("仆人", ({ "pu ren", "pu"}));
	set("long", "他\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("race", "人类");	
	set("max_qi", 200);
	set("eff_qi", 200);
	set("qi", 200);
	set("max_jing", 200);
	set("eff_jing", 200);
	set("jing", 200);
	set("max_neili", 200);
	set("eff_neili", 200);
	set("neili", 200);
	set("max_jingli", 200);
	set("eff_jingli", 200);
	set("jingli", 200);
	set("combat_exp", 50000);
	set("score", 1000);

	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("cuff", 70);
	set_skill("sword", 70);
	
	set("inquiry", ([
			"兵器"   :  (: ask_weapon :),
			"防具"   :  (: ask_armor :),
			"中原"   : 	(: ask_leave :),
			"岛主"   : 	"岛主好象在後山\n",
			
		]));
	setup();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	
	say("仆人微微一笑说道：这位" + 
			RANK_D->query_respect(me) + "走山路或野路时要小心野兽，老虎和毒蛇见人就咬的。\n");
	say("仆人说道：你身上可有当武器的东西? 刀，剑，石块或树枝都可以用来加强你的攻击力。\n");
	say("仆人说道：如果有你可以用来装备自己(wield item)。如果没有你可以去买(buy item)。\n");
	say("仆人说道：我这里正好有几件，你要的话就告诉我(ask pu about 武器)。\n");
	say("仆人说道：还有你可以找些东西来穿，狗皮，牛皮，皮背心，或铁甲等等。\n");
	say("仆人说道：这些都可以增加你的防御能力。有就快穿上吧(wear item)。\n");
	say("仆人说道：我这好象也还有一两件，要就问我要吧(ask pu about 防具)。\n");

}
int ask_leave()
{	
	say("仆人摇了摇头说道：没有岛主同意，你可不能私自离岛。\n");
}
int ask_weapon()
{

}
int ask_armor()
{

}