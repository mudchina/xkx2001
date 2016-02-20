//Cracked by Roath
#include <ansi.h>

inherit ITEM;
inherit F_EQUIP;

void create()
{
        set_name( "麒麟臂", ({ "qilin bi", "qilin", "bi", "arm" }) );
	set_color(RED);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
                set("long", "这是一根手臂，相传是于岳少年时赤膊搏斗火麒麟，左臂被麒麟血所溅而成。\n");
                set("unit", "根");
                set("value", 150);
                set("armor_type", "arm");
                set("armor_prop/armor", 1);
                set("armor_prop/strength", 20);
		set("wear_msg", "$N「咔嚓」一声，将$n接在了断臂之处。\n");
		set("remove_msg", "$N把心一横，「咯」的一声，将$n卸了下来。\n");
                set("no_sell", 1);
        }
        setup();
}

void init()
{
	add_action("do_enfor", "jiali");
	add_action("do_enfor", "enforce");
}

int wear()
{
	set("embedded", 1);
        set("no_drop", 1);
        set("no_get", 1);
        set("owner", environment()->query("name"));
        ::wear();
        return 1;
}

int unequip()
{
	if( !wizardp(environment()) ) return 0;
}

string query_autoload()
{
        if( query("equipped") ) return query("name");
}

void autoload(string arg)
{
        set("name", arg);
        set("embedded", 1);
        set("no_drop", 1);
        set("no_get", 1);
        set("owner", environment()->query("name"));
        ::wear();
}

int do_enfor(string arg)
{
        int pts;
	object me = this_player();

	if( !query("embedded") ) return 0;

        if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
                return notify_fail("指令格式：enforce|jiali <使出几点内力伤敌>|none");

        if( !me->query_skill_mapped("force") )
                return notify_fail("你必须先 enable 一种内功。\n");

        if( arg=="none" )
                me->delete("jiali");
        else {
                if( pts < 0 )
                        return notify_fail("你只能用 none 表示不运内力，或数字表示每一击用几点内力。\n");
                if( pts > (int)me->query_skill("force") / 3 * 2 )
                        return notify_fail("你的内功火侯还加不了那么大力。\n");
                me->set("jiali", pts);
        }

	if( pts > 150 )
		message_vision(RED"$N暗暗将内力运到左臂之上，只见麒麟臂隐隐现出黯红的色泽。\n"NOR, me);
        write("从现在起你用" + chinese_number(pts)+"点内力伤敌。\n");
        return 1;
}
