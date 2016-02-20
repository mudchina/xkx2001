//Cracked by Roath
// clone/beast/pig.c
// xbc 06/21/97

inherit NPC;

void create()
{
        set_name("小猪", ({"mu zhu", "pig"}));
        set("race", "野兽");
        set("age", 5);
	set("long", "一头臭气熏天的小猪。\n");
	set("attitude", "peaceful");
//	set("limbs", ({ "里脊", "蹄膀", "腰花", "大排" }) );
	set("verbs", ({ "bite" }) );
	set("combat_exp", 100);
	
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 4);
        set_temp("apply/armor", 1);

	setup();
}

void die()
{
        object ob;
	int i;

        message_vision("$N低低地哼了一声，倒在地上一动也不动了。\n", this_object());
	i = random (5);
	switch (i) {
	case 0:
        	ob = new("/u/rover/liji");
		break;
	case 1:
        	ob = new("/u/rover/yaohua");
		break;
	case 2:
        	ob = new("/u/rover/tipang");
		break;
	case 3:
		ob = new(__DIR__"obj/pork");
		break;
	case 4:
		ob = new(__DIR__"obj/pork");
		break;
	}

        ob->move(environment(this_object()));
        destruct(this_object());
}
