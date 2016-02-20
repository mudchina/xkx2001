//Cracked by Roath
// room.c
// modified by sdong to force cleanup in refresh time for /kunfu/class npc, 12/15/98, this may help to resolve
//		multiple clone of unique npc and robot problem
//

#pragma save_binary

#include <dbase.h>
#include <room.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

static mapping doors;

int query_max_encumbrance() { return 100000000000; }

// cyz&kitten 99/05/09
//checks if there's any user in this room
int usr_in()
{
	object *inv = deep_inventory(this_object());
	for(int i= 0; i < sizeof(inv); i++)
	{
		if(userp(inv[i])) return 1;
	}
	return 0;
}

// added by sdong, 12/15/98
int npc_clean_up(string str)
{
		  object *ob_list;
		  int i;

		  if (!str) return notify_fail("指令格式：cleanup <档名>\n");
		  ob_list = children(str);
		  ob_list->clean_up();
		  for(i=0; i<sizeof(ob_list); i++)
					 if( ob_list[i] )
					 {
								if( living( ob_list[i]) && environment(ob_list[i]) )
									tell_room( environment(ob_list[i]),ob_list[i]->query("name")+"急急忙忙离开了。\n");
								destruct(ob_list[i]);
					 }
		  return 1;
}



object make_inventory(string file)
{
	object ob;

		  if( objectp(ob = new(file)) ) {
				// modified by ryu here to avoid class npc's multiple clone.
				if(strsrch(base_name(ob), "/kungfu/class/") == 0
					&& sizeof(filter_array(children(base_name(ob)), (: clonep :))) > 1)
				{
					npc_clean_up(file); // clean up all then make a new one, sdong , 12/15/98
					ob = new(file);
					if(!ob)return 0;
				}

				ob->move(this_object());
				ob->set("startroom", base_name(this_object()));
				if( living( ob ) && environment(ob) ) // added by sdong to give reasonable message, 12/15/98
						tell_room( environment(ob),ob->query("name")+"急急忙忙走了过来。\n" );
				return ob;
		  }

		  return 0;
}

void reset()
{
	mapping ob_list, ob;
	object *inv;
	string *list;
	int i,j;

	//
	// Check loaded objects to match the objects specified in "objects"
	// while query("objects") is
	// ([ <object filename>: <amount>, ..... ])
	// and query_temp("objects") is
	// ([ <object filename>: ({ob1, ob2, ...}), .... ])
	//
	set("no_clean_up", 0);
	ob_list = query("objects");
	inv = all_inventory(this_object());
	if( !mapp(ob_list) ) {
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->is_character()
//			||inv[i]->query("no_clean_up")
			||inv[i]->query("no_refresh")
			||!clonep(inv[i]) ) continue;
			destruct(inv[i]);
		}
		return;
	}
	
	if( !mapp(ob = query_temp("objects")) )
		ob = allocate_mapping(sizeof(ob_list));
	list = keys(ob_list);
	for(i=0; i<sizeof(inv); i++) {
		if(inv[i]->is_character()
//		 ||inv[i]->query("no_clean_up")
		 ||inv[i]->query("no_refresh")
		 ||!clonep(inv[i])
		 ||member_array(base_name(inv[i]), list) != -1) continue;
		destruct(inv[i]);
	}
	for(i=0; i<sizeof(list); i++) {
		// Allocate an array if we have multiple same object specified.
		if(	undefinedp(ob[list[i]])
		&&	intp(ob_list[list[i]])
		&&	ob_list[list[i]] > 1 )
			ob[list[i]] = allocate(ob_list[list[i]]);

		switch(ob_list[list[i]]) {
		case 1:
			if( !ob[list[i]] ) ob[list[i]] = make_inventory(list[i]);
                 // modified by aln here to avoid move 0
                        if( !(ob[list[i]]) ) continue;

			if( environment(ob[list[i]]) != this_object()
			&&	ob[list[i]]->is_character() ) {
				if( !ob[list[i]]->return_home(this_object()) )
					add("no_clean_up", 1);
			}
			break;
		default:
			for(j=0; j<ob_list[list[i]]; j++) {
				// If the object is gone, make another one.
				if( !objectp(ob[list[i]][j]) ) {
					ob[list[i]][j] = make_inventory(list[i]);
					continue;
				}

                                // modified by aln here to avoid move 0
                                if( !(ob[list[i]][j]) ) continue;

				// Try to call the wandering npc come back here.
				if( environment(ob[list[i]][j]) != this_object()
				&&	ob[list[i]][j]->is_character() ) {
					if( !ob[list[i]][j]->return_home(this_object()) )
						add("no_clean_up", 1);
				}
			}
		}
	}
	set_temp("objects", ob);
}

