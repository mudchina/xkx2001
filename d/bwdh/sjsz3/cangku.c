//Cracked by Roath
// cangku to store all players's stuff

inherit ITEM;
#include <ansi.h>

void create()
{
  set_name("团体赛仓库", ({ "cangku", "ku"}) );
  set_weight(100000000);
  set_max_encumbrance(500000000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "坐");
    set("long", "团体赛仓库存着比武的玩家们的随身物品．\n");
    set("value", 1000000);
    set("material", "steel");
    set("no_get",1);
    set("no_clean_up", 1);
  }
  setup();
}
