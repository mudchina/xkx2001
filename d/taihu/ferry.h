//Cracked by Roath
// maco 4/6/2000
string day_event(){return NATURE_D->outdoor_room_event();}

void init()
{
	add_action("do_yell", "yell");
}

int do_yell(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg == "boat" ) arg = "船家";

	if( (int)this_player()->query("age") < 16 )
		message_vision("$N使出吃奶的力气喊了一声：“" + 
			arg + "”\n", this_player());
	else if( (int)this_player()->query("neili") > 500 )
		message_vision("$N吸了口气，一声“" + arg + 
			"”，声音中正平和地远远传"
			"了出去。\n", this_player());
	else    message_vision("$N鼓足中气，长啸一声：“" + arg + 
			"！”\n", this_player());

	if( arg == "船家") {		
		check_trigger();
		return 1;
	} else  message_vision("湖面上远远传来一阵回声：“" + arg + "～～～”\n", this_player());

	return 1;
}

void check_trigger()
{
	object room;
	string myboat;

	if( this_object()->query("exits/enter") ) {
		message("vision", "岸边一只渡船上的船夫说道：正等着你呢，上来吧。\n",
			this_object());
		return;
	}

	if( day_event() == "event_midnight" ) {
		message("vision", "可是这时侯夜色已深，湖面上的船家大都歇息了，祗有西边的湖岸还有扁舟往返。\n",
			this_object());
		return;
	}

	if( this_player()->query("family/family_name") != "桃花岛") {
		message("vision", "湖面上的船家来来往往，一无反应……\n",
			this_object());
		return;
	}

	myboat = this_object()->query("boat");
		room = new(myboat);

	room->set("yell_trigger", 1);
	this_object()->set("exits/enter", file_name(room) );
	room->set("exits/out", base_name(this_object()));

	message("vision", "一叶扁舟缓缓地驶了过来，船夫将一块踏脚"
		"板搭上堤岸，以便乘客上下。\n", this_object() );
	message("vision", "船夫将一块踏脚板搭上堤岸，形成一个向上"
		"的阶梯。\n", room);

	remove_call_out("on_board");
	call_out("on_board", 15, room);
}

void on_board(object room)
{
	if( !this_object()->query("exits/enter") ) 
		return;

	message("vision", "船夫收了踏脚板，划桨荡水，一叶扁舟消失在垂柳深处。\n", this_object() );
	room->set("sail_time", time());
	room->delete("exits/out");
	message("vision", "船夫把踏脚板收起来，说了一声“坐稳喽”，"
			"扳桨一划，扁舟向湖心驶去。\n", room );

	this_object()->delete("exits/enter");

	room->arriving();
	room->set_temp("opp", this_object()->query("opposite"));
}
