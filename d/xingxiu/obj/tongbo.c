//Cracked by Roath
// tongbo.c
// updated by wsky

#include <ansi.h>

inherit F_CLEAN_UP;
inherit ITEM;

void create()
{
        set_name("铜钹", ({ "tongbo" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("long", "这是一对金光闪亮的铜钹。\n");
                set("value", 10);
                set("material", "iron");
        }
        setup();
}


void init()
{
        add_action("do_flatter","paima");
}

int do_flatter(string arg)
{

        string* flatter = ({
                "$N敲着铜锣，大声吆喝着：“$n老仙，德配天地，威镇寰宇，古今无比！”",
                "$N嚷嚷道：“$n老仙今日威镇中原，大显我星宿派的声威。”",
                "$N满脸媚色的看着$n，大声说道：“你们这些中原武夫，还不及$n老仙得一根小指。”",
                "$N肉麻的喊道：“$n老仙足一蹬山崩地裂，手一遥日月无光。”",
                "$N望着旁边的人，大声说道：“谁敢得罪$n老仙，我第一个和他拼命。”说完看了看后路。",
                "$N说道：“谁和$n老仙比武，简直是螳臂挡车，自不量力吗。”",
        });

        int skill,int1,int2;
        object me,obj;
        string msg;
        mapping myfam, vtfam;
        
        me=this_player();

        skill = me->query("flattering");

        if(skill<300) skill==30;
                else if(skill>300 && skill < 600) skill==60;
                else if(skill>600) skill==100;

        if( !arg ) return notify_fail("你想拍谁的马屁？\n");

        if(arg==me->query("id")) return notify_fail("拍自己马屁？？\n");

        if( !objectp(obj = present(arg, environment(me)) ))
                return notify_fail("对象已经离开这个地方了。\n");

        if (me->is_fighting()) return notify_fail("打架中还想拍马屁，你真是不要脸到家了。\n");

	if( me->is_busy() ) return notify_fail("( 你上一个动作还没有完成，不能施用外功。)\n");

	if( environment(me)->query("no_fight") ) return notify_fail("在这里还想拍马屁？\n");

        if ( (!( myfam= me->query("family")) || myfam["family_name"] != "星宿派") && me->query("id")!="wsky")
          return notify_fail("只有星宿弟子才有这样厚的脸皮！\n");

        if( me->query_temp("flattering") )
                return notify_fail("你已经在鼓着劲大拍马屁了。\n");
    
        if ( (vtfam = obj->query("family")) && vtfam["family_name"] != "星宿派" && me->query("id")!="wsky")
                return notify_fail("你只敢拍星宿弟子马屁！\n");
        
        if (!userp(obj) && me->query("id")!="wsky") return notify_fail("你只能拍玩家马屁。\n");
        
        if (obj->query("combat_exp")<(me->query("combat_exp"))/3*2 && me->query("id")!="wsky") return notify_fail("这人功夫太差，值得拍吗？\n");
	
        if (obj->query_temp("flattered")) return notify_fail("这"+RANK_D->query_rude(obj)+"正被人捧的熏熏然的呢。\n");

        if (obj->query_temp("angry")) {
                message_vision(HIR"$n心中怒不可抑，全身向$N扑来，$N心中一惊：糟糕马屁拍到马脚上了。\n"NOR,me,obj);
                me->start_busy(random(2)+1);
		obj->set_temp("yield",0);
                if( !obj->is_killing(me) ) obj->kill_ob(me);
		if( !me->is_killing(obj) ) me->kill_ob(obj);
                return 1;
        }

        msg=flatter[random(sizeof(flatter))];
        message_vision(HIM+msg+"\n"+NOR,me, obj);
        int1=me->query("int");int2=obj->query("int");
        if(random(int1*100)>random(int2*100)){
                message_vision(HIG"$n听了以后，心中有些飘飘然的，似乎对功夫有些推波助澜的效应。\n"NOR,me,obj);

                me->set_temp("flattering",1);
                obj->add_temp("apply/damage", skill/3);
                obj->add_temp("apply/parry", skill/3);
                obj->add_temp("apply/dodge", skill/3);

                me->add("jing",-100);
                me->add("jingli",-100);
                me->add("flattering",1);

                me->start_busy(random(2)+1);
                if(me->query("potential") < me->query("max_potential")){
                        me->add("potential",random(2));
                }       
                me->add("combat_exp",random(6)+1);
                obj->set_temp("flattered",1);
                call_out("remove_effect", 5, me, obj, skill); 
        } else {
                message_vision(HIB"$n瞪了$N一眼，一声冷哼。\n"NOR,me,obj);                      
                obj->set_temp("angry",1);
                call_out("remove_effect2", 10, me, obj); 
        }
        return 1;
}


int remove_effect(object me, object obj, int skill){            
        me->delete_temp("flattering");
        obj->delete_temp("flattered",1);
        obj->add_temp("apply/damage", -skill/3);
        obj->add_temp("apply/parry", -skill/3);
        obj->add_temp("apply/dodge", -skill/3);
        message_vision(HIY"$N深深的吸了口气，清了清嗓子。\n"NOR,me,obj);
}

int remove_effect2(object me, object obj){
        obj->delete_temp("angry");
        message_vision(HIY"$n脸色略见缓和。\n"NOR,me,obj);
}

