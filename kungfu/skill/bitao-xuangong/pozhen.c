//Cracked by Roath
// pozhen.c

#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        object env;
        string msg;

        env = environment(me);
        if (!env)
                return notify_fail("这里什么地方也不是！\n");
        if (!env->query("th_buzhen"))
                return notify_fail("这里并无布有奇门阵法。\n");
        
        if( me->query_skill_mapped("force") != "bitao-xuangong")
                return notify_fail("你所用的内功与「奇门阵法」心法相悖！\n");

        if( me->query_skill("bitao-xuangong", 1) < 90 )
                return notify_fail("你的内功修为火候未到，还未领悟「奇门阵法」！\n");

        if( me->query("jingli") < me->query("max_jingli") )
                return notify_fail("你的精力不够，不足以破解「奇门阵法」！\n");

        if( me->query("jing") < me->query("max_jing") )
                return notify_fail("你的精不够，不足以破解「奇门阵法」！\n");

        if( me->query_skill("qimen-dunjia", 1) < 90 )
                return notify_fail("你的奇门遁甲修为不够，还未领悟「奇门阵法」！\n");

        me->set("jing", me->query("max_jing")/2);
        me->set("jingli", me->query("max_jingli")/2);

        if( me->query("id") != env->query("th_zhen_owner") && 
        me->query_skill("qimen-dunjia",1) < env->query("th_pozhen")*3/4) {
                message_vision(CYN"$N坐在地上冥思苦想，突然脸色大变，口吐鲜血！\n"NOR,me);
                me->unconcious();
                return 1;
        }

        msg = HIW"$N凝思片刻，阵法的种种生克变化已全盘了然于胸，仰天一声长笑，袍袖一拂，\n";
        msg += "掠入阵中，掌劈脚挑，顿时飞沙走石，不一刻，阵中阴霾戾气已消散得无影无踪！\n"NOR;
        message_vision(msg, me);
        
	if( me->query("id") == env->query("th_zhen_owner") 
	&& me->query_skill("qimen-dunjia",1) > 100 
	&& me->query("qmdj_use")*10 <= me->query_skill("qimen-dunjia",1)-100 ) {
	tell_object(me,"你在奇门遁甲上的运用有了进一步的领会。\n");
	me->add("qmdj_use",1);
	}
        env->set("long", env->query("org_desc"));
        env->set("exits", env->query("org_exits"));
        env->set("cost", env->query("org_cost"));
        env->delete("org_desc");
        env->delete("org_cost");
        env->delete("org_exits");
        env->delete("th_buzhen");
        env->delete("th_pozhen");
        env->delete("th_zhen_owner");

        return 1;
}
