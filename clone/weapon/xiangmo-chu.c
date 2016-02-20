//Cracked by Roath
// weapon: xiangmo-chu.c
// Summer. 10/7/96

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit STAFF;

void create()
{
        set_name(HIY"降魔杵"NOR, ({ "xiangmo chu", "xiangmo","chu" }));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", HIY"此杵顶呈莲花状，杵身长约两尺，鸭蛋粗细，杵段尖锐锋厉。是密宗喇嘛降妖伏魔的法器。\n"NOR);
                set("value", 7000000);
                set("material", "steel");
		set("rigidity", 4000);
                set("wield_msg", HIY"一道金光在你眼前一闪，$N操出一根降魔杵，举过头顶，光茫万照。\n"NOR);
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_staff(120);
        setup();
	::create();
}


