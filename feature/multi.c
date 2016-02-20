//Cracked by Roath
//multi.c 
//by cyz&kitten 
//01.22.1999 (1 day past NHL All-Star game)

#include <dbase.h>
#include <multi.h>

/**************************************************************************
void load_parts()
	loads all defined components into parent object
	parts should be defined in parent object as below:
	
	set("components", ([ (object file):(object id) ]))

	this function should be called after the above statement and
	before starting to set any value to components(for obvious reason)	
**************************************************************************/
void load_parts()
{
	mapping ob_list, part_list;
	object ob;
	string *list;
	
	part_list = ([]);
	set("no_clean_up", 0);
	ob_list = query("components");
		
	if( !mapp(ob_list) ) 
		return;
	
	list = keys(ob_list);
	for (int i = 0; i<sizeof(list); i++)
	{
		ob = make_part(ob_list[list[i]], list[i]);
		part_list[list[i]] = ob;
	}
	set("children", part_list);
}

object make_part(string file, string id)
{
	object ob;
	string err;
	
	ob = new(file);

	ob->set("parent", this_object());
	ob->set_name(ob->query("name"), ({id}));	
	ob->m_move(this_object());

	return ob;
}

/*********************************************************************
m_set(), m_query(), m_delete(), m_add(), m_query_entire_dbase(),
m_set_temp(), m_query_temp(), m_delete_temp(), m_add_temp(), 
m_query_entire_temp_dbase()

similiar to functions defined in /feature/dbase.c, last argument is the
id of object which the dbase/temp_dbase is to be changed

find_offsprings() is created for the sole purpose to accomendate
multi functions, it returns the location of all the offsprings of a
parent object.

these functions also works with offspring objects more than 1 level from
this_object()

if there are more than one objects with the same id, all of them will be
processed.
***********************************************************************/
mixed *m_set(string prop, mixed data, string id)
{
	object *obj_list;
	
	obj_list = find_relatives(id);
	return obj_list->set(prop, data);
}

varargs mixed m_query(string prop, string id, int raw)
{
	object *obj_list;
	
	obj_list = find_relatives(id);
	return obj_list->query(prop, raw);
}

int *m_delete(string prop, string id)
{
	object *obj_list;
	
	obj_list = find_relatives(id);
	return obj_list->delete(prop);
}

mixed m_add(string prop, mixed data, string id)
{
	object *obj_list;
	
	obj_list = find_relatives(id);
	return obj_list->add(prop, data);
}

mapping *m_query_entire_dbase(string id)
{
	object *obj_list;
	
	obj_list = find_relatives(id);
	return obj_list->query_entire_dbase();
}

mixed m_set_temp(string prop, mixed data, string id)
{
	object *obj_list;
	
	obj_list = find_relatives(id);
	return obj_list->set_temp(prop, data);
}

varargs mixed m_query_temp(string prop, string id, int raw)
{
	object *obj_list;
	
	obj_list = find_relatives(id);
	return obj_list->query_temp(prop, raw);
}

int *m_delete_temp(string prop, string id)
{
	object *obj_list;
	
	obj_list = find_relatives(id);
	return obj_list->delete_temp(prop);
}

mixed m_add_temp(string prop, mixed data, string id)
{
	object *obj_list;
	
	obj_list = find_relatives(id);
	return obj_list->add_temp(prop, data);
}

mapping *m_query_entire_temp_dbase(string id)
{
	object *obj_list;
	
	obj_list = find_relatives(id);
	return obj_list->query_entire_temp_dbase();
}

/******************************************************************
m_add_action(<dest object>, <function name>, <verb>, <flag>)

similiar to efun add_action(), add local function of "this_object"
to "dest object" as an action of "dest ob".

unlike add_action, m_add_action should be called in create() instead
of init()

flag can only be set to 0 or 1
******************************************************************/
varargs mixed m_add_action(string id, string fun, string verb, int flag)
{
	object *ob, this_ob;
	mixed m_action_map;
	mixed action_arr;

	this_ob = this_object();
	
	action_arr = allocate(3);
	
	if (!flag)
		action_arr[2] = 0;
	else
	{
		action_arr[2] = 1;
	}
		
	action_arr[0] = this_ob;
	action_arr[1] = fun;
	
	m_action_map = allocate_mapping(1);
	m_action_map[verb] = action_arr;
	
	return this_ob->m_add_temp("actions", m_action_map, id);
}

