//Cracked by Roath
// hz_guangchang.c 华藏庵广场
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "华藏庵广场");
	set("long", @LONG
这里是峨嵋华藏庵的广场，地上铺着青砖。正前方有一道台阶，通往大
雄宝殿。殿前有个丈许高的大香炉，香炉前的香台上，红烛高烧，香烟飘绕。
广场上有几个小师太正在练功。自此左右各有一条走廊通向后殿。
LONG
	);
	set("exits", ([
		"southup" : __DIR__"daxiong",
		"east" : __DIR__"hz_donglang1",
		"west" : __DIR__"hz_xilang1",
		"north" : __DIR__"hz_front",
	]));

        set("objects",([
                CLASS_D("emei") + "/jingxu" : 1,
        ]));

        set("outdoors", "emei" );

        set("valid_startroom", 1);

	set("cost", 1);
	setup();
	replace_program(ROOM);
        "/clone/board/emei2_b"->foo();

}

