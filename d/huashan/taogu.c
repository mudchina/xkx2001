//Cracked by Roath
// Room: taogu.c 桃谷
// qfy July 25, 1996.

inherit ROOM;

void reset();
int valid_leave(object, string);

void create()
{
    set("short", "桃谷");
    set("long", @LONG
小径尽头尽是一山谷，气候适中，四季如春。山谷内长满了一大
片桃林，真是一处好所在。遗罕的是此处竟然喧闹之极，便如身处酒
肆之中，原来有几个老儿在为一件芝麻绿豆的小事高声争论不休。东
北方还有一条小径。
LONG
    );

    set("exits", ([
	"south" : __DIR__"xiaojing1",
	"northeast" : __DIR__"xiaojing2",
    ]));

    set("objects", ([
        __DIR__"npc/tao6" : 1,
	__DIR__"npc/tao5" : 1,
	__DIR__"npc/tao4" : 1,
	__DIR__"npc/tao3" : 1,
        __DIR__"npc/tao2" : 1,
        __DIR__"npc/tao1" : 1,
    ]));

    set("no_clean_up", 0);

	set("cost", 1);
    setup();
    //replace_program(ROOM);
}

void init()
{
	add_action("do_hit", "hit");
}

int do_hit(string arg)
{
	write("明人不作暗事，还是光明正大地挑战吧！\n");
	return 1;
}

int valid_leave(object me, string dir)
{
    if ( me->query("family/master_id") != "feng qingyang" && dir == "northeast" ) {

	if ( !me->query_temp("win/tao1") && present("tao genxian", environment(me)) )
	   	return notify_fail("桃根仙伸手一拦道：你还没跟我较量呢！\n");

	if ( !me->query_temp("win/tao2") && present("tao ganxian", environment(me)) )
		return notify_fail("桃干仙侧身拦路道：你还没跟我比划哟！\n");

	if ( !me->query_temp("win/tao3") && present("tao zhixian", environment(me)) )
		return notify_fail("桃枝仙闪身拦道说：你怎么把我给忘了呀！\n");

	if ( !me->query_temp("win/tao4") && present("tao yexian", environment(me)) )
                return notify_fail("桃叶仙双手一摊说：你想到那儿去呀？！\n");

	if ( !me->query_temp("win/tao5") && present("tao huaxian", environment(me)) )
        	return notify_fail("桃花仙笑嘻嘻地说：该轮到我来陪你过两招了吧！\n");

	if ( !me->query_temp("win/tao6") && present("tao shixian", environment(me)) )
        	return notify_fail("桃实仙强壮胆色说：打得过我便让你去见风前辈！\n");

    }		

    return ::valid_leave(me, dir);
}