int m_setup_actions()
{
	object ob = this_object();
	mixed m_action_map = ob->query_temp("actions");
	string *verbs;
	int flag;
	
	if (!mapp(m_action_map))
		return 0;
		
	verbs = keys(m_action_map);
	
	for (int i = 0; i<sizeof(m_action_map); i++)
	{
		//if object no longer exists, do not add it to cmd list.
		if (!objectp(m_action_map[verbs[i]][0])) continue;
		
		if (!(flag = m_action_map[verbs[i]][2]))
			add_action("m_parse_action", verbs[i]);
		else
			add_action("m_parse_action", verbs[i], flag);
	}
	return 1;
}

int m_parse_action(string arg)
{
	mixed m_action_map = query_temp("actions");
	mixed val;
	string *verbs;
	int flag;
	
	if (!mapp(m_action_map))
		return 0;
	
	val = m_action_map[query_verb()];
	//if the object no longer exists, action will not be 
	//executed.
	if (!objectp(val[0]))
		return 0;	
	
	return call_other(val[0], val[1], arg);
}

void init()
{
	m_setup_actions();
}

/*******************************************************************
all the find_* and is_* functions are created to establish the inter-
connection between all multiple parts and the main object. so that the 
m_set etc. and m_add_action() functions not only work with their own child 
objects, but with all objects in the whole family.
for detailed description and explanation about purpose, usage, principle
etc. of multi-parts object, please refer to doc/multi.txt(if I write 
one later).
********************************************************************/
varargs int is_ancestor(object ob, string id)
//if this_object is <ob>'s ancestor
{
	int found = 0;
	object obj;
	
	if ((stringp(id)) && (ob->query("id") != id))
	{
		return 0;
	}
	while ((!found) && (objectp(obj = ob->query("parent"))))
	{
		if (obj == this_object())
			found = 1;
		ob = obj;
	}
	
	return found;
}

object *find_offsprings(string id)
//find all offspring objects with <id> of this_object()
{
	object *inv_list;
	object *offspring_list = ({});
	
	inv_list = deep_inventory(this_object());
	offspring_list = filter_array(inv_list, (: is_ancestor :), id);
	return offspring_list;
}

int is_parent(object ob)
//if this_object is <ob>'s ancestor
{
	if (ob->query("parent") == this_object())
		return 1;
	return 0;
}

object find_owner()
{
	object ob, obj;
	
	obj = this_object();
	while (objectp(ob= obj->query("parent")))
	{
		obj = ob;
	}
	return obj;
}

object *find_relatives(string id)
{
	object owner = this_object()->find_owner();
	if (owner->query("id") == id)
	{
		return owner->find_offsprings(id) + ({owner});	
	}
	return owner->find_offsprings(id);
}

object *all_offsprings()
{
	object *inv_list;
	object *offspring_list = ({});
	
	inv_list = deep_inventory(this_object());
	offspring_list = filter_array(inv_list, (: is_ancestor :));
	return offspring_list;
}

object *all_relatives()
{
	object owner = this_object()->find_owner();
	return owner->all_offsprings() + ({owner});	
}

object *all_children()
{
	object *inv_list;
	object *offspring_list = ({});
	
	inv_list = all_inventory(this_object());
	offspring_list = filter_array(inv_list, (: is_ancestor :));
	return offspring_list;
}

int m_find(string id)
{
	return sizeof(find_relatives(id));
}

int m_exists(object owner)
//if a clone of this_object() already exists in <owner>
{
	object *ob_list = owner->all_offsprings();
	
	for (int i = 0; i < sizeof(ob_list); i++)
	{
		if (base_name(ob_list[i]) == base_name(this_object()))
			return 1;
	}
	return 0;
}
/****************************************************************
the current standard move/inventory functions and commands will 
cause error on multi-part objects, such as over-encumbrance, 
inventory/beg/steal/get/drop/put bugs. so functions defined below
is created to solve those problems.
****************************************************************/
varargs int m_move(mixed dest, int order)
{
	object ob;
	//simply move the object, do not add encumbrance, 
	//use it in load_parts()
	if (objectp(dest))
	{
		move_object(dest);
	}else if(stringp(dest))
	{
		if (m_find(dest)<(order + 1))	
		{
			write("cant find destination\n");
			return 0;
		}
		ob = find_relatives(dest)[order];
		if (is_ancestor(ob))
		{
			write("cant move object inside itself\n");
			return 0;
		}
		move_object(find_relatives(dest)[order]);
	}
	return 1;
}

