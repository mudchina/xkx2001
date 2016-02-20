//Cracked by Roath
// jiulao3.c 九老洞
// Shan: 96/06/22

int valid_leave(object me, string dir)
{
	me->receive_damage("jingli", 5, "钻洞累死了");
        return ::valid_leave(me, dir);
}

int do_zuan(string arg)
{
      object me = this_player();

      message_vision(
      		"$N像没头苍蝇一样在洞里瞎钻，结果一头撞在洞壁上。\n", this_player());
      if (random(2)==1) {
         	write("你觉得你晕乎乎的，似乎撞傻了。\n"); 
		// hehe, I am nice, no permanent literate decrease now:)
		// xixi, you are so nice.  I didn't realize that -1 means 1 level :)
             	me->add_temp("apply/intelligence", -1);
      }
      else {
         	me->receive_damage("jingli", 10+random(10), "钻洞累死了");
      		write("你转来转去，终于转到了洞口。\n");
		me->move(__DIR__"jiulao2");
      }
      return 1;
}

void fire_out(object me, object ob)
{
	object* inv = all_inventory(this_object());
	int i;
	for (i=0; i < sizeof(inv); i++) {
		if (inv[i]->is_character()) continue;
		destruct(inv[i]);
	}
	message("vision", "过了一会儿，手中的火折子灭了，什么也看不见了，只听到蝙蝠的吱吱声。\n", environment(me) );
	if (ob=present("fire", me))
		destruct(ob);
	delete("exits");
}


