//Cracked by Roath
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIW "钻石耳饰" NOR, ({ "diamond earring", "earring" }));
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("value", 24000);
                set("long", "一对金质耳饰，其上串连泪滴形状的钻坠，闪烁著如梦似幻般的光彩。\n");
                set("material", "diamond");
                set("armor_prop/armor", 6);
				set("female_only", 1);
        }
        setup();
}