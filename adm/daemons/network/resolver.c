//Cracked by Kafei
// rcsid = "$Header: /weaver2/archive/mudlib/single/resolver.c,v 1.1 1995/04/29 02:08:34 garnett Exp $"

// object: resolver daemon
// author: John Garnett
// date:   1995/04/28

// todo: implement culling so that the cache doesn't grow too large.


mapping cache;
mapping callbacks;

void
create()
{
	cache = ([]);
	callbacks = ([]);
}

mixed query_cache(string addr, string callback)
{
	int tag;
	string result;

	if (undefinedp(result = cache[addr])) {
		tag = resolve(addr, "resolve_callback");
		callbacks[tag] = ([
		  "client" : previous_object(),
		  "callback" : callback
		]);
		return tag;
	} else {
		return result;
	}
}

void resolve_callback(string name, string addr, int tag)
{
	object client;

	if (stringp(addr) && stringp(name)) {
		cache[addr] = name;
	}
  if(tag==-1) log_file("resolver","Detected failed tag of -1\n");
	client = callbacks[tag]["client"];
	if (client) {
		call_other(client, callbacks[tag]["callback"], name, addr, tag);
	}
	map_delete(callbacks, tag);
}
