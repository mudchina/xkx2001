//Cracked by Roath
// Ryu, 5/10/97
// wsky 2000

#include "ansi.h"
#include <room.h>


inherit ROOM;

private int blow_result(object victim);
void blow();
int do_dig();


void create()
{
        set("short", "冰洞");
        set("long", @LONG
进到冰洞里面，那洞顶上紧紧垂挂着冰锥(icicle)，长短不齐，
粗细不一；洞底下冰树丛生，千姿万态。穿行洞内，好似进了光怪
陆离的神话世界。
LONG
        );
        set("exits", ([
                "west" : __DIR__"icecave2",
        ]));
        set("cost", 2);
        set("icicle", 100);
        set("bing_can", 7);

        setup();
}

void init()
{
        add_action("do_flick", "flick");
        add_action("do_flick", "tan");
//      add_action("do_lingwu", "lingwu");
        add_action("do_dig", "dig");
        remove_call_out("blow");
        call_out("blow",4 + random(3) );
}

int do_dig()
{
        remove_call_out("blow");
        call_out("blow",1 );
        return 1;
}


int do_flick(string arg) {
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return 0;

        if (me->query_busy())
                return notify_fail("你正忙着呢。\n");

        if (query("icicle") < 1)
                return notify_fail("这里的冰锥你都够不着了。\n");

        if ( (int)me->query("jing") < 30 || (int)me->query("jingli") < 30)
                return notify_fail("你的精神不能集中。\n");

        if( arg=="icicle")
        {
        me->receive_damage("jing", 15); 
        me->receive_damage("jingli", 15);
        add("icicle", -1);
        message_vision("$N轻轻地用手指弹断了一根冰锥。\n", me);
        if (random(me->query_skill("feixing-shu", 1)) > 30){
        me->improve_skill("feixing-shu", me->query("int"));

	message_vision("$N弹飞出去的冰锥撞断了另一根冰锥，乒乒乓乓乱响。\n", me);
        tell_object(me, "你似乎领悟了一层飞星术的技能。\n");
        if (me->query_skill("feixing-shu", 1) > 100)
        me->receive_damage("jing", 15);
        if (me->query_skill("feixing-shu", 1) > 150)
        me->receive_damage("jing", 15);
        }
/*
        if (query("icicle") < 1){
        remove_call_out("renew_up");
        call_out("renew_up", 100+random(200));
        }
*/
        return 1;
        }
}

int blow()
{
        object *inv = all_inventory(find_object("/d/xingxiu/icecave1"));
        object ob, me= this_player();
        int i;

        if( !this_player() || !environment(this_player()) )  return 1;
        if( base_name(environment(this_player())) !="/d/xingxiu/icecave1") return 1;

        message_vision( HIC"\n露水从洞顶流下来，慢慢地结成了冰锥。\n"NOR, this_player() );

        for ( i=0 ; i < sizeof(inv); i++)
        {
                if ( (string)inv[i]->query("race") == "人类" )
                {
                        blow_result(inv[i]);
                }
        }


        remove_call_out("blow");
        call_out( "blow",4 + random(6) );
        return 1;

}


