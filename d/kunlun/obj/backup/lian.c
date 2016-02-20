//Cracked by Roath
// lian.c 铁链

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("铁链", ({ "lian", "tielian","chain" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "这是不过筷子粗细的铁链。\n");
                set("value", 50);
                set("material", "iron");
                set("wield_msg", "$N从腰间解下一条$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n缠回腰上。\n");
        }
        init_whip(5);
        setup();
}

int init()
{
   add_action("do_cut", "cut");	
   add_action("do_cut", "la");	
}
int do_cut(string arg)
{	object weapon;
	object me = this_player();
	if ( !arg && arg != "lian" && arg != "chain" )
	     return notify_fail( "什么？\n");
	if ( !objectp(weapon = me->query_temp("weapon")))
	{  if (me->query("qi") > 500)
	   {	message_vision( "$N拉住小昭双手只间的铁链，运劲分拉，铁链渐渐延长，却是不断。\n", me);
		write("小昭说道“这链子古怪得紧，便是宝刀利刃，也伤它不了。锁上的钥匙在小姐手里。”");
		return 1;
	   }
	   else
	   {	message_vision( "$N拉住小昭双手只间的铁链，运劲分拉，铁链渐渐延长，却是不断。\n", me);
		message_vision("小昭叫道“唉呀，不好。你越拉越长，我可更加不便啦。”");
		return 1;
	   }

	}
   	if ((string)weapon->query("skill_type") != "sword" )
	{	
	   message_vision("$N举起" + weapon->name() + "，用劲砸下，只听得砰的一声，但铁链还是不断。\n", me);
	}

	
}
