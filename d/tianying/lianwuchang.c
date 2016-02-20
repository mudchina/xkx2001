//Cracked by Roath
// room: lianwuchang.c

inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
这里是一个练武场，场上排着一些木桩(muzhuang)和木人。几名
弟子在不停的击打练习。还有些弟子蹲着马步，跟师傅练着武功。每
个月这里都要举行一次比武，以检查教众的武功进度。
LONG );

        set("exits", ([
                "north" : __DIR__"fanting",
                "east" : __DIR__"guangchang",
		"south" : __DIR__"bingqifang",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
