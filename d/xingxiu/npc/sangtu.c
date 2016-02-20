//Cracked by Roath
// sangtu.c 桑土公
// wsky 4/7/00

#include <ansi.h>
inherit NPC;
#include "/kungfu/class/xingxiu/auto_perform.h"
#include "/d/REGIONS.h";

int ask_wu();

void create()
{
        set_name("桑土公", ({"sang tugong", "gong" }));
        set("nickname", "碧磷洞洞主");
        set("long", 
                "他就是川西碧磷洞洞主，他身材矮胖，有如一个圆球，\n"
                "小小的眼睛里透出一丝乖戾之气。\n");
        set("gender", "男性");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 28);
        set("con", 26);
        set("dex", 26);
        
        set("max_qi", 1700);
        set("max_jing", 2700);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 80);
        set("combat_exp", 1800000);
        set("score", 40000);

        set_skill("force", 200);
        set_skill("huagong-dafa", 200);
        set_skill("dodge", 200);
        set_skill("zhaixinggong", 100);
        set_skill("strike", 200);
        set_skill("poison", 200);
        set_skill("chousui-zhang", 200);
        set_skill("feixing-shu", 200);
        set_skill("parry", 200);
        set_skill("claw", 200);
        set_skill("sanyin-zhua", 200);
        set_skill("staff", 200);
        set_skill("tianshan-zhang", 200);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("claw", "sanyin-zhua");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");

        prepare_skill("strike", "chousui-zhang");
        prepare_skill("claw", "sanyin-zhua");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	set("wimpy",20);
	set("wu",0);

	set("inquiry", ([
        	"乌老大": (: ask_wu :),
        ]));

    	set("no_get", "此人又老又丑，你想拿去作什么？");

	
        setup();

        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
	carry_object("/u/wsky/obj/cishi");
}

int ask_wu(){
	object me=this_player();
	object ob=this_object();
	int skill=me->query_skill("dodge",1);
	int exp=me->query("combat_exp");
        while(skill*skill*skill<exp*10) skill++;
	
	skill=skill*2/3;
	
	ob->set("xxtarget",me->query("id"));
        ob->set("max_qi", me->query("max_qi"));
        ob->set("eff_qi", me->query("max_qi"));
        ob->set("qi", me->query("max_qi"));
        ob->set("max_jing", me->query("max_jing"));
        ob->set("jing", me->query("max_jing"));
        ob->set("eff_jing", me->query("max_jing"));
        ob->set("neili", me->query("neili"));
        ob->set("max_neili", me->query("max_neili"));
        ob->set("jingli",me->query("jingli"));
        ob->set("max_jingli",me->query("max_jingli"));
        ob->set("jiali", me->query("jiali"));
        
        set_skill("force", skill);
        set_skill("huagong-dafa", skill);
        set_skill("dodge", skill);
        set_skill("zhaixinggong", skill);
        set_skill("strike", skill);
        set_skill("poison", skill);
        set_skill("chousui-zhang", skill);
        set_skill("feixing-shu", skill);
        set_skill("parry", skill);
        set_skill("claw", skill);
        set_skill("sanyin-zhua", skill);
        set_skill("staff", skill);
        set_skill("tianshan-zhang", skill);
        
	say("桑土公哼哼道：“好啊，原来是乌老大派来的，拿命来吧！”\n");
	if( !ob->is_killing(me) ) ob->kill_ob(me);    
	set("wu",1);
	return 1;
}
	
void unconcious(){
	if(query("wu")==1)
	::unconcious();
	else{
	say("桑土公大叫一声：哎哟！\n只见灰影一闪，桑土公循在土中不见了。\n");
	destruct(this_object());
	} 
}

	