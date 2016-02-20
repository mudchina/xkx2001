//Cracked by Roath
// 

#include <ansi.h>
inherit NPC;
string ask_midao();

void create()
{
	set_name("小昭", ({"xiao zhao", "zhao"}));
	//set("nickname", "");
	set("long", 
		"她右目大，左目小，鼻子和嘴角也都扭曲，左足跛行，背脊成弓形，\n"
		"形状极是怕人。她双脚之间系着一根细铁链，双手腕上也锁着一根铁链。\n");

	set("age", 17 );
	set("gender", "女性");
	set("attitude", "heroism");

	set("str", 24);
	set("dex", 16);
	set("per", 34);
	set("shen_type", 0);

	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 20);
	set("combat_exp", 50000);
	set("score", 0);


	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("force", 50);

//	set_skill("mofu-wuzong", 0);

	map_skill("dodge", "");

        set("inquiry", ([
                "秘道" : (:ask_midao:),
                //"秘道" : (:do_midao :),

        ]) );

        set("chat_chance_combat", 10);
	setup();
	carry_object(__DIR__"obj/lian")->wield();
//	carry_object(__DIR__"obj/")->wear();
}
int init()
{
   ::init();
   add_action("do_cut", "cut");	
   add_action("do_cut", "la");	
}
int do_cut(string arg)
{	object weapon;
	object me = this_player();
	if ( !arg && arg != "lian" && arg != "chain" )
	     return notify_fail( "什么？\n");
	if ( !objectp(weapon = me->query_temp("weapon")))
	{  if (me->query("qi") > 500)
	   {	message_vision( "$N拉住小昭双手只间的铁链，运劲分拉，铁链渐渐延长，却是不断。\n", me);
		message_vision("小昭叫道“唉呀，不好。你越拉越长，我可更加不便啦。”");
		return 1;
	   }
	   else
	   {	message_vision( "$N双手握住小昭双手只间的铁链，用劲一崩，只听见嗡的一声，铁链却是不断。\n", me);
		message_vision("小昭说道“这链子古怪得紧，便是宝刀利刃，也伤它不了。锁上的钥匙在小姐手里。”");
		return 1;
	   }

	}
   	if ((string)weapon->query("skill_type") != "sword" && (string)weapon->query("skill_type") != "blade" )
	{	
	   message_vision("$N举起" + weapon->name() + "用劲砸下，只听得砰的一声，但铁链还是不断。\n", me);
	   return 1;
	}
	if ( weapon->name() == "玄铁剑" || weapon->name() == "倚天剑" || weapon->name() == "屠龙刀")
	{
	   message_vision("$N一挥手中的" + weapon->name() + "，向小昭手上的铁链砍去，铁链应手被砍断了。\n", me);
	   me->set_temp("marks/断", 1);
	   return 1;
	}

	
}
int ask_midao()
{	
	object me = this_player();
	if ((int)me->query_temp("marks/断"))
	{  write("小昭咬着下唇，微一沉吟，低声道，“好，我带你去。”\n");
	   me->set_temp("marks/摸", 1);
	   me->delete_temp("marks/断");
	   return 1;
	}
	else
	{  write("小昭摇了摇头说，“不知道。”\n";
	   return 0;
	}
}
