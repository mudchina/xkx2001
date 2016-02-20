//Cracked by Roath
// road: /zhongnan/yinwutin.c

inherit ROOM;

void create()
{
        set("short","演武厅");

        set("long",@LONG
这演武厅为平时全真弟子聚集之地。比之大殿的庄严肃穆，这ㄦ却
更为年青弟子所喜爱。只见一旁不少弟子聚在一起，正在喝茶聊天。正
当中两三对弟子正在比划练剑。如果没事的话，倒可和他们讨教讨教。
往西是一间静室。往东是男厢房。往北是兵器房。
LONG);

        set("exits",([ 
		 	"west" : __DIR__"jinshi",
                        "north" : __DIR__"bingqifang",
			"south" : __DIR__"yuanneixiaojing5",
                        "east" : __DIR__"liangong1",
                      	]));
	set("cost",1);

        setup();

        replace_program(ROOM);
}
