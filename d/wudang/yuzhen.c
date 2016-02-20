//Cracked by Roath
// yuzhen.c 武当遇真宫
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "遇真宫");
	set("long", @LONG
	这里是进入武当山的第一道宫宇遇真宫，宽敞无比，可容千人食宿，
是进香客的一大歇脚处。宫中供着张三丰真人像。由于张真人闭关已久，外人
不知其是否仍在人间，民间传说他已得道仙逝，立像膜拜。
LONG
	);
	
    set("indoors", "wudang");

	set("exits", ([
		"southup" : __DIR__"bailin",
		"northdown" : __DIR__"shijie1",
	]));
	
	set("objects", ([
		CLASS_D("wudang")+"/zhixiang" : 1 ]));
		
	set("cost", 3);
	setup();
}


int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");


    if ( dir == "southup" && me->query("wudang/offerring") < me->query("age")
	&& me->query("title") != "武当道童"
	&& me->query("family/family_name") != "武当派"
        && objectp(present("zhixiang daozhang", environment(me)))
        && !objectp(present("incense", me)) )
    {
        return notify_fail("制香道长喝道：如不是上山敬香，即刻请回！\n");
    }
    

    return ::valid_leave(me, dir);
}

