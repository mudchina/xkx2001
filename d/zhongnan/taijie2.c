//Cracked by Roath
// Room: /d/zhongnan/taijie2.c
// Date: sdong 07/23/98

inherit ROOM;


void create()
{
		  set("short", "台阶");
		  set("long", @LONG
穿过大殿，面前三道平行的青石台阶通向前方的一个高台。台阶上精工
镂刻着麒麟，玄龟，松鹤等瑞兽，形态逼真动人。高台正中方着个二人高的
青铜大香炉，前面摆着个香台，几位香客正在虔诚谟拜。再往前就是长生殿。
LONG
		  );

		  set("exits", ([
					 "south" : __DIR__"dadian",
					 "northup" : __DIR__"chanshen",
		  ]));

        set("outdoors", "zhongnan");
        set("objects",([
                __DIR__"npc/xiang-ke" : 1,
		//"/clone/npc/qiu": 1,
        ]));
        set("cost", 2);
        setup();
		call_other("/clone/board/quanzhen_b","???");
}

