//Cracked by Roath
// allow-letter5.c 大理晋级用公文
inherit ITEM;

void create()
{
	set_name("信印", ({"xin yin", "xin", "letter"}));
	set_weight(100);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("unit", "幅");
		set("long","这是一幅由当今圣上签发的信印，凭此可自由向善阐侯挑战。\n");
		set("no_get", "这样东西不能离开你。\n");
		set("material", "paper");
	}
}
