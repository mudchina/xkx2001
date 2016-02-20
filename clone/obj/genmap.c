//Cracked by Roath
// map generator
// author: chu@xkx
// name: route.c
// date: 5/9/98

#include <ansi.h>
#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif


// max number of nodes we "reload", since it is really expensive and
// may cause server crash, we try to be very prudent here.
#define MAX_NODE 5 

inherit F_SAVE;

object queue;	 // the queue storing front-end for BFS
int map_ready;   // whether the map has been fully constructed 
mapping map;     // The real map.  see enter_map for its format
object cur_room;
object loading_room;

#define DEBUG
// #define DEBUG printf
#define STATUS printf

void mapit(int);

void create()
{
    seteuid(getuid());

    if (! restore()) {
	save();
    }
}

string query_save_file()
{
    return NPCDATA+"map";
}

string no_suffix(string name)
{
  string ret;
  
  if (name[0] != '/') name="/"+name;
  if (sscanf(name, "%s.c", ret) == 1) return ret;
  return name;
}

mapping find_exits(object room)
{
    mapping exits, rivers, ret;
    string  *dirs, dir, exit, this_room_file;
    int     i;
    // I don't know why I can't include it at the
    // begining of the file, so that these variables
    // are global.  It always says islands is 0  -Chu
#include "/clone/ship/harbor.h"

    rivers=([ ]);
    exits = room->query("exits");
    if (stringp(room->query("boat"))) {
	rivers["cross_river"] = room->query("opposite");
    }
    // connect all the islands
    if (mapp(room->query("navigate"))) {
	this_room_file = base_name(room);
	dirs = keys(islands) + keys(harbors);
  	for (i=0; i<sizeof(dirs); i++) {
	    dir=dirs[i];
	    if (dir != this_room_file)
		rivers["out_sea"+i] = dir;
	}
    }
    if (mapp(exits)) rivers = rivers+exits;

    dirs = keys(rivers);
    ret = ([]);
    for (i=0; i<sizeof(dirs); i++) {
      dir = dirs[i];
      exit = rivers[dir];
      if (stringp(dir) && stringp(exit)) {
	ret[dir] = no_suffix(exit);
      }
    }
    return ret;
}

/*
   format:
   ([ room_path : info ])

   info is another mapping, which contains all the exits of the room
   and the chinese name of the room
   ([ "short" : chinese_name,
      "exits" : <exits map>,
    ])
*/
void enter_map(object room)
{
    string base = base_name(room);
    mapping info = ([ ]);

    info["short"] = room->query("short");
    info["exits"] = find_exits(room);

    if (! mapp(map)) {
	map = ([ base : info ]);
    } else {
	map[base] = info;
    }
}

void start_mapping(int max_node)
{
    object start;
    string *map_home;
    string room_path;
    int    i;
    
    map_ready = 0;
    map = ([ ]);
    queue = new("/u/chu/misc/queue");

    start = find_object("/d/beijing/kedian");
    if (! objectp(start)) {
	start = load_object("/d/beijing/kedian");
    }
    if (! objectp(start)) {
	DEBUG("can't find kedian???\n");
	return;	// kedian is gone?
    }
    queue->enque(start);
    enter_map(start);
    cur_room = 0;
    loading_room = 0;

    if (max_node <= 0) max_node = MAX_NODE;
    DEBUG("start mapping with max_node %d\n", max_node);
    mapit(max_node);
}

void enque_exits(object room)
{
    mapping exits;
    string *dirs, key;
    object next_room;
    int    i;

    exits = find_exits(room);
    if (mapp(exits)) {
	dirs = keys(exits);
	if (sizeof(dirs) == 0) return;
	for (i=0; i<sizeof(dirs); i++) {
	    key = dirs[i];

	    next_room = find_object(exits[key]);
	    if (! next_room) {
		// we are in a crash recovery process and this room
		// didn't load last time.  Now we ignore it.
 	 	if (loading_room && loading_room==exits[key]) {
		    continue;
		}
		// let the room crash us if it is buggy, we will try again.
	        loading_room = exits[key];
		next_room = load_object(exits[key]);
		loading_room = 0;	// succesfully done
	    }
	    if (! objectp(next_room)) continue; 
	    if (map[base_name(next_room)]) continue;  // already in map

	    enter_map(next_room);
	    queue->enque(next_room);
	}
    }
}

int mapit(int max_node)
{
    int    current_total;
    object cr;
    object mapdb;

    if (!queue) return 0;	// make sure we have a queue to use
    if (map_ready) return 0;	// prevent ready-map from being overwritten

    remove_call_out("mapit");
    call_out("mapit", 2, max_node);


    if (objectp(cur_room)) {	// we were crashed last time by a buggy room
	// try again.
	enque_exits(cur_room);
	cur_room = 0;
    }

    current_total = sizeof(map);
    while (!queue->empty()) {
	if (sizeof(map)-current_total > max_node) { // be nice to the server
	    STATUS("mapping %s(%s), map size: %d (from %d).\n", 
		  cr->query("short"), base_name(cr), sizeof(map),
			  current_total);
	    return;
  	}
        cur_room = queue->deque();
	cr=cur_room;
	enque_exits(cur_room);
	cur_room = 0;
    }

    // bravo! we are done!
    destruct(queue);
    queue = 0;
    map_ready = 1;
    save();	

    STATUS("done mapping. map size: %d.\n", sizeof(map));
    // kill old mapdb
    while (objectp(mapdb=find_object("/clone/npc/mapdb"))) {
	destruct(mapdb);
    }
    
    destruct(this_object());
}

