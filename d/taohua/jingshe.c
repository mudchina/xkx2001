//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "精舍");
	set("long", @LONG
这座精舍全是以绿色大方竹搭成，屋外攀满青藤，使人一见之下心中顿生凉意。
周围环以奇花异草，闻之足可忘俗。精舍虽看似粗糙，但细观之下，却发觉精舍竟与
四周景物浑然天成，如同自然生成的一般，当真是巧夺天工，好一片清凉洞天。西面
有条小径通向桃花深处。
LONG
	);
	 set("exits", ([
               	"west" : __DIR__"taolin",
                "south" : __DIR__"bibochi",
                "enter" : __DIR__"shuilong",
        ]));

         set("objects", ([
                 "/d/taohua/npc/shagu" : 1,
        ]));

	set("outdoors", "taohua");
	set("cost", 2);

	setup();
        "/clone/board/taohua_b"->foo();
}

int valid_leave(object me, string dir)
{

        if( (me->query("family/master_name") != "程英")
        && (me->query("family/master_name") != "黄药师")
        && (!me->query_temp("shagu_pass"))
	&& (dir == "enter")
        && present("sha gu", this_object()) )
	return notify_fail("\n傻姑傻笑了几声，伸开双手一拦，说到：要进去先陪我玩一会儿吧，\n这里人都不理我，闷死了！\n");
        return ::valid_leave(me, dir);
}
