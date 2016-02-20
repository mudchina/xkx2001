//Cracked by Roath
// xiakedao/chuan.c
// modified by aln 5 / 98
// fixed bug, sdong, 10/30/98
// Modified by xQin to forbid the use of sheyao bug, 7/00

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "小船");
        set("long", @LONG
这是一艘不大的小船，勉勉强强可以容下几个人。浪花击打之下，
吱呀作响，似乎便要倾覆。船头支起一张黄色的三角帆，吃着缓缓的
北风前进。
LONG );

      set("exits", ([
		"out" : __DIR__"shatan",
      ]));
	set("invalid_startroom", 1);
	set("no_fight", 1);
	set("outdoors", "xiakedao" );
	setup();
//      replace_program(ROOM);

}
int valid_leave(object me, string dir)
{	object money;
	object ling1, ling2;
	object *inv;
        int found, i;
 //       if ( present(this_player()) || found )
//        return notify_fail("你不能背其它玩家出岛。\n");
        if ( present("she yao", me) || found ) 
	return notify_fail("为了身体着想，还是快把蛇药服用了再上路吧。\n");
	
	if (query("exits/out")=="/d/xiakedao/shatan3")
	{	write ("你正要下船，船家塞了点东西在你手中，你一看原来是些银子和两块
令牌。你忙向船家道了声谢，挥了挥手，然後从小船上跳到沙滩上。\n");
//				money = new("/clone/money/silver");
//				money->set_amount(20);
//				money->move(me);
		ling1 = new("/d/xiakedao/obj/fa-ling.c");
		ling2 = new("/d/xiakedao/obj/shan-ling.c");
		ling1->move(me);
		ling2->move(me);
		ling1->set("long",
"这是一块铁牌，牌的一面是一个苦脸，另一面刻着“" + me->query("name") + "”\n");
		ling1->set("owner", me->query("id"));
		ling2->set("long",
"这是一块铁牌，牌的一面是一个笑脸，另一面刻着“" + me->query("name") + "”\n");
		ling2->set("owner", me->query("id"));
		me->set("xkd/set", 0);   
	}

	 return ::valid_leave(me, dir);
}
