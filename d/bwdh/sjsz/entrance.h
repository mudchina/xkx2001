//Cracked by Roath
#define CANGKU __DIR__"cangku"

void full_all(object me) {
    if( !living(me) ) me->revive(0);
    me->set("eff_jing", (int)me->query("max_jing"));
    me->set("jing", (int)me->query("max_jing"));
    me->set("eff_qi", (int)me->query("max_qi"));
    me->set("qi", (int)me->query("max_qi"));
    me->set("jingli", (int)me->query("max_jingli"));
	 me->set("neili", (int)me->query("max_neili"));
	 me->set("food", (int)me->max_food_capacity());
	 me->set("water", (int)me->max_water_capacity());
	 me->remove_all_killer();
	 me->clear_condition();
}


int relogin_player(object me)
{
		  object env, link_ob, obj;

		  if( !me ) return 1;
		  if(!objectp(me))return 1;
		  if(!userp(me))return 1;

		  env = environment(me);
		  if(!env){
				 if( me->query("sjsz/red") )
				{
					me->move("/d/bwdh/sjsz/west_xiangfang.c");
				}
				else if( me->query("sjsz/white") )
				{
					me->move("/d/bwdh/sjsz/east_xiangfang.c");
				}
				env = environment(me);
		  }

		  // Save the data and exec the player to his/her link object.
		  me->save();

		  // First, create the new body.
		  link_ob = me->query_temp("link_ob");
		  if(!link_ob)return 0;

		  obj = LOGIN_D->make_body(link_ob);
		  if (!obj) return 0;

		  exec(link_ob, me);
		  destruct(me);

		  // Restore new body and exec to it via enter_world in LOGIN_D
		  obj->restore();
		  LOGIN_D->enter_world(link_ob, obj, 1);

		  obj->move(env);
		  obj->delete("sjsz/is_updating");
		  return 1;
}

int update_player(object me)
{
		  object env, link_ob, obj;

		  if( !me ) return 1;
		  if(!objectp(me))return 1;
		  if(!userp(me))return 1;

		  call_out("relogin_player",1,me);
		  return 1;
}


void go_xiangfang() {
    object *inv, me=this_player();
    int i;

    inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++) {
       if( inv[i]->is_character())continue;
        destruct(inv[i]);
    }

	 if( me->query("sjsz/is_updating") )return;

	 /*
	 object me = this_player();
	 object *inv;
	 object *old_basket, *basket;
	 object cangku;
	 int i;

	 inv = all_inventory(me);
	 basket = allocate(sizeof(inv));
	 cangku = find_object(CANGKU);
	 if (! objectp(cangku)) {
		  cangku = load_object(CANGKU);
		  if (!objectp(cangku)) {
				message_vision("$N请告诉 wiz: cangku not found\n", me);
				return;
		  }
	 }

	 for (i=0; i<sizeof(inv); i++) {
		  
		  if ( inv[i]->query("id") != "yu di"  ) { // leave yudi/bu dai etc.
				basket[i] = inv[i];
				inv[i]->move(cangku);
				message_vision("$N将一" + inv[i]->query("unit")+ inv[i]->query("name")+"交给小厮。\n", me);
		  }
		  else
				basket[i] = 0;
	 }

	 old_basket = cangku->query("basket/" + me->query("id"));
	 if (arrayp(old_basket)) basket = basket + old_basket;
	 cangku->set("basket/" + me->query("id"), basket);
	 */

	 me->set("sjsz/fighting", 1);
	 me->set("sjsz/is_updating",1);
	 update_player(me);
	 return;
}

void back_stuff(string id)
{
	object *inv, cangku, *basket;
	int i;
	object player;

	return;

	player = find_player(id);
	if(!player)
	{
	  message_vision(NOR"主持人说：咦，"+id+"不见了？好，东西统统归我了！主持人忍不住奸笑了几声。\n");
	  return;
	}


  cangku = find_object(CANGKU);
  if (! objectp(cangku)) {
	 cangku = load_object(CANGKU);
	 if (!objectp(cangku)) {
		message_vision("$N请告诉 wiz: cangku not found\n", player);
		return 0;
	 }
  }

  basket = cangku->query("basket/"+player->query("id"));

  if (basket) {
	 for (i=0; i<sizeof(basket); i++) {
		if (objectp(basket[i])) {
		  basket[i]->move(player);
		  message_vision("$N从主持人手里拿回一"+
					 basket[i]->query("unit")+
					 basket[i]->query("name")+"。\n", player);
		}
	 }
	 cangku->delete("basket/"+player->query("id"));
  }
  else message_vision("主持人说：$N什么也没存在我这里，可别赖我贪污喔！\n", player);

}

void out_xiangfang() {

	 object me = this_player();
	 object *inv, cangku, *basket;
	 int i;
	 string id;

	 return;

	 if ( objectp(me) && me->query("sjsz/fighting") ) {
		  me->remove_all_killer();
		  me->clear_condition();
		  inv = all_inventory(me);
		  for (i=0; i<sizeof(inv); i++) {
				if ( !inv[i]->query_autoload() && inv[i]->query("id") != "bu dai" ) {
					 message_vision(NOR"$N把从擂台取的"+inv[i]->query("name")+"还给主持人。\n", me);
					 destruct(inv[i]);
				}
		  }

		 me->delete("sjsz/fighting");
		 id = me->query("id");
		 call_out("back_stuff",2,id);
		 full_all(me);
		 update_player(me);
	 }

	 return;
}


