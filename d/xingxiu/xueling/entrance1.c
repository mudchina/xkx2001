//Cracked by Roath
// entrance1 for fighting ground

inherit ROOM;
#include <ansi.h>
int valid_leave();
int do_cun();

#define CANGKU "/d/xingxiu/xueling/cangku"
#include "battlefield.h"

void create()
{
  set("short", HIG"群英堂"NOR);
  set("long", @LONG
这里是来试剑山庄的英雄们休息闲谈的地方，此间主人还未现身，
可是群雄都已经急不可待。从这里往里就是试剑亭，听说有不少珍藏
的名器。门边有几个小厮帮客人们收起随身携带的物品。
LONG
  );
  set("no_fight", 1);
  set("invalid_startroom", 1);
  set("exits", ([
		 "enter" : __DIR__"entrance2",
		 ]));
  setup();
}

void init()
{
  disableCmds();
}


int valid_leave(object who, string dir) {
  object room = this_object();
  object player = this_player();
  object *inv;
  object *old_basket, *basket;
  object cangku;
  int i;

  if (player->query_all_condition())
    return notify_fail("门口的小厮看了你一眼道：您老身有不适，还是改日再来吧。\n");

  inv = all_inventory(player);
  basket = allocate(sizeof(inv));

  cangku = find_object(CANGKU);
  if (! objectp(cangku)) {
    cangku = load_object(CANGKU);
    if (!objectp(cangku)) {
      message_vision("$N请告诉 wiz: cangku not found\n", player);
      return 0;
    }
  }

  for (i=0; i<sizeof(inv); i++) {
    if (! inv[i]->query_autoload()) { // leave yudi etc.
      basket[i] = inv[i];
      inv[i]->move(cangku);
      message_vision("$N将一"+
	inv[i]->query("unit")+
	inv[i]->query("name")+"交给小厮。\n", player);
    }else{
      basket[i] = 0;
    }
  }
  old_basket=cangku->query("basket/"+player->query("id"));
  if (arrayp(old_basket)) basket = basket + old_basket;
  cangku->set("basket/"+player->query("id"), basket);
  player->set_temp("xueling/playing", 1);
  return ::valid_leave(who, dir);
}
