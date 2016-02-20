//Cracked by Roath

// room: /d/xingxiu/saimachang.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "赛马场");
        set("long", @LONG
这里是小镇的赛马场。场上正在举行维吾尔族的「姑娘追」表演。
一个小伙子可以找一个姑娘并骑慢驰到一处折返点。去的路上小伙子
可以对姑娘随便挑逗。回来时姑娘则可以用鞭子抽打小伙子。当然，
如果姑娘喜欢这个小伙子，落鞭就会轻些。否则的话，有小伙子好受的。
北面是一间马厩。
LONG
        );
        set("exits", ([
	     "southeast" : __DIR__"beijiang",
	     ]));
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        set("objects", ([
                __DIR__"npc/alamuhan" : 1  ]) );

        setup();
        replace_program(ROOM);
}
