//Cracked by Roath
// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

inherit ROOM;

void create()
{
	set("short", "树洞下");
	set("long", @LONG
这是老槐树底部，四周光线昏暗，人影晃晃，似乎有几个黑暗的洞口在你
身边，通向四面八方。一位老乞丐大咧咧地坐在正中的地上。不经意中你发现
墙壁上画着幅粗糙的路线草图（map）。
LONG
	);


	set("exits", ([
		"up":__DIR__"inhole",
//              "down":__DIR__"chuchang",
		"1":__DIR__"xcandao1",
		"2":__DIR__"zlandao1",
		"3":__DIR__"slandao1",
		"4":__DIR__"xxandao1",
		"5":__DIR__"wdandao1",
		"6":__DIR__"qzandao1",
		"7":__DIR__"emandao1",
		"8":"/d/qilian/xsandao1",
	]));

	set("item_desc",([ "map" : 
		"出口一：通往华山。\n" +
		"出口二：通往竹林。\n" +
		"出口三：通往少林。\n" +
		"出口四：通往星宿。\n" +
		"出口五：通往武当。\n" +
		"出口六：通往泉州。\n" +
		"出口七：通往峨嵋。\n" +
		"出口八：通往雪山。\n"
	]));

	set("objects",([
		CLASS_D("gaibang") + "/liang" : 1,
	]));

	set("cost", 1);
	setup();
	"/clone/board/gaibang_b"->foo();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	object *inv;
	int found, i;
	
	myfam = (mapping)me->query("family");

	if ( present("liang zhanglao", environment(me)) ) {
	    if ( (!myfam || myfam["family_name"] != "丐帮") && dir != "up" )
		return notify_fail("梁长老挡住了你的去路。\n");

	    inv = all_inventory(me); 
	    for (i=0; i<sizeof(inv); i++) {
	        if ( inv[i]->is_container() && (present("baicao dan", inv[i]) 
	        || present("xionghuang wan", inv[i])) ) found = 1;
	    }

	    if ( present("baicao dan", me) || present("xionghuang wan", me) || found )
		return notify_fail("梁长老挡住了你说道：快把丹药吃下再出去， 免得伤势恶化！\n");
	}
	   
	return ::valid_leave(me, dir);
}
