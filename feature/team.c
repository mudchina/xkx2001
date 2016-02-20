//Cracked by Roath
// team.c

#include <command.h>
#include <dbase.h>
#include <origin.h>

static object leader, lord, *team;

int set_leader(object ob)
{
	if( ob==this_object() )
		error("set_leader: Cannot set this_object() as leader.\n");
	leader = ob;
}

object query_leader() { return leader; }

int set_lord(object ob)
{
	if( ob==this_object() )
		error("set_lord: Cannot set this_object() as lord.\n");
	lord = ob;
}

object query_lord() { return lord; }

int follow_path(string dir)
{
//	if( ((int)origin()==ORIGIN_LOCAL) || ((int)origin()==ORIGIN_CALL_OUT) ) {
	if (1) {
		this_object()->remove_all_enemy();
		return GO_CMD->main(this_object(), dir);
	}
}

int follow_me(object ob, string dir)
{
	if( !living(this_object()) || ob==this_object() ) return 0;
	if( ob==leader
	||	(query("pursuer") && this_object()->is_killing(ob->query("id")))) {
		if( random(ob->query_skill("move")) > this_object()->query_skill("move") ) {
			remove_call_out("follow_path");
			call_out("follow_path", 1, dir);
			return 1;
		}
		return follow_path(dir);
	}
}

int add_team_member(object ob)
{
	if( ob==this_object() ) return 0;

	if( arrayp(team) ) {
		if( member_array(ob, team)==-1 ) {
			team += ({ ob });
			map_array(team, (: $1->set_team(team) :));
		} else
			return 0;
	} else {
		team = ({ this_object(), ob });
		ob->set_team(team);
	}
	return 1;
}

int join_team(object ob)
{
	object *t;

	if( ob == this_object()
	|| !arrayp(team)
	|| member_array(ob, team) != -1 )
		return 0;

	if( arrayp(t = ob->query_team()) )
		team = t + team;
	else
		team = ({ ob }) + team;
	map_array(team, (: $1->set_team(team) :));
	return 1;
}

int is_team_leader()
{
	if( !arrayp(team) ) return 0;

	team = filter_array(team, (: living :));
	return team[0]==this_object();
}

int have_team_member(object ob)
{
	return arrayp(team) && (member_array(ob, team) != -1);
}

int set_team(object *t)
{
	team = t;
}

varargs int dismiss_team(object ob)
{
	if( !arrayp(team) ) return 0;
	
	if( !ob ) {
		if( this_object()->is_team_leader() )
			map_array(team, (: $1->set_team(0) :));
		else {
			team -= ({ this_object() });
			map_array(team, (: $1->set_team(team) :));
			team = 0;
		}
	} else {
		team -= ({ ob });
		map_array(team, (: $1->set_team(team) :));
		ob->set_team(0);
	}

	return 1;
}

object *query_team()
{
	return team;
}
