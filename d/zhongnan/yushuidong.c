//Cracked by Roath
// road: /zhongnan/yushuidong.c

inherit ROOM;

void create()
{
        set("short","玉虚洞");

        set("long",@LONG
这玉虚洞为全真教前辈闭关修行之处。据闻全真七子就是在此领悟出
全真教的不传之秘：七星聚会。可惜的是洞口已被巨石所封，不然倒可以
进去瞧瞧，是否有什麽武功秘籍。往东是一条阴森森的小径。
LONG);

		  set("exits",([ "east" : __DIR__"haoshanxiaojing2",
							 ])
			  );
	  set("cost",1);

			set("objects", ([
				 __DIR__"npc/wang-zd" : 1,
			 ]));

	 setup();
}

