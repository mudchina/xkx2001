//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "涵碧峰");
	set("long", @LONG
涵碧峰实际上是一块硕大无朋的太湖石峰，高四丈有余，因为特别适合青苔生长，
通体碧绿，故而得名“涵碧”。据传说，这是花石纲遗物中的上品，比起苏州名闻天
下的瑞云峰和狮子峰来有过之而无不及，原址本在苏州，因黄药师夫人冯氏原籍苏州，
黄药师才费偌大心力，将之移往桃花岛，使夫人不致有僻处海外之感。
LONG
	);
	 set("exits", ([
                "south" : __DIR__"songlin3",
                "northeast" : __DIR__"bibochi",
        ]));

/*
        set("objects", ([
                "/d/taohua/npc/shagu" : 1,
        ]));
*/
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}

/*
int valid_leave(object me, string dir)
{

        if( (me->query("family/master_name") != "程英")
        && (me->query("family/master_name") != "黄药师")
        && (!me->query_temp("shagu_pass"))
        && present("sha gu", this_object()) )
        return notify_fail("\n傻姑傻笑了几声，伸开双手一拦，说到：要进去先陪我玩一会儿吧，这里人都不理我，闷死了！\n");

        return ::valid_leave(me, dir);
}
*/
