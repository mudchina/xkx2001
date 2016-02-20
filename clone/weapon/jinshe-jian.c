//Cracked by Roath
// jinshe-jian 金蛇剑
// qfy September 18, 1996

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name("金蛇剑",({ "jinshe jian", "jinshe", "sword", "jian" }) );
        set_weight(4000);
	set_color(HIY);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 7000000);
                set("material", "steel");
                set("long", 
		"此剑就如是一条蛇盘曲而成，蛇尾勾成剑柄，蛇头则是剑尖，蛇舌分叉，\n"
		"是以剑尖竟有两叉。此剑是由黄金混和了其他五金所铸，剑身上一道血痕\n"
		"，发出碧油油的暗光，极是诡异。\n");
                set("wield_msg", 
		    HIY "$N一挥$n，霎时寒气逼人、金光流窜。剑上"+GRN+"碧绿"+HIY+"的血痕随着剑身的抖动，\n"
		    "似一条活蛇不停地扭动身子，欲择人而嗤。\n" NOR);
                set("unwield_msg", HIY "$N将$n仔细地用布革包好藏妥。\n" NOR);
                set("unequip_msg", HIY "$N将$n仔细地用布革包好藏妥。\n" NOR);
        }
	init_sword(260);
        setup();
}
