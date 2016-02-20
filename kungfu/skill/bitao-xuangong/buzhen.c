//Cracked by Roath
// buzhen.c

#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        object *ob, env;
        string msg, desc;
        int i, qmdj, k = 0;
        mapping exit;

        if (me->is_busy()
        || me->query_temp("pending/exercising")
        || me->query_temp("exit_blocked"))
                return notify_fail("你现在正忙着呢。\n");

        env = environment(me);
        exit = env->query("exits");

        if( !env )
                return notify_fail("这里什么地方也不是！\n");
        if( !env->query("outdoors") )
                return notify_fail("室内空间太小，阵法施展不开。\n");
        if (env->query("th_buzhen"))
                return notify_fail("这里已布有奇门阵法。\n");
/*
        if( k > 1 )
                return notify_fail("有旁人在场，休得让他人窥了阵法秘奥！\n");
*/
	if( !present("tie bagua", me)) 
		return notify_fail("你没有携带铁八卦。\n");

        if( me->query_skill_mapped("force") != "bitao-xuangong")
                return notify_fail("你所用的内功与「奇门阵法」心法相悖！\n");

        if( me->query_skill("bitao-xuangong", 1) < 90 )
                return notify_fail("你的内功修为火候未到，还未领悟「奇门阵法」！\n");

        if( me->query("jingli") < me->query("max_jingli") )
		return notify_fail("你的精力不够，不足以施展「奇门阵法」！\n");

        if( me->query("jing") < me->query("max_jing") )
                return notify_fail("你的精不够，不足以施展「奇门阵法」！\n");
        
	if( me->query_skill("qimen-dunjia", 1) < 90 )
                return notify_fail("你的奇门遁甲修为不够，还未领悟「奇门阵法」！\n");

        me->set("jing", me->query("max_jing")/2);
        me->set("jingli", me->query("max_jingli")/2);

        msg = HIG"$N身形飞旋，掌劈脚挑，地下顿时烟尘四起，砂石乱飞，声势煞时惊人！\n";
        msg += GRN"不一刻，$N收势凝形，负手而立，四下里从寂静中隐隐透出一股肃杀之气！\n"NOR;
        desc = env->query("long")+HIB"四下景况似乎和寻常所见略有不同，透出森森鬼气。\n"NOR;
        env->set("org_desc", env->query("long"));
        env->set("org_exits", env->query("exits"));
        env->set("org_cost", env->query("cost"));

        qmdj = (int)me->query_skill("qimen-dunjia",1);
        env->set("cost", qmdj/2);
        env->set("long", desc);
        env->set("th_buzhen", 1);
	env->set("th_zhen_owner",me->query("id"));
        env->set("th_pozhen", qmdj*2);

        if( qmdj < 120 ) {
                env->set("exits", ([
                        "east" : file_name(env),
                        "south" : file_name(env), 
                        "west" : file_name(env),
                        "north" : file_name(env),
                ]));
        } else if ( qmdj < 150 ) {
                env->set("exits", ([
                        "east" : file_name(env),
                        "south" : file_name(env),
                        "west" : file_name(env),
                        "north" : file_name(env),
                        "northwest" : file_name(env),
                        "northeast" : file_name(env),
                        "southeast" : file_name(env),
                        "southwest" : file_name(env),
                ]));
        } else if ( qmdj < 180 ) {
                env->set("exits", ([
                        "east" : file_name(env),
                        "south" : file_name(env),
                        "west" : file_name(env),
                        "north" : file_name(env),
                        "northwest" : file_name(env),
                        "northeast" : file_name(env),
                        "southeast" : file_name(env),
                        "southwest" : file_name(env),
                        "enter" : file_name(env),
                        "out" : file_name(env),
			"up" : file_name(env),
			"down" : file_name(env),
                ]));
        } else {
                env->set("exits", ([
                        "east" : file_name(env),
                        "south" : file_name(env),
                        "west" : file_name(env),
                        "north" : file_name(env),
                        "northwest" : file_name(env),
                        "northeast" : file_name(env),
                        "southeast" : file_name(env),
                        "southwest" : file_name(env),
                        "enter" : file_name(env),
                        "out" : file_name(env),
			"up" : file_name(env),
			"down" : file_name(env),
                        "eastup" : file_name(env),
                        "southup" : file_name(env),
                        "westup" : file_name(env),
                        "northup" : file_name(env),
                        "eastdown" : file_name(env),
                        "southdown" : file_name(env),
                        "westdown" : file_name(env),
                        "northdown" : file_name(env),
                ]));
        }

        call_out("remove_effect", qmdj/2, env);

        message_vision(msg, me);

        return 1;
}

void remove_effect(object env)
{
        if (!env) return;
        if (!env->query("th_buzhen")) return;

        env->set("long", env->query("org_desc"));
        env->set("exits", env->query("org_exits"));
        env->set("cost", env->query("org_cost"));
        env->delete("org_desc");
        env->delete("org_cost");
        env->delete("org_exits");
        env->delete("th_buzhen");
        env->delete("th_pozhen");
	env->delete("th_zhen_owner");

        tell_object(env, CYN"一阵微风吹过，四面景致似乎起了些变化。\n"NOR);
}
