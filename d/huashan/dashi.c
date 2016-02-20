//Cracked by Roath
// 大石上
// qfy July 8, 1996.

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "大石上");
	set("long", @LONG
你站在山洪中的巨石上，四周水花飞溅，你衣履尽湿。你凝气守中，
双足稳稳站定。水位逐渐上升，很快地山洪便从你头顶轰隆轰隆的冲过。
你的身子却如中流砥柱般在水中屹立不动。溪流中带下树枝山石(stone)
，在你身旁急速流过。岸边(bank)也开始泛滥了。
LONG
        );
        
	set("item_desc",([
	    "stone" : "一块块的山石，正迅急地被山洪带动向你冲来。\n",
	    "bank" : "水位逐渐升高，开始泛滥了。\n",
	]));
	
        set("no_clean_up", 0);
        set("outdoors", "huashan" );

	set("cost", 3);
        setup();
}

void init()
{
	add_action("do_da", "da");
	add_action("do_da", "ji");
	add_action("do_da", "hit");
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me = this_player();

	if ( !arg || arg != "bank" )
	     return notify_fail( "什么？\n");

	message_vision("$N纵身跳回岸上。\n\n", me);
	me->move(__DIR__"shanhong");
	message("vision", me->name() + "纵身由巨岩上跳了过来。\n",environment(me), ({me}) );

	return 1;
}

int do_da(string arg)
{
	object weapon, me = this_player();

	if ( !arg || arg != "stone" )
	     return notify_fail( "什么？\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
   	|| (string)weapon->query("skill_type") != "sword"){ 
	  if ( me->query("neili") >=50 ) {
	     me->add("neili", -50);
	  }
	  else {
	     me->set("neili", 0);
          }
	  me->receive_wound("qi", 50, "被山石砸死了");   	
	  me->receive_damage("qi", 70, "被山石砸死了");
	  message_vision(
	  "$N运起内力，双掌同时拍向山石，结果劲力反震，自己反而受伤。\n", me);
	  return 1;
	}

	if ( (int)me->query("neili") < 50 )
		return notify_fail( "你内力不足，不能击石练剑。\n"); 
	if ( (int)me->query("jingli") < 50 )
                return notify_fail( "你精力不足，不能击石练剑。\n");


	if ( weapon->name() == "小树枝" && weapon->query_temp("marks/击") >= 1 ) {
	  message_vision(HIW "只听见「啪」地一声，$N手中的" + weapon->name() + "已经断为两截！\n" NOR, me);
	  weapon->unequip();
          weapon->move(environment(me));
          weapon->set("name", "断掉的" + weapon->name());
          weapon->set("value", 0);
          weapon->set("weapon_prop", 0);
        }
	else if ( weapon->name() == "绣花针" && weapon->query_temp("marks/击") >=3 ) {
	  message_vision(HIW "只听见「啪」地一声，$N手中的" + weapon->name() + "已经断为两截！\n" NOR, me);
	  weapon->unequip();
          weapon->move(environment(me));
          weapon->set("name", "断掉的" + weapon->name());
          weapon->set("value", 0);
          weapon->set("weapon_prop", 0);
        }
	else if ( weapon->name() == "竹剑" && weapon->query_temp("marks/击") >= 3 ) {
	  message_vision(HIW "只听见「啪」地一声，$N手中的" + weapon->name() + "已经断为两截！\n" NOR, me);
	  weapon->unequip();
	  weapon->move(environment(me));
	  weapon->set("name", "断掉的" + weapon->name());
	  weapon->set("value", 0);
	  weapon->set("weapon_prop", 0);
	}
	else if ( weapon->name() == "短剑" && weapon->query_temp("marks/击") >= 5 ) {
	  message_vision(HIW "只听见「啪」地一声，$N手中的" + weapon->name() + "已经断为两截！\n" NOR, me);
          weapon->unequip();
          weapon->move(environment(me));
          weapon->set("name", "断掉的" + weapon->name());
          weapon->set("value", 0);
          weapon->set("weapon_prop", 0);
        }
	else if ( weapon->name() == "峨眉刺" && weapon->query_temp("marks/击") >= 6 ) {
  	  message_vision(HIW "只听见「啪」地一声，$N手中的" + weapon->name() + "已经断为两截！\n" NOR, me);
  	  weapon->unequip();
  	  weapon->move(environment(me));
  	  weapon->set("name", "断掉的" + weapon->name());
  	  weapon->set("value", 0);
  	  weapon->set("weapon_prop", 0);
	}
	else if ( weapon->name() == "长剑" && weapon->query_temp("marks/击") >= 8 ) {
	  message_vision(HIW "只听见「啪」地一声，$N手中的" + weapon->name() + "已经断为两截！\n" NOR, me);
          weapon->unequip();
          weapon->move(environment(me));
          weapon->set("name", "断掉的" + weapon->name());
          weapon->set("value", 0);
          weapon->set("weapon_prop", 0);
        }
	else if ( weapon->name() == "钢剑" && weapon->query_temp("marks/击") >= 15 ) {
  	  message_vision(HIW "只听见「啪」地一声，$N手中的" + weapon->name() + "已经断为两截！\n" NOR, me);
  	  weapon->unequip();
  	  weapon->move(environment(me));
  	  weapon->set("name", "断掉的" + weapon->name());
  	  weapon->set("value", 0);
  	  weapon->set("weapon_prop", 0);
	}
	else if ( weapon->name() == "游龙剑" && weapon->query_temp("marks/击") >= 20 ) {
          message_vision(HIW "只听见「啪」地一声，$N手中的" + weapon->name() + "已经断为两截！\n" NOR, me);
          weapon->unequip();
          weapon->move(environment(me));
          weapon->set("name", "断掉的" + weapon->name());
          weapon->set("value", 0);
          weapon->set("weapon_prop", 0);
	}
	else {
	  if ( weapon->name() != "玄铁重剑" && weapon->name() != "倚天剑" ) { 
	     weapon->add_temp("marks/击",1);
	  }
	  message_vision("$N举剑往石块挑去，将山石打了回去，使山石流不过身边。\n", me);
	  
	  if ( (int)me->query_skill("strike",1) >= 30 
	  && (int)me->query_skill("strike",1) <= 100 ) {
	     me->improve_skill("strike", me->query("int"));
	     write( "你的基本掌法进步了。\n");
	  }

	  if ( (int)me->query_skill("sword",1)  >= 30
	  && (int)me->query_skill("sword",1) <= 100 ) {
             me->improve_skill("sword", me->query("int"));
	     write( "你的基本剑法进步了。\n");
	  }

	  if ( (int)me->query_skill("force",1) >= 30
	  && (int)me->query_skill("force",1) <= 100 ) {
  	     me->improve_skill("force", me->query("int"));
	     write( "你的基本内功进步了。\n");
	  }	

	  if ( me->query_skill("dugu-jiujian",1) >= 1 ) {
	     me->improve_skill("dugu-jiujian", me->query("int")+20);
	     write( "你的独孤九剑进步了。\n");
	  }

	  me->receive_damage("jingli", 30, "体力透支过度死了");
	  me->receive_damage("qi", 10, "体力透支过度死了");
          me->add("neili",-50);
	  return 1;
	}	  
} 
