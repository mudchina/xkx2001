// Room: /d/wizard/wizard_room.c
//Change by Server (7/26/2001)
inherit ROOM;

void create()
{
	set("short", "巫师休息室");
	set("long", @LONG
这里就是游戏中巫师们休息的所在。屋子布置的清雅别致，四周墙壁上悬挂
着名家字画，几把紫檀木椅放在窗边，在这里四处眺望可以看到游戏中的场景。
离门不远的桌子上摆放着一本巫师留言簿(board)。
LONG );

	set("exits", ([
        "down" : __DIR__"guest_room" ]));

	set("valid_startroom", 1);
	set("no_fight", "1");
	set("no_clean_up", 0);
	set("cost", 0);
	setup();

	call_other("/clone/board/wiz_b", "???");
//	replace_program(ROOM);
}

void init()
{
	object me = this_player();

	if (wizhood(me) == "(player)")
		me->move("/d/death/death.c");
}
