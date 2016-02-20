//Cracked by Roath
// byskirt.c

inherit ITEM;

void create()
{
	set_name("纺纱机", ({ "fangsha ji", "ji", "machine" }) );
	set("long", "一台构造相当简单的手工纺纱机，心灵手巧的摆夷妇女就用这种粗糙的飞梭编织精秀的织品。\n");
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "台");
		set("material", "wood");
		set("no_get", 1);
	}
	setup();
}
