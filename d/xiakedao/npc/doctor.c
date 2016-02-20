//Cracked by Roath
// doctor.c 医者
// Ssy

#include <ansi.h>
inherit NPC;

void greeting(object);


void create()
{
	set_name("医者", ({ "doctor", "yizhe"}));
	set("long", 
	    "一位白发银须的老者。据说当年曾经是江湖上一位著名的神医。\n"
            "但自从来到侠客岛上后，隐姓埋名，至今谁也不知道他真名是甚么了。\n"
            "他看起来懒洋洋的，你要是想请他疗伤的话恐怕不那么容易。\n");
	set("gender", "男性");
	set("age", 74);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("race", "人类");	
	set("max_qi", 150);
	set("eff_qi", 150);
	set("qi", 150);
	set("max_jing", 150);
	set("eff_jing", 150);
	set("jing", 150);
	set("max_neili", 150);
	set("eff_neili", 150);
	set("neili", 150);
	set("max_jingli", 150);
	set("eff_jingli", 150);
	set("jingli", 150);
	set("combat_exp", 1000);

	set_skill("force", 5);
	set_skill("dodge", 5);
	set_skill("parry", 5);
	set_skill("cuff", 5);
	set_skill("sword", 5);
	
	set("inquiry", ([
			"疗伤"   : 	"我现在倦得很，让我歇歇罢。\n",
			"heal"   :      "我现在倦得很，让我歇歇罢。\n",
		]));

	setup();
        carry_object("/d/wudang/obj/greyrobe")->wear();

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
        int wound = (me->query("eff_qi")*100)/(me->query("max_qi"));
	if (wound < 20)
	  {
	    command("walkby " + me->query("id"));
	    command("say " + RANK_D->query_respect(me) + "怎么伤得这样厉害？\n");
	  }
	else if (wound < 100)
	  {
	    command("sigh");
	    command("say " + RANK_D->query_respect(me) +
"又受伤啦？没关系，练武嘛，不吃点苦头怎么能成大器呢？");
	  }
	else
	  {
	    command("hehehe " + me->query("id"));
	  }
}

int accept_object(object me, object obj)
{
        call_out("accept_obj", 1, me, obj);
        return 1;
}

int accept_obj(object me, object obj)
{
        object ke;
        if( obj->query("name")=="椰子") 
	  {
	     command("thumb "+ me->query("id"));
	     command("say " + RANK_D->query_respect(me) +
"怎么知道我喜欢吃椰子？　好罢，我给你看看伤……\n");
	     message_vision("$N取了些药品，又拿来许多绷带夹板等物，给$n利落地包扎了一下，果然是妙手回春！\n", this_object(), me);
	     message_vision("$N笑道：你这点小伤，在我看来算不了甚么。\n", this_object(), me);
	     me->set("eff_qi", me->query("max_qi"));
	     return 1;
	  }
	else 
	  {
             command("? "+ me->query("id"));
	     return 0;
	  }
}
 
