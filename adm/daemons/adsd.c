//Cracked by Kafei
// adsd.c
#define TIME_TICK (time()*60)


static int current_ads_phase;
mapping *ads_phase;

mapping *read_table(string file);
void init_ads_phase();

void create()
{
	ads_phase = read_table("/adm/etc/ads_phase");
	init_ads_phase();
}

void init_ads_phase()
{
	mixed *local;
	int i, t;

	// Get minutes of today.
	local = localtime(TIME_TICK);
	t = local[2] * 60 + local[1];		// hour * 60 + minutes

	// Find the ads phase for now.
	for( i=0; i < sizeof(ads_phase); i++)
		if( t >= ads_phase[i]["length"] )
			t -= (int)ads_phase[i]["length"];
		else
			break;

	current_ads_phase = (i==0? sizeof(ads_phase)-1: i - 1);

	call_out("update_ads_phase",
		(int)ads_phase[(current_ads_phase+1) % sizeof(ads_phase)]["length"] - t);
}

void update_ads_phase()
{
	int i;
	int ads_count = 0;
	object* all;
	
	remove_call_out("update_ads_phase");
	
	if(current_ads_phase==0) 
	{
       		init_ads_phase();
   	}

	current_ads_phase = (++current_ads_phase) % sizeof(ads_phase);
	
	message("channel:ads", "【广告】" + ads_phase[current_ads_phase]["time_msg"] + "\n", users());
	
	all = users();
	for(i=0;i<sizeof(all);i++) {
		if( member_array("ads", all[i]->query("channels"))==-1 ) continue;
		else ads_count++;
	}
	
	if(ads_count >=1) {
	//	message( "channel:wiz", sprintf("【巫师】%d 个玩家接收此广告。\n", ads_count), users());
		log_file("ADS", sprintf("[%s] \"" + ads_phase[current_ads_phase]["time_msg"] + "\" 被 [%d] 个玩家接收\n", 
		ctime(time()),	ads_count));
	}

	this_object()->event_common();

       	call_out("update_ads_phase", ads_phase[current_ads_phase]["length"]);
}

// This function is to read a regular type of data table for ads_phase and etc.
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


mapping *query_ads_phase() { return ads_phase; }
