//Cracked by Roath
// 白玉峰
// maco
#include "localtime.h"
#include <ansi.h>

inherit ROOM;
void sun_light();
void check_turn();
int do_turn(string arg);
int do_move(string arg);
string look_bed();
string look_table();
string day_event(){ return NATURE_D->outdoor_room_event();}

void create()
{
	set("short", "玉室");
	set("long", @LONG
这是一间玉室，一道光线从上面数十丈高处的壁缝里照射进
来，当年建造者依着这道天然光线，在峰中度准位置，开凿而成
。石室中有玉床(bed)、玉桌(table)、玉椅(chair)，都雕刻得
甚是精致，床上斜倚着一具骸骨。石室一角，又有一大一小的两
具骸骨。
LONG
	);

	set("exits", ([
		"east" : __DIR__"jaderoad6",
	]));
	set("item_desc", ([
	"bed" : (: look_bed :),
	"table" : (: look_table :),
	"chair" : "几张由白玉造成的椅子。\n",
	]));
	set("sleep_room", 1);
	set("outdoors","xingxiu");
	set("bamboo", 1);
	set("table_wrong",5+random(6));
	set("cost", 1);
	setup();
}

void init()
{
	add_action("do_turn", "turn");
	add_action("do_move", "move");
	add_action("do_move", "pull");
	add_action("do_move", "push");
	add_action("do_pick", "pick");
}

string look_bed()
{
	string desc;
	if(!query("exits/down")) desc = "一张白玉造成的床，床上斜倚着一具骸骨。\n";
	else desc = "一张白玉造成的床，床上有一个大洞，下面是一道梯级，旁边斜倚着一具骸骨。\n";	
	return desc;
}

string look_table()
{
	string desc, msg;
	int w;
	w = query("table_wrong");
	if(w >= 10) msg = "一尺";
	else if(w > 0) msg = chinese_number(w)+"寸";

	if(wizardp(this_player())) tell_object(this_player(),"现在是"+day_event()+"。\n");
	if (day_event() == "event_morning" || day_event() == "event_afternoon") {
	this_player()->set_temp("checkd_table",1);
	desc = "此时日光对正了玉桌，你走近细看，见玉桌刻着一群背上生翅的飞骆驼，花纹极细，\n日光不正射时全然瞧不出来，刻工甚是精致。\n";
		if(w > 0)
		desc += "然而骆驼的头和身子却并不连在一起，各自离开了"+msg+"多位置。\n";
	}
	else {
	remove_call_out("sun_light");
	call_out("sun_light", 1);
	desc = "这白玉圆桌是整块从玉石中雕刻出来的，连在地上，此外无特异之处。\n";
	}
	return desc;
}
void sun_light()
{
	object room = this_object();

	if(day_event() == "event_morning") {
	message("vision", HIW"过了大半个时辰，日光渐正，射到了圆桌桌面。\n"NOR, room );
	remove_call_out("sun_light");
	}
	else {
	remove_call_out("sun_light");
	call_out("sun_light", 1);
	}
}
int do_turn(string arg)
{
	object me = this_player();
	string dir;

	if (!me->query_temp("checkd_table")) return 0;

	if( !arg || arg=="" ) return 0;

	if( arg=="table") {
		write("你要把白玉圆桌往什麽方向转动？\n");
		return 1;
	}

	if( sscanf(arg, "table %s", dir)==1 ) {
		if (me->is_busy() || me->query_temp("pending/exercising"))
			return notify_fail("你正忙着呢。\n");

		if(me->query_str() < 30)
			return notify_fail("你的臂力太小，扳不动石桌。\n");

		if( dir=="left" ) {
			message_vision("$N拿住圆桌边缘，自右至左一扳，",me);
			add("table_wrong", 1);
			check_turn();
			me->start_busy(random(2));
			return 1;
		}
		if( dir=="right" ) {
			message_vision("$N拿住圆桌边缘，自左至右一扳，",me);
			add("table_wrong", -1);
			check_turn();
			me->start_busy(random(2));
			return 1;
		} else {
			write("你要怎麽转动白玉圆桌？\n");
			return 1;
		}
	}
}

void check_turn()
{
	object me, room;
	int w;
	w = query("table_wrong");
	me = this_player();

	if( w > 0 && query("exits/down")) {
		message_vision("只听轧轧连声，玉床上的地道洞口又合上了。\n",me);
		delete("exits/down");
		if( room = find_object(__DIR__"jaderoad7") ) {
			room->delete("exits/up");
			message("vision", "只听轧轧连声，头顶上的石板又关上了。\n",room );
		}
		return;
	}

	if( w >= 10) {
		message_vision("稍稍可以移动，但扳得寸许便不动了。\n", me );
		set("table_wrong",10);
		return;
	}
	
	if( w < 0 ) {
		message_vision("稍稍可以移动，但扳得寸许便不动了。\n", me );
		delete("table_wrong");
		return;
	}

	if( w < 1) {
		set("exits/down", __DIR__"jaderoad7");
		message_vision("稍稍可以移动。\n",me);
		message_vision(HIW"$N使力慢慢把边缘扳将过去，使得刻在桌缘一圈的骆驼头与刻在桌心的骆驼身子连成一体。\n"
		"刚刚凑合，只听轧轧连声，玉床上出现了一个大洞，下面是一道梯级。\n"NOR,me);
		delete("table_wrong");
		if( room = find_object(__DIR__"jaderoad7") ) {
			room->set("exits/up", __FILE__);
			message("vision", "只听轧轧连声，头顶上的石板慢慢打开了。\n",room );
		}
		remove_call_out("close_bed");
		call_out("close_bed", 10);

	}
	else message_vision("稍稍可以移动。\n",me);

	return;
}

void close_bed()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision", "祗听得轰隆只听轧轧连声，玉床上的地道洞口又合上了。\n", this_object() );
	delete("exits/down");
	set("table_wrong",5+random(6));
	if( room = find_object(__DIR__"jaderoad7") ) {
		room->delete("exits/up");
		message("vision", "只听轧轧连声，头顶上的石板又关上了。\n", room );
	}
}

int do_move(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg == "table") {
	message_vision("$N伸手在圆桌桌面下用力一抬，石桌纹丝不动。不论横推直拉，桌脚始终便如钉牢在地下一般。\n",me);
	return 1;
	}
	return 0;
}

int do_pick(string arg)
{
	object me, where, book;
	
	me = this_player();
	where = environment(me);
	
	if (me->query_kar() < 30 || !query("bamboo") )
	return 0;

	if(arg != "skeleton") {
	write("你要捡什麽？\n");
	return 1;
	}

	book = new("/d/xingxiu/obj/zhujian");

	if(!book) return 0;

	message_vision("$N捡起骸骨，只见骸骨旁有一捆竹简。\n"
	"$N提了起来，穿竹简的皮带已经烂断，竹简一提就散成片片。\n",me);
	CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到了一捆庄子竹简。", me->query("name")));
	delete("bamboo");
	book->move(me);
	return 1;
}
