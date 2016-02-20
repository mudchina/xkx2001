//Cracked by Roath
///d/zhongnan/guangchang2.c 广场
// sdong: 07/23/98

inherit ROOM;

void create()
{
		  set("short", "广场");
		  set("long", @LONG
这里是三清殿后面的广场，地上铺着青砖。正前方有一道台阶，通往重阳宫
广宁殿。殿前有个丈许高的大香炉，香炉前的香台上，红烛高烧，香烟飘绕。广
场上有几个小道士正在练功。往北是广宁殿。
LONG
		  );
		  set("exits", ([
					 "south" : __DIR__"sanqing",
					 "north" : __DIR__"disan",
		  ]));

		  set("objects",([
					 CLASS_D("quanzhen") + "/cui" : 1,
        ]));

        set("outdoors", "zhongnan" );

        set("valid_startroom", 1);

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

