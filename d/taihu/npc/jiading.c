//Cracked by Roath
// 
// 
inherit NPC;

int accept_object(object me, object obj);
void create()
{
	set_name("家丁", ({ "jia ding", "ding" }));
	set("long", "一个二十出头的小伙子，身板结实，双目有神，似乎练过几年功夫。\n");
	set("gender", "男性");
	set("age", 25);

	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("stick", 30);
	set_skill("staff", 30);
	set_skill("sword", 30);
	set_skill("blade", 30);	
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 5);

	set("combat_exp", 10000);
	set("shen_type", 1);
	setup();

	switch( random(4) )
        {
                case 0:
                       carry_object("/d/city/obj/gangjian")->wield();
                       break;
                case 1:
                       carry_object("/d/city/obj/gangdao")->wield();
                       break;
                case 2:
                       carry_object("/d/xingxiu/obj/gangzhang")->wield();
                       break;
                case 3:
                       carry_object("/d/city/obj/zhubang")->wield();
		       break;		
	}
}

int accept_object(object me, object obj)
{
      if((string)obj->query("name") == "书信") {
		command("bow "+me->query("id"));
		message_vision("家丁说道："+RANK_D->query_respect(me)+"原来是少庄主的朋友，快快请进\n",me);
		me->set_temp("guiyun",1);
	}
	return 0;
}
