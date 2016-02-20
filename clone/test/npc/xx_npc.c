//Cracked by Roath
// xx_npc.c 
// 08/03/00

#include <ansi.h>

inherit NPC;

int auto_perform();
int unarmed();
int weapon();

void create()
{
	set_name("星宿弟子", ({"xx_npc", "dizi", "xx"}));
	set("gender", "男性");
	set("age", 65);
	set("long", 
		"据说是星宿武功最高的大师兄。\n");
 	
	set("attitude", "peaceful");
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	

	set("chat_chance", 1);
	set("chat_msg", ({
		(: command("say 老子我最利害，不服气就和我比划一下！") :),
		(: command("grin") :),
	}));

	
	set("neili", 8000);
	set("eff_neili", 8000);
	set("max_neili", 8000);
	set("jingli", 5000);
	set("max_jingli", 5000);
	set("eff_jingli", 5000);
	set("jiali", 200);
	set("jiajin",30);
	
	set("combat_exp", 6400000);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
              (: auto_perform :),
        }) );

	create_family("星宿派", 2, "弟子");

	set_skill("force", 400);		
	set_skill("huagong-dafa", 400);		
	set_skill("strike", 400);
	set_skill("claw", 400);
	set_skill("sanyin-zhua", 400);	
	set_skill("tianshan-zhang", 400);	
	set_skill("dodge", 400);		
	set_skill("zhaixinggong", 400);		
	set_skill("chousui-zhang", 400);		
	set_skill("parry", 400);		
	set_skill("staff", 400);			
	set_skill("feixing-shu", 400);
	set_skill("poison", 400);

	map_skill("force", "huagong-dafa");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-zhua");
	map_skill("dodge", "zhaixinggong");
	map_skill("parry", "tianshan-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-zhua");
	

	set("inquiry", ([ 
                "unarmed"   : (: unarmed :),
                "weapon"    : (: weapon :),

	]) );

	setup();
	
	carry_object("/clone/weapon/gangzhang")->wield();
    carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
	carry_object("/d/xingxiu/obj/blzhen");
    carry_object("/d/xingxiu/obj/lianxin");
	carry_object("/d/xingxiu/obj/sanxiao");
	carry_object("/d/xingxiu/obj/yudi");

}

void init(){ set_heart_beat(1);}


// auto perform function (dispatched by chat_combat_msg)

int auto_perform()
{
        object me = this_object();
        object target = me->select_opponent();


        if ( !objectp(target)
          || !random( (int)me->query("combat_exp") * 2
                   / (int)target->query("combat_exp") + 1) ) return 0;

        if( objectp(me->query_temp("weapon")) ) {
                command("perform jinxian");
        }
        else
        {
                if( !target->query_temp("huagong") )
                        command("perform sanyin");
                else
                        command("yun qisuck "+target->query("id"));
        }

/*        if( present("sanxiao san", me) ||present("biling zhen", me)
          ||present("lianxin dan", me)){
          command("throw " + target->query("id"));
          }
*/
		return 1;
}

int unarmed(){
	command("unwield gangzhang");
	map_skill("parry", "chousui-zhang");
	command("blow di");
	command("say OK 了！\n");
	return 1;
}

int weapon(){
	command("wield gangzhang");
	map_skill("parry", "tianshan-zhang");
	command("say OK 了！\n");
	return 1;
}
