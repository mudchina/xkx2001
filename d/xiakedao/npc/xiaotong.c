//Cracked by Roath
// xiaotong.c 小童
// Long, 6/13/97

#include <ansi.h>
inherit NPC;

void greeting(object);


void create()
{
	set_name("小僮", ({ "xiao tong", "tong"}));
	set("long", "他是个年龄不大的小男孩，但已很健壮了。\n");
	set("gender", "男性");
	set("age", 14);
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
	set("score", 1000);

	set_skill("force", 5);
	set_skill("dodge", 5);
	set_skill("parry", 5);
	set_skill("cuff", 5);
	set_skill("sword", 5);
	
//	set("inquiry", ([
//			""   : 	"\n",
//		]));
	setup();
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
{	command("bow " + me->query("id"));
	command("say 你如果要些吃的或喝的只要叫我一声"+HBRED+HIW"(serve)"NOR+"。");
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
	     command("xixi "+ me->query("id"));
	     message_vision("$N接过椰子，掏出一把小刀，熟练地挖了个洞，笑眯眯地把椰子壳还给了你。\n", this_object());
	     ke = new("/d/xiakedao/obj/yezike");
	     ke->move(this_player());
	     return 1;
	  }
	else 
	  {
             command("? "+ me->query("id"));
	     return 0;
	  }
}
 
