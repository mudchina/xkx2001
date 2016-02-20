//Cracked by Roath
// stone.c
// Jay 7/4/96

#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

string* names = ({
	"鹅卵石","石块","大石头",
});

string* longs = ({
	"这是一块不太大的鹅卵石。\n",
	"这是一块有着棱角的石块。\n",
	"这是一块沉甸甸的大石头。\n",
});

void create()
{
    int i = random(sizeof(longs));

    set_name(names[i], ({"shikuai", "shi", "stone"}));
    set_weight(i*500 + 300); 
    if( clonep() )
       set_default_object(__FILE__);
    else {
       set("long", longs[i]);
	set("unit","块");
	set("wield_msg","$N搬起一块石头准备战斗。\n");
	set("material", "stone");
    }
    init_hammer(i+1);
    setup();
}

void init()
{
	add_action("do_break", "break");
}

int do_break(string arg)
{
	object obj, me;

	if (!arg || (arg != "stone" && arg != "shikuai"))
		return notify_fail("什么？\n");

	me = this_player();
	if (me->query("neili") < 500)
		return notify_fail("你功力不足，不能击石成粉！\n");
	message_vision(HIW"$N气沉丹田，运足真气，向石头击去！\n"NOR,me); 
	write(HIW"只听得“嘭”的一声，石头被击成碎块！\n"NOR);
	obj = new("/d/taohua/obj/shizi2");
	obj->move(me);
	me->add("neili", -(100+random(100)));
	destruct(this_object());
	return 1;
}
