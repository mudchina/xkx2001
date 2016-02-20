//Cracked by Roath
// fighter.c

#include <ansi.h>
#include <origin.h>
#include <user.h>

inherit CHARACTER;
inherit F_SAVE;

void quit(object ob);

void create()
{
	::create();
	set_name("打擂者", ({ "user object", "fighter dummy" }) );
	seteuid(getuid());
}



// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

	id = query("id", 1);
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

void unconcious()
{
	die();
}

void die()
{
	object link_ob, rum_ob, muyi_ob;
	object me = this_object();
	object ob = me->query_temp("last_damage_from");
	if( !living(this_object()) ) this_object()->revive(1);
	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());
	if(objectp(ob)){
		message_vision(me->query("family/family_name")+"$N被"+
							  ob->query("family/family_name")+"$n击败。\n", me, ob);

		rum_ob = load_object("/d/huashan/npc/referee");


//		if(objectp(rum_ob))
//			CHANNEL_D->do_channel(rum_ob, "chat", me->short(1)+HIC+" 被"+
//										 ob->short(1)+HIC+" 击败。");
	}

//	if(objectp(ob)) quit(ob);

	quit(me);
}

void quit(object ob)
{
	object link_ob = ob->query_temp("link_ob");
	if(objectp(link_ob) ) {
		if(link_ob->is_character()) {
			tell_object(ob, "你退出擂台。\n");
			if(!interactive(link_ob) && interactive(ob) ) {
				exec(link_ob, ob);
				link_ob->setup();
				link_ob->delete_temp("netdead");
				link_ob->delete_temp("admitted");
				link_ob->set_temp("defeated",1);
			}
			if(!interactive(link_ob)) destruct(link_ob);
		}
	}
	if(!interactive(ob)) {destruct(ob); return;}
	if (ob == this_object()) {
		ob->set_temp("quit/forced", 1);
		command("quit");
		return;
	} else {
		ob->quit(ob);
	}
}

int save()
{
		  string file;
/*
		  if( stringp(file = this_object()->query_save_file()) ) {
					 assure_file(file+ __SAVE_EXTENSION__);
					 return save_object(file);
		  }
*/
		  return 0;
}


void disconnect(object ob)
{
	object link_ob = ob->query_temp("link_ob");
	if(objectp(link_ob) ) {
		link_ob->set_temp("quit/forced", 1);
		link_ob->command("quit");
	}
	if( objectp(ob) )destruct(ob);
}


// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
private void net_dead()
{
	object link_ob;

	set_heart_beat(0);
	if( objectp(link_ob = query_temp("link_ob")) ) {

		 if( userp(this_object()) ) {
			  tell_room(environment(), query("name") + "断线了。\n", this_object());
			  tell_room(environment(link_ob), link_ob->query("name") + "断线了。\n", link_ob);
			CHANNEL_D->do_channel(this_object(), "sys", "断线了。");
			disconnect(this_object());
			//destruct(this_object());
		 }
//		 destruct(link_ob);
	}
//	set_temp("quit/forced", 1);

}


