//Cracked by Roath

#include <ansi.h>

inherit ITEM;

#define TIMEOUT 500

void create()
{
  set_name("青铁令", ({ "qingtie ling", "ling" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "块");
    set("long", "这是西夏国一品堂堂主令。\n");
    set("value", 0);
    set("material", "steel");
  }
  setup();
}

void init()
{
  add_action("do_behead", "behead");
}

/*
 * This decay feature of ypling is designed to prevent the players from using
 * multiple ypling to gain super fast, yet it still leaves some tricks for the 
 * players to get multiple lings for easier and faster job. 
 * 
 * Normally a ling will dissappear within 5 TIMEOUTs (a little less than 2
 * refresh period) so that the gain from multiple ypling would be very limited.
 *
 * However, if a player can find a cold environment to store the ling, they
 * can hold a ling for up to 100 minutes.  The ice cube is designed for this
 * purpose.
 *
 * Further, if a player can find a freezer (<0 temprature), he can hold the
 * ling forever.  This needs to be carefully designed and is not available
 * right now.
 *
 * -chu@xkx
 */
void decay(int phase)
{
  object env;
  string msg;
  int    temp;

  env = environment(this_object());
  temp = env->query("temperature");

  // Question: how do I know if a variable is not set or it is 0?
  if (temp == 0) temp = 37;  // default

  /*  no decay: not available now
  if (temp < 0) {
    call_out("decay", TIMEOUT, phase);  
    return;
  }
  */

  if (temp < 5) {
    phase = phase +1;
  }else{
    phase = phase +2;
  }
  
  call_out("decay", TIMEOUT, phase+1);  // low temp, decay 1
  switch (phase) {
  case 1:
  case 2:
    msg="青铁令上的鲜血慢慢地凝固，结成了血块．";
    break;
  case 3:
  case 4:
    msg="青铁令上的血块开始发出一阵阵的恶臭．";
    break;
  case 5:
  case 6:
    msg="腐肉臭血渐渐地把青铁令上的字迹模糊了．";
    break;
  case 7:
  case 8:
    msg="青铁令上的字迹已经几乎不可辨认了．";
    break;
  default:
    msg="你看了看烂得不可辨认的青铁令，叹了口气，把它扔了．";
    break;
  }
  message_vision(msg+"\n", environment());
  this_object()->set("decay", phase);
  if (phase>8) destruct(this_object());
  return;
}

int do_behead(string arg)
{
  object me, obj, ob;

  me = this_player();
  ob = new(__DIR__"head.c");

  if (!arg || arg != "corpse" || !(obj = present(arg, environment(me))))
    return 0;
  
  if (obj->query("beheaded", 1)) return 0;

  message_vision("$N用青铁令把"+obj->query("name")+
		 "头割了下来，拎在手里。\n", me);
  ob->set("name", obj->query("victim_name")+"的头");
  ob->set("victim_name", obj->query("victim_name"));
  if (query("victim") == obj->query("victim_name")
      && query("owner") == obj->query("my_killer")) {
    set("done", 1);
    ob->set("gain", obj->query("combat_exp")*10/me->query("combat_exp"));	
    ob->set("owner", me->query("id"));
  }
  ob->move(me);
  obj->set("name", "一具无头尸体");
  obj->set("beheaded", 1);

  remove_call_out("decay");
  call_out("decay", TIMEOUT, this_object()->query("decay"));
  return 1;
}
