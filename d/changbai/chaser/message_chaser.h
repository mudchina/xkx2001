//Cracked by Roath
// /d/changbai/bj/message_chaser.h
// this file only takes care those chasers or stealer to rob special stuff
// by ALN 2 / 98
// modified by sdong 6/99

void message_chaser()
{
        mapping owner_list;
        object *obj, ob, owner, rum_ob, *owners;
        object victim, chaser_ob, thief_ob, dest, room;
        string *names, filename, *filenames, file, chaser_file;
        int i, v_exp, temp;

        string *levels = ({
					 "500000",
					 "1000000",
		  });

        remove_call_out("message_chaser");
		  call_out("message_chaser", 100 + random(100));

		  filenames = keys(wanted_list);
		  for(i = 0; i < sizeof(filenames); i++) {
					 filename = filenames[i];
					 obj = filter_array(children(filename), (: clonep :));
					 if( sizeof(obj) < 1 ) continue;
					 ob = obj[random(sizeof(obj))];

					 //if( (int)ob->query("value") < 100 ) continue;

					 if( !(owner = environment(ob)) ) continue;

					 if( !living(owner) )
								{ ob->move(this_object()); continue;}

					 if( (string)owner->query("race") != "人类" )
								{ ob->move(this_object()); continue;}

					 if( owner->query("combat_exp") < 100000  )
								{ ob->move(this_object()); continue;}

					 if( !userp(owner) && owner->query("no_fight") )
								{ ob->move(this_object()); continue;}

					 if( !random(200)  ) {
								if( !objectp(rum_ob = find_object("/d/city/npc/aqingsao")) )
										  rum_ob = load_object("/d/city/npc/aqingsao");

								if( !userp(owner) ) {
								CHANNEL_D->do_channel(rum_ob, "rumor",
								sprintf("听说%s"+HIM+"好象落在%s的%s手里了！"NOR,
										  ob->name(),
					 region_names[explode(base_name(environment(owner)), "/")[1]],
										  owner->name()));
				  } else {
								CHANNEL_D->do_channel(rum_ob, "rumor",
								sprintf("听说%s"+HIM+"好象落在%s手里了！"NOR,
										  ob->name(),
										  owner->query("name")));
								}
			}


					 if( !userp(owner) ) continue;

					 owner->add("unique_hold", 1);
					 if( owner->query("unique_hold") > (int)owner->query("kar") * wanted_list[filename] ) {
								if( !mapp(owner_list) )
										  owner_list = ([ owner: ob ]);
								else    owner_list[owner] = ob;
					 }
		  }

		  if( !mapp(owner_list) ) return;

		  owners = keys(owner_list);
		  victim = owners[random(sizeof(owners))];
		  if( !(dest = environment(victim)) ) return;
		  ob = owner_list[victim];

		  if( dest->query("no_fight") ) {
					 obj = filter_array(children(THIEF), (: clonep :));
					 if( !sizeof(obj) )
								thief_ob = new(THIEF);
					 else  {
								thief_ob = obj[0];
								if( !(room = environment(thief_ob)) ) {
										  destruct(thief_ob);
										  return;
								}
								if( !living(thief_ob) || thief_ob->is_fighting() )
										  return;
								if( dest == room ) return;
								message("vision",
										  thief_ob->name() + "急急忙忙地离开了。\n",
										  room, ({thief_ob}));
					 }

					 thief_ob->move(dest);
                message("vision",
                        thief_ob->name() + "走了过来。\n",
                        dest, ({thief_ob}));
                return;
        }

        v_exp = (int)victim->query("combat_exp");
        v_exp = (4 * v_exp + random(2 * v_exp)) / 5;
        for( i = 0; i < sizeof(levels); i++ )
                if( v_exp < atoi(levels[i]) ) break;

        chaser_file = CHASER + (3 - i) + ".c";
        obj = filter_array(children(chaser_file), (: clonep :));
        if( (temp = sizeof(obj)) ) {
                if( temp > 1 ) {
                        for( i = 1; i < temp; i++ ) destruct(obj[i]);
                } 
                if( obj[0]->is_fighting() && obj[0]->is_busy() ) return;
                message("vision",
                        obj[0]->name() + "急急忙忙地离开了。\n",
                        environment(obj[0]), ({obj[0]}));
                destruct(obj[0]);        
        }

        chaser_ob = new(chaser_file);
        chaser_ob->move(dest);
        message_vision("\n$N走了过来。\n", chaser_ob);
        "/cmds/std/look"->main(chaser_ob, victim->query("id"));
        chaser_ob->set_leader(victim);
        chaser_ob->set("stuff", ob);
        chaser_ob->set("victim", victim);
        victim->delete("unique_hold");
}

private int is_keeper(object ob, object obj)
{
        object env;
        string file, skill;
        string *no_keeper_list = ({
                "mu ren",
                "mengzhu",
                "shangshan shizhe",
                "fae shizhe",
                "xuantong dashi",
                "feng qingyang",
                "huang zhen",
                "juexin dashi",
                "yideng dashi",
                "ren woxing",
        });

        if( !clonep(ob) || userp(ob)
        ||   ob->query("race") != "人类" ) return 0;
        if( !(env = environment(ob)) ) return 0;
        if( !env->query("exits") || env->query("no_fight") ) return 0;

        file = base_name(ob);
        if(  strsrch(file, "/d/xiakedao/") == 0
        ||   strsrch(file, "/u/") == 0
        ||   strsrch(file, "/kungfu/class/shenlong") == 0
        ||   strsrch(file, "/d/changbai/npc") == 0
        ||   strsrch(file, "/d/huanghe/npc") == 0
        ||   strsrch(file, "/d/shenlong/npc") == 0 ) return 0;

        if( (int)ob->query("combat_exp") < 100000
        ||  (int)ob->query("combat_exp") > 800000
        ||  !living(ob) || ob->is_fighting() || ob->is_busy()
        ||  member_array(ob->query("id"), no_keeper_list) != -1 )
                return 0;

        if( (skill = obj->query("skill_type")) ) {
                if( (int)ob->query_skill(skill, 1) < 100 )
                        return 0;
        }

        return 1;
}
