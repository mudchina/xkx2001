//Cracked by Roath
// Write by Wzfeng 12-29

inherit ITEM;

void create()
{
	set_name("封套", ({"feng tao"}));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装书函的封套。\n");
		set("unit", "个");
		set("value", 100);
		set("send_level",1);
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
	if(!arg) return notify_fail("你要将什么装进封套里？\n");
	
	ob_letter = present(arg, me);
	if(!ob_letter)
		return notify_fail("你身上好像并没有这封书函？\n");
	if(!ob_letter->query("can_feng"))
		return notify_fail("对不起！你不能将这个放进封套里。\n");
	
	message_vision("$N从身上掏出一张写好的书函装在封套里。\n",me);

	ob_letter->set("long", "这是一个已经封好的封套，里面装有书函。\n");
	ob_letter->set_name("信函", ({"xin han","letter"}));
	ob_letter->set("can_feng",0);		
	ob_letter->set("can_send",1);
	ob_letter->set("letter/send_level",1);
	destruct(this_object());
	return 1;
}



