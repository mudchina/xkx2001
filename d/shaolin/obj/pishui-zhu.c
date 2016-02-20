//Cracked by Roath
// pishui-zhu.c ±ÙË®ÁéÖé

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
	add_action("do_han", "han");
}

void create()
{
	set_name("±ÙË®ÁéÖé", ({"pishui zhu", "zhu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¿Å");
		set("long", "ÕâÊÇÒ»¿ÅÓÉ±ÌË®½ğ¾¦ÊŞÊŞ½ÇÖÆ³ÉµÄ±ÙË®ÁéÖé£¬ÄÜÈÃÅå´÷Õßº®¶¾²»ÇÖ£¬ºé²¨±ÙÒ×¡£\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg)) return notify_fail("ÄãÒª³ÔÊ²Ã´£¿\n");

	message_vision("\n$N¹¾ààÒ»Éù£¬°Ñ±ÙË®ÖéÍÌÏÂ¶ÇÀï£¬ËÆºõÊ²Ã´Î¶µÀÒ²Ã»³¢µ½ ... \n", this_player());
	this_player()->set_temp("zhu_eat", 1);

	destruct(this_object());
	return 1;
}

int do_han(string arg)
{
	if (!id(arg)) return notify_fail("ÄãÒªº¬Ê²Ã´£¿\n");

	message_vision("\n$NĞ¡ĞÄÒíÒíµØÄéÆğ±ÙË®ÁéÖé£¬º¬ÔÚ×ìÀï¡£\n", this_player());
	this_player()->set_temp("zhu_han", 1);

	return 1;
}
