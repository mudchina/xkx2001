//Cracked by Roath
// xiakedao/yongdao10.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里往来者甚多，多数是急匆匆的武林人物，亦有不少青衣弟子。
许多人都手持食物边走边吃，惟恐耽误了时间。几个衣衫褴褛的乞丐
便在墙边鼾然入睡。一个小僮踮起脚尖，正在添加灯油。
LONG );

      set("exits", ([
		"out" : __DIR__"dadong",
		"north" : __DIR__"gate",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 0);
    	set("objects", ([ 
		__DIR__ +"npc/gaibang" : 1, 
    	]));
	setup();
}
