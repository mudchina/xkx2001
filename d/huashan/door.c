//Cracked by Roath
// door1.c 华山后山小路密室石门前
// qfy 8/11/97

inherit ROOM;

void create()
{
	set("short", "石门前");
	set("long", @LONG
石门(door)紧闭着，看起来似乎相当的厚。门上有两个大石环，各自
嵌在两个精雕的龙头嘴里。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"up" : __DIR__"stair",
	]));

	set("item_desc",([
	    "石门" : "石门上刻着「仗义江湖」四个古篆大字，四周皆是精致的浮雕。\n",
	    "door" : "石门上刻着「仗义江湖」四个古篆大字，四周皆是精致的浮雕。\n",
	]));

	set("cost", 0);
	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_close", "close");
}

int do_open()
{
	object me=this_player();

	if ( query_temp("open") ) {
		write("石门已经是开着的了！\n");
		return 1;
	}

	message_vision("$N运起内功，双掌按在石门上，缓缓往後推去。\n", me);
	message_vision("石门在一阵轰响之後，慢慢地开启了。\n", me);

	set("exits/enter", __DIR__"mishi");
	set("long", "石门敞开着，看起来约有一尺来厚。\n");
	set_temp("open", 1);
	remove_call_out("auto_close");
	call_out("auto_close", 5, this_object());

	return 1;
}

int do_close()
{
	object me=this_player();

	if ( !query_temp("open") ) {
		write("石门已经是关着的了！\n");
		return 1;
	}

	message_vision("$N运起内功，双手抓在石门门环上，缓缓地往前拉。\n", me);
	message_vision("石门在一阵轰响之後，慢慢地关闭了。\n", me);

	set("long", "石门(door)紧闭着，看起来似乎相当的厚。门上有两个大石环，各自\n嵌在两个精雕的龙头嘴里。\n");
	delete("exits/enter");
	delete_temp("open");
	remove_call_out("auto_close");

	return 1;
}

void auto_close(object room)
{
    	if ( room->query_temp("open") ) {
    		message("vision","石门突然发出一阵轰响，自动关闭起来。\n", room);
		set("long", "石门(door)紧闭着，看起来似乎相当的厚。门上有两个大石环，各自\n嵌在两个精雕的龙头嘴里。\n");
    		room->delete("exits/enter");
		room->delete_temp("open");
	}
}	