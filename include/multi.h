//Cracked by Roath
#ifndef __MULTI__
#define __MULTI__

void load_parts();
object make_part(string file, string id);

varargs int is_ancestor(object ob, string id);
object *find_offsprings(string id);
int is_parent(object ob);
object find_owner();
object *find_relatives(string id);
object *all_offsprings();
object *all_relatives();
int m_find(string id);

mixed *m_set(string prop, mixed data, string id);
varargs mixed m_query(string prop, string id, int raw);
int *m_delete(string prop, string id);
mixed m_add(string prop, mixed data, string id);
mapping *m_query_entire_dbase(string id);

mixed m_set_temp(string prop, mixed data, string id);
varargs mixed m_query_temp(string prop, string id, int raw);
int *m_delete_temp(string prop, string id);
mixed m_add_temp(string prop, mixed data, string id);
mapping *m_query_entire_temp_dbase(string id);

varargs int m_move(mixed dest, int order);
object *m_all_inv();
object *m_deep_inv();

varargs int m_remove(string id, int amount);
varargs int m_load(string owner, string id, int order);
#endif
