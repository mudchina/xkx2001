//Cracked by Roath
// heilong-bian.c 黑龙鞭

#include <weapon.h>
#include <ansi.h>
inherit WHIP;

void create()
{
	set_name("黑龙鞭", ({ "heilong bian", "bian" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", 
"这是一根乌黑油亮的长鞭，乃黑金索夹杂人发和雪山天蚕丝编织而成。
据传当年少林觉字辈祖师除奸灭邪，每次降服巨恶，即予其剃度，以其
落发编织此鞭。及至江湖撄宁，共成此三鞭。受者筋断骨折，厉害无比。\n");
		set("value", 100000000);
		set("material", "leather");
		set("rigidity", 1000);
		set("no_sell", 1);
		set("wield_msg", HIR "$N手腕一动，一根长长的黑索“哗”地展开，如黑龙般在空中盘旋滚动！\n" NOR);
		set("unwield_msg", HIR "黑龙鞭在半空中一转，「唰」地没入$N得袖中。\n" NOR);
		set("shaolin", 1);
        }
        init_whip(50);
        setup();
}
