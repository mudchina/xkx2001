//Cracked by Roath

#include <ansi.h>

inherit NPC;
int ask_me();
int ask_wage();
void create()
{
	set_name("努儿海", ({ "nuerhai"}) );
	set("title", "一品堂总管");
	set("gender", "男性");
	set("age", 55);
	set("long",
		"这是个身形极高、鼻子极大的汉子。\n");
	set("combat_exp", 20000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set("str", 26);
	set("con", 22);
	set("int", 20);
	set("dex", 24);

	set("max_qi", 600);
	set("eff_qi", 600);
	set("qi", 600);
	set("max_jing", 500);
	set("jing", 500);

	set_temp("apply/attack",  60);
	set_temp("apply/defense", 60);

	set_skill("parry", 60);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	
	set("inquiry",
        ([
		"效命" : (: ask_me :),
		"工钱" : (: ask_wage :),
	]));

	setup();

        carry_object("/d/city/obj/cloth")->wear();
}

int ask_wage()
{
	say("努尔海说道：令呢？\n");
	this_player()->set_temp("wait_ling", 1);
	return 1;
}
int accept_object(object who, object ob)
{
	object obj;

	if (who->query_temp("wait_ling") 
	&& ob->query("id") == "qingtie ling" && ob->query("done")){
	obj=new("/clone/money/gold");
	obj->move(who);
	who->delete_temp("wait_ling");
	say("努尔海递给你几锭黄金，说道：大人请收好。\n");
	call_out("destroy_it", 1, ob);
	return 1;
	}
	else{ return 0;}
}
void destroy_it(object ob)
{
	if (ob)
	destruct(ob);
}
int check_worker()
{
	object *all;
        int i,j=0;

	all = users();

                for(i=0; i<sizeof(all); i++){
	if(all[i]->query_temp("xixia/一品堂"))
        printf("%s(%s)\n", 
			all[i]->query("name"),
			all[i]->query("id"));}
}

int ask_me()
{
        object ob, me=this_player();
	object *all;
	int i,j=0;

	all = users();

	        for(i=0; i<sizeof(all); i++) 
        {
	 if(all[i]->query_temp("xixia/一品堂") )
			j++;
	}
	if (j>4){
	say("努儿海粗声说道：今天人满了，你明天再来吧！\n");
	return 1;
	}

	if (me->query("age") < 20 || me->query("combat_exp") < 15000)
	{
        command("say 你这个小毛孩子是在打趣老夫吧！边上玩着去！");
	return 1;
	}

	if (me->query("shen") > -me->query("combat_exp")/2)
	{
	command("say 你莫不是白道派来我们西夏卧底的吧。");
	return 1;
	}

	if (me->query_temp("xixia/testpass")) return 0;
	if (me->query_temp("xixia/一品堂")) return 0;

if ((int)me->query_temp("marks/西夏1")) 
{
 say("努儿海满脸不悦的说：不是告诉你了吗，干什么还在这儿跟我耗着？\n");
return 1;
}
else 
{
string qname = me->query("name");
me->set_temp("marks/西夏1", 2);
switch(random(3)) 
{
/*case 5:
me->set_temp("marks/西夏duan");
command("say 你去找段延庆先生测试武功吧。");
break ;
*/
case 0: 
me->set_temp("marks/西夏ye", 2);
command("say 你去找叶二娘测试武功吧。");
break ;  
case 1:
me->set_temp("marks/西夏nan", 2);
command("say 你去找南海鳄神先生测试武功吧。");
break ;  
case 2:
me->set_temp("marks/西夏yun", 2);
command("say 你去找云中鹤先生测试武功吧。");
break ;
}
return 1;
}

}
