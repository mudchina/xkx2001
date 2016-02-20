//Cracked by Roath
// mitao.c 酥油 
// By Summer 

inherit ITEM;

void create()
{
	set_name("酥油", ({"butter", "suyou"}));
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一罐准备挑到寺院里去还愿供佛用的酥油。\n");
		set("unit", "罐");
		set("value", 500);
	}
}