// Redirect item_desc of the door to this function in default.
string look_door(string dir)
{
	if( !mapp(doors) || undefinedp(doors[dir]) )
		return "你要看什么？\n";
	if( doors[dir]["status"] & DOOR_CLOSED )
		return "这个" + doors[dir]["name"] + "是关着的。\n";
	else
		return "这个" + doors[dir]["name"] + "是开着的。\n";
}

varargs int open_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;

	if( !mapp(doors) || undefinedp(doors[dir]) )
		return notify_fail("这个方向没有门。\n");

	if( !(doors[dir]["status"] & DOOR_CLOSED) )
		return notify_fail( doors[dir]["name"] + "已经是开着的了。\n");

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: open_door: attempt to open a door with out an exit.\n");

	if( from_other_side )
		message("vision", "有人从另一边将" + doors[dir]["name"] + "打开了。\n", this_object());
	else if( objectp(ob = find_object(exits[dir])) ) {
		if( !ob->open_door(doors[dir]["other_side_dir"], 1) ) return 0;
	}

	doors[dir]["status"] &= (!DOOR_CLOSED);
	return 1;
}

varargs int close_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;

	if( !mapp(doors) || undefinedp(doors[dir]) )
		return notify_fail("这个方向没有门。\n");

	if( (doors[dir]["status"] & DOOR_CLOSED) )
		return notify_fail( doors[dir]["name"] + "已经是关着的了。\n");

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: close_door: attempt to open a door with out an exit.\n");

	if( from_other_side )
		message("vision", "有人从另一边将" + doors[dir]["name"] + "关上了。\n", this_object());
	else if( objectp(ob = find_object(exits[dir])) ) {
		if( !ob->close_door(doors[dir]["other_side_dir"], 1) ) return 0;
	}

	doors[dir]["status"] |= DOOR_CLOSED;
	return 1;
}

int check_door(string dir, mapping door)
{
	// If we have no responding door, assume it is correct.
	if( !mapp(doors) || undefinedp(doors[dir]) ) return 1;

	door["status"] = doors[dir]["status"];
	return 1;
}

varargs void create_door(string dir, mixed data, string other_side_dir, int status)
{
	mapping d, exits, item_desc;
	object ob;

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: create_door: attempt to create a door without exit.\n");

	// Compact mode.
	if( stringp(data) ) {
		d = allocate_mapping(4);
		d["name"] = data;
		d["id"] = ({ dir, data, "door" });
		d["other_side_dir"] = other_side_dir;
		d["status"] = status;
	} else if( mapp(data) )
		d = data;
	else
		error("Create_door: Invalid door data, string or mapping expected.\n");

	set("item_desc/" + dir, (: look_door, dir :) );

	if( objectp(ob = find_object(exits[dir])) ) {
		if( !ob->check_door(other_side_dir, d) )
			return;
	}

	if( !mapp(doors) ) doors = ([ dir: d ]);
	else doors[dir] = d;
}

mapping query_doors() { return doors; }

mixed query_door(string dir, string prop)
{
	if( !mapp(doors) || undefinedp(doors[dir]) ) return 0;
	else return doors[dir][prop];
}

int valid_leave(object me, string dir)
{
	if( mapp(doors) && !undefinedp(doors[dir]) ) {
		if( doors[dir]["status"] & DOOR_CLOSED )
			return notify_fail("你必须先把"  + doors[dir]["name"] + "打开！\n");
                // if ( door[dir]["status"] & DOOR_HAS_TRAP ) ....
        }
        return 1;
}

void setup()
{
        seteuid(getuid());
        this_object()->reset();
}
