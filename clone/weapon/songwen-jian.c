//Cracked by Roath
//松纹剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(YEL"松纹古剑"NOR, ({ "songwen jian","sword","jian" }));
	set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("long","这是一把形制古朴的长剑，颜色黯淡，入手颇为沉重，剑身隐隐有一些条纹。\n");
		set("value", 15000);
                set("material", "steel");
		set("wield_msg", "$N面色凝重，缓缓抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n缓缓插入剑鞘。\n");
        }
	init_sword(54);
        setup();
}
