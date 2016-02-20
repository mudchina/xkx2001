//Cracked by Roath
// road: /zhongnan/jinshi.c

inherit ROOM;

void create()
{
        set("short","静室");

        set("long",@LONG
这静室空荡荡的，只有几个垫子放在一旁，给弟子打坐练功用。这
ㄦ是严禁说话的，所以弟子们都轻声轻脚的走动，以免打扰了他人的静
修。往东是演武厅，往北通往女厢房。
LONG);

		  set("exits",([
		"east" : __DIR__"yinwutin",
		"north" : __DIR__"liangong2",
							 ])
			  );
	  set("cost",1);

		  set("objects",([
					 CLASS_D("quanzhen") + "/cheng" : 1,
		  ]));

		  setup();

}

