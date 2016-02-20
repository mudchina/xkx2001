//Cracked by Roath
// guaishezhang.c
// sdong, 11/20/98

#include <weapon.h>
#include <ansi.h>

inherit STAFF;

string long_desc();

void create()
{
	set_name(HIB"怪蛇杖"NOR, ({ "guai shezhang", "staff", "shezhang" }));
	set_weight(4000);
	set("unit", "根");
	set("long", (: long_desc :));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", (: long_desc :));
	}
		set("value", 450);
		set("material", "steel");
		set("snake_type","怪蛇");
		set("wield_msg", HIW"$N抽出一根$n"+HIW"握在手中，杖端的蛇头呲呲做响，让人不寒而栗。\n"NOR);
		set("unwield_msg", "$N将手中的$n放了下来。\n");
		init_staff(35);
		setup();
}
string long_desc()
{
		  string desc ;
		  object staff = this_object();

		  desc = HIB"一根弯弯曲曲的黑色粗杖，似是钢铁所制，杖头铸着个裂口而笑的人头，人头口中露出尖利雪白的牙齿，\n模样甚是狰狞诡异，\n"NOR;

		  if( staff->query("snake")==1 ) desc += HIW"杖上盘着一条银鳞闪闪的小蛇，不住的蜿蜒上下。\n"NOR;
		  else if ( staff->query("snake")==2 ) desc += HIW"杖上盘着两条银鳞闪闪的小蛇，不住的蜿蜒上下。\n"NOR;
		  
		  return desc;
}

void init()
{
		  add_action("convert","convert");
}

int convert(string arg)
{
		  object me = this_player();
		  object ob;

		  if (arg!="shezhang" && arg!="staff" && arg!="zhang") return 0;
		  if (me->query("family/family_name") != "白驼山")
					 return notify_fail("你不能化杖为蛇。\n");
		  if ((int)me->query("jing") < 100)
					 return notify_fail("你的精力不够。\n");

	if (!present("guai shezhang", me))
		return notify_fail("你身上没有怪蛇杖。\n");

		  if (random(me->query_skill("training",1)) <20) {
			  message_vision("$N手握蛇杖手舞足蹈，好像发疯一般。\n"
					 ,me);
			  me->receive_damage("jing", 95);
			  return 1;
		  }

		 if(query("snake") <1)return notify_fail("蛇杖上没有蛇。\n");

		  message_vision("$N手握蛇杖手舞足蹈，猛地一摔，蛇杖上的毒蛇似箭一般飞了出来。\n",
					 me,);

		  //seteuid(ROOT_UID);
		  set_default_object(__FILE__);
		  ob = new("/d/xingxiu/npc/guaishe.c");
		  ob->move(environment(me));
		  ob->set_owner(me);
        ob->set("food",250);

		  add("snake",-1);

		  return 1;
}



