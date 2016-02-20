//Cracked by Roath
// weapon: 「绿波香露刀」 (Xianglu dao)
// wsky 4/7/00

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;

inherit BLADE;

void create()
{
        set_name(HIG "绿波香露刀" NOR, ({ "xianglu dao", "xianglu", "blade" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", HIG"这是一柄厚背薄刃，锋锐异常的鬼头刀，刀口向外。\n刀刃上隐隐青光微闪，却是臭气熏天。\n"NOR);
                set("value", 10000);
                set("material", "steel");
                set("rigidity", 2000);
                set("wield_msg", HIG"$N一声冷笑，“波”的一声，横刀当胸，身前绿光闪闪。\n众人随着鼻中问到一阵腥臭，几乎作呕，知道这刀上喂有剧毒，邪门险恶之极！\n"NOR);
                set("unwield_msg", "青光晃闪，血腥臭味消失无踪！「绿波香露刀」 已收回刀鞘。\n");
        }
        init_blade(88);
        setup();
        ::create();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        int damage;
        
        if(random(me->query("combat_exp"))>random(victim->query("combat_exp"))){
                victim->apply_condition("xianglu-du", 250);   
                return HIG "$n鼻中问到一阵腥臭，根着觉得伤口上一麻！\n" NOR;
        } else {
                return HIM "$n鼻中问到一阵腥臭，急运内功和毒气相抗。" NOR;
        }
        
}