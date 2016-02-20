//Cracked by Kafei
#include <ansi.h>

inherit COMBINED_ITEM;
inherit F_EQUIP;
int throw_ob(object me, object victim);
void create()
{
   set_name("玉蜂针", ({"yufeng zhen", "zhen"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "把");
      set("base_unit", "枚");
      set("skill", "throwing");
      set("long", "一枚细如毛发的金针，六成黄金，四成精钢，以玉蜂尾刺上毒液喂
过，虽然细小，但因黄金沉重，掷出时仍可及远。\n" );
		set("damage", 6);
                set("armor_type", "embed");
                set("armor_prop/armor",1);
                set("armor_prop/attack", -50);
                set("armor_prop/defense", -50);
      set("unequip_msg", HIR"$N一咬牙将$n"+HIR+"从伤口上拔了下来，一股鲜血猛地涌了出来。\n"NOR);
   }
   set_amount(1);
   setup();
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
	return 1;
}
int throw_ob(object me, object victim)
{
	int ap, dp;
	string limbs, dodge_skill, str;
	object ob2, ob = this_object();

   message_vision(HIY"$N左手在袖底轻轻一扬，一枚玉蜂针向$n激射而去。\n" NOR, me, victim);
   ap = me->query_skill("throwing", 1);
   dp = (int)victim->query_skill("dodge");
   ap *= me->query("combat_exp")/1000;
   dp *= victim->query("combat_exp")/1000;
	
   ap = random(ap);
   limbs = victim->query("limbs");

	if (ap > dp && !victim->query_temp("armor/embed")){
                message_vision(CYN"\n结果$N一声惨叫，玉蜂针已然穿进了$N的"+limbs[random(sizeof(limbs))]
                          +"。\n"NOR, victim, ob);
                                 ob2=new(__FILE__);
                                 ob2->set_amount(1);
                                 ob2->set("embedded", 1);
                                 ob2->move(victim);
                                 ob2->do_embed();
                                 victim->receive_wound("qi", me->query_str()
                                 *ob->query("damage"), me);
                                 victim->receive_damage("qi", ob->query_weight()/100, me);
				 victim->apply_condition("insect_poison", 100);
   			 	 victim->set("poisoner", me);
	                         victim->kill_ob(me);
				 ob->add_amount(-1);
   }
   else{
	if (victim->query("neili") > me->query("neili"))
        message_vision(RED"$n袍袖一拂，一股内劲发出，将那细针激得斜在一旁，插在地上。\n" NOR, me, victim);

	else {
	dodge_skill = victim->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                str = SKILL_D(dodge_skill)->query_dodge_msg();
                message_vision(str, me, victim);
	}
	if( !victim->is_killing(me) ) victim->kill_ob(me);
	me->start_busy(1+random(3));
	ob2=new(__FILE__);
        ob2->set_amount(1);
	ob2->move(environment(me));
	ob->add_amount(-1);
        }
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
