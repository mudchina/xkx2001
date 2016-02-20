//Cracked by Roath
//摺扇
//Ryu

#include <weapon.h>
#include <ansi.h>
inherit STICK;
inherit SKILL;

mapping *action = ({
([      "action" : 
"啪的一声，$N手中摺扇摺成一根短棒，向$n肩井穴微点，右掌呼地劈出，势挟劲风，凌厉狠辣",
        "force" : 160,
        "dodge" : 10,
        "damage_type" : "瘀伤",
]),
([      "action" : 
"$N手中扇子挥动，一阵劲风向$n迎面扑去，风中竟带幽香",
        "force" : 220,
        "dodge" : 5,
        "damage_type" : "鞭伤",
]),
([      "action" : 
"$N一扇挥出，跟着擦的一声，扇子已摺成一条八寸长的点穴笔，迳向$n$l点去",
        "force" : 300,
        "dodge" : 5,
        "damage_type" : "刺伤",
]),
([      "action" : 
"$N一侧身，摺扇斜点，左掌如风，扇点是虚，掌击是实，直击$n脑门",
        "force" : 360,
        "dodge" : -5,
        "damage_type" : "内伤",
]),
([      "action" : 
"$N发声长啸，右扇左袖鼓起一阵疾风，朝$n扑去，劲道凌厉",
        "force" : 420,
        "dodge" : 10,
        "damage_type" : "鞭伤",
]),
([      "action" : 
"$N手中摺扇回转，两下一凑合，手指转了两转，正好搭上$n的$l",
        "force" : 480,
        "dodge" : 10,
        "damage_type" : "劈伤",
])
});
void create()
{
    set_name(HIC"摺扇"NOR, ({"fan","zheshan", "shan"}) );

        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "柄");
        set("long","一柄摺扇，扇骨是钢铸的。\n");
	set("rigidity", 1000000);
	set_weight(1000);
        set("value", 2000000000);
	set("ding", 10);
	set("material", "blacksteel");

        set("wield_msg",HIM"$N从袖中掏出一柄摺扇，一挥，张了开来，露出扇上一朵娇艳欲滴的牡丹。\n"NOR);
        set("unwield_msg", "啪的一声，$N把摺扇合了起来，收进袖中。\n");

	init_stick(30);
	set("actions", (: call_other, __FILE__, "query_action" :) );
        setup();
}
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
void init()
{
        add_action("do_duan", "duan");
        add_action("do_shoot", "shoot");
	add_action("do_duan", "break");
}
int do_duan(string arg)
{
        object target;
        object me = this_player();
        object weapon;

        if (!arg)
        return notify_fail("什么？\n");

        target = present(arg,environment(me));
        if( !target
        ||      !target->is_character()
	||      !me->is_fighting(target) )
                return notify_fail("什么？\n");

        if( !objectp(weapon = me->query_temp("weapon"))
         || (string)weapon->query("id") != "fan" )
                return notify_fail("什么？\n");

        if( me->is_busy() )
                return notify_fail("你前一个动作还没有做完。\n");

        if( !objectp(weapon = target->query_temp("weapon")))
                return notify_fail("什么？\n");

        message_vision("\n$N眼见$n的" + weapon->name()
                        + "攻到，左手食指往上一托，搭住了"
			+ weapon->name() + "，扇子斜着挥去，拦腰朝"
			+ weapon->name() + "一击。\n", me, target);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2){
	message_vision(HIW "只听见「铮」地一声，$n手中的" + weapon->name()
                                + "已经断为两截！\n" NOR, me, target);
	weapon->unequip();
                        weapon->move(environment(target));
                        weapon->set("name", "断掉的" + weapon->query("name"));
                        weapon->set("value", 0);
                        weapon->set("weapon_prop", 0);
                        target->reset_action();
	}else{
	message_vision("$N的摺扇和$n的" + weapon->name()
                                + "相击，冒出点点的火星。\n", me, target);
	me->start_busy(1+ random(3));
	}
	return 1;
}
int do_shoot(string arg)
{
   object me = this_player();
   object victim, weapon;

   if (!arg)
        return notify_fail("你要射谁？\n");

   victim = present(arg,environment(me));

	if( !objectp(weapon = me->query_temp("weapon"))
         || (string)weapon->query("id") != "fan" )
                return notify_fail("什么？\n");

   if (!victim)
        return notify_fail("这里并无此人！\n");

   if (query("ding") < 1)
	return notify_fail("摺扇里的毒钉已经射完了。\n");

   if (!living(victim))
        return notify_fail("这不是活物！\n");

   if (me->is_busy())
        return notify_fail("你前一个动作还没有做完。\n");

   if (victim == me) return notify_fail("何必多此一举？\n");

   if( environment(me)->query("no_fight") )
                return notify_fail("在这里不能攻击他人。\n");

   message_vision(HIG"$N右手姆指一按扇柄上的机括，一枚毒钉从扇骨中飞出，朝$n射去。\n" NOR, me, victim);
   add("ding", -1);
   if( random(me->query("combat_exp")) > (int)victim->query("combat_exp")/2){ 
   message_vision(CYN"只听一声惨叫，毒钉已钉在了$N的身上。\n"NOR, victim);
   victim->apply_condition("insect_poison", 100);
   victim->receive_wound("qi", 500, "被" + me->query("name") +"杀死了");
   victim->receive_wound("jing", 100, "被" + me->query("name") +"杀死了");
   if (!victim->is_killing(me))
   victim->kill_ob(me);
   } else {
   message_vision(CYN"但是$N机灵地躲了开去！\n"NOR, victim);
   if (!victim->is_killing(me))
   victim->kill_ob(me);
   }
   return 1;
}
