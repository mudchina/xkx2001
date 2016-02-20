//Cracked by Kafei
// natured.c
// Last modification: Marz added automatically save on 08/27/96
// Cyz added time sychronizition (if it doesnt work, hmm, so be it)
// Fixed natured stuck problem also added garbage cleanup fucntion, sdong, 12/3/99
#define TIME_TICK (time()*60)

static int current_day_phase;
mapping *day_phase;

string *weather_msg = ({
	"天空中万里无云",
	"几朵淡淡的云彩妆点著清朗的天空",
	"白云在天空中飘来飘去",
	"厚厚的云层堆积在天边",
	"天空中乌云密布",
});

mapping *read_table(string file);
void init_day_phase();

void create()
{
	day_phase = read_table("/adm/etc/nature/day_phase");
	init_day_phase();
}

void init_day_phase()
{
	mixed *local;
	int i, t;

	// Get minutes of today.
	local = localtime(TIME_TICK);
	t = local[2] * 60 + local[1];		// hour * 60 + minutes

	// Find the day phase for now.
	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you 
	// changed the time scale, be sure to convert it.

	call_out("update_day_phase",
		(int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
	int synchronize = 0;
	
	remove_call_out("update_day_phase");
	
	if(current_day_phase==0)
	{
       		init_day_phase();
       		synchronize = 1;
   	}

	current_day_phase = (++current_day_phase) % sizeof(day_phase);

        if(! synchronize)
        call_out("update_day_phase", day_phase[current_day_phase]["length"]);

	message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

	this_object()->event_common();

}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

// save player data automatically at sunrise
void event_sunrise()
{
/*	object link_ob, *ob;
	int i;

	ob = users();
	for(i=0; i<sizeof(ob); i++) 
	if( objectp(link_ob = ob[i]->query_temp("link_ob")) )
	{
		link_ob->save();
		ob[i]->save();
	}
*/
	"/u/ryu/mudlist"->main();
}

// check player inventory at turning points of events.
void event_common()
{
	int i, count;
	object *ob;
        object where;
        
	ob=livings();
        i = sizeof(ob);
        while (i--) {
        if(!ob[i]||!objectp(ob[i]))continue;
        where=environment(ob[i]);
        if(!where||!objectp(where)){

        /*
               write(sprintf("Delete %s(%s) for having no environment.\n",ob[i]
->query("id"),file_name(ob[i]) ) );
        */

        if(!userp(ob[i]))destruct(ob[i]);
                else ob[i]->move("/d/city/wumiao.c");
                continue;

        }

        /*
        write(sprintf("%s(%s,%s) in %s(%s)\n",ob[i]->query("name"),ob[i]->query(
"id"),file_name(ob[i]),where->query("short"),file_name(where)
        ));
        */

        }

	ob = users();
//	count = 1+random(sizeof(ob));
	count = sizeof(ob);
	i = random(sizeof(ob));
	
	while (count-- > 0) {
		if( environment(ob[i]) )
		  UPDATE_D->inventory_check(ob[i]);
		i = (i+1) % sizeof(ob);
	}
}

string outdoor_room_description()
{
	return "    " + day_phase[current_day_phase]["desc_msg"] + "。\n";
}

string outdoor_room_event()
{
        return day_phase[current_day_phase]["event_fun"];
}

string game_time()
{
	return CHINESE_D->chinese_date(TIME_TICK);
}

// This function is to read a regular type of data table for day_phase and
// etc.
mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}


mapping *query_day_phase() { return day_phase; }
