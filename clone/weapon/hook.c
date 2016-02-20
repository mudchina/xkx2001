//Cracked by Roath
// shuanggou.c 双钩

#include <ansi.h>
#include <weapon.h>
inherit HOOK;

void create()
{
	set_name(HIW"双钩"NOR, ({ "shuang gou", "gou","hook" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一对普通的钢钩，有一护手月牙。\n");
		set("value", 250);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一对$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回背后。\n");
	}
	init_hook(35);
	setup();
}
