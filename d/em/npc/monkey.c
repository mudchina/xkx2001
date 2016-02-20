//Cracked by Roath
// /d/emei/npc/monkey.c 小猴子
// Shan 6/26/96

inherit NPC;

void create()
{
        seteuid(getuid());

        set_name("小猴子", ({ "monkey", "hou", "houzi" }) );
        set("race", "野兽");
        set("age", 2+random(3));
        set("long", "一只机灵的小猴子，眼巴巴的看着你，大概想讨些吃的。\n");
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "身体",  "前腿", "后腿", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("thief", 0);

        set_skill("stealing", 10+random(20));
	set_skill("dodge", 10+random(20));

        set("combat_exp", 350+random(200));
        set_temp("apply/attack", 6+random(8));
        set_temp("apply/defense", 6+random(4));
        set_temp("apply/armor", 2);

        setup();

        set("chat_chance", 8);
        set("chat_msg", ({
                "一只小猴子忽然跑过来，向你作了个揖。\n",
		"一只小猴子叽叽喳喳跑了过来。\n",
		"小猴子蹦蹦跳跳地跑开了。\n",
                "小猴子摇摇尾巴跑开了。\n",
                (: random_move :)
        }) );
}

int accept_object(object me, object obj)
{
        object obj2;

        if ( obj->query("food_supply") && obj->value() >= 0 ) {
           command("drop"+obj->query("id"));
           message_vision("小猴子高兴地从$N身边跑开了。\n", me);
           set_leader(me);
           say("小猴子三两下便把"+(string)obj->query("name")+"吃得干干净净。\n");
           me->add("monkey", 1);

           remove_call_out("destroy_it");
           call_out("destroy_it", 1, obj);
           return 1;
        }
        else {
           say("小猴子把"+(string)obj->query("name")+"接了过来，玩弄了几下，似乎不懂有什么用。\n");
           command("shake");
           if (obj->query("money_id")) {
              obj2 = new(base_name(obj));
              obj2->set_amount((int)obj->query_amount());
              obj2->move(environment(me));
              say("小猴子把"+(string)obj->query("name")+"丢到地上。\n");
           }
           remove_call_out("drop_it");
           call_out("drop_it", 1, obj);
        }

        return 1; 
}

void drop_it(object obj)
{
        command("drop all");
}

void destroy_it(object obj)
{
        destruct(obj);
}


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
                       command("bow" + ob->query("id"));
		       break;
		case 1:
			command("steal kaoya from " + ob->query("id"));
			break;
		case 2:
                       command("jump" );
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
                       command("steal chuan from " + ob->query("id"));
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
                case 10:
                       command("steal bottle from " + ob->query("id"));  
                       command("drink bottle");
                       break;
	}
}

int is_grpfight()
{
	object me=this_object();
	object ob;
	int i;
	
	message_vision("周围的"+me->name()+"对$n群起而攻之！！\n\n", me, this_player());
	for (i=0;i<sizeof(all_inventory(environment(me)));i++)
		if (objectp(ob=present("monkey "+(i+1), environment(me))))
			ob->kill_ob(this_player());
	return 1;
}
