//Cracked by Roath
// Room: xiaozhu.c 华山小筑
// qfy July 25, 1996.

inherit ROOM;

void create()
{
    set("short", "华山小筑");
    set("long", @LONG
华山小筑是华山两位长老的避世居所。摆设简单，却清雅自然。小筑
外有个小池塘，几只鹤有的在池塘边飞舞，有的站在池塘边歇息。两位长
老不喜欢外人打扰，当今华山掌门也甚少到访。
LONG
    );

    set("exits", ([
	"east" : __DIR__"xiaolu2",
    ]));

    set("objects", ([
	CLASS_D("huashan") + "/gaolao" : 1,
	CLASS_D("huashan") + "/ailao" : 1,
    ]));

    set("no_clean_up", 0);

    set("cost", 0);
    setup();
    //replace_program(ROOM);
}

void init()
{
	object me = this_player();

   	if ( interactive(me) && me->query("huashan/job_pending") ) {
		me->set_temp("hz_job/xiaozhu", 1);
   	}
}
