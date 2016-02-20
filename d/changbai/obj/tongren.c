//Cracked by Roath
// /d/changbai/obj/tongren.c

#include <weapon.h>
inherit CLUB;

void create()
{
       set_name("独足铜人", ({"tongren"}));
       set_weight(10000);
       if( clonep() )
              set_default_object(__FILE__);
       else {
              set("long", "这铜人只有独足，手却有一对，双手过顶合拢，正是一把厉害的闭穴撅。\n");
              set("unit", "个");
              set("value", 2000);
              set("material", "bonze"); 
              set("wield_msg","$N从背上卸下独脚铜人握在手中。\n");
              set("unwield_msg","$N把独足铜人放在背上。\n");
       }

       init_club(50);

       setup();
}
