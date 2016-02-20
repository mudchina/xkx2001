//Cracked by Roath
// Ryu 3/26/97

inherit ITEM;

void create()
{
        set_name("òóÉßÏÑ", ({"venom", "xian"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "Ò»Ì²¸¹ÉßÍÂ³öµÄ¶¾ÏÑ¡£\n");
                set("unit", "Ì²");
                set("value", 0);
		set("no_get", 1);
        }
}

