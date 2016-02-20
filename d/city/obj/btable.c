//Cracked by Roath
#include  <ansi.h>

inherit  ITEM;

void  create()
{
	set_name(HIC"麻将桌"NOR,  ({  "table"  }));
        set_weight(200000);
        set("long",  "这是张以蓝色硫璃石镶嵌成的麻将桌。\n"  );
        if(  clonep()  )
        set_default_object(__FILE__);
        else  {
        set("unit",  "张");
        set("material",  "stone");
        set("value",  2000);
        set("no_get",  1);
        set("amount",30);
                }
        setup();
}
