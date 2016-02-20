//Cracked by Kafei
//Room: /u/yunq/workroom

inherit ROOM;

void create()
{
      set("short", "运气小榭");
     set("long",@LONG
这里是个世外桃源，仙人、神仙来往的地方，窗
外阳关明媚，几只小鸟在欢快地叫着，里面放着几台
电脑，有几个人在里面日夜的为侠客行新网站努力着，
一张很大的电脑桌上;有一本天书（tian shu）,里面
有各路神仙、侠客行新网站的建议和指正。仙人来这
里有种分外亲切的感觉，好像回家了一样。
LONG);
       set("exits", ([
       "qfy" : "/u/qfy/workroom",
     "sdong" : "/u/sdong/workroom",
      ]) );

      set("item_desc", ([
       "shu" : "\n诸位神仙请指教,多留言谢谢。 \n" 
         ]) );
    set("valid_startroom", 1);
    set("no_fight", "1");

      setup();
       //"/clone/board/yunq_b"->foo();
}
