//Cracked by Roath
// yideng quest room, small boat

inherit ROOM;
void create()
{
	set("short", "小船");
	set("long", @LONG
你坐在一条小船里，扳动铁桨用力划着，正在瀑布前的湍急水流中逆水而上。
LONG);
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoor","dali");
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
}
void init()
{
	object me;
	me=this_player();
	remove_call_out("moveon");
	call_out("moveon", 10, me);
}
void moveon(object me)
{
	tell_object(me, "你用力划了一会儿，小船到了水流浅缓的溪流，你靠岸下船。\n");
	me->move("/d/dali/yideng4.c");
}
