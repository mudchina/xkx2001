//Cracked by Roath
///d/zhongnan/guangchang.c 广场
// sdong: 07/23/98

inherit ROOM;

void create()
{
		  set("short", "重阳宫广场");
		  set("long", @LONG
这里是重阳宫的广场，地上铺着青砖。正前方有一道台阶，通往重阳宫
大殿。殿前有个丈许高的大香炉，香炉前的香台上，红烛高烧，香烟飘绕。
广场上有几个小道士正在练功。往南是第三殿。
LONG
		  );
		  set("exits", ([
					 "south" : __DIR__"disan",
					 "east" : __DIR__"c_dlang",
					 "west" : __DIR__"c_xilang",
					 "northup" : __DIR__"dadian",
		  ]));

		  set("objects",([
					 __DIR__"npc/ji" : 1,
		  ]));

		  set("outdoors", "zhongnan" );

		  set("valid_startroom", 1);

		  set("cost", 1);
		  setup();
}

