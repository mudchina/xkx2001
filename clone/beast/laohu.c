//Cracked by Roath
// laohu.c 老虎

inherit NPC_TRAINEE;

void create()
{
	set_name("老虎", ({ "lao hu", "hu", "tiger" }) );
	set("race", "野兽");
	set("age", 25);
	set("long", "这是一头吊睛白额，气势汹汹的大虎，正恶狠狠地盯着你，好象随时随地都会扑上来择人而噬！\n");
	set("msg_fail", "$n冲$N呲牙吼了一声");
	set("msg_succ", "$n一面口中向$N荷荷发威，一面向后退了半步，似乎有些怯了");
	set("msg_trained","$n低吼着在$N的面前伏了下来");
	set("auto_follow",1);
	set("attitude", "aggressive");

	set("wildness", 12);
	set("ridable", 1);
	set("ability", 4);
	
	set("str", 40);	
	set("con", 40);
	set("dex", 40);	
	set("int", 10);

	set("combat_exp", 20000);

	set_temp("apply/attack", 50);
	set_temp("apply/damage", 70);
	set_temp("apply/armor",  30);

	set_weight(150000);

	set("chat_chance", 10);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"老虎用前爪拍击着地面，口中荷荷发威，好象随时都要扑上来！\n",
		"老虎微微侧着脑袋，双目炯炯，紧紧地注视着你的一举一动。\n",
		"老虎突然立了起来，绕着你走了半圈，似乎在观察着什么。\n",
	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"\n老虎怒啸一声，一反身，长长的尾巴向铁棍一样挥了过来！\n",
		"\n老虎全身一曲一弓，忽然跃起半空，猛地扑了下来！\n",
	}) );
		
	setup();
}

void die()
{
	message_vision("\n$N仰天惨嚎了一声，趴在地上不动了。\n", this_object());
	::die();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && ob->query_weight() >= 50000) {
		if(!this_object()->query_lord(ob)) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob);
		}
	}	

//	add_action("do_ride", "ride");
//	add_action("do_unride", "unride");
        add_action("do_look", "look");
}

/*int do_ride()
{
	object me, ob;
	me = this_object();
	ob = this_player();

	if( me->query_lord() == ob ) 
	{
		if( !ob->query_temp("riding") )
		{
			if( !me->query_temp("rider") ) 
			{
				ob->set_temp("riding", me->name());
				me->set_temp("rider",  ob->name());
				me->set_leader(ob);

				me->set("chat_msg", ({
					"老虎用前爪拍击着地面，口中荷荷发威，好象随时都要扑上来！\n",
					"老虎微微侧着脑袋，双目炯炯，紧紧地注视着你的一举一动。\n",
					"老虎突然立了起来，绕着你走了半圈，似乎在观察着什么。\n",
				}) );

				message_vision("\n$N一纵身，威风凛凛地骑在了" + me->name() +"身上。\n", ob);
				return 1;
			}
			else    return notify_fail( me->query_temp("rider") + "已经骑在它身上上了！\n");
		}
		else	return notify_fail("你已经骑在" + ob->query_temp("riding") + "上了！\n");
	}
	else return notify_fail("你不是它的主人！\n");

	return 0;
}

int do_unride()
{
	object me, ob;
	me = this_object();
	ob = this_player();

	if( ob->query_temp("riding") == me->name() && me->query_temp("rider") == ob->name() ) 
	{
		ob->delete_temp("riding");
		me->delete_temp("rider" );
		message_vision("\n$N一纵身，从" + me->name() +"身上跃了下来。\n", ob);
		return 1;
	}
	else return notify_fail("你还没骑它呢！\n");

	return 0;
}
 */

int do_look(string arg)
{
        object *inv;
        int i;

        inv = all_inventory(this_object());

        if (!id(arg)) return 0;

        if (!sizeof(inv)) return 0;

        printf(this_object()->query("long") + 
        COMBAT_D->eff_status_msg((int)this_object()->query("eff_qi")* 100 / (int)this_object()->query("max_qi")) + "\n" 
        + "它身上驮着：\n");
        for (i = 0; i < sizeof(inv); i++)
                printf("%s \n", inv[i]->short());
        return 1;
}

