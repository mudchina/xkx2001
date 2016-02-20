//Cracked by Roath
// d/emei/obj/fruit.c
// xbc 1997/02/03

inherit ITEM;
inherit F_FOOD;

string* titles = ({
        "香木瓜",
        "石榴",
        "海梨",
        "柿子",
	"葡萄",
	"蜜罗柑",
});

void create()
{
        set_name(titles[random(sizeof(titles))], ({ "fruit", "guo" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗野果，新鲜水灵极了。\n");
                set("value", 10);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
}
