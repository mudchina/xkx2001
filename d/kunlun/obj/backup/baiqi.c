//Cracked by Roath
// weapon: hongqi.c
// long Apirl 13, 97

#include <weapon.h>
#include <ansi.h>

inherit HALBERD;

void create()
{
        set_name(WHT"小白旗"NOR, ({ "bai qi", "qi" }));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                set("long", "这是一面连杆不到二尺的白色小旗，旗上绣着个明教的火炎记号\n");
                set("value", 0);
                set("material", "");
                set("wield_msg", "$N拿出一柄$n。\n");
                set("unwield_msg", "$N把$n插回背後。\n");
        }
        init_halberd(20);
        setup();
}
int init()
{
   add_action("do_throw", "throw");	
}

int do_throw(string arg)
{
   int skill, skill2, zhen, dod, parr;
   int nt;
   object me = this_player();
   object victim;
   object *t;
   t = me->query_team();

   if (!arg) 	
        return notify_fail("你要对谁使用飞斧阵？\n");

   victim = present(arg,environment(me));

   if (!victim)
	return notify_fail("这里并无此人！\n");

   if (!living(victim))
	return notify_fail("这不是活物！\n");

   if (victim == me) return notify_fail("何必多此一举？\n");

   //if (!wizardp(me) && wizardp(victim))
   //    return notify_fail("大胆！竟想谋害巫师！\n");
	
   if( environment(me)->query("no_fight") )
                return notify_fail("不能在这里摆阵。\n");
	
   message_vision("$N一扬手，手中的小白旗向$n飞了过去，斜斜插再他的脚边。\n", me, victim);
   message_vision("只见$N的手下摆开飞斧阵迅速把$n团团围住。\n", me, victim);
   if( !victim->is_killing(me) ) victim->kill_ob(me);
   nt = (int) sizeof(t);
   for( int i = 1; i < sizeof(t); i++ )
   {
	if( living(t[i]))
	{	message_vision("$N拔出腰间的短斧一扬手，手中短斧向$n飞了过去。\n", t[i], victim);
	}
   }
   message_vision("短斧整整齐齐地摆成一个圆圈把$N笼罩在里面，$N不由的脸色大变。\n", victim);	
   zhen = (int)me->query_skill("feifu-zhen");
   dod = (int)victim->query_skill("dodge");
   parr = (int)victim->query_skill("parry");
   skill = random(zhen);
   skill2 = (dod + parr)/7;
   if( random(me->query("combat_exp") * nt) > (int)victim->query("combat_exp")/2 && skill > skill2)
   {
   	message_vision(RED"$N躲闪不及，被砍昏了。\n" NOR, victim);
    victim->unconcious();
	me->improve_skill("feifu-zhen", 20);
	victim->receive_wound("max_qi", 100);
	return 1;
   }
   else
   {
	message_vision(GRN"$N左闪右躲才好不容易避过所有斧头，但已吓出一身冷汗。\n" NOR, victim);
	victim->receive_wound("jing", 100);
	if( !victim->is_killing(me) ) victim->kill_ob(me);
   }
   me->start_busy(1+random(3));
   return 1;
}    

