//Cracked by Roath
// dulong-bian.c ¶¾Áú±Ş 
// Ryu

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit WHIP;

void create()
{
        set_name("¶¾Áú±Ş",({ "dulong bian", "bian", "whip", "dulong" }) );
        set_weight(700);
	set_color(YEL);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("value", 7000000);
		set("rigidity", 100000);
		set("poison_applied", 100);
                set("material", "leather");
                set("long", 
		"ÕâÊÇÒ»ÌõÀÃÒøÒ²ËÆµÄÒøÉ«Èí±Ş£¬³¤´ïËÄÕÉÓĞÓà£¬±ŞÍ·×°×ÅÊ®¶àÖ»Ã÷»Î»ÎµÄ¼âÀûµ¹³¹³¡£\n");
		set("wield_msg", "$N¡¸à§¡¹µÄÒ»Éù´ÓÑüºó³é³öÒ»±ú$nÎÕÔÚÊÖÖĞ¡£\n");
                set("unwield_msg", "$N½«ÊÖÖĞµÄ$n±ğ»ØÑüºó¡£\n");
        }
	init_whip(100);
        setup();
	::create();
}
