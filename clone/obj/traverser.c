//Cracked by Roath
// author: chu@xkx
// name: route.c
// date: 5/8/98

#define MAX_NODE 2048
#define MAPDB "/clone/obj/mapdb"
#define QUEUE "/clone/obj/queue"

static int total, current_total;
static object queue;
static int traverse_done;
static mapping visited;
static object mapdb;
int visit(string room, mapping info, mixed args);

#define DEBUG 
// #define DEBUG printf

void create()
{
    queue = 0;
    traverse_done = 0;
}

int traverse_finish()
{
    return traverse_done;
}

mixed thread_route(string room)
{
    mixed route;
    mapping info;
    string cur;
    int   i, n;

    if (! traverse_done) return 0;
    info = visited[room];
    if (! mapp(info)) return 1;	 // no route

    n = info["dist"]+1;
    route = allocate(n);
    cur = room;
    for (i=n-1; i>=0; i--) {
        route[i]=([cur : visited[cur]]);
	info = visited[cur];
	if (! mapp(info)) return 0;	// problem
	cur = info["from"];
    }
    return route;
}

int push_in(mapping exits, string room, function callback, mixed args)
{
    string *dirs, key, err;
    string next_room;
    mapping info;
    int     i;

    dirs = keys(exits);
    if (sizeof(dirs) == 0) return 0;
    for (i=0; i<sizeof(dirs); i++) {
	key = dirs[i];
	next_room = exits[key];
	if (mapp(visited[next_room])) continue;
	if (!mapp(mapdb->query_room_info(next_room))) continue;

	// we found a new one
	total ++;
	current_total ++;

    	info = ([ "from": room, "dir" : key, "dist": visited[room]["dist"]+1]);
	visited[next_room] = info;
	switch (evaluate(callback, next_room, info, 
			 mapdb->query_room_info(next_room), args)) {
	case 0:       // normal, enque this room
	  queue->enque(next_room);
	  break;
	case 1:       // ignore.  Don't enque this room
	  break;
	default:      // abort or done.  Let's finish it.
	  return 1;
	}
    }
    return 0;
}

mixed enque_exits(string room, function callback, mixed args)
{
    mapping exits;

    exits = mapdb->query_room_exits(room);
    if (mapp(exits)) {
	return push_in(exits, room, callback, args);
    }
    return 0;
}

int traverse_with_limit(string from, function callback, mixed args)
{
    string cur;
    int    ret;

    if (! objectp(queue)) return 0;
    if (traverse_done) return 0;

    current_total = 0;
    DEBUG("Traversing map, nodes evaluated: %d.\n", total);
    while (!queue->empty()) {
	if (current_total > MAX_NODE) {	// limit number of nodes we search each time
	    current_total = 0;
	    call_out("traverse_with_limit", 2, from, args);
	    traverse_done = 0;
	    DEBUG("nodes evaluated: %d, rest...\n", total);
	    return 0;
	}
        cur = (string)queue->deque();
	// DEBUG("checking "+cur+"\n");
	ret = enque_exits(cur, callback, args);
	if (ret) {
	    destruct(queue);
	    queue = 0;
	    traverse_done = 1;
	    DEBUG("Traversal terminated by callback, evaluated %d nodes.\n", 
		  total);
	    return ret;
	}
    }
    destruct(queue);
    queue = 0;
    traverse_done = 1;

    DEBUG("Traversal done by exhausted all %d nodes.\n", total);
    return 1;
}

int traverse(string from, function callback, mixed args)
{
    if (objectp(queue)) return 0;  // synchronization, avoid race conditions 

    seteuid(getuid());

    if (!objectp(mapdb)) {
	mapdb = find_object(MAPDB);
	if (! objectp(mapdb))	  mapdb = new(MAPDB);
	if (! objectp(mapdb)) 	  return -1;
    }

    mapdb->restore();
    total = 0;
    traverse_done = 0;
    visited = ([ ]);
    visited[from]=(["dist":0]);

    if (evaluate(callback, from, visited[from], 
		 mapdb->query_room_info(from),
		 args) == -1) {
      traverse_done = 1;
      return 1;
    }
    queue = new (QUEUE);
    queue->enque(from);

    return traverse_with_limit(from, callback, args);
}

// The method visit() is the key to customize the traverser.
// This specific example is to find the shortest path 
int visit_room(string room, mapping info, mapping mapdb_info, mixed args)
{
  string to = (string)args;
  if (room == to) return -1;   // found room, done
  return 0;      // otherwise, keep going
}

int find_route(string from, string to)
{
  return traverse(from, (: visit_room :), to);
}

