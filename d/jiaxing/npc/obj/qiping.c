//Cracked by Roath
// Jay 7/11/96

#include <weapon.h>
inherit HAMMER;

void create()
{
    set_name("棋枰", ({"qiping"}));
    set_weight(3000); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "这是块铁铸的棋枰，上面刻着十九路棋道。\n");
	set("unit","块");
	set("wield_msg","$N抽出一块方形棋枰，抓住棋枰一角。\n");
	set("unwield_msg","$N把棋枰收入怀中。\n");
	set("material", "steel");
    }
    init_hammer(30);

    setup();
}
