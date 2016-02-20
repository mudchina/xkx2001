//Cracked by Roath
// jinshe-zhuifa 金蛇锥法

#include <ansi.h>
#include <weapon.h>
inherit COMBINED_ITEM;
inherit F_EQUIP;
int throw_ob(object me, object victim);

string* xuedao = ({
        "四白穴",
        "地仓穴",
        "大迎穴",
        "峡车穴",
        "头维穴",
        "下关穴",
        "隐白穴",
        "太白穴",
        "商丘穴",
        "地机穴",
	"少冲穴",
        "少海穴",
        "通理穴",
        "神门穴",
        "印堂穴",
        "金律穴",
        "玉液穴",
        "鱼腰穴",
        "百劳穴",
        "百会穴",
        "灵台穴",
        "太阳穴",
        "膻中穴",
        "命门穴",
        "鸠尾穴",
        "气海穴"
});
string *throw_msg = ({
"$N拿起一枚金蛇锥，对准$n一扬手，将金蛇锥笔直射向$n的"+xuedao[random(sizeof(xuedao))]+"。\n",
//"$N双手连挥，两枚金蛇锥带着呼啸风声，划成二弧射向$n的"+xuedao[random(sizeof(xuedao))]+"和"+xuedao[random(sizeof(xuedao))],
//"$N飞身跃起，居高临下向$n猛射三枚金蛇锥，直取$n的双目和"+xuedao[random(sizeof(xuedao))],
"突然$N低头恭身，只听得「嗖」的一声，一枚金蛇锥由后领飞出，往$n的"+xuedao[random(sizeof(xuedao))]+"电射而去。\n",
"但见$N将双手拢入袖中，无声无息地发出一枚金蛇锥，斜射到$n的"+xuedao[random(sizeof(xuedao))]+"，迅捷无比。\n",
"$N一笑而退，伸手却在腰间一拍，一枚金蛇锥由胸前猛然射出，飞取$n的"+xuedao[random(sizeof(xuedao))]+"。\n",
//"$N双手同挥发出两枚金蛇锥攻向$n双目，张口一吐又是一枚金蛇锥，后来居上地超越前两枚金蛇锥，急劲地射至$n的"+xuedao[random(sizeof(xuedao))],
});
string query_throw_msg()
{
        return throw_msg[random(sizeof(throw_msg))];
}
void create()
{
        set_name("金蛇锥", ({ "jinshe zhui", "zhui" }) );
        set_weight(1000);
        set_color(HIY);
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long", "金蛇锥是纯金所造，重约一两，长约二寸八分，打成昂首吐舌。\n"
                    "的蛇形，蛇舌尖端分成双叉，每一叉都是一个倒刺。蛇锥的蛇上\n"
                    "有个“雪”字。\n");
	set("unit", "袋");
        set("base_unit", "枚");
	set("value", 160000);
	set("skill", "jinshe-zhuifa");
	set("damage", 5);
                set("armor_type", "embed");
                set("armor_prop/armor",1);
                set("armor_prop/attack", -50);
                set("armor_prop/defense", -50);
		set("no_sell", 1);
                set("unequip_msg", HIR"$N一咬牙将$n从伤口上拔了下来，一股鲜血猛地涌了出来。\n"NOR);
        }
        set_amount(16);
        setup();
}
int throw_ob(object me, object victim)
{
	string str, dodge_skill, action, limbs;
        int ap, dp;
	object ob2, ob = this_object();
	
	action = query_throw_msg();
	message_vision(HIY+action+NOR, me, victim);

	ap = me->query_skill("jinshe-zhuifa", 1)+me->query("str")*5;
	dp = victim->query_skill("dodge");
	ap *= me->query("combat_exp")/1000;
	dp *= victim->query("combat_exp")/1000;

	ap = random(ap);

	if ( ap > dp){
        limbs = victim->query("limbs");

                if(!victim->query_temp("armor/embed")){
                message_vision(CYN"\n结果$N一声惨叫，$n已然插在$N的"+limbs[random(sizeof(limbs))]
                          +"上。\n"NOR, victim, ob);
                                 ob2=new(__FILE__);
                                 ob2->set_amount(1);
                                 ob2->set("embedded", 1);
                                 ob2->move(victim);
                                 ob2->do_embed();
                                 victim->receive_wound("qi", me->query_str()
                                 *ob->query("damage"), me);
				 victim->receive_damage("qi", ob->query_weight()/100, me);
			victim->kill_ob(me);
                }
                else {
                message_vision(CYN"结果在$N的"+limbs[random(sizeof(limbs))]
                          +"造出一处擦伤。\n"NOR, victim);
				victim->receive_wound("qi", me->query_str());
				ob2=new(__FILE__);
                		ob2->set_amount(1);
		                ob2->move(environment(me));
				victim->fight_ob(me);
                }
		me->start_busy(random(3));
                ob->add_amount(-1);
        }

        else if ( ap < dp/7 && victim->query("race") == "人类"){
                message_vision(CYN"不料$N眼明手快，身子一侧，把$n轻轻地接在手里。\n"NOR, victim, ob);
                me->start_busy(random(3));
                                 ob->add_amount(-1);
                                 ob2=new(__FILE__);
                                 ob2->set_amount(1);
                                 ob2->move(victim);
        }
	else {
	dodge_skill = victim->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                str = SKILL_D(dodge_skill)->query_dodge_msg();
                message_vision(str, me, victim);
                victim->fight_ob(me);
                me->start_busy(random(3));
                add_amount(-1);
                                 ob2=new(__FILE__);
                                 ob2->set_amount(1);
                                 ob2->move(environment(me));
        }
	return 1;
}
int wear() { return 0; }
int do_embed()
{
        ::wear();

        set("no_drop", 1);
        set("no_get", 1);

        environment()->apply_condition("embedded", 100);

        return 1;
}
int unequip()
{
        ::unequip();

	        set("no_drop", 0);
       		set("no_get", 0);
        	set("embedded", 0);

        environment()->apply_condition("embedded", 0);
	environment()->receive_damage("qi", 200+random(1000));

        return 1;
}
string query_autoload()
{
        if( query("equipped") )
        return query_amount() + "";
}

void autoload(string param)
{
        int amt;

        if( sscanf(param, "%d", amt)==1 )
                set_amount(amt);
        set("embedded", 1);
        set("no_drop", 1);
        set("no_get", 1);
        ::wear();
}
