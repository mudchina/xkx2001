//Cracked by Roath
// /d/xueshan/obj/tonggang.c
//tong gang


#include <ansi.h>

inherit ITEM;
inherit "/d/xueshan/inherit/liquid_container.c";

void create()
{
		object suyou;

        set_name(HIY "遍照雪海" NOR, ({"tong gang", "gang"}));
        set_max_encumbrance(600000);
        set_weight(300000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "尊");
                set("long", 
                "一尊通体镀金的铜缸。缸上雕刻着〖遍照雪海佛〗像。相传\n"
                "这尊雕像是佛的受用身，受天下信徒崇拜。佛身上镶嵌着五\n"
                "种天上的珠宝，五种地上的珠宝和五百零一种不同的水晶石。\n"
                "喇嘛们和信徒们敬奉的酥油都储存在这里。\n");
                set("value", 10000);
				set("material","bronze");
				set("no_get",1);
         		// make it doesn't refresh the butter
                set("no_refresh",1);
        }

		// mark it as a liquid container
		set("liquid/container",1);
		set_max_liquid(50000);
		set_current_liquid(0);
		set("liquid/unique",1);
	    set("liquid/uniqueid","su you"); 

		setup();

        carry_liquid("/d/xueshan/obj/suyou", 12000);

}
