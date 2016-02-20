//Cracked by Roath
// bboard.c

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

void tune_channels();
void open_channels();

void setup()
{
	string loc;
		
	if( stringp(loc = query("location")) )
		move(loc);
	set("no_get", 1);
	restore();
}

void init()
{
	add_action("do_post", "post");
	add_action("do_read", "read");
	add_action("do_discard", "discard");
	add_action("do_store", "store");
	add_action("do_list","list");
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}

string short()
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return ::short() + " [ 没有任何留言 ]";

	if( this_player() ) {
		last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		return sprintf("%s [ %d 张留言，%d 张未读 ]", ::short(), sizeof(notes), unread);
	else
		return sprintf("%s [ %d 张留言 ]", ::short(), sizeof(notes));
}

string long()
{
	mapping *notes;
	int i, last_time_read;
	string msg, myid;

	notes = query("notes");
	msg = query("long");
	msg = msg + query("name") +"的使用方法请见 help board。\n";
	return msg;
}

int do_list()
{
        mapping *notes;
        int i, last_time_read;
        string msg, myid;

        notes = query("notes");
        msg = query("long");

	if( !pointerp(notes) || !sizeof(notes) ) 
                return notify_fail(msg+query("name")+"上目前没有任何留言。\n");
	msg += query("name")+"上现有下列留言：\n————————————————————————\n";
	last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
	for(i=0; i<sizeof(notes); i++)
		msg += sprintf("%s[%2d]" NOR "  %-40s %12s (%s)\n",
			( notes[i]["time"] > last_time_read ? HIY: ""),
			i+1, notes[i]["title"], notes[i]["author"], ctime(notes[i]["time"])[0..15] );
	this_player()->start_more( msg);
	return 1;

}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, string text)
{
	mapping *notes;

	note["msg"] = text;
	note["time"] = time();
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	// Truncate the notes if maximum capacity exceeded.
	if( sizeof(notes) > BOARD_CAPACITY )
		notes = notes[BOARD_CAPACITY / 4 .. BOARD_CAPACITY];

	set("notes", notes);
	tell_object(me, "留言完毕。\n");

	open_channels();
	save();
	return;
}

int do_post(string arg)
{
	int i, j=0;
	mapping note;
	string poster_lvl, family;
	object the_player;
	mapping fam;

	the_player = this_player();	
	poster_lvl = query("poster_level");
	
	if(!stringp(poster_lvl))
		poster_lvl = "(player)";

	for(i=0; i<sizeof(query("notes")); i++){
		if (the_player->name()+"("+the_player->query("id")+")" == query("notes")[i]["author"]) 
		j++;}

	if(j>=10 && !wizardp(the_player)) return notify_fail("对不起，你的留言已超过十篇，请删掉前面的再POST新的。\n");

//	write("Board Restricted to " + poster_lvl + " and above.\n");

	if ( (int)SECURITY_D->cmp_wiz_level(the_player, poster_lvl ) < 0 )
		return notify_fail("本板不接受你的投稿。\n");

	family = query("poster_family");
	fam = the_player->query("family");

//	write("Board Restricted to " + family + " players only.\n");

	if ( stringp(family)
		&& (int)SECURITY_D->cmp_wiz_level(the_player, "(immortal)" ) < 0
		&& ( !mapp( fam ) || fam["family_name"] != family ) )
		return notify_fail("非本派弟子不得向本板乱涂乱写。\n");

	if(!arg) return notify_fail("留言请指定一个标题。\n");
	
	note = allocate_mapping(4);
	note["title"] = arg;
	note["author"] = the_player->name()+"("+the_player->query("id")+")";
	tune_channels();
	the_player->edit( (: done_post, the_player, note :) );
	return 1;
}

int do_read(string arg)
{
	int num, arc;
	mapping *notes, last_read_time;
	string myid;
	object the_player;
	string family;
	mapping fam;

	the_player = this_player();	

	last_read_time = the_player->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");
//dts
	arc = query("wizard_only");
	if ( arc
		&& (int)SECURITY_D->cmp_wiz_level(the_player, "(immortal)" ) < 0)
		return notify_fail("内部通讯不得窥视。\n");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("留言板上目前没有任何留言。\n");

	family = query("poster_family");
	fam = the_player->query("family");

//	write("Board Restricted to " + family + " players only.\n");

	if ( stringp(family)
		&& (int)SECURITY_D->cmp_wiz_level(the_player, "(immortal)" ) < 0
		&& ( !mapp( fam ) || fam["family_name"] != family ) )
		return notify_fail("非本派弟子不得窥视本派内部通讯。\n");

	if( !arg ) return notify_fail("指令格式：read <留言编号>|new|next\n");
	if( arg=="new" || arg=="next" ) {
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else {
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;
		}
			
	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("你要读第几张留言？\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("没有这张留言。\n");
	num--;
	tune_channels();
	the_player->start_more( sprintf(
"[%d] %-40s %s(%s)\n----------------------------------------------------------------------\n",
		num + 1, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9])
		+ notes[num]["msg"] );
	open_channels();
	
	// Keep track which post we were reading last time.
	if( !mapp(last_read_time) )
		the_player->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else 
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];

	return 1;
}


