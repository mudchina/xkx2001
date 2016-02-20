//Cracked by Roath
// jiyou.c ¼¦ÓÍ 
// By xbc 

inherit ITEM;

void create()
{
	set_name("¼¦ÓÍ", ({"ji you", "chicken butter", "butter"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¹ŞÄåÄåµÄ¼¦ÓÍ¡£\n");
		set("unit", "¹Ş");
		set("value", 0);
	}
}
