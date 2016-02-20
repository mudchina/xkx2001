//Cracked by Roath
// maco

#include <ansi.h>

inherit ITEM;

int arriving();
void arrive();
void close_passage();
string look_lake();
string day_event(){return NATURE_D->outdoor_room_event();}

void create()
{
	set("short", "渡船");
	set("long", @LONG
这是归云庄来往太湖(lake)的一叶扁舟。离岸渐远，四望空阔
，真是莫知天地之在湖海，抑惑是湖海之在天地。
LONG
	);

	set_weight(3000000);
	set_max_encumbrance(5000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "艘");
		set("water_name", "湖");
		set("invalid_startroom",1);
		set("outdoors", "shaolin");
		set("item_desc", ([
			"lake" : (: look_lake :),
		]));

		set("cost", 2);
	}
	setup();
}

string look_lake()
{
	string desc;
	object *boat;

	if( day_event() == "event_night" || day_event() == "event_midnight")
	desc = WHT"放眼望去，繁星在天，薄雾笼湖，阵阵凉风自背後吹来，甚是畅快。\n"NOR;
	else if( day_event() == "event_dawn" )
	desc = HIY"这时天已大明，日光自东射来，水波晃动，犹如万道金蛇在船边飞舞一般。\n"NOR;
	else if( day_event() == "event_evening" )
	desc = HIM"放眼但见暮霭苍苍，烟波浩淼，夕阳橙黄，晚霞桃红，真像是一幅水墨山水一般。\n"NOR;
	else  desc = HIG"放眼但见山青水绿，天蓝云苍，一阵轻风吹来，水波泊泊泊的打在船头。\n"NOR;
	boat = filter_array(children(base_name(this_object())), (: clonep :));
	if (sizeof(boat) > 8)
		desc += "只见湖面上一排排的全是小船，放眼望去，舟似蚁聚，不计其数，"
		"犹如一张大绿纸上溅满墨点一般。\n";
	else if (sizeof(boat) > 1)
		desc += "湖面上帆影点点，你随手点数，来往归云庄水路的便有"+chinese_number(sizeof(boat))+"、"+chinese_number(sizeof(boat)+1)+"艘小船。\n";
	else desc += "湖面上帆影点点，不过来往归云庄水路的船祗，似乎就祗有这一两艘。\n";

	return desc;
}

int is_container() { return 1; }

/*
void init()
{
	remove_call_out("auto_clean_up");
	call_out("auto_clean_up",60);
}
*/

int auto_clean_up()
{
	object *inv, room, exit;
	string dest, msg;
	int i, k = 0;
	room = this_object();
	exit = load_object(query("exits/out"));

	inv = all_inventory(room);

	if( room->query("exits/out") ) {

		for(i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("race") == "人类" )
				msg = "请";
			else msg = "赶";

			if( inv[i]->is_character() ) {
				tell_object(inv[i], "船夫向你说道：“"+ RANK_D->query_respect(inv[i]) +"，已经到岸了，请下船罢！\n");
				message_vision("船夫把$N"+msg+"下了渡船。\n", inv[i]);
				inv[i]->move(exit);
				if( inv[i]->query("race") == "人类" ) message("vision", inv[i]->name()+"从船上走了下来。\n", exit, inv[i]);
				else message( "vision", inv[i]->name() + inv[i]->query("comein_message") , environment(inv[i]), inv[i] );

			}
		}
		destruct(room);
	}

	for(i=0; i<sizeof(inv); i++) {
		if(userp(inv[i]))
		k++;
	}
	if ( k > 0 || !inv ) {
		remove_call_out("auto_clean_up");
		call_out("auto_clean_up", 20);
	}
	else destruct(room); 

	return 1;
}

int arriving()
{
	add_action("do_anchor", "anchor");
	add_action("do_anchor", "tingbo");

	call_out("auto_clean_up", 40);
	call_out("arrive", 20);
}

void arrive()
{
	object boat = this_object();

	message("vision", "船夫扳桨划船，在湖中行了数里，缓缓停泊在岸边，将一块踏脚板搭上了堤岸。\n", boat );

	boat->set("exits/out", this_object()->query_temp("opp"));

//	remove_call_out("close_passage");
//	call_out("close_passage", 20);
}

void close_passage()
{
	object *inv, boat = this_object();

	boat->delete("exits/out");
	message("vision", "船夫把踏脚板收起来，把扁舟驶向湖心。\n", this_object());
	boat->delete("yell_trigger");
	inv = all_inventory(boat);
	if (sizeof(inv) < 1) 
	destruct(boat);
	else call_out("auto_clean_up",60);
}

int valid_leave(object me, string dir)
{
	return 1; 
}

int do_anchor(string arg)
{
	object me, boat;
	string dir;

	me = this_player();
	boat = this_object();

	if( arg ) return 0;

	if( boat->query("exits/out") )
		return notify_fail("船已经靠岸了。\n");

	message_vision("$N向船夫催问：“船家，还没到岸吗？”\n", me);

	if( time() - query("sail_time") < 10 ) {
		message_vision("船夫瞄了$N一眼，说道：“"+ RANK_D->query_respect(me) +"，咱们才刚离岸哪！”\n", me);
	}

	else if( time() - query("sail_time") < 30 ) {
		message("vision", "船夫悠哉悠哉地扳着桨，一边答着：“"+ RANK_D->query_respect(me) +"别急哪，就快到了！”\n", boat );
	}

	else {
		message("vision", "船夫扳着桨，答道：“哪，这不就到了麽？”\n", boat );
		message("vision", "船夫将船缓缓停泊在岸边，将一块踏脚板搭上了堤岸。\n", boat );
		boat->set("exits/out", this_object()->query_temp("opp"));
	}

	return 1;
}
