//Cracked by Roath
// yufenguan.c

#include <ansi.h>
#include <armor.h>

inherit F_AUTOLOAD;
inherit F_UNIQUE;
inherit HEAD;

void create()
{
	set_name( "凤冠" , ({ "feng guan", "guan" }) );
    set_color("$HIC$");
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
        set("long", "这是一顶白玉雕刻成的凤冠，精工细作，端的是维妙维肖。上面还镶有一颗巨大的夜明珠，闪闪发光。\n");
		set("value", 50000);
		set("material", "jade");
        set("regidity", 1000000);
		set("armor_prop/armor", 100);
	}

	setup();
}

int is_special() { return 1;}

int query_autoload()
{
        object me = this_player();
        if( wizardp(me) || me->query("beauty")==1 )
            return 1;
        else return 0;
}

void init()
{
        object me = this_player();

		if(me->query("gender")=="女性")
		{
			set("wear_msg", HIM "$N戴上一顶玉凤冠，顿时光芒四射，夺人心魄。她两颊生辉，神采飞扬，端然是沉鱼落雁之貌、倾城倾国之姿。\n" NOR);
		}
		else
			set("wear_msg", HIM "$N戴上一顶玉凤冠，顿时光芒四射，夺人心魄。\n" NOR);

        set("unequip_msg", HIY "$N将玉凤冠小心翼翼地摘了下来。\n" NOR);

         if (!wizardp(me)) {
                  set("no_get",   "匹夫无罪，怀璧其罪，你还是算了吧。\n");
                  set("no_drop",  "这么珍贵的东西怎么能扔了呢。\n");
                  set("no_steal", "这个东西你偷不到。\n");
         }
}


mixed hit_by(object me, object victim, int damage, object weapon)
{
        string result;

        damage = damage/10;
        if( damage < 5 ) damage = 0;

        return ([ "result": result, "damage": damage+random(damage) ]);
}