int do_discard(string arg)
{
	mapping *notes;
	int num;

	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("指令格式：discard <留言编号>\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("没有这张留言。\n");
	num--;
	if( notes[num]["author"] != (string)this_player(1)->name()+"("+this_player(1)->query("id")+")"
	&&  ( (int)SECURITY_D->cmp_wiz_level(this_player(), "(caretaker)") < 0 ) )
		return notify_fail("这个留言不是你写的。\n");

	notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
	set("notes", notes);
	save();
	write("删除第 " + (num+1) + " 号留言....Ok。\n");
	return 1;
}

void tune_channels()
{
	string *tuned_ch;
	object me;
	
	me = this_player();
	
	tuned_ch = me->query("channels");
	me->set_temp("tuned_ch", tuned_ch);
	me->set("channels", 0);
}
 
void open_channels()
{
	string *tuned_ch;
	object me;
	
	me = this_player();
	               
	tuned_ch = me->query_temp("tuned_ch");
	me->set("channels", tuned_ch);
	me->set_temp("tuned_ch", 0);
}                             

int do_store(string arg)
{
	int num, numb;
	mapping *notes, last_read_time;
	string myid, fmonth, fyear, filename;
	int arc;
	object me=this_player();
	
	arc = query("wizard_only");
	seteuid(getuid()); /* yzc */

	last_read_time = this_player()->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("留言板上目前没有任何留言。\n");

//	if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)" 
//	&&      (string)SECURITY_D->get_status(this_player(1)) != "(arch)"
//	&&      (string)SECURITY_D->get_status(this_player(1)) != "(wizard)")
//		return notify_fail("你不能收编“侠客行”文摘。\n");

	if( !arg ) return notify_fail("指令格式：store <留言编号>\n");

	if( !sscanf(arg, "%d", num) )
		return notify_fail("你要收编第几张留言？\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("没有这张留言。\n");
	num--;
	if( notes[num]["stored"] ) 
		return notify_fail("这张留言已经被收录了。\n记录显示："+notes[num]["stored"]+"\n");

	fyear  = ctime(notes[num]["time"])[20..23];
	fmonth = ctime(notes[num]["time"])[4..6];
//	fmonth = lower_case( ctime(notes[num]["time"])[4..6] );
//	write( "FILENAME +" + fext );

	numb = EDITOR_D->get_file_num(arc, fyear, fmonth) + 1;

	filename = sprintf("%s/%s/%03d", fyear, fmonth, numb);	

	if (arc)
	write( "ARC: writing ..." + filename + "\n" );
	else
	write( "WEN: writing ..." + filename + "\n" );
	
	EDITOR_D->add(arc, "※※※※※※※※※※※※※※【“侠客行”文选】"+
		"※※※※※※※※※※※※※※", filename);
	EDITOR_D->add(arc, sprintf("№%03d  %-40s  %12s(%s)",
		numb, notes[num]["title"],
		notes[num]["author"],
		ctime(notes[num]["time"])[0..9]), filename );
	EDITOR_D->add(arc, notes[num]["msg"], filename);
	EDITOR_D->add(arc, "〖本篇完〗", filename);

/* index */
	filename = sprintf("%s/wenxuan.%s", fyear, fmonth);	

	if (arc)
	write( "ARC: writing ..." + filename + "\n" );
	else
	write( "WEN: writing ..." + filename + "\n" );

	if ( numb == 1)
	{
EDITOR_D->add(arc,
"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n" +
"                    【侠客行文选" + fyear +"年第 " + fmonth + " 卷目录】\n" +
"编号   题目                                              作者(发稿日期)\n"+
"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※",
	filename);
	}

	if (EDITOR_D->add(arc, sprintf("№%03d  %-40s  %12s(%s)",
		numb, notes[num]["title"],
		notes[num]["author"],
		ctime(notes[num]["time"])[0..9]), filename )) {
		write( notes[num]["stored"] = sprintf("【“侠客行”文选】第 %d 篇收入 %s 卷，第 %03d 篇。\n",
			num+1, fmonth, numb) );
		log_file("wenxuan",sprintf("%s%s(%s)收入【“侠客行”文选】第 %d 篇收入 %s 卷，第 %03d 篇。\n",
                        ctime(time()),me->query("name"),me->query("id"),num+1, fmonth, numb) );
		set("notes", notes);
	} else
		write( sprintf("【“侠客行”文选】第 %d 篇收编失败。\n", num+1) );

	return 1;
}
