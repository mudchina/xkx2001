//Cracked by Roath
// /d/zhongnan/obj/lingpai.c
// lingpai.c 全真教令牌
// sdong 06/01/99

inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
		  set_name("全真教令牌", ({"ling pai", "pai"}));
		  set("long",
					 "这是一把铜制的，打造的非常精致。\n");
		  set("unit", "把");
		  set("weight", 10);

		  set("no_get",   "匹夫无罪，怀璧其罪，你还是算了吧。\n");
		  set("no_steal", "这个东西你偷不到。\n");

}