private int blow_result(object victim)
{
        object me, ob, room;
        int skill, exp;
	mapping fam;
	
	fam = this_player()->query("family");
        me = this_player();
        room = this_object();
        exp=me->query("combat_exp");

        if( random(50)<1 && !me->is_fighting() && fam["family_name"] =="星宿派")
        {

message_vision(HIR"$N只听见一声怒喝，从黑暗角落中钻出一人，向$N攻来。\n"NOR,me);

                ob = new("/d/xingxiu/npc/xxnpc");
                ob->set_name("正派侠客", ({ "xia ke", "ke", "xia" }) );
                skill=me->query_skill("dodge",1);
        
                while(skill*skill*skill<exp*10) skill++;
		
		skill=skill/4*3;
		
                ob->set("shen",-me->query("shen")/6);           
                ob->set("xxtarget",me->query("id"));
                ob->set("combat_exp",exp*3/2);
                ob->set("max_qi", me->query("max_qi"));
                ob->set("eff_qi", me->query("max_qi"));
                ob->set("qi", me->query("max_qi"));
                ob->set("max_jing", me->query("max_jing"));
                ob->set("jing", me->query("max_jing"));
                ob->set("eff_jing", me->query("max_jing"));
                ob->set("neili", me->query("max_neili"));
                ob->set("max_neili", me->query("max_neili"));
                ob->set("jingli",me->query("jingli"));
                ob->set("max_jingli",me->query("max_jingli"));
                ob->set("jiali", me->query("jiali"));



                if(ob->query("menpai")=="huashan") {
        	        
                	ob->set_skill("sword", skill);
	                ob->set_skill("huashan-jianfa", skill);
        	        ob->set_skill("parry", skill);
                	ob->set_skill("force", skill);
	                ob->set_skill("zixia-gong",skill);
        	        ob->set_skill("huashan-shenfa",skill);
                	ob->set_skill("hunyuan-zhang",skill);
	                ob->set_skill("dodge",skill);
        	        ob->set_skill("strike",skill);
                	ob->set_skill("cuff",skill);
	                ob->set_skill("pishi-poyu",skill);
   
   	                ob->map_skill("strike", "hunyuan-zhang");
        	        ob->map_skill("force", "zixia-gong");
	                ob->map_skill("parry", "huashan-jianfa");
        	        ob->map_skill("sword", "huashan-jianfa");
                	ob->map_skill("dodge", "huashan-shenfa");
	                ob->map_skill("cuff", "pishi-poyu");
        	
                	ob->prepare_skill("cuff","pishi-poyu");
	                ob->prepare_skill("strike","hunyuan-zhang");

			ob->carry_object("/clone/weapon/gangjian")->wield();

	        }       else if(ob->query("menpai")=="shaolin"
        	) {
                	ob->set_skill("dodge", skill);
	                ob->set_skill("shaolin-shenfa", skill);
        	        ob->set_skill("cuff", skill);
                	ob->set_skill("jingang-quan", skill);
	                ob->set_skill("club", skill);
        	        ob->set_skill("zui-gun", skill);
                	ob->set_skill("strike", skill);
	                ob->set_skill("sanhua-zhang", skill);
        	        ob->set_skill("finger", skill);
                	ob->set_skill("nianhua-zhi", skill);
	                ob->set_skill("parry", skill);
        	        ob->set_skill("buddhism", skill);
                	ob->set_skill("literate", skill);
	                ob->set_skill("whip",skill);
        	        ob->set_skill("riyue-bian",skill);
                	ob->set_skill("yizhi-chan",skill);
	                ob->set_skill("banruo-zhang",skill);
			ob->set_skill("force",skill);
	
	                ob->map_skill("force", "hunyuan-yiqi");
        	        ob->map_skill("dodge", "shaolin-shenfa");
                	ob->map_skill("club", "zui-gun");
	                ob->map_skill("sword", "damo-jian");
        	        ob->map_skill("finger", "yizhi-chan");
	                ob->map_skill("strike", "banruo-zhang");
        	        ob->map_skill("claw", "longzhua-gong");
	                ob->map_skill("parry", "yizhi-chan");
        	        ob->map_skill("whip", "riyue-bian");
                	ob->map_skill("cuff", "jingang-quan");

	                ob->prepare_skill("finger", "yizhi-chan");
        	        ob->prepare_skill("strike", "banruo-zhang");
                	ob->carry_object("/clone/weapon/tiegun")->wield();              
        
        	}       else if(ob->query("menpai")=="quanzhen"){
                	ob->set_skill("force", skill);
	                ob->set_skill("xiantian-gong", skill);
        	        ob->set_skill("dodge", skill);
                	ob->set_skill("jinyangong", skill);
	                ob->set_skill("cuff", skill);
        	        ob->set_skill("chunyang-quan", skill);
                	ob->set_skill("strike", skill);
	                ob->set_skill("sanhua-juding", skill);
        	        ob->set_skill("parry", skill);
                	ob->set_skill("sword", skill);
	                ob->set_skill("quanzhen-jian", skill);
        	        ob->set_skill("whip", skill);
                	ob->set_skill("duanyun-bian", skill);
	                ob->set_skill("literate", skill);
        	        ob->set_skill("taoism", skill);
                	ob->map_skill("force", "xiantian-gong");
	                ob->map_skill("dodge", "jinyangong");
        	        ob->map_skill("cuff", "chunyang-quan");
                	ob->map_skill("strike", "sanhua-juding");
	                ob->map_skill("parry", "quanzhen-jian");
        	        ob->map_skill("sword", "quanzhen-jian");
	                ob->map_skill("whip", "duanyun-bian");
	
        	        ob->prepare_skill("cuff", "chunyang-quan");
                	ob->prepare_skill("strike", "sanhua-juding");
                

			ob->carry_object("/d/jiaxing/obj/fuchen.c")->wield();
		}	else if(ob->query("menpai")=="emei"){
                	ob->set_skill("force", skill);
	                ob->set_skill("linji-zhuang", skill);
        	        ob->set_skill("dodge", skill);
                	ob->set_skill("zhutian-bu", skill);
	                ob->set_skill("tiangang-zhi", skill);
        	        ob->set_skill("finger", skill);
                	ob->set_skill("strike", skill);
	                ob->set_skill("jingding-zhang", skill);
        	        ob->set_skill("parry", skill);
                	ob->set_skill("blade", skill);
	                ob->set_skill("yanxing-dao", skill);
        	        ob->map_skill("force", "linji-zhuang");
	                ob->map_skill("dodge", "zhutian-bu");
        	        ob->map_skill("finger", "tiangang-zhi");
                	ob->map_skill("strike", "jinding-zhang");
	                ob->map_skill("parry", "yanxing-dao");
        	        ob->map_skill("blade", "yanxing-dao");
	                	
        	        ob->prepare_skill("finger", "tiangang-zhi");
                	ob->prepare_skill("strike", "jinding-zhang");
                

			ob->carry_object("/clone/weapon/gangdao.c")->wield();
		}	else {
			ob->set_skill("force", skill);
	                ob->set_skill("taiji-shengong", skill);
        	        ob->set_skill("dodge", skill);
                	ob->set_skill("tiyunzong", skill);
	                ob->set_skill("taiji-quan", skill);
        	        ob->set_skill("cuff", skill);
                	ob->set_skill("taoism", skill);
	                ob->set_skill("parry", skill);
                	ob->set_skill("sword", skill);
	                ob->set_skill("taiji-jian", skill);
        	        ob->map_skill("force", "taiji-shengong");
	                ob->map_skill("dodge", "tiyunzong");
        	        ob->map_skill("strike", "taiji-quan");
	                ob->map_skill("parry", "taiji-jian");
        	        ob->map_skill("sword", "taiji-jian");
	                	
        	        ob->prepare_skill("cuff", "taiji-quan");
                	ob->carry_object("/clone/weapon/gangjian.c")->wield();
                }
                        
                        ob->move(room); 
                        if( !ob->is_killing(me) ) ob->kill_ob(me);    
                
        }


        if( random( victim->query_skill("force") ) > 45 && victim->query("neili") > 20 && victim->query_skill("feixing-shu",1)>100 )
        {
                message_vision( WHT"\n$N运功抵御寒流，同时望着洞顶的冰锥，研析着暗器地奥妙！\n"NOR, victim );
                if(query("icicle")<100) add("icicle", 1+random(6));
                victim->add("neili",-random(40));
                victim->improve_skill("feixing-shu",me->query("int"));
        }
        else
        {
                message_vision( RED"\n$N打了个冷颤！\n"NOR, victim );
                victim->receive_damage("qi", random(50), "被冻死了！");
                if(query("icicle")<100) add("icicle", 1+random(3));
        }


        return 1;
}


/*

void renew_up()
{
        set("icicle", 100);
}
*/
