//Cracked by Roath
// laohu.c 老虎

inherit NPC_TRAINEE;

void create()
{
	set_name("白熊", ({ "bai xiong", "xiong", "bear" }) );
	set("race", "野兽");
	set("age", 25);
	set("long", "这头大白熊，毛长身巨，竟和大牯牛相似，张牙舞爪，狰狞可怖！\n");
	set("msg_fail", "$n冲$N呲牙吼了一声");
	set("msg_succ", "$n人立起来，向后退了半步，似乎有些怯了");
	set("msg_trained","$n低吼着在$N的面前伏了下来");
	set("auto_follow",1);
	set("attitude", "aggressive");

	set("wildness", 12);
	set("ridable", 1);
	set("ability", 4);
	
	set("str", 60);	
	set("con", 60);
	set("dex", 30);	
	set("int", 10);

	set("combat_exp", 30000);

	set_temp("apply/attack", 50);
	set_temp("apply/damage", 70);
	set_temp("apply/armor",  50);

	set_weight(150000);

	set("chat_chance", 10);
	set("chat_msg", ({
		"白熊在地上打了个滚，张嘴打了个哈欠。\n",
		"白熊微微侧着脑袋，双目炯炯，紧紧地注视着你的一举一动。\n",
		"白熊在绕着你走了半圈，不时仰头吼叫！\n",
	}) );
	
	set("chat_msg_combat", ({
		"\n白熊人立起来，提起巨掌，便要拍落！\n",
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

        add_action("do_look", "look");
}

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

