//Cracked by Roath
// road: /zhongnan/puguansi.c

inherit ROOM;

void create()
{
        set("short","普光寺");

        set("long",@LONG
这是一个位於终南山下的小寺庙，庙门横额写着 "普光寺" 三个大字
。由於此庙是上终南山的必经之路，大多数的游客都会在此落脚休息，也
因此此处香火也颇为鼎盛。庙前的几株松树下，立着一块石碑(shibei)，
几乎快被周围的长草给遮掩了。往西走是一条小路.
LONG);

		  set("item_desc",(["shibei" : "
			
			安 仰 万 天
			得 天 灵 苍
			大 大 日 苍    常
			千 叫 夜 兮
			复 天 相 临    春
			混 不 凌 下
			饨 应 迟 土
			， ， ， ，
			免 一 引 胡    常
			叫 物 气 为    春
			造 细 吞 不    子
			物 琐 声 救    丘
			生 枉 死 万    处
			精 劳 无 灵    机
			灵 形 语 苦    
			。 。 .  ?     题
			
		\n",]));

        set("exits",([ "west" : __DIR__"daolu",
                      ])
           );
	  set("cost",1);
	  set("objects", ([
				 __DIR__"npc/shen" : 1,
				 __DIR__"npc/lu" : 1,
	  ]));

	  set("outdoors", "zhongnan");

	  setup();

}

