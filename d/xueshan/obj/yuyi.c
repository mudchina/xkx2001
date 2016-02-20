//Cracked by Roath
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void setup()
{}
void init()
{
        add_action("do_move", "get");
}
void create()
{
        set_name(HIG"鸟羽大氅"NOR, ({"da chang", "chang"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一件鸟羽织成的大氅，五颜六色，煞是好看。\n");
                set("unit", "件");
                set("material", "cloth");
		set("value", 100);
		set("armor_prop/armor", 1);
		
	}
        setup();
}
int do_move(string arg)
{
        object ob; 
        object me = this_player();
		
	if ( arg == "all") return 1;

	if (!id(arg) || file_name(environment(me)) != "/d/xueshan/dycave" )
                return 0;

	if (me->query("combat_exp") > 50000){
                message_vision(
"$N轻轻地挪动羽毛大氅，抖起一些尘土，忽然羽衣上的羽毛全都松了开来，一片片掉到地上...，呛得$N直打喷嚏。\n", this_player());

		ob = new("/d/xueshan/obj/wucan-yi");
                if (ob){
                ob->move("/d/xueshan/dycave");
                message_vision("$N突然发现下面有一件乌黑的物事。\n", this_player());
		}
        }
	else {
                message_vision(
"$N轻轻地挪动袈裟，突然从羽毛大氅的窟窿中冒出一股毒气，钻进$N的鼻子中。\n", this_player());
                me->unconcious();
        }
	destruct(this_object());
	return 1;
}
