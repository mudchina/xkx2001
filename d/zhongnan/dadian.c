//Cracked by Roath
// road: /zhongnan/dadian.c

#include <ansi.h>
inherit ROOM;

void create()
{
		  set("short", HIR"重阳宫长春殿"NOR);

		  set("long",@LONG
这里就是全真教位於终南山的总部重阳宫大殿。只见这重阳宫大殿背
倚终南山麓而建，屋顶是绿色琉璃瓦，顶脊列着飞禽走兽，栩栩如生。琉
璃花墙，雕刻十分精美。整个结构异常严谨，殿内明灯高挂，黄幔低垂，
青烟袅袅。殿中央的墙上挂了一幅画像(hua)。往南下是一个广场。往东北
的殿後是一走廊。往北是重阳宫长生殿。往西通往养心殿。
LONG);

	  set("item_desc",(["hua" : "
这画中是一个身材甚高的中年道人，眉宇间隐隐一股英侠正气。只见
他腰悬长剑，一袭青袍似在凤中轻轻飘动，颇具仙凤道骨之气，令人为之
心折。\n",]));

        set("objects", ([
					 //CLASS_D("quanzhen") + "/qiu" : 1,
                "/clone/npc/qiu":1,
					 ]));

		  set("exits",([
								"west" : __DIR__"zhoulang",
								"north" : __DIR__"taijie2",
								"northeast" : __DIR__"yuanneixiaojing1",
								"southdown" : __DIR__"guangchang",
							 ])
			  );
		  set("cost",1);

		  setup();

	//"/clone/board/quanzhen_b"->foo();
}
