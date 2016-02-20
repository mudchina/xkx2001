//Cracked by Roath
// Write by Wzfeng 12-29
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"帛套"NOR, ({"jin tao"}));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用丝绸做成的套子，可以用来装书函，文书。套子的背面沾着五根羽毛。\n");
		set("unit", "个");
		set("value", 1000);
		set("send_level",3);

	}
}
void init()
{
	add_action("do_feng", "feng");	
}

int do_feng(string arg)
{
	object ob_letter,me;
	me=this_player();
	if(!arg) return notify_fail("你要将什么装进帛套里？\n");
	
	ob_letter = present(arg, me);
	if(!ob_letter)
		return notify_fail("你身上好像并没有封书函？\n");
	if(!ob_letter->query("can_feng"))
		return notify_fail("对不起！你不能将这个放进帛套里。\n");
		message_vision("$N从身上掏出一张写好的书函装在帛套里。\n",me);
	ob_letter->set("long", "这是一个已经封好的帛套，里面装有书函。套子的背面沾着五根羽毛。\n");
	
	ob_letter->set_name(HIR"信函"NOR, ({"xin han","letter"}));
	ob_letter->set("can_feng",0);
	ob_letter->set("can_send",1);
	ob_letter->set("letter/send_level",3);
	destruct(this_object());
	return 1;
}
