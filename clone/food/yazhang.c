//Cracked by Roath
// yazhang.c Ñ¼ÕÆ

inherit ITEM;
inherit F_FOOD;

void init();

void create()
{
	set_name("Ñ¼ÕÆ", ({"ya zhang", "yazhang"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»Ö»·ÊÑ¼µÄÑ¼ÕÆ¡£\n");
		set("unit", "Ö»");
		set("value", 30);
		set("food_remaining", 1);
		set("food_supply", 60);
	}

	setup();
}

