//Cracked by Roath
// /d/xiakedao/npc/monkey.c 猴子
// Shan 6/26/96
// Ssy

inherit NPC;

void create()
{
        seteuid(getuid());

        set_name("小猴子", ({ "monkey", "hou", "houzi" }) );
        set("race", "野兽");
        set("age", 8);
        set("long", "一只机灵的猴子，眼巴巴的看着你，大概想讨些吃的。\n");
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "身体",  "前腿", "后腿", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("thief", 0);

        set("combat_exp", 30);
        set_temp("apply/armor", 3);

        setup();

        set("chat_chance", 8);
        set("chat_msg", ({
                "一只猴子忽然跑过来，向你作了个揖。\n",
		"一只猴子叽叽喳喳跑了过来。\n",
		"猴子蹦蹦跳跳地跑开了。\n",
                "猴子摇摇尾巴跑开了。\n",
                (: random_move :)
        }) );
}

// inherit F_UNIQUE;

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("stealing");
		call_out("stealing", 1, ob);
	}
}

void stealing(object ob)
{
	mapping fam; 
 
	switch( random(10) ) {
		case 0:
                       command("bow " + ob->query("id"));
		       break;
		case 1:
                       command("xixi " + ob->query("id"));
		       break;
		case 2:
                       command("jump" );
		       break;
		case 3:
                       command("trip " + ob->query("id"));
		       break;
		case 4:
                       command("wanfu");
		       break;
                case 5:
                       command("trip" );
                       break;
                case 6:
                       command("claw");
                       break;
                case 7:
                       command("pat");
                       break;
                case 8:
                       command("fear");
                       break;
                case 9:
                       command("giggle" );
                       break;
                case 10:
                       command("wave" );
                       break;
	}
}


int accept_object(object me, object obj)
{
	if (obj->query("food_supply") && obj->value() >= 0) {
        	 command("bow "+ me->query("id"));
		 command("bite");
	}
        else {
        	 command("shake");
	         command("give " + obj->query("id") + " to " + me->query("id"));
		 obj->move(this_player());
        }
	return 1;
}

