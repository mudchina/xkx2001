//Cracked by Roath
// dulong-bian.c ¶¾Áú±Þ 
// Ryu

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit WHIP;

void create()
{
        set_name("¶¾Áú±Þ",({ "dulong bian", "bian", "whip", "dulong" }) );
        set_weight(700);
	set_color(HIB);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("value", 7000000);
		set("rigidity", 100000);
                set("material", "leather");
                set("long", 
		"ÕâÊÇÒ»ÌõÀÃÒøÒ²ËÆµÄÒøÉ«Èí±Þ£¬³¤´ïËÄÕÉÓÐÓà£¬±ÞÍ·×°×ÅÊ®¶àÖ»Ã÷»Î»ÎµÄ¼âÀûµ¹³¹³¡£\n");
		set("wield_msg", "$N¡¸à§¡¹µÄÒ»Éù´ÓÑüºó³é³öÒ»±ú$nÎÕÔÚÊÖÖÐ¡£\n");
                set("unwield_msg", "$N½«ÊÖÖÐµÄ$n±ð»ØÑüºó¡£\n");
        }
	init_whip(150);
        setup();
	::create();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("whip")) > 40 ) {
                victim->apply_condition("snake_poison",
                random(me->query_skill("whip")/10) + victim->query_condition("snake_poison"));
        }
	return 1;
}
