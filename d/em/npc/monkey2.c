//Cracked by Roath
// /d/emei/npc/monkey2.c 猴子
// Shan 6/26/96

inherit NPC;

void create()
{
        seteuid(getuid());

        set_name("猴子", ({ "monkey", "hou", "houzi" }) );
        set("race", "野兽");
        set("age", 8);
        set("long", "一只机灵的猴子，眼巴巴的看着你，大概想讨些吃的。\n");
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "身体",  "前腿", "后腿", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("thief", 0);

        set_skill("stealing", 30);
	set_skill("dodge", 20);

        set("combat_exp", 500);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
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
 
	if( !ob || environment(ob) != environment() 
                || ((fam = ob->query("family")) && fam["family_name"] == "峨嵋")
          ) return;

	switch( random(10) ) {
		case 0:
                       command("bow " + ob->query("id"));
		       break;
		case 1:
                       command("smirk " + ob->query("id"));
		       break;
		case 2:
                       command("jump " );
		       break;
		case 3:
                       command("steal jitui from " + ob->query("id"));	
                       command("eat jitui");
		       break;
		case 4:
                       command("steal jiudai from " + ob->query("id"));	
                       command("drink jiudai");
		       break;
                case 5:
                       command("trip " );
                       break;
                case 6:
                       command("steal hulu from " + ob->query("id"));  
                       command("drink hulu");
                       break;
                case 7:
                       command("steal tao from " + ob->query("id"));  
                       command("eat tao");
                       break;
                case 8:
                       command("fear ");
                       break;
                case 9:
                       command("giggle " );
                       break;
                case 10:
                       command("wave " );
                       command("steal bottle from " + ob->query("id"));  
                       command("drink bottle");
                       break;
	}
}


int accept_object(object me, object obj)
{
	if (obj->query("food_supply") && obj->value() >= 0) {
        	 command("bow "+ me->query("id"));
		command("bite ");
//		command("eat" + obj->query("id"));
	}
        else {
        	 command("shake");
	         command("give " + obj->query("id") + " to " + me->query("id"));
//		command("drop " + obj->query("id"));
               obj->move(this_player());
        }
	return 1;
}