//since all components would also be reported as ancestor object's
//inventory, we should exclude them to get what this_object is 
//really carrying
object *m_all_inv()
{
	object *all_inv_list = all_inventory(this_object());
	object *inv_list = ({});
	
	for (int i = 0; i < sizeof(all_inv_list); i++)
	{
		if (!is_ancestor(all_inv_list[i]))
			inv_list += ({all_inv_list[i]});
	}
	return inv_list;
}

object *m_deep_inv()
{
	object *all_inv_list = deep_inventory(this_object());
	object *inv_list = ({});
	
	for (int i = 0; i < sizeof(all_inv_list); i++)
	{
		if (!is_ancestor(all_inv_list[i]))
			inv_list += ({all_inv_list[i]});
	}
	return inv_list;
}

/***************************************************************
all components are removable
***************************************************************/
varargs int m_remove(string id, int amount)
{
	object owner = find_owner();
	object *obj = owner->find_offsprings(id);
	object me = this_player();
	string msg, str1;
		
	if (!(amount)) amount = 1;
	
	if (sizeof(find_offsprings(id)) < amount)
		amount = sizeof(find_offsprings(id));
	
	if (!amount)	return 0;
		
	obj = obj[0..amount-1];
			
	for (int i = 0; i < amount; i++)
	{
		if (!obj[i]->move(me))
			obj->move(environment(me));
		obj[i]->delete("parent");
		if (!(msg = obj[i]->query("msg_remove")))
			message_vision("$N把" + obj[i]->query("name") +
				"从" + owner->query("name") + "上卸了下来。\n", me);
		else
		{
			str1 = replace_string(msg,  "$m", query("name"));
			str1 = replace_string(str1, "$M", owner->query("name"));
			message_vision(str1, me);
		}
		owner->post_remove(this_object());
	}
	return 1;
}

varargs int m_load(string owner, string id, int order)
{
	object ob;
	object me = this_player();
	object owner_ob = present(owner, me);
	string msg, str1;
	int carr;
		
	if (!owner_ob)
	{
		write("你要把" + query("name") + "装到" + "什么地方？\n");
		return 0;
	}
	
	if (!id) id = owner_ob->query("id");
	
	if (owner_ob->m_find(id) < (order + 1))	
	{
		write("你要把" + query("name") + "装到" + 
			owner_ob->query("name") + "的什么地方去？\n");
		return 0;
	}
	
	if (query("unique") && m_exists(owner_ob))
	{
		write(owner_ob->query("name") + "上已经有一个" +
			query("name") + "，不能再装了。\n");
		return 0;
	}
	
	ob = owner_ob->find_relatives(id)[order];
	if ((carr = ob->query("carribility")) && (carr <= sizeof(ob->all_children())))
	{
		write(owner_ob->query("name") + 
			"的" + ob->query("name") + "已经满了，不能再装了。\n");
		return 0;
	}
	
	if (m_move(ob))
	{
		if (!(msg = query("msg_load")))
		{
			if (owner_ob == ob)
				message_vision("$N把" + query("name") +
				"装到了" + owner_ob->query("name") +"上去。\n", me);
			else
				message_vision("$N把" + query("name") +
					"装到了" + owner_ob->query("name") + "的" + 
					ob->query("name") + "上去。\n", me);
		}
		else
		//wildcard for "msg_load": $N---this_player, $m---name of this object, 
		//$M----name of owner_ob, $D----name of destination part
		{
			str1 = replace_string(msg,  "$m", query("name"));
			str1 = replace_string(str1, "$M", owner_ob->query("name"));
			str1 = replace_string(str1, "$D", ob->query("name"));
			message_vision(str1, me);
		}
		
		set("parent", ob);
		owner_ob->post_load(this_object());
	}
	
	return 1;
}
